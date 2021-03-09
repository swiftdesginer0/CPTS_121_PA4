//
//  functions.hpp
//  PA4
//
//  Created by Kyle Parker on 2/24/21.
//

#ifndef functions_hpp
#define functions_hpp

// following macros were found at https://sourceforge.net/p/predef/wiki/OperatingSystems/

#if defined(_WIN16)
#define UNSUPPORTED_OS _WIN16 // warn depictated version of Windows (Windows 16-bit env)
#elif defined(__WINDOWS__)
#define UNSUPPORTED_OS __WINDOWS__ // warn depictated version of Windows (Watcom C/C++)
#elif defined(MSDOS) || defined (__MSDOS__) || defined(_MSDOS) || defined(__DOS__)
#define UNSUPPORTED_OS MSDOS // warn MSDOS is not supported
#elif defined(macintosh) || defined(Macintosh)
#define UNSUPPORTED_OS Macintosh // warn depictated version of Mac OS (Mac OS 9)
#elif defined(_WIN32) || defined(_WIN64)
// import Windows-specific libraries as needed
#elif defined(__APPLE__) || defined(__MACH__)
// import macOS-specific libraries as needed.
#elif defined(__linux__) || defined(linux) || defined(__linux)
// import Linux-specific libraries as needed.
#else
#define UNSUPPORTED_OS UNKNOWN // was not caught by one of the above cases.
#endif

// include libraries for ALL platforms. Platform-specific libraries should be imported above.
#include <iostream> // std::cout, std::cin, std::endl, std::string
#include <map> // map


// declare using statements
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;

// define structs, enums

/**
 Errors thrown by fakeArray.
 
 *Values*
 
 `NegativeCount` The count is less than 0.
 
 `EmptyString1` The first string argument is empty.
 
 `EmptyStriinitSongond string argument is empty.
 
 - Author:
 Newbie
 - Version:
 0.1
 */

// define custom/encaspulated types:


// define protocol stubs
void checkOS(void);
void fatalError(int, ...);


// define classes:

class Plan {
protected:
    string name, date;
public:
    void setName(string newName) { name = newName; }
    
    void setDate(string newDate) { date = newDate; }
    
    string getName() { return name; }
    
    string getDate() { return date; }
};

class DietPlan : Plan {
    int goalCalories;
public:
    DietPlan(DietPlan &copy) {
        this->goalCalories = copy.goalCalories;
        this->name         = copy.name;
        this->date         = copy.date;
    }
    
    DietPlan(int cals = 0, string name = "NOT SET", string date = "NOT SET") {
        this->goalCalories = cals;
        this->name         = name;
        this->date         = date;
    }
    
    ~DietPlan() {
        
    }
    int& getCalories() { return goalCalories; }
    int& addCalories(int amount = 1) { goalCalories += 1; return goalCalories; }
};

class ExercisePlan : Plan {
    int goalSteps;
    
public:
    ExercisePlan(ExercisePlan &copy) {
        this->goalSteps = copy.goalSteps;
        this->name      = copy.name;
        this->date      = copy.date;
    }
    
    ExercisePlan(int steps = 0, string name = "NOT SET", string date = "NOT SET") {
        this->goalSteps = steps;
        this->name      = name;
        this->date      = date;
    }
    
    int& getSteps() { return goalSteps; }
    int& addSteps(int amount = 1) { goalSteps += 1; return goalSteps; }
    
    string& getName() { return this->name; }
    string& updateName(string &newName) {
        this->name = newName;
        return newName;
    }
    
    string& getDate() { return this->date; }
    string& updateDate(string &newDate) {
        this->date = newDate;
        return newDate;
    }
};

#endif /* functions_hpp */
