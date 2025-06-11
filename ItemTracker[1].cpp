// ItemTracker.cpp
#include "ItemTracker.h"
#include <fstream>     // file streams
#include <iostream>    // error messages / prints
#include <iomanip>     // setw
#include <algorithm>   // std::transform
#include <cctype>      // std::tolower


/* load all words from file – every token separated by whitespace counts */
bool ItemTracker::LoadFile(const std::string& inFile) {
    std::ifstream fin(inFile);
    if (!fin) { std::cerr << "Cannot open " << inFile << '\n'; return false; }

    auto toLower = [](std::string& s) {                 // <- helper
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char ch) { return std::tolower(ch); });
        };

    std::string word;
    while (fin >> word) {
        toLower(word);                                 // force lower-case
        ++counts[word];
    }
    return true;
}


/* write “word count” pairs to outFile – one per line */
bool ItemTracker::WriteBackup(const std::string& outFile) const {
    std::ofstream fout(outFile);
    if (!fout) {
        std::cerr << "Cannot write " << outFile << '\n';
        return false;
    }
    for (const auto& kv : counts)
        fout << kv.first << ' ' << kv.second << '\n';
    return true;
}

int ItemTracker::GetCount(const std::string& item) const {
    std::string key = item;                            // make a local copy
    std::transform(key.begin(), key.end(), key.begin(),
        [](unsigned char ch) { return std::tolower(ch); });

    auto it = counts.find(key);
    return (it == counts.end()) ? 0 : it->second;
}


void ItemTracker::PrintAll() const {
    std::cout << std::left;
    for (const auto& kv : counts)
        std::cout << std::setw(15) << kv.first << ' ' << kv.second << '\n';
}

void ItemTracker::PrintHistogram() const {
    for (const auto& kv : counts) {
        std::cout << std::setw(15) << kv.first << ' '
            << std::string(kv.second, '*') << '\n';
    }
}
