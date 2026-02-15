#include <iostream>
#include <string>
#include "utility.h"
#include "block.h"
#include "stream.h"
#include <cstring>

using namespace std;

int main([[maybe_unused]] int argc, char *argv[]) {

    string contents;
    const char* cipherType = argv[1];
    const char* input = argv[2];
    const char* output = argv[3];
    const char* key = argv[4];
    const char* mode = argv[5];

    Utility utility;

    bool validCipher = utility.validCipher(cipherType);
    bool validInputPath = utility.validInputPath(input);
    utility.outputPath(output);
    bool validKeyPath = utility.validKeyPath(key);
    bool validMode = utility.validMode(mode);

    if(strcmp(cipherType, "B") == 0) {

        BlockCipher blockCipher;
        string inputcontents = blockCipher.inputContents(input);
        string keyContents = blockCipher.keyContents(key);

        if(inputcontents.length() == 0) {
            blockCipher.outputContents(inputcontents, output);  
            exit(0);  
        }

        if(strcmp(mode, "E") == 0) {
            string value = blockCipher.encrypt(inputcontents, keyContents);
            blockCipher.outputContents(value, output);
        }

        if(strcmp(mode, "D") == 0) {
            string value = blockCipher.decrypt(inputcontents, keyContents);
            blockCipher.outputContents(value, output);
        }

    }

    else if (strcmp(cipherType, "S") == 0) {

        StreamCipher streamCipher;
        string inputcontents = streamCipher.inputContents(input);
        string keyContents = streamCipher.keyContents(key);

        if(inputcontents.length() == 0) {
            streamCipher.outputContents(inputcontents, output);  
            exit(0);  
        }

        else {
            string value = streamCipher.encrypt(inputcontents, keyContents);
            streamCipher.outputContents(value, output);
        } 

    }

}