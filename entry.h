#ifndef ENTRY_H
#define ENTRY_H

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
int num_syllables() const;
int num_pheonomes() const;
const std::vector<std::vector<std::string>>& get_phenomes() const;
const std::vector<Stress>& get_stress() const;
private:
    std::string word;
    //std::unordered_set<DictEntry> rhymes_with;
    std::vector<Stress> stress;
    std::vector<std::vector<std::string>> phenomes;
};

#endif // ENTRY_H