//
//  main_header.hpp
//  PA4
//
//  Created by Kyle Parker on 3/7/21.
//

#ifndef main_header_h
#define main_header_h

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
#elif defined(__APPLE__) || defined(__MACH__)
// import macOS-specific libraries as needed.
    #define CLEAR_SCREEN "clear"
#elif defined(__linux__) || defined(linux) || defined(__linux)
// import Linux-specific libraries as needed.
    #define CLEAR_SCREEN "clear"
#else
#define UNSUPPORTED_OS UNKNOWN // was not caught by one of the above cases.
#endif

// include libraries for ALL platforms. Platform-specific libraries should be imported above.
#include <iostream> // std::cout, std::cin, std::endl, std::string


// declare using statements
using std::cout;
using std::cin;
using std::endl;
using std::string;

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
string strToLower(string str);

// define inline methods:
inline bool isYes(string str) {
    str = strToLower(str);
    return str == "yes" || str == "y";
}

template <typename T>
inline bool isYes(T value) {
    return value == 1;
}

#endif /* main_header_h */