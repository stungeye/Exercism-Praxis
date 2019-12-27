#include "pangram.h"

#include <bitset>

namespace pangram {
    // ASCII table positions for Roman letters.
    inline const char ascii_a = 97;
    inline const char ascii_z = 122;
    inline const char ascii_A = 65;
    inline const char ascii_Z = 90;

    inline const int letters_in_alphabet = 26;

    // Track presence of case-insensitive Roman letters
    // in a sentence using a bitset.
    bool is_pangram(std::string_view sentence) {
        std::bitset<letters_in_alphabet> letters_seen;

        // Letters tracked by their ASCII table position.
        // i.e. letters_seen[0] represents both 'A' and 'a'.
        for (auto c : sentence) {
            if ((c >= ascii_A) && (c <= ascii_Z )) {
                letters_seen.set(c - ascii_A);
            }

            if ((c >= ascii_a) && (c <= ascii_z)) {
                letters_seen.set(c - ascii_a);
            }
        }

        // Have all the Roman letters been seen? 
        return letters_seen.all();
    }
} // namespace pangram
