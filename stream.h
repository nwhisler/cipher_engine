#ifndef STREAM_H
#define STREAM_H

#include <string>

using namespace std;

class StreamCipher {

    public:

        StreamCipher();
        string encrypt(string inputContents, string keyContents);
        string inputContents(const char* input);
        string keyContents(const char* key);
        void outputContents(string contents, const char* path);

};

#endif // STREAM_H