#include "pascals_triangle.h"

#include <iostream>

namespace pascals_triangle {

	std::vector<std::vector<int>> generate_rows(int number_of_rows) {
		std::vector<std::vector<int>> triangle(number_of_rows);

		for (size_t row_num = 0; row_num < triangle.size(); ++row_num) {
			auto& current_row = triangle.at(row_num);
			current_row.resize(row_num + 1, 1);

			for (size_t pos = 1; pos < row_num; ++pos) {
				const auto& prev_row = triangle.at(row_num - 1);
				current_row[pos] = prev_row[pos - 1] + prev_row[pos];
			}
		}

		return triangle;
	}
} // namespace pascals_triangle
