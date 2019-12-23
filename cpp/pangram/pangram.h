#if !defined(PANGRAM_H)
#define PANGRAM_H

#include <string>
#include <string_view>

namespace pangram {
	inline static const std::string alphabet{ "abcdefghijklmnopqrstuvwxyz" };
	bool is_pangram(std::string_view sentence);
}  // namespace pangram

#endif // PANGRAM_H