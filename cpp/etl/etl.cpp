#include "etl.h"

#include <cctype>

namespace etl {

    std::map<char, int> transform(const std::map<int, std::vector<char>>& old_points) {
        std::map<char, int> output;
        
        for (const auto& value_to_letters : old_points) {
            const auto value = value_to_letters.first;
            const auto letters = value_to_letters.second;

            for (auto letter : letters) {
                output[std::tolower(letter)] = value;
            }
        }

        return output;
    }
} // namespace etl
