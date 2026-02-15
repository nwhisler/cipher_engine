#include <iostream>
#include "block.h"
#include "utility.h"
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

BlockCipher::BlockCipher() {


}

string BlockCipher::inputContents(const char* input) {
    Utility utility;
    return utility.readInput(input);
}

string BlockCipher::keyContents(const char* key) {
    Utility utility;
    return utility.readInput(key);
}

string BlockCipher::encrypt(string inputContents, string keyContents) {

    Utility utility;
    string result;
    string decrypt;

    result = utility.xorUtilityEncrypt(inputContents, keyContents);
    decrypt = utility.xorUtilityDecrypt(result, keyContents);

    return result;

}

string BlockCipher::decrypt(string xored, string keyContents) {

    Utility utility;
    string result;

    string decrypted = utility.xorUtilityDecrypt(xored, keyContents);

    for(int idx = 0; idx < decrypted.length(); idx++) {
        int range = (int) decrypted[idx];
        if((range >= 0) && (range <= 127)) {
            result += decrypted[idx];
        }
    }

    return result;

}

void BlockCipher::outputContents(string contents, const char* path) {

    fstream f;

    f.open(path);
    f << contents;
    f.close();

}



