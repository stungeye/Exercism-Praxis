#if !defined(HAMMING_H)
#define HAMMING_H

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

namespace hamming {
	int compute(const string& strand1, const string& strand2);
}  // namespace hamming

#endif // HAMMING_H