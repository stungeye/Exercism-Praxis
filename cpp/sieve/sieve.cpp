#include "sieve.h"

#include <algorithm>
#include <cmath>

namespace sieve {

	constexpr int smallestPrime{2};

	std::vector<int> sequence(int startingValue, int endingValue) {
		std::vector<int> v(endingValue - startingValue + 1);
		std::generate(v.begin(), v.end(),
		              [n = startingValue]() mutable { return n++; });
		return v;
	}

	bool includes(std::vector<int> haystack, int needle) {
		const auto it{std::find(haystack.begin(), haystack.end(), needle)};
		return it != haystack.end();
	}

	std::vector<int> primes(int limit) {
		if (limit < smallestPrime) return {};

		const auto testRange{sequence(smallestPrime, static_cast<int>(std::sqrt(limit)))};
		auto potentialPrimes{sequence(smallestPrime, limit)};

		for (auto prime : testRange) {
			if (!includes(potentialPrimes, prime)) continue;

			potentialPrimes.erase(std::remove_if(potentialPrimes.begin(),
			                                     potentialPrimes.end(),
			                                     [prime](auto num) {
				                                     return prime != num && num % prime == 0;
			                                     }),
			                      potentialPrimes.end());
		}

		return potentialPrimes;
	}


} // namespace sieve
