//
//  main_functions.cpp
//  PA4
//
//  Created by Kyle Parker on 3/7/21.
//

#include "mylib.hpp"

/// Simply print a warning if a macro is defined and warn user the OS is not supported
///
/// - Precondition: Program loaded into memory
/// - Postcondition: Warning was issued if requred
/// - seealso: functions.hpp
/// - version: 1.0

void checkOS() {
#if defined(UNSUPPORTED_OS)
    cout << "[WARN] Unsupported Operating System! (" << UNSUPPORTED_OS << ")" << endl;
#endif
}

/// throw a non-recoverable error for debugging. Should never be called when deploying software.
///
/// - Precondition: aruguments are all strings. all other values are not accepted.
/// - Postcondition: program stopped.
/// - Warning: Program will exit
/// - Parameter count: the number of arguments
/// - Parameter ... : the variable list to run through.
/// - seealso: [Microsoft Docs, "Functions with Variable Argument Lists (C++)"] (https://docs.microsoft.com/en-us/cpp/cpp/functions-with-variable-argument-lists-cpp?view=msvc-160)
/// - version: 1.0
void fatalError(int count, ...) {
    va_list vl;
    va_start(vl, count);
    for (int i = count; i > 0; i -= 1) {
        char * str = va_arg(vl, char *);
        cout << str << " ";
    }
    cout << endl;
    va_end(vl);
    
    abort();
}

/// Convert a string to all lowercase, rather than a single character.
///
/// - Postcondition: string is lowercased
/// - Warning: not localized, undefined behavior may occur with non-ascii characters
/// - Parameter str: the string ot lowercase
/// - version: 1.0
string strToLower(string &str) {
    string newStr = "";
    
    for (char ch : str) {
        newStr += tolower(ch);
    }
    
    return newStr;
}

/// get a yes/no response from user
///
/// - Precondition: user prompted for a yes/no question.
/// - Postcondition: bool is returned, true for yes, false for no
/// - Returns: boolean indicating success
/// - version: 1.0
bool getYesNo(void) {
    string str;
    cout << "(y)es/(n)o\n>";
    cin >> str;
    return isYes(str);
}
