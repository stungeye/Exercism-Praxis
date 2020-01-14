#include "sum_of_multiples.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

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
