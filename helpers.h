#ifndef NEU_HELPERS_H
#define NEU_HELPERS_H

#include <vector>
#include <string>

#include "lib/json/json.hpp"

using namespace std;
using json = nlohmann::json;

namespace helpers {
    vector<string> split(const string &s, char delim);
    string generateToken();
    void urldecode(char *dst, const char *src);
    char* cStrCopy(string str);
    json makeErrorPayload(string code, string message);
} // namespace helpers

#endif // #define NEU_HELPERS_H

