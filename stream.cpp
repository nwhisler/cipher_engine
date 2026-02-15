#include <iostream>
#include "stream.h"
#include "utility.h"
#include <cstring>
#include <fstream>

using namespace std;

StreamCipher::StreamCipher() {


}

string StreamCipher::inputContents(const char* input) {
    Utility utility;
    return utility.readInput(input);
}

string StreamCipher::keyContents(const char* key) {
    Utility utility;
    return utility.readInput(key);
}

string StreamCipher::encrypt(string inputContents, string keyContents) {

    Utility utility;

    string xored = utility.xorUtilityStream(inputContents, keyContents);

    return xored;

}

void StreamCipher::outputContents(string contents, const char* path) {

    fstream f;

    f.open(path);
    f << contents;
    f.close();

}