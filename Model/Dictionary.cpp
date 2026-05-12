#include "Dictionary.h"
#include <fstream>
#include <iostream>

// Метод для загрузки слов из текстового файла
void Dictionary::load(const std::string& filename) {
    std::ifstream file(filename); // Otwieramy plik do odczytu
    if (!file.is_open()) {
        std::cerr << "Błąd: Nie można otworzyć pliku słownika: " << filename << std::endl;
        return;
    }

    std::string word;
    while (file >> word) {
        // Желательно переводить все слова в верхний регистр (uppercase) для единообразия,
        // но для простоты предположим, что файл уже содержит слова в нужном формате.
        words.insert(word); // Dodajemy słowo do hash tabeli (unordered_set)
    }
    file.close();
}

// Проверка, существует ли слово в базе
bool Dictionary::isValidWord(const std::string& word) const {
    // Metoda count() w unordered_set zwraca 1, jeśli element istnieje, i 0, jeśli nie.
    return words.count(word) > 0;
}

// "House rule": добавление нового слова в процессе игры
void Dictionary::addWord(const std::string& word) {
    words.insert(word);
}