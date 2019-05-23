#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

enum class Stress { Unstressed, PrimaryStress, SecondaryStress };

class DictEntry{
public:
    // ctor
    DictEntry(std::string& _word, std::stringstream& _entry);
    // copy ctor
//    DictEntry(const DictEntry&);
    // don't assign
//    DictEntry& operator=(const DictEntry&) = delete;
//    DictEntry& operator=(DictEntry&&) = delete;
    // dtor
//    ~DictEntry();
private:
    std::string word;
    //std::unordered_set<DictEntry> rhymes_with;
    int num_syllables;
    std::vector<Stress> stress;
    std::vector<std::string> phenomes;
};