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
    int& addSteps(int amount = 1) { goalSteps += 1; return goalSteps; }
};

#endif /* exerciseplan_hpp */
