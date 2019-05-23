#include "entry.h"
#include <fstream>

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

    private:
        std::vector<DictEntry> dict;
};