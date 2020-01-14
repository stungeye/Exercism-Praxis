#if !defined(ETL_H)
#define ETL_H

#include <vector>
#include <map>

namespace etl {
    std::map<char, int> transform(const std::map<int, std::vector<char>>& old_points);
}  // namespace etl

#endif // ETL_H