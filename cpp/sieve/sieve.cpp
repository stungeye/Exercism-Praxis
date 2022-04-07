#include "sieve.h"

#include <algorithm>
#include <cmath>

namespace sieve {

	constexpr int smallestPrime{2};

	std::vector<int> sequence(int startingValue, const int endingValue) {
		std::vector<int> v(endingValue - startingValue + 1);
		std::ranges::generate(v, [n = startingValue]() mutable { return n++; });
		return v;
	}

	bool includes(std::vector<int> haystack, const int needle) {
		const auto it{std::ranges::find(haystack, needle)};
		return it != haystack.end();
	}

	std::vector<int> primes(const int limit) {
		if (limit < smallestPrime) return {};

		const auto testRange{sequence(smallestPrime, static_cast<int>(std::sqrt(limit)))};
		auto potentialPrimes{sequence(smallestPrime, limit)};

		for (auto prime : testRange) {
			if (!includes(potentialPrimes, prime)) continue;

			std::erase_if(potentialPrimes, [prime](auto num) {
				return prime != num && num % prime == 0;
			});
		}

		return potentialPrimes;
	}


} // namespace sieve
