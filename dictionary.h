#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "entry.h"
#include <fstream>
#include <unordered_map>

const int kMAXLINELENGTH = 256;

class Dictionary{
    public:
    // ctor
    Dictionary(std::fstream& fs);
    // copy ctor
    Dictionary(const Dictionary&);
    // don't assign
    Dictionary& operator=(const Dictionary&) = delete;
    Dictionary& operator=(Dictionary&&) = delete;
    // dtor
 //   ~Dictionary();

    int lookup(std::string& query);
    
    DictEntry& at(int num);

    private:
        std::vector<DictEntry> dict;
        std::unordered_multimap<std::string, int> index;
};

#endif //DICTIONARY_H