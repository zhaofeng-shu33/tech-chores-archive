#define NUM 5
#ifndef WORDLIST_H
#define WORDLIST_H
#include <QString>
struct Word{
    QString hiragana;
    QString katakana;
    QString address;

};

class WordList
{
public:
    WordList();
    Word word[NUM];
};

#endif // WORDLIST_H
