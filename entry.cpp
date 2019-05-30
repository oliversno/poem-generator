#include "entry.h"
#include <algorithm>
#include <ctype.h>

DictEntry::DictEntry(std::string& _word, std::stringstream& _entry){
    // remove any non alphabet chars
    word = _word;
    phenomes.push_back(std::vector<std::string>{});
    std::string input;
    while(_entry >> input){
        if(input == "-") {
            phenomes.push_back(std::vector<std::string>{});
        }
        else{
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
            phenomes.back().push_back(input);
        }
    }
}

int DictEntry::num_syllables() const{
    return (int)phenomes.size();
}

int DictEntry::num_pheonomes() const{
    int res = 0;
    for(auto syllable : phenomes){
        res += syllable.size();
    }
}

const std::vector<std::vector<std::string>>& DictEntry::get_phenomes() const{
    return phenomes;
}

const std::vector<Stress>& DictEntry::get_stress() const{
    return stress;
}