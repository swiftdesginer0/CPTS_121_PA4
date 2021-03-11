//
//  FitnessAppWrapper.hpp
//  PA4
//
//  Created by Kyle Parker on 3/9/21.
//

#ifndef FitnessAppWrapper_hpp
#define FitnessAppWrapper_hpp

#include "main.hpp"

class FitnessAppWrapper final {
    // string defined for displaying options to the user.
    const string optionsString = "1) Load week diet plan from file.\n2) Load weekly exercise plan from file.\n3) Store weekly diet plan to file.\n4) Store weekly exercise plan to file.\n5) Display weekley diet plan to screen.\n7)Edit daily diet plan.\n8) Edit daily exercise plan.\n9) Exit and save.\n10) Exit WITHOUT saving.";
    
    // vectors for array of plans.
    vector<DietPlan> diet = {};
    vector<ExercisePlan> exercise = {};
    
    /// load data into the diet vector from the file defined at the path.
    ///
    /// - Precondition: <#PRECOND#>
    /// - Postcondition: <#POSTCOND#>
    /// - Warning: macOS hosts will need to define an import source on the first run.
    /// - Parameter <#PARAM NAME#>:  <#PARAM DESC#>
    /// - Returns: <#RTN VAL SUM#>
    /// - seealso: [<#LINK NAME#>](<#LINK#>)
    /// - version: <#1.0#>
    bool loadDiet(string filePath = "Local Srcs/dietPlans.txt") {
        bool success = false;
        
        return success;
    }
    
    bool loadExercise(string filePath = "Local Srcs/exercisePlans.txt") {
        bool success = false;
        
        return success;
    }
    
    int getOption() {
        int opt = getOptionHelper();
        
        while (opt < 1 || opt > 10) {
            clearScreen();
            cout << this->optionsString;
            opt = getOptionHelper();
        }
        
        return opt;
    }
    
    int getOptionHelper() {
        int opt;
        
        cout << "Please enter a number between 1 and 10, inclusive." << endl;
        
        cin >> opt;
        
        return opt;
    }
    
public:
    /// Called from main.cpp. Runs application and calls required functions.
    ///
    /// - Precondition: Application is loaded into memory
    /// - Postcondition: Application will exit
    /// - version: 1.0
    void runApp(void) {
        checkOS();
        
        int opt = this->getOption();
        while (opt != 9) {
            switch (opt) {
            case 1:
                this->loadDiet();
                break;
                
            default:
                break;
            }
        }
    }
};

#endif /* FitnessAppWrapper_hpp */
