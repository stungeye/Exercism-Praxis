#include "pangram.h"

#include <algorithm>
#include <iostream>

namespace pangram {
	bool is_pangram(std::string_view sentence) {
		std::string lower_case_sentence;

		// Convert sentence to all lower case letters.
		std::transform(sentence.begin(), sentence.end(),
		               std::back_inserter(lower_case_sentence), std::tolower);

		// Are all of the letters in the alphabet contained in the lower case sentence?
		return std::all_of(alphabet.begin(), alphabet.end(),
		                   [lower_case_sentence](char letter) {
			                   return lower_case_sentence.find(letter) != std::string::npos;
		                   });
	}
} // namespace pangram
