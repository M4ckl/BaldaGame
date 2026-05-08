#ifndef BALDAGAME_DICTIONARY_H
#define BALDAGAME_DICTIONARY_H

#include <string>
#include <unordered_set>


class Dictionary {
private:
    std::unordered_set<std::string> words;

public:
    void load(const std::string& filename);
    bool isValidWord(const std::string& word) const;
    void addWord(const std::string& word);
};

#endif