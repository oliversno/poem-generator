#include "dictionary.h"
#include "poetic.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// std::vector<std::string> colorCodes{"31", "32", "33", "34", "35", "36", "91", "92", "93", "94", "95", "96"};
// std::map<char, std::string> color_mapping;

// std::string mod_code(char c){
//     color_mapping.insert(std::pair<char, std::string>{' ', "37"});
//     auto it = color_mapping.find(c);
//     if(it != color_mapping.end())
//         return it->second;
//     std::pair<char, std::string> p;
//     p.first = c;
//     p.second = colorCodes.back();
//     colorCodes.pop_back();
//     color_mapping.insert(p);
//     return p.second;
// }

// int main(){
//     std::cout << "Please input words\n";
//     std::vector<std::string> inputs;
//     std::string input;
//     while(std::cin >> input){
//         if(input == "0")
//             break;
//         inputs.push_back(input);
//     }
//     std::vector<char> codes;
//     codes.reserve(2*inputs.size());
//     for(std::string word : inputs){
//         for(char c : Metaphone{word}.encode()){
//             codes.push_back(c);
//         }
//         codes.push_back(' ');
//     }
//     for(char c : codes){
//         std::cout << "\033[" << mod_code(c) << "m" << c;;
//     }
//     std::cout << '\n';
//     return 0;
// }

const std::string kFILENAME = "/mnt/c/Users/Sean/Documents/Personal Projects/poem generator/cmudict.rep";

int main(){
    std::fstream fs{kFILENAME};
    if(!fs.is_open()){
        std::cout << "File Open Failed\n";
        return 1;
    }
    Dictionary dict{fs};
    std::string input;
    std::vector<std::string> inputs{"forgotten", "spot", "in", "the", "caribbean"};
    std::for_each(inputs.begin(), inputs.end(), [](std::string& s){std::transform(s.begin(), s.end(), s.begin(), ::toupper);});
    // while(std::cin >> input){
    //      if(input == "0")
    //          break;
    //      inputs.push_back(input);
    //  }
     std::vector<int> poem;
     poem.reserve(inputs.size());
     std::transform(inputs.begin(), inputs.end(), std::back_inserter(poem), [&dict](std::string& s){return dict.lookup(s);});
     techniques(poem, dict);
}