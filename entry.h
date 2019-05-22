#include <vector>
#include <string>
#include <unordered_set>

enum class Stress { Unstressed, PrimaryStress, SecondaryStress };

class DictEntry{
public:

private:
    std::string word;
    std::unordered_set<DictEntry> rhymes_with;
    int num_syllables;
    std::vector<Stress> stress;
    std::vector<std::string> syllables;
};