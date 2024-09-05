#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int countWordOccurrences(const char* text, const char* word) {
    int count = 0;
    const char* temp = text;
    size_t wordLen = strlen(word);
    while ((temp = strstr(temp, word)) != nullptr) {
        if ((temp == text || isspace(*(temp - 1)) || ispunct(*(temp - 1))) &&
            (temp[wordLen] == '\0' || isspace(temp[wordLen]) || ispunct(temp[wordLen]))) {
            ++count;
        }
        temp += wordLen;
    }
    return count;
}

int countSentences(const char* text) {
    int count = 0;
    while (*text) {
        if (*text == '.' || *text == '!' || *text == '?') {
            ++count;
        }
        ++text;
    }
    return count;
}

void countPunctuation(const char* text, int& dotCount, int& commaCount) {
    dotCount = 0;
    commaCount = 0;
    while (*text) {
        if (*text == '.') {
            ++dotCount;
        }
        else if (*text == ',') {
            ++commaCount;
        }
        ++text;
    }
}

void reverseText(char* text) {
    size_t len = strlen(text);
    for (size_t i = 0; i < len / 2; ++i) {
        swap(text[i], text[len - 1 - i]);
    }
}

void reverseSentences(char* text) {
    char* start = text;
    char* end = nullptr;
    while (*start) {
        end = start;
        while (*end && *end != '.' && *end != '!' && *end != '?') {
            ++end;
        }
        if (*end) {
            ++end; 
        }
        size_t len = end - start;
        for (size_t i = 0; i < len / 2; ++i) {
            swap(start[i], start[len - 1 - i]);
        }
        start = end;
    }
}

int main() {
    char text[1000];
    cout << "Enter the text (max 1000 characters): " << endl;
    cin.getline(text, 1000);

    char word[100];
    cout << "Enter the word to search for: " << endl;
    cin.getline(word, 100);

    int wordCount = countWordOccurrences(text, word);
    cout << "The word \"" << word << "\" occurs " << wordCount << " times." << endl;

    int sentenceCount = countSentences(text);
    cout << "Number of sentences: " << sentenceCount << endl;

    int dotCount, commaCount;
    countPunctuation(text, dotCount, commaCount);
    cout << "Number of dots: " << dotCount << endl;
    cout << "Number of commas: " << commaCount << endl;

    reverseText(text);
    cout << "Reversed text: " << text << endl;

    reverseSentences(text);
    cout << "Text with reversed sentences: " << text << endl;

    return 0;
}
