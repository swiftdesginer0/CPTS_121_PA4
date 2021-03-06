//
//  dietplan.hpp
//  PA4
//
//  Created by Kyle Parker on 3/9/21.
//

#ifndef dietplan_h
#define dietplan_h

/**
 * DietPlan
 *
 * Values:
 *
 * `goalCalories` the target number for calories.
 *
 * - Author:
 * Kyle Parker
 * - Version:
 * 1.0
 * - See Also:
 * `Plan`
 * `ExercisePlan` (Similar type)
 */

class DietPlan : public Plan {
    int goalCalories;
public:
    /// DietPlan copy initalizer
    ///
    /// - Precondition: `copy` is not NULL
    /// - Postcondition: a copy of `copy` is non-NULL
    /// - Parameter copy: the class to copy from
    /// - version: 1.0
    DietPlan(DietPlan &copy) {
        this->goalCalories = copy.goalCalories;
        this->name         = copy.name;
        this->date         = copy.date;
    }
    
    /// DietPlan initalizer with defaults.
    ///
    /// Default for `cals`: 0
    /// Default for `name`, `date`: ""
    ///
    /// - Precondition: `copy` is not NULL
    /// - Postcondition: a copy of `copy` is non-NULL
    /// - Parameter copy: the class to copy from
    /// - Parameter copy: the class to copy from
    /// - Parameter copy: the class to copy from
    /// - version: 1.0
    DietPlan(int cals = 0, string name = "", string date = "") {
        this->goalCalories = cals;
        this->name         = name;
        this->date         = date;
    }
    
    ~DietPlan() {}
    
    int & getCalories() { return goalCalories; }
    int & addCalories(int amount = 1) { goalCalories += 1; return goalCalories; }
    
    string& getName() { return Plan::getName(); }
    string& updateName(string &newName) { return Plan::updateName(newName); }
    
    string& getDate() { return Plan::getDate(); }
    string& updateDate(string &newDate) { return Plan::updateDate(newDate); }
};

ostream & operator << (ostream &lhs, DietPlan &rhs) {
    return lhs << "Name: " << rhs.getName() << "\nCalories Goal: " << rhs.getCalories() << "\nDate: " << rhs.getDate();
}

#endif /* dietplan_h */
