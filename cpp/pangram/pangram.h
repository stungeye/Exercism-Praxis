#if !defined(PANGRAM_H)
#define PANGRAM_H

#include <string>
#include <string_view>

namespace pangram {
	bool is_pangram(std::string sentence);
}  // namespace pangram

#endif // PANGRAM_H