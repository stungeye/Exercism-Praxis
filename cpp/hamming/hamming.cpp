#include "hamming.h"

namespace hamming {
	int compute(const string& strand1, const string& strand2) {
		if (strand1.length() != strand2.length()) {
			throw domain_error("Strand lengths do not match.");
		}

		vector<bool> matches;

		transform(strand1.begin(), strand1.end(),
		          strand2.begin(),
		          std::back_inserter(matches),
		          [](char c1, char c2) { return c1 == c2; });

		return count(matches.begin(), matches.end(), false);
	}
} // namespace hamming
