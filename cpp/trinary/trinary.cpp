#include "trinary.h"

namespace trinary {
	int from_base_to_decimal(const int base, const std::string& numerals) {
		const auto length = numerals.length();
		auto decimal = 0;

		for (size_t i = 0; i < length; ++i) {
			const size_t position_from_end = length - 1 - i;
			const auto digit = numerals.at(position_from_end) - '0';

			if ((digit < 0) || (digit >= base)) {
				return 0;
			}

			decimal += digit * pow(base, i);
		}

		return decimal;
	}

	int to_decimal(const std::string& trinary) {
		return from_base_to_decimal(3, trinary);
	}
} // namespace trinary
