#include "entry.h"
#include <algorithm>
#include <ctype.h>

DictEntry::DictEntry(std::string _word, std::stringstream _entry){
    // remove any non alphabet chars
    word = std::string{ _word.begin(), std::remove_if(_word.begin(), _word.end(), [](char c){ return !isalpha(c); }) };
    std::string input;
    while(_entry >> input){
        if(input != "-") {
            char back = input.back();
            if(back == '0'){
                stress.push_back(Stress::Unstressed);
                input.pop_back();
            }
            else if(back == '1'){
                stress.push_back(Stress::PrimaryStress);
                input.pop_back();
            }
            else if(back == '2'){
                stress.push_back(Stress::SecondaryStress);
                input.pop_back();
            }
            phenomes.push_back(input);
        }
    }
    num_syllables = stress.size();
}