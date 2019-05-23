#include "dictionary.h"

Dictionary::Dictionary(std::fstream& fs){
    std::string input;
    while(fs >> input){
        if(input == "##"){
            fs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else{
            char c[kMAXLINELENGTH];
            fs.getline(c, kMAXLINELENGTH, '\n');
            std::stringstream ss{c};
            dict.push_back(DictEntry{input, ss});
        }
    }
}