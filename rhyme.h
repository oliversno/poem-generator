#ifndef RHYME_H
#define RHYME_H

#include<string>
#include<algorithm>

// Metaphone codes are 0,B,F,H,J,K,L,M,N,P,R,S,T,W,X,Y where 0 is 'th' X is 'sh'/'ch'

class Metaphone {
private:

    std::string word;
    int pos;

    bool equalExcludingCPred(char a, char b);

    char peek();

    char peek(int offset);

    void moveAhead();

    void moveAhead(int offset);

    bool EqualToAny(char test, std::string chars);

    bool isVowel(char test);

public:
    Metaphone(std::string _word) {
        std::transform(_word.begin(), _word.end(), _word.begin(), ::toupper);
        std::unique(_word.begin(), _word.end(), equalExcludingCPred); // remove duplicate letters except for c
        word = _word;
        pos = 0;
    }

    std::string encode();
};

#endif //RHYME_H