#include "Dictionary.h"
#include <fstream>
#include <iostream>

void Dictionary::load(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Błąd: Nie można otworzyć pliku słownika: " << filename << std::endl;
        return;
    }

    std::string word;
    while (file >> word) {
        words.insert(word);
    }
    file.close();
}

bool Dictionary::isValidWord(const std::string& word) const {
    return words.count(word) > 0;
}

void Dictionary::addWord(const std::string& word) {
    words.insert(word);
}