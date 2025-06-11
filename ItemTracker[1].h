// ItemTracker.h
// Simple class that counts how many times each word appears
#ifndef ITEM_TRACKER_H        // include-guard start
#define ITEM_TRACKER_H

#include <unordered_map>
#include <string>

class ItemTracker {
public:
    bool LoadFile(const std::string& inFile);          // read & count words
    bool WriteBackup(const std::string& outFile) const;// dump counts to file
    int  GetCount(const std::string& item) const;      // look-up one word
    void PrintAll() const;                             // list “word  N”
    void PrintHistogram() const;

private:
    std::unordered_map<std::string, int> counts;        // word -> frequency
};

#endif  // ITEM_TRACKER_H     // include-guard end
