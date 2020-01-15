#include "scrabble_score.h"

#include <map>
#include <cctype>

namespace scrabble_score {
	const std::map<char, int> letter_scores{
		{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}, {'l', 1}, {'n', 1}, {'r', 1}, {'s', 1}, {'t', 1}, {'d', 2},
		{'g', 2}, {'b', 3}, {'c', 3}, {'m', 3}, {'p', 3}, {'f', 4}, {'h', 4}, {'v', 4}, {'w', 4}, {'y', 4}, {'k', 5},
		{'j', 8}, {'x', 8}, {'q', 10}, {'z', 10}
	};

	int score(std::string_view word) {
		int score = 0;

		for (auto letter : word) {
			score += letter_scores.at(std::tolower(letter));
		}

		return score;
	}
} // namespace scrabble_score
