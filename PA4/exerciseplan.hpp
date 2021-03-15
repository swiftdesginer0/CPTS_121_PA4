//
//  exerciseplan.hpp
//  PA4
//
//  Created by Kyle Parker on 3/9/21.
//

#ifndef exerciseplan_hpp
#define exerciseplan_hpp

/**
 * ExercisePlan
 *
 * Values:
 *
 * `goalSteps` the target number for steps.
 *
 * - Author:
 * Kyle Parker
 * - Version:
 * 1.0
 * - See Also:
 * `Plan`
 * `DietPlan` (Similar type)
 */

class ExercisePlan : Plan {
    int goalSteps;
    
public:
    ExercisePlan(ExercisePlan &copy) {
        this->goalSteps = copy.goalSteps;
        this->name      = copy.name;
        this->date      = copy.date;
    }
    
    ExercisePlan(int steps = 0, string name = "", string date = "") {
        this->goalSteps = steps;
        this->name      = name;
        this->date      = date;
    }
    
    ~ExercisePlan() {}
    
    int& getSteps() { return goalSteps; }
    int& updateSteps(int amount = 1) { goalSteps += 1; return goalSteps; }
    
    string& getName() { return Plan::getName(); }
    string& updateName(string &newName) { return Plan::updateName(newName); }
    
    string& getDate() { return Plan::getDate(); }
    string& updateDate(string &newDate) { return Plan::updateDate(newDate); }
};

ostream & operator << (ostream &lhs, ExercisePlan &rhs) {
    return lhs << "Name: " << rhs.getName() << "\nCalories Goal: " << rhs.getSteps() << "\nDate: " << rhs.getDate();
}

#endif /* exerciseplan_hpp */
