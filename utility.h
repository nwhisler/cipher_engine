#ifndef UTILITY_H
#define UTILITY_H

#include <string>

using namespace std;

class Utility {

    public:

        Utility();
        bool validInputPath(const char* input);
        void outputPath(const char* output);
        bool validKeyPath(const char* key);
        bool validCipher(const char* cipher);
        bool validMode(const char* mode);
        string readInput(const char* input);
        string xorUtilityStream(string inputContents, string keyContents);
        string xorMethod(string inputContents, string keyContents);
        string swap(string xored, string keyContents);
        string xorUtilityDecrypt(string inputContents, string keyContents);
        string xorUtilityEncrypt(string inputContents, string keyContents);


};


#endif // UTILITY_H