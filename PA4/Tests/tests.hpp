//
//  tests.hpp
//  PA4
//
//  Created by Kyle Parker on 2/24/21.
//

#ifndef tests_hpp
#define tests_hpp

#include "functions.hpp"


class TestResult {
    bool success;
    string exceptionReason;
    string sender;
public:
    TestResult() {
        this->success = false;
        this->sender = "[UNKNOWN SENDER]";
        this->exceptionReason = "[INSTANCE INITALIZED WITHOUT ANY ARGUMENTS]";
    }
    
    TestResult(bool val, string sender = "[UNKNOWN SENDER]", string exc = "[NO REASON PROVIDED]") {
        this->success = val;
        this->sender = sender;
        this->exceptionReason = exc;
    }
    
    
    friend std::ostream& operator<< (std::ostream &lhs, const TestResult &rhs) {
        string success = rhs.success ? "SUCCESS!" : "FAILED!";
        return lhs << "Function: " << rhs.sender << ". Status: " << success << ". Reason: " << rhs.exceptionReason << std::endl;
    }
};

#endif /* tests_hpp */
