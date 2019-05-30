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
            index.insert(std::pair<std::string, int>{input, dict.size()-1});
        }
    }
}

class notInDictionaryException{};

int Dictionary::lookup(std::string& query){
    std::unordered_map<std::string,int>::const_iterator it = index.find(query);
    if(it != index.end()){
        return it->second;
    }
    throw notInDictionaryException();
}

DictEntry& Dictionary::at(int num){
    return dict[num];
}