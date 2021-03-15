//
//  plan.hpp
//  PA4
//
//  Created by Kyle Parker on 3/9/21.
//

#ifndef plan_hpp
#define plan_hpp
/**
 Plan
 
 *Values*
 
 `name` the name of the plan, type: string
 `date` the time of the plan, type: string
 
 - Author:
 Kyle Parker
 - Version:
 1.0
 */


class Plan {
protected:
    string name, date;
    
    Plan(string name = "", string date = "") {
        this->name = name;
        this->date = date;
    }
    
    ~Plan() {}
    
    string& getName() { return this->name; }
    string& updateName(string &newName) { return (this->name = newName); }
    
    string& getDate() { return this->date; }
    string& updateDate(string &newDate) { return (this->date = newDate); }
};

#endif /* plan_hpp */
