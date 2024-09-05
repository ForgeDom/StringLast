#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void replaceWord(char* text, const char* oldWord, const char* newWord) {
    char buffer[10000];
    char* pos;
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    buffer[0] = '\0';

    while ((pos = strstr(text, oldWord)) != nullptr) {
        strncat(buffer, text, pos - text); 
        strcat(buffer, newWord);       
        text = pos + oldWordLen;            
    }
    strcat(buffer, text); 
    strcpy(text, buffer); 
}

void capitalizeSentences(char* text) {
    bool newSentence = true;
    while (*text) {
        if (newSentence && isalpha(*text)) {
            *text = toupper(*text);
            newSentence = false;
        }
        if (*text == '.' || *text == '!' || *text == '?') {
            newSentence = true;
        }
        ++text;
    }
}

void countLetters(const char* text) {
    int letterCount[26] = { 0 }; 
    while (*text) {
        if (isalpha(*text)) {
            char c = tolower(*text); 
            letterCount[c - 'a']++;
        }
        ++text;
    }

    cout << "Letter counts:" << endl;
    for (int i = 0; i < 26; ++i) {
        if (letterCount[i] > 0) {
            cout << char('a' + i) << ": " << letterCount[i] << endl;
        }
    }
}

int countDigits(const char* text) {
    int digitCount = 0;
    while (*text) {
        if (isdigit(*text)) {
            ++digitCount;
        }
        ++text;
    }
    return digitCount;
}

int main() {
    char text[1000];
    cout << "Enter the text (max 1000 characters): " << endl;
    cin.getline(text, 1000);

    char oldWord[100];
    char newWord[100];
    cout << "Enter the word to replace: " << endl;
    cin.getline(oldWord, 100);
    cout << "Enter the new word: " << endl;
    cin.getline(newWord, 100);

    replaceWord(text, oldWord, newWord);
    cout << "Text after replacement: " << endl << text << endl;

    capitalizeSentences(text);
    cout << "Text after capitalizing sentences: " << endl << text << endl;

    countLetters(text);

    int digitCount = countDigits(text);
    cout << "Number of digits: " << digitCount << endl;

    return 0;
}
