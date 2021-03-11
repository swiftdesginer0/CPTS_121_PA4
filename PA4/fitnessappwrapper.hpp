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
    vector<DietPlan> diet = {};
    vector<ExercisePlan> exercise = {};
public:
    void runApp(void) {
        checkOS();
        
        
    }
};

#endif /* FitnessAppWrapper_hpp */
