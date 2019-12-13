#if !defined(HAMMING_H)
#define HAMMING_H

#include <string>
#include <stdexcept>

namespace hamming {
	int compute(const std::string& strand1, const std::string& strand2);
}  // namespace hamming

#endif // HAMMING_H