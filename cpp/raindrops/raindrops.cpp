#include "raindrops.h"

namespace raindrops {

	std::string convert(int number) {
		std::string pling, plang, plong;

		if (number % 3 == 0) {
			pling = "Pling";
		}

		if (number % 5 == 0) {
			plang = "Plang";
		}

		if (number % 7 == 0) {
			plong = "Plong";
		}

		const std::string raindrops = pling + plang + plong;

		return raindrops.empty() ? std::to_string(number) : raindrops;
	}
} // namespace raindrops
