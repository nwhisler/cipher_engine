#include <iostream>
#include "utility.h"
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

Utility::Utility() {
    
}

bool Utility::validCipher(const char* cipher) {

    if((strcmp(cipher, "B") == 0) || (strcmp(cipher, "S") == 0)) {
        return true;
    }

    else {
        cout << "Invalid Function Type\n";
        exit(1);
    }

}

bool Utility::validInputPath(const char* input) {

    if (FILE *file = fopen(input, "r")) {
        fclose(file);
        return true;
    } else {
        cout << "Input File Does Not Exist\n";
        exit(1);
    }  

}

string Utility::readInput(const char* inputPath) {

    string line;
    ifstream input(inputPath);
    string contents = "";

    while(getline (input, line)) {
        contents += line;
        contents += "\n";
    }

    contents = contents.substr(0, contents.length() - 1);

    input.close();

    return contents;

}

void Utility::outputPath(const char* output) {

    FILE *file = fopen(output, "w");
    fclose(file); 

}

bool Utility::validKeyPath(const char* key) {

    if (FILE *file = fopen(key, "r")) {
        fclose(file);
        return true;
    } else {
        cout << "Key File Does Not Exist\n";
        exit(1);
    }  

}


bool Utility::validMode(const char* mode) {

    if((strcmp(mode, "E") == 0) || (strcmp(mode, "D") == 0)) {
        return true;
    }

    else {
        cout << "Invalid Mode Type\n";
        exit(1);
    }

}

string Utility::xorUtilityEncrypt(string inputContents, string keyContents) {
   
    char input;
    char key;
    char xorChar;
    char padding = (char) (0x81);
    string xored;
    string result;
    string contents;
    int startInput = 0;
    int startKey = 0;
    int loopSize = inputContents.length() + 1;

    if(inputContents.length() < 16) {
       
        for(int idx = 0; idx <= (16 - loopSize); idx++) {
            inputContents += padding;
        }

    }

    if(inputContents.length() > 16) {

        for(int idx = 0; idx < inputContents.length(); idx++) {
            if((idx % 16 == 0) && (idx != 0)) {
                contents = xorMethod(xored, keyContents);
                result += swap(contents, keyContents);
                xored = "";
                xored += inputContents[idx];
            }
            else {
                if((inputContents.length() - idx) < 16) {
                    if(idx == (inputContents.length() - 1)) {
                        xored += inputContents[idx];
                        for(int index = 0; xored.length() < 16; index++) {
                            xored += padding;
                        } 
                        contents = xorMethod(xored, keyContents);
                        result += swap(contents, keyContents);    
                    }
                    else {
                        xored += inputContents[idx];
                    }             
                }
                else {
                    xored += inputContents[idx];
                }
            }
        }

    }

    else {
        contents = xorMethod(inputContents, keyContents);
        result = swap(contents, keyContents);
    }

    return result;
}

string Utility::xorUtilityDecrypt(string inputContents, string keyContents) {
   
    char input;
    char key;
    char xorChar;
    char padding = (char) (0x81);
    string xored;
    string result;
    string contents;
    int startInput = 0;
    int startKey = 0;

    if(inputContents.length() > 16) {

        for(int idx = 0; idx < inputContents.length(); idx++) {
            if((idx % 16 == 0) && (idx != 0)) {
                contents = swap(xored, keyContents);
                result += xorMethod(contents, keyContents);
                xored = "";
                xored += inputContents[idx];
            }
            else {
                if((inputContents.length() - idx) < 16) {
                    if(idx == (inputContents.length() - 1)) {
                        xored += inputContents[idx];
                        contents = swap(xored, keyContents);
                        result += xorMethod(contents, keyContents);    
                    }
                    else {
                        xored += inputContents[idx];
                    }             
                }
                else {
                    xored += inputContents[idx];
                }
            }
        }

    }

    else {
        contents = swap(inputContents, keyContents);
        result = xorMethod(contents, keyContents);
    }

    return result;
}

string Utility::swap(string xored, string keyContents) {

    char tempStart;
    int xoredStart = 0;
    int xoredEnd = xored.length() - 1;
    int index = 0;
    int converge = 1;
    int startKey = 0;

    for(int idx = 0; idx < xored.length(); idx++) {

        if(xoredStart >= xoredEnd) {
            break;
        }

        if(index % keyContents.length() == 0) {
            startKey = 0;
        }

        if(keyContents[startKey] % 2 == 1) {

            tempStart = xored[xoredStart];
            xored[xoredStart] = xored[xoredEnd];
            xored[xoredEnd] = tempStart;

            xoredEnd--;

        }

        xoredStart++;
        converge++;
        startKey++;
        index++;

    }

    return xored;

}

string Utility::xorMethod(string inputContents, string keyContents) {

    char input;
    char key;
    char xorChar;
    char padding = (char) (0x81);
    string xored;
    int startInput = 0;
    int startKey = 0;
    
    for(int idx = 0; idx < inputContents.length(); idx++) {

        if(idx % keyContents.length() == 0) {

            startKey = 0;   

        }

        input = inputContents[idx];
        key = keyContents[startKey];
        xorChar = input ^ key;

        xored += xorChar;

        startKey++;

        
    }

    return xored;

}

string Utility::xorUtilityStream(string inputContents, string keyContents) {
   
    char input;
    char key;
    char xorChar;
    char padding = (char) (0x81);
    string xored;
    int startInput = 0;
    int startKey = 0;

    for(int idx = 0; idx < inputContents.length(); idx++) {

        if(idx % keyContents.length() == 0) {

            startKey = 0;   

        }

        input = inputContents[idx];
        key = keyContents[startKey];
        xorChar = input ^ key;

        xored += xorChar;

        startKey++;

        
    }

    return xored;
}
