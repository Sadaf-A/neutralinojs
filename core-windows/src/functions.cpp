// MIT License

// Copyright (c) 2018 Neutralinojs

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include <random>

using namespace std;
namespace functions {

    vector<string> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> tokens;
        while (getline(ss, item, delim)) {
            tokens.push_back(item);
        }
        return tokens;
    }

    string generateToken(int len = 32) {
        srand (time(NULL));
        
        string s = "";
        static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < len; ++i) {
            s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        return s;
    }

    string decodeUrl(string &encoded) {
        string decoded;
        char c;
        int i, j;

        for (i = 0; i < encoded.length(); ++i) {
            if (int(encoded[i]) == 37) {
                sscanf(encoded.substr(i + 1, 2).c_str(), "%x", &j);
                c = static_cast<char>(j);
                decoded += c;
                i += 2;
            } else {
                decoded += encoded[i];
            }
        }

        return decoded;
    }

}