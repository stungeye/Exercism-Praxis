#include "binary.h"

#include <cmath>

namespace binary {

	int convert(const std::string& binary) {
		const auto length = binary.length();
		auto decimal = 0;

		for (size_t i = 0; i < length; ++i) {
			const size_t position_from_end = length - 1 - i;
			if (binary.at(position_from_end) == '1') {
				decimal += pow(2, i);
			}
		}

		return decimal;
	}
} // namespace binary
