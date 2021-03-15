//
//  Error Domain.hpp
//  PA4
//
//  Created by Kyle Parker on 3/11/21.
//

#ifndef Error_Domain_hpp
#define Error_Domain_hpp

class FileError final {
public:
    typedef unsigned int failure;
    static const failure none         = 0x00;
    static const failure couldNotOpen = 0x01;
    static const failure badFormat    = 0x02;
    static const failure alreadyOpen  = 0x03;
    
    static string getPrintableError(FileError::failure e) {
        switch (e) {
        case 0x00:
            return "No error.";
        case 0x01:
            return "Failed to open the file.";
        case 0x02:
            return "File failed some verification, unexpected format.";
        case 0x03:
            return "File already open. File must be closed prior to the entry of method. (Internal Error)";
        default:
            return "Could not get description of error. Check for valid type.";
        }
    }
};

#endif /* Error_Domain_hpp */
