#ifndef NEU_FILESYSTEM_H
#define NEU_FILESYSTEM_H

#include <string>
#include <vector>

#include "lib/json/json.hpp"

using json = nlohmann::json;
using namespace std;

namespace fs {

struct FileReaderResult {
    bool hasError = false;
    string error;
    string data;
};

struct FileReaderOptions {
    long long pos = -1;
    long long size = -1;
};

struct FileWriterOptions {
    string filename;
    string data;
    bool append = false;
};

enum EntryType { EntryTypeFile, EntryTypeDir, EntryTypeOther };

struct FileStats {
    bool hasError = false;
    string error;
    long long size;
    EntryType entryType = fs::EntryTypeOther;
    long long createdAt;
    long long modifiedAt;
};

struct DirReaderEntry {
    string name;
    EntryType type = fs::EntryTypeOther;
};

struct DirReaderResult {
    bool hasError = false;
    vector<DirReaderEntry> entries;
};

bool createDirectory(const string &path);
bool removeFile(const string &filename);
fs::FileReaderResult readFile(const string &filename, const fs::FileReaderOptions &fileReaderOptions = {});
bool writeFile(const fs::FileWriterOptions &fileWriterOptions);
string getDirectoryName(const string &filename);
string getCurrentDirectory();
string getFullPathFromRelative(const string &path);
fs::FileStats getStats(const string &path);
fs::DirReaderResult readDirectory(const string &path);

namespace controllers {

json createDirectory(const json &input);
json removeDirectory(const json &input);
json writeFile(const json &input);
json writeBinaryFile(const json &input);
json appendFile(const json &input);
json appendBinaryFile(const json &input);
json readFile(const json &input);
json readBinaryFile(const json &input);
json removeFile(const json &input);
json readDirectory(const json &input);
json copyFile(const json &input);
json moveFile(const json &input);
json getStats(const json &input);

} // namespace controllers

} // namespace fs

#endif // #define NEU_FILESYSTEM_H
