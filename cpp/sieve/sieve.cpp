#include "sieve.h"

#include <numeric>   // std::iota

namespace sieve {
	constexpr int smallestPrime{ 2 };

	std::vector<int> primes(const int limit) {
		if (limit < smallestPrime) return {};

		// Fill potentialPrimes with integers 2 to limit, inclusive.
		std::vector<int> potentialPrimes(limit - 1);
		std::iota(potentialPrimes.begin(), potentialPrimes.end(), smallestPrime);

		for (auto prime : potentialPrimes) {
			std::erase_if(potentialPrimes, [prime](auto num) {
				return prime != num && num % prime == 0;
				});
		}

		return potentialPrimes;
	}


} // namespace sieve
