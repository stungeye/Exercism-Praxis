#include "pangram.h"

#include <algorithm>
#include <cctype>

#include <set>


namespace pangram {
    inline const int letters_in_alphabet = 26;

    bool is_pangram(std::string sentence) {
        std::transform(sentence.begin(), sentence.end(), sentence.begin(),
                       [](char letter) { return std::tolower(letter); });

        std::set<char> characters(sentence.begin(), sentence.end());
        
        return std::count_if(characters.begin(), characters.end(), [](char letter) {
            return isalpha(letter);
        }) == letters_in_alphabet;
    }
} // namespace pangram
