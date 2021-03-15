//
//  FitnessAppWrapper.hpp
//  PA4
//
//  Created by Kyle Parker on 3/9/21.
//

#ifndef FitnessAppWrapper_hpp
#define FitnessAppWrapper_hpp

class FitnessAppWrapper final {
    // string defined for displaying options to the user.
    const string optionsString = "1) Load week diet plan from file.\n2) Load weekly exercise plan from file.\n3) Store weekly diet plan to file.\n4) Store weekly exercise plan to file.\n5) Display weekley diet plan to screen.\n7)Edit daily diet plan.\n8) Edit daily exercise plan.\n9) Exit and save.\n10) Exit WITHOUT saving.";
    
    string dietFilePath = "Local Srcs/dietPlans.txt";
    string exerciseFilePath = "Local Srcs/exercisePlans.txt";
    
    // vectors for array of plans.
    vector<DietPlan *> diet = {};
    vector<ExercisePlan *> exercise = {};
    
    /// load data into the diet vector from the file defined at `filePath`.
    ///
    /// - Precondition: steam must be closed.
    /// - Postcondition: data is loaded
    /// - Warning: macOS hosts will need to define an import source on the first run.
    /// - Parameter filePath:  the path to the file [default case is file in local sourcs folder.]
    /// - Returns: bool, indicator of success
    /// - seealso: loadDataFromFile(string,char), filePath
    /// - version: 1.0
    inline pair<bool, FileError::failure> loadDiet(fstream& stream) {
        return loadDataFromFile(stream, 'd');
    }
    
    /// load data into the exercise vector from the file defined at `filePath`.
    ///
    /// - Precondition: stream must be closed.
    /// - Postcondition: data is loaded
    /// - Warning: macOS hosts will need to define an import source on the first run.
    /// - Parameter filePath:  the path to the file [default case is file in local sourcs folder.]
    /// - Returns: bool, indicator of success
    /// - seealso: loadDataFromFile(string,char), filePath
    /// - version: 1.0
    inline pair<bool, FileError::failure> loadExercise(fstream &stream) {
        return loadDataFromFile(stream, 'e');
    }
    
    /// load data into the defined vector (determined by type) and at the filePath.
    ///
    /// - Precondition: stream must be closed.
    /// - Postcondition: data is loaded
    /// - Parameter filePath:  the path to the file
    /// - Parameter type:  should be either 'e' or 'd'
    /// - Returns: bool, indicator of success, FileError::failure, the error code (if any)
    /// - seealso: loadExercise(fstream&), loadDiet(fstream&), filePath
    /// - version: 1.0
    pair<bool, FileError::failure> loadDataFromFile(fstream& stream, char type) {
        bool success = false;
        FileError::failure error = FileError::none;
        
        // check to make sure stream is closed
        if (stream.is_open()) {
            error = FileError::alreadyOpen;
        } else {
            stream.open(type == 'e' ? exerciseFilePath : dietFilePath, ios::in);
            
            if (stream.is_open()) {
                
                string line, name, date;
                int goal = 0, i = 0;
                while (getline(stream, line)) {
                    switch (i) {
                    case 0:
                        name = line;
                        break;
                    case 1:
                        goal = stoi(line);
                        break;
                    case 2:
                        date = line;
                        break;
                    case 3:
                        if (type == 'd') {
                            DietPlan * d = new DietPlan(goal, name, date);
                            this->diet.push_back(d);
                        } else if (type == 'e') {
                            ExercisePlan * e = new ExercisePlan(goal, name, date);
                            this->exercise.push_back(e);
                        }
                        i = 0;
                    default:
                        i = 0;
                        break;
                    }
                    i += 1;
                }
                
                stream.close();
                success = true;
            } else {
                success = false;
                error = FileError::couldNotOpen;
            }
        }
        
        return make_pair(success, error);
    }
    
    /// get a valid option from the user that is within the valid range.
    ///
    /// - Postcondition: A valid integer, btween 1 and 10, inclusive is returned.
    /// - Warning: This could be infinate if invalid options are always entered.
    /// - Returns: int, a value describing the user's choice
    /// - seealso: getOptionHelper()
    /// - version: 1.0
    int getOption(void) {
        int opt = -1;
        
        while (opt < 1 || opt > 10) {
            clearScreen();
            cout << this->optionsString << endl;
            opt = getOptionHelper();
        }
        
        return opt;
    }
    
    /// returns an integer based off user input. this is only called from `getOption()`
    ///
    /// - Precondition: `getOption()` was called
    /// - Postcondition: an integer value is returned
    /// - Returns: int, a value describing the user's choice, valid or not.
    /// - seealso: `getOption`
    /// - version: 1.0
    int getOptionHelper(void) {
        int opt;
        
        cout << "Please enter a number between 1 and 10, inclusive:" << endl;
        
        cin >> opt;
        
        return opt;
    }
    
    /// check the result based off the argument. result is returned by data loaders and savers.
    ///
    /// - Precondition: a data loader or saver was called.
    /// - Postcondition: result was checked and may have interacted with user.
    /// - Parameter data:  the pair containing possible error data
    /// - seealso: pair<bool, FileError::failure> loadDataFromFile(fstream& stream, char type),
    /// - version: 1.0
    void checkResult(pair<bool, FileError::failure> data) {
        if (!data.first) {
            cout << "Failed! Error code: " << data.second << ". Description: " << FileError::getPrintableError(data.second) << "." << endl;
        }
    }
    
    inline pair<bool, FileError::failure> storeDiet(fstream &output) {
        return storeDataToFile(output, 'd');
    }
    
    inline pair<bool, FileError::failure> storeExercise(fstream &output) {
        return storeDataToFile(output, 'e');
    }
    
    /// save data into the file at '*filePath'
    ///
    /// - Precondition: stream must be closed.
    /// - Postcondition: data is stored to file, or given error is returned
    /// - Parameter filePath:  the path to the file
    /// - Parameter type:  should be either 'e' or 'd'
    /// - Returns: bool, indicator of success and FileError::failure, error type
    /// - seealso: storeExercise(fstream&), storeDiet(fstream&), filePath
    /// - version: 1.0
    pair<bool, FileError::failure> storeDataToFile(fstream& stream, char type) {
        clearScreen();
        bool success = false;
        FileError::failure error = FileError::none;
        
        cout << "Saving data..." << endl;
        
        // check to make sure stream is closed
        if (stream.is_open()) {
            error = FileError::alreadyOpen;
            cout << "Error! Internal error." << endl;
        } else {
            
            stream.open(type == 'e' ? exerciseFilePath : dietFilePath, ios::out);
            
            if (stream.is_open()) {
                if (type == 'e') {
                    for (ExercisePlan * p : this->exercise) {
                        stream << *p;
                    }
                } else {
                    for (DietPlan * p : this->diet) {
                        stream << *p;
                    }
                }
//                string line, name, date;
//                int goal = 0, i = 0;
////                while (getline(stream, line)) {
////                    switch (i) {
////                    case 0:
////                        name = line;
////                        break;
////                    case 1:
////                        goal = stoi(line);
////                        break;
////                    case 2:
////                        date = line;
////                        break;
////                    case 3:
////                        if (type == 'd') {
////                            DietPlan * d = new DietPlan(goal, name, date);
////                            this->diet.push_back(d);
////                        } else if (type == 'e') {
////                            ExercisePlan * e = new ExercisePlan(goal, name, date);
////                            this->exercise.push_back(e);
////                        }
////                        i = 0;
////                    default:
////                        i = 0;
////                        break;
////                    }
////                    i += 1;
////                }
                
                stream.close();
                success = true;
            } else {
                success = false;
                error = FileError::couldNotOpen;
            }
        }
        
        return make_pair(success, error);
    }
    
    void displayDietPlan(bool shouldDisplayNumber = false) {
        clearScreen();
        if (this->diet.empty()) {
            cout << "[NO DATA TO DISPLAY]" << endl;
        } else {
            cout << "------------------------------" << endl;
            int i = 1;
            for (DietPlan * p: this->diet) {
                if (shouldDisplayNumber) {
                    cout << "----------" << i << "----------";
                } else {
                    cout << "---------------------";
                }
                
                cout << *p << endl;
                cout << "---------------------" << endl;
                i += 1;
            }
            i -= 1;
            cout << "------------------------------" << endl;
        }
        
        waitForReturn();
    }
    
    void displayExercisePlan(bool shouldDisplayNumber = false) {
        clearScreen();
        if (this->exercise.empty()) {
            cout << "[NO DATA TO DISPLAY]" << endl;
        } else {
            cout << "------------------------------" << endl;
            
            int i = 0;
            for (ExercisePlan * p: this->exercise) {
                if (shouldDisplayNumber) {
                    cout << "----------" << i << "----------";
                } else {
                    cout << "---------------------";
                }
                cout << *p << endl;
                cout << "---------------------" << endl;
                i += 1;
            }
            i -= 1;
            cout << "------------------------------" << endl;
        }
        
        waitForReturn();
    }
    
    void editDietPlan(void) {
        clearScreen();
        if (this->diet.empty()) {
            cout << "[NO DATA TO EDIT]" << endl;
        } else {
            displayDietPlan(true);
            int x = 0;
            string str = "";
            
            while (!(x > 0 && x < this->diet.size()) && !((strToLower(str) == "cancel" || strToLower(str) == "c"))) {
                cout << "\nWhich number would you like to edit? To cancel, type \"C\"\n> ";
                cin >> str;
                try {
                    x = stoi(str);
                } catch (exception & e) {
                    cout << "Edit canceled." << endl;
                }
            }
            
            if (strToLower(str) == "cancel" || strToLower(str) == "c") {
                cout << "Edit canceled." << endl;
            } else {
                DietPlan * ele = this->diet.at(x-1);
                cout << "New name (" << ele->getName() << "): ";
            }
        }
        
        waitForReturn();
    }
    
    void editExercisePlan(void) {
        clearScreen();
        if (this->exercise.empty()) {
            cout << "[NO DATA TO EDIT]" << endl;
        } else {
            bool ex = true;
            while (ex) {
                displayExercisePlan(true);
                int x = 0;
                string str = "";
                
                while (!(x > 0 && x < this->exercise.size()) && !((strToLower(str) == "cancel" || strToLower(str) == "c"))) {
                    cout << "\nWhich number would you like to edit? To cancel, type \"C\"\n> ";
                    cin >> str;
                    try {
                        x = stoi(str);
                    } catch (exception & e) {
                        cout << "Edit canceled." << endl;
                        ex = false;
                    }
                }
                
                if (strToLower(str) == "cancel" || strToLower(str) == "c") {
                    cout << "Edit canceled." << endl;
                    ex = false;
                } else {
                    ExercisePlan * ele = this->exercise.at(x-1);
                    cout << "You will be walked through steps to set new values. Leave blank (just press " << RETURN_KEY_LOWER << ") to maintain current value." << endl;
                    
                    string tmp_val;
                    cout << "New name (" << ele->getName() << "):\n>";
                    cin >> tmp_val;
                    if (tmp_val != "") { ele->updateName(tmp_val); }
                    cout << "New date (" << ele->getDate() << "):\n>";
                    cin >> tmp_val;
                    if (tmp_val != "") { ele->updateDate(tmp_val); }
                    cout << "New steps target (" << ele->getSteps() << "):\n>";
                    cin >> tmp_val;
                    if (tmp_val != "") { ele->updateSteps(stoi(tmp_val)); }
                    
                    cout << "Updated value:\n" << *ele << endl;
                    
                    cout << "Update another? ";
                    ex = getYesNo();
                }
            }
        }
        
        waitForReturn();
    }
    
    
    void exitAndSave(void) {
        clearScreen();
    }
    
    void exitNoSave(void) {
        clearScreen();
    }
    
    inline void waitForReturn() {
        string wait;
        cout << endl << "[PRESS " << RETURN_KEY_UPPER << " TO CONTINUE]" << endl;
        cin >> wait;
    }
public:
    
    ~FitnessAppWrapper() {
        for (DietPlan * p : diet) {
            delete p;
        }
        for (ExercisePlan * p : exercise) {
            delete p;
        }
    }
    
    FitnessAppWrapper(FitnessAppWrapper & copy) {
        this->dietFilePath = copy.dietFilePath;
        this->exerciseFilePath = copy.exerciseFilePath;
        
        for (DietPlan * d : copy.diet) {
            DietPlan * newDiet = new DietPlan(*d);
            this->diet.push_back(newDiet);
        }
        
        reverse(this->diet.begin(), this->diet.end());
        
        for (ExercisePlan * e : copy.exercise) {
            ExercisePlan * newExercise = new ExercisePlan(*e);
            this->exercise.push_back(newExercise);
        }
        
        reverse(this->exercise.begin(), this->exercise.end());
    }
    
    FitnessAppWrapper() { }
    
    
    /// Called from main.cpp. Runs application and calls required functions.
    ///
    /// - Precondition: Application is loaded into memory
    /// - Postcondition: Application will exit
    /// - version: 1.0
    void runApp(void) {
        checkOS();
        
        fstream stream;
        
        int opt = 0;
        bool bypass = false;
        while (opt != 9) {
            if (bypass) { bypass = false; } else { opt = this->getOption(); }
            switch (opt) {
            case 1: {
                pair<bool, FileError::failure> result = this->loadDiet(stream);
                if (!result.first) {
                    clearScreen();
                    if (result.second == FileError::couldNotOpen) {
                        cout << "Either the file does not exist or we do not have permission to access it. Would you like to define a path to the file now?" << endl;
                        if (getYesNo()) {
                            while (true) {
                                cout << "Type the full file path to the diet file:\n> " << endl;
                                cin >> dietFilePath;
                                cout << "Is '" << dietFilePath << "' the correct path?" << endl;
                                if (getYesNo()) {
                                    bypass = true;
                                    break;
                                }
                            }
                        } else {
                            cout << "An Error occured while loading the file!\nError Description: " << FileError::getPrintableError(result.second) << endl;
                        }
                    } else {
                        cout << "An Error occured while loading the file!\nError Description: " << FileError::getPrintableError(result.second) << endl;
                    }
                }
                break;
            }
            case 2: {
                pair<bool, FileError::failure> result = this->loadExercise(stream);
                if (!result.first) {
                    clearScreen();
                    if (result.second == FileError::couldNotOpen) {
                        cout << "Either the file does not exist or we do not have permission to access it. Would you like to define a path to the file now?" << endl;
                        if (getYesNo()) {
                            while (true) {
                                cout << "Type the full file path to the exercise file:\n> " << endl;
                                cin >> dietFilePath;
                                cout << "Is '" << dietFilePath << "' the correct path?" << endl;
                                if (getYesNo()) {
                                    bypass = true;
                                    break;
                                }
                            }
                        } else {
                            cout << "An Error occured while loading the file!\nError Description: " << FileError::getPrintableError(result.second) << endl;
                        }
                    } else {
                        cout << "An Error occured while loading the file!\nError Description: " << FileError::getPrintableError(result.second) << endl;
                    }
                }
                break;
            }
            case 3: {
                pair<bool, FileError::failure> result = this->storeDiet(stream);
                if (!result.first) {
                    clearScreen();
                    if (result.second == FileError::couldNotOpen) {
                        cout << "Either the file does not exist or we do not have permission to access it. Would you like to define a path to the file now?" << endl;
                        if (getYesNo()) {
                            while (true) {
                                cout << "Type the full file path to the diet file:\n> " << endl;
                                cin >> dietFilePath;
                                cout << "Is '" << dietFilePath << "' the correct path?" << endl;
                                if (getYesNo()) {
                                    bypass = true;
                                    break;
                                }
                            }
                        } else {
                            cout << "An Error occured while loading the file!\nError Description: " << FileError::getPrintableError(result.second) << endl;
                        }
                    } else {
                        cout << "An Error occured while loading the file!\nError Description: " << FileError::getPrintableError(result.second) << endl;
                    }
                }
                break;
            }
            case 4: {
                pair<bool, FileError::failure> result = this->storeExercise(stream);
                if (!result.first) {
                    clearScreen();
                    if (result.second == FileError::couldNotOpen) {
                        cout << "Either the file does not exist or we do not have permission to access it. Would you like to define a path to the file now?" << endl;
                        if (getYesNo()) {
                            while (true) {
                                cout << "Type the full file path to the exercise file:\n> " << endl;
                                cin >> dietFilePath;
                                cout << "Is '" << dietFilePath << "' the correct path?" << endl;
                                if (getYesNo()) {
                                    bypass = true;
                                    break;
                                }
                            }
                        } else {
                            cout << "An Error occured while loading the file!\nError Description: " << FileError::getPrintableError(result.second) << endl;
                        }
                    } else {
                        cout << "An Error occured while loading the file!\nError Description: " << FileError::getPrintableError(result.second) << endl;
                    }
                }
                break;
            }
            case 5: {
                this->displayDietPlan();
                break;
            }
            case 6: {
                this->displayExercisePlan();
                break;
            }
            case 7: {
                this->editDietPlan();
                break;
            }
            case 8: {
                this->editExercisePlan();
                break;
            }
            case 9: {
                this->exitAndSave();
                break;
            }
            case 10: {
                this->exitNoSave();
                break;
            }
            default:
                break;
            }
        }
    }
};

#endif /* FitnessAppWrapper_hpp */
