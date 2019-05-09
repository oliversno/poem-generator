#include "rhyme.h"
#include<string>

bool Metaphone::equalExcludingCPred(char a, char b){
  if(a == 'C')
        return false;
    return (a == b);
}

char Metaphone::peek() {
    return peek(0);
}

char Metaphone::peek(int offset){
    int newpos = pos + offset;
    if(newpos < 0 || newpos >= word.length())
        return '\0';
    return word[newpos];
}

void Metaphone::moveAhead(){
    moveAhead(1);
}

void Metaphone::moveAhead(int offset){
    pos = std::min(pos + offset, (int)word.length());
}

bool MetaphoneEqualToAny(char test, std::string chars){
    return chars.find(test) != std::string::npos;
}

bool Metaphone::isVowel(char test){
    return EqualToAny(test, "AEIOU");
}

std::string Metaphone::encode(){
    if(word.empty())
            return;
        
        std::string encoded;
        encoded.reserve(word.length());
        switch(peek()){ // ignore silent letters at the begining
            case 'P':
            case 'G':
            case 'K':
                if(peek(1) == 'N')
                    moveAhead();
                break;
            case 'A':
                if(peek(1) == 'E')
                    moveAhead();
                break;
            case 'W':
                if(peek(1) == 'R')
                    moveAhead();
                else if(peek(1) == 'H'){
                    encoded.push_back('W'); // begining WH makes 'W' sound
                    moveAhead(2);
                }
                break;
            case 'X':
                encoded.push_back('S'); // begining X makes 'S' sound
                moveAhead();
                break;

        } // switch

        while(peek() != '\0'){
            char current = peek(); // for cache optimization

            if(EqualToAny(current, "FJLMNR") || encoded.empty() && isVowel(c)){
                encoded.push_back(c); // F,J,L,M,N,R and beining vowels always make their own sounds
                moveAhead();
            }
            else{
                int chars_consumed = 1;
                switch(current){
                    case 'B':
                        if(peek(-1) != 'M' || peek(1) != '\0')
                            encoded.push_back('B'); // dont add -MB
                        break;
                    case 'C':
                        if(peek(-1) != 'S' || !EqualToAny(peek(1), "EIY")){
                            if(peek(1) == 'I' && peek(2) == 'A'){
                                encoded.push_back('X'); // CIA makes 'X' sound
                            }
                            else if(EqualToAny(peek(1), "EIY")){
                                encoded.push_back('S'); // CE, CI, CY make 'S' sound
                            }
                            else if(peek(1) == 'H'){
                                if((pos == 0 && !isVowel(peek(2))) || peek(-1) == 'S'){
                                    encoded.push_back('K'); // begining CH makes 'K' sound unless followed by vowel
                                                            // SCH always makes 'K' sound
                                }
                                else{
                                    encoded.push_back('X'); // CH makes 'X' sound
                                }
                                ++chars_consumed; // CH is one sound
                            }
                            else{
                                encoded.push_back('K'); // other configurations the C makes a 'K' sound
                            }
                        }
                        break;
                    case 'D':
                       if(peek(1) == 'G' && EqualToAny(peek(2), "EIY")){
                           encoded.push_back('J'); // DGE,DGI,DGY make 'J' sound
                       }
                       else{
                           encoded.push_back('T'); // otherwise D makes 'T' sound
                       }
                       break;
                    case 'G':
                        if ((peek(1) != 'H' || isVowel(peek(2))) &&
                            (peek(1) != 'N' || (peek(1) != '\0' &&
                            (peek(2) != 'E' || peek(3) != 'D'))) &&
                            (peek(-1) != 'D' || !EqualToAny(peek(1), "EIY"))){
                                if (EqualToAny(peek(1), "EIY") && peek(2) != 'G'){
                                    encoded.push_back('J'); //GE,GI,GY makes 'J' sound
                                }
                                else {
                                    encoded.push_back('K'); // otherwise G makes 'K' sound
                                }
                        }
                        if(peek(1) == 'H')
                            ++chars_consumed;
                        break;
                    case 'H':
                        if (!isVowel(peek(-1)) || isVowel(peek(1)))
                            encoded.push_back('H'); // H is silent if used before or after vowel
                        break;
                    case 'K':
                        if (peek(-1) != 'C')
                            encoded.push_back('K'); // CK doesn't make 'K' sound
                        break;
                    case 'P':
                        if (peek(1) == 'H'){
                            encoded.push_back('F'); // PH makes 'F' sound
                            ++chars_consumed;
                        }
                        else{
                            encoded.push_back('P');
                        }
                        break;
                    case 'Q':
                        encoded.push_back('K');
                        break;
                    case 'S':
                        if (peek(1) == 'H')
                        {
                            encoded.push_back('X'); // SH makes 'X' sound
                            ++chars_consumed;
                        }
                        else if (peek(1) == 'I' && EqualToAny(peek(2), "AO")){
                            encoded.push_back('X'); // SIO and SIA make 'X' sound
                        }
                        else{
                            encoded.push_back('S');
                        }
                        break;
                    case 'T':
                        if (peek(1) == 'I' && EqualToAny(peek(2), "AO"))
                            encoded.push_back('X'); // TIA and TIO make 'X' sound
                        else if (peek(1) == 'H')
                        {
                            encoded.push_back('0'); // TH is 0
                            ++chars_consumed;
                        }
                        else if (peek(1) != 'C' || peek(2) != 'H')
                            encoded.push_back('T');
                        break;
                    case 'V':
                        encoded.push_back('F');
                        break;
                    
                    case 'W':
                    case 'Y':
                        if (isVowel(peek(1)))
                            encoded.push_back(c); // W and Y make their own sound unless followed by a vowel
                        break;
                     case 'X':
                        encoded.push_back('K');
                        encoded.push_back('S');
                        break;
                     case 'Z':
                        encoded.push_back('S');
                        break;
                }// switch
                moveAhead(chars_consumed);
            } // else
        }// while
        return encoded;
}