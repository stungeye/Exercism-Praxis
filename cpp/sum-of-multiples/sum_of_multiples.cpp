#include "sum_of_multiples.h"

#include <algorithm>
#include <numeric>

// Refactor with:
// https://exercism.io/tracks/cpp/exercises/sum-of-multiples/solutions/de81544b49814f509c330baa14cf885d
// https://exercism.io/tracks/cpp/exercises/sum-of-multiples/solutions/149f41a09da94a4dbe9aab73ece99c9e
// https://exercism.io/tracks/cpp/exercises/sum-of-multiples/solutions/818d2a014dfa41389a8b9b53bbcb54cf
// https://exercism.io/tracks/cpp/exercises/sum-of-multiples/solutions/b84fd51b07ae4b8f84fbbf5c26a932d2

namespace sum_of_multiples {

	int to(const std::vector<int>& factors, int exclusive_upper_bound) {
		if ((exclusive_upper_bound == 0) || factors.empty()) {
			return 0;
		}

		std::vector<int> multiples(static_cast<size_t>(exclusive_upper_bound) - 1);

		std::iota(multiples.begin(), multiples.end(), 1);

		const auto new_past_end = std::remove_if(multiples.begin(),
		                                         multiples.end(),
		                                         [factors](auto num) {
			                                         for (auto factor : factors) {
				                                         if (num % factor == 0) {
					                                         return false;
				                                         }
			                                         }
			                                         return true;
		                                         });

		multiples.erase(new_past_end, multiples.end());

		return std::accumulate(multiples.begin(), multiples.end(), 0);
	}
} // namespace sum_of_multiples
