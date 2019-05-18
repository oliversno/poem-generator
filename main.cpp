#include "rhyme.h"

int main(){
    Metaphone m{"feign"};
    std::string res = m.encode();
    return 0;
}