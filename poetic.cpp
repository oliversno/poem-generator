#include "poetic.h"
#include <unordered_map>
#include <cmath>
#include <algorithm>

std::vector<std::vector<int>> techniques(std::vector<int> line, Dictionary& dictionary){
    std::vector<std::vector<std::string>> line_syllables;
    std::vector<Stress> total_stress;
    for (int num : line){
        DictEntry& entry = dictionary.at(num);
        line_syllables.insert(line_syllables.end(), entry.get_phenomes().begin(), entry.get_phenomes().end());
        total_stress.insert(total_stress.end(), entry.get_stress().begin(), entry.get_stress().end());
    }
    std::vector<std::vector<int>> rhyme_matrix ( line_syllables.size(), std::vector<int> ( line_syllables.size(), 0 ) );
    for(int i = 0; i < line_syllables.size(); ++i){
        rhyme_matrix[i][i] = std::numeric_limits<int>::min();
    }
    for(int i = 0; i < line_syllables.size(); ++i){
        for(int j = i+1; j < line_syllables.size(); ++j){
            rhyme_matrix[i][j] = techniques(line_syllables[i], line_syllables[j], total_stress[i], total_stress[j]);
        }
    }
    return rhyme_matrix;
}

bool vowel_phenome_pred(std::string& str){
    return str == "IY" || str == "UW" || str == "AE" || str == "AA" ||
        str == "AO" || str == "EH" || str == "ER" || str == "IH" ||
        str == "UH" ||str == "AH" || str == "AY" || str == "AW" ||
        str == "EY" || str == "OW" || str == "OY";
}

std::vector<std::string>::iterator vowel(std::vector<std::string>& syllable){
    return std::find_if(syllable.begin(), syllable.end(), vowel_phenome_pred);
}

int similar_constanant_score(const std::string& c1, const std::string& c2, const char pos){
    if(c1 == c2)
        return 1;
    auto map_it = (pos == 'I') ? constanant_map_initial.find(std::make_pair(c1, c2)) : constanant_map_final.find(std::make_pair(c1, c2));
    if(map_it == constanant_map_initial.end() || map_it == constanant_map_final.end())
        return 0;
    return map_it->second;
}

double similar_constanant_score(std::vector<std::string> syllable1, std::vector<std::string> syllable2){
    auto it_vowel1 = vowel(syllable1);
    auto it_vowel2 = vowel(syllable2);
    double res = 0;
    for(auto it1 = syllable1.begin(); it1 != it_vowel1; it1++){
        for(auto it2 = syllable2.begin(); it2 != it_vowel2; it2++){
            res += similar_constanant_score(*it1, *it2, 'I')/800;
        }
    }
    for(auto it1 = ++it_vowel1; it1 != syllable1.end(); it1++){
        for(auto it2 = ++it_vowel2; it2 != syllable2.end(); it2++){
            res += similar_constanant_score(*it1, *it2, 'F')/800;
        }
    }
    return res;
}

double cord_dist(const std::pair<int,int>& c1, const std::pair<int,int>& c2){
    return std::sqrt((c1.first-c2.first)*(c1.first-c2.first)+(c1.second-c2.second)*(c1.second-c2.second));
}

double vowel_dist(const std::string& vowel1, const std::string& vowel2){
    static std::unordered_map<std::string, std::pair<int, int>> CORDMAP;
    CORDMAP["IY"] = std::make_pair(240, 2400);
    CORDMAP["UW"] = std::make_pair(250, 595);
    CORDMAP["AE"] = std::make_pair(900, 2000);
    CORDMAP["AA"] = std::make_pair(750, 940);
    CORDMAP["AO"] = std::make_pair(500, 700);
    CORDMAP["EH"] = std::make_pair(610, 1900);
    CORDMAP["ER"] = std::make_pair(450, 1600);
    CORDMAP["IH"] = std::make_pair(400, 2250);
    CORDMAP["UH"] = std::make_pair(475, 1250);
    CORDMAP["AH"] = std::make_pair(600, 1170);
    CORDMAP["A"] = std::make_pair(850, 1610);
    CORDMAP["E"] = std::make_pair(360, 2300);
    CORDMAP["O"] = std::make_pair(460, 1310);
    auto it1 = CORDMAP.find(vowel1);
    if(it1 == CORDMAP.end()){
        if(vowel1 == "AY")
            return std::min(vowel_dist("A", vowel2), vowel_dist("IH", vowel2));
        if(vowel1 == "AW")
            return std::min(vowel_dist("A", vowel2), vowel_dist("UH", vowel2));
        if(vowel1 == "EY")
            return std::min(vowel_dist("E", vowel2), vowel_dist("IH", vowel2));
        if(vowel1 == "OW")
            return std::min(vowel_dist("O", vowel2), vowel_dist("UH", vowel2));
        if(vowel1 == "OY")
            return std::min(vowel_dist("AH", vowel2), vowel_dist("IH", vowel2));
    }
    auto it2 = CORDMAP.find(vowel2);
    if(it2 == CORDMAP.end()){
        return vowel_dist(vowel2, vowel1);
    }
    return cord_dist(it1->second, it2->second);
}

int techniques(std::vector<std::string>& syllable1, std::vector<std::string>& syllable2, const Stress stress1, const Stress stress2){
    double vowel_sim = 1800 - vowel_dist(*vowel(syllable1), *vowel(syllable2));
    if(stress1 == Stress::PrimaryStress)
        vowel_sim *= 2;
    if(stress2 == Stress::PrimaryStress)
        vowel_sim *= 2;
    if(stress1 == Stress::Unstressed)
        vowel_sim *= 0.5;
    if(stress2 == Stress::Unstressed)
        vowel_sim *= 0.5;
    return vowel_sim + similar_constanant_score(syllable1, syllable2);
}