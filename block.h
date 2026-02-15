#ifndef BLOCK_H
#define BLOCK_H

#include <string>

using namespace std;

class BlockCipher {

    public:

        BlockCipher();
        string encrypt(string inputContents, string keyContents);
        string decrypt(string inputContents, string keyContents);
        string inputContents(const char* input);
        string keyContents(const char* key);
        void outputContents(string contents, const char* path);

};

#endif // BLOCK_H