//
//  standard.hpp
//  PA4
//
//  Created by Kyle Parker on 3/7/21.
//

#ifndef standard_hpp
#define standard_hpp

// following macros definitons were found at https://sourceforge.net/p/predef/wiki/OperatingSystems/

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
    #ifndef _CRT_SECURE_NO_WARNINGS
        #define _CRT_SECURE_NO_WARNINGS // disable secure warnings
    #endif
    #define CLEAR_SCREEN "cls"
    #define RETURN_KEY_UPPER "ENTER"
    #define RETURN_KEY_LOWER "enter"
#elif defined(__APPLE__) || defined(__MACH__)
// import macOS-specific libraries as needed.
    #define CLEAR_SCREEN "clear"
    #define RETURN_KEY_UPPER "RETURN"
    #define RETURN_KEY_LOWER "return"
#elif defined(__linux__) || defined(linux) || defined(__linux)
// import Linux-specific libraries as needed.
    #define CLEAR_SCREEN "clear"
    #define RETURN_KEY_UPPER "RETURN"
    #define RETURN_KEY_LOWER "return"
#else
#define UNSUPPORTED_OS UNKNOWN // was not caught by one of the above cases.
#endif

// include libraries for ALL platforms. Platform-specific libraries should be imported above.
#include <iostream> // std::cout, std::cin, std::endl, std::pair, std::make_pair
#include <string> // std::string, std::stoi
#include <vector> // std::vector
#include <fstream> // std::fstream
#include <istream> // std::istream
#include <ostream> // std::ostream
#include <map> // std::map
#include <exception> // std::exception


// declare using statements
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::make_pair;
using std::fstream;
using std::istream;
using std::ostream;
using std::ios;
using std::stoi;
using std::map;
using std::exception;
using std::reverse;

// define custom/encaspulated types:


// define protocol stubs
void checkOS(void);
void fatalError(int, ...);

string strToLower(string &str);

bool getYesNo(void);
// define inline methods:
/// clears the screen using a macro defined per OS for cross platform compatability.
///
/// - Precondition: Screen needs to be cleared
/// - Postcondition: Screen is cleared
/// - Warning: Any information printed prior to this call may not be accessable.
/// - version: 1.0
inline void clearScreen() {
    system(CLEAR_SCREEN);
}

inline bool isYes(string str) {
    str = strToLower(str);
    return str == "yes" || str == "y" || str == "true" || str == "t";
}

template <typename T>
inline bool isYes(T value) { return value == 1; }

#endif /* standard_hpp */
