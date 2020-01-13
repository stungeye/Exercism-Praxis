#include "isogram.h"

#include <bitset>

namespace isogram {
    inline const int letters_in_alphabet = 26;

    bool is_isogram(const std::string word) {
        std::bitset<letters_in_alphabet> letters_seen;

        for (auto c : word) {
            const auto position = tolower(c) - 'a';

            if ((position < 0) || (position >= letters_in_alphabet)) {
                continue;
            }

            if (letters_seen[position]) {
                return false;
            } else {
                letters_seen.set(position);
            }
        }

        return true;
    }
}  // namespace isogram
