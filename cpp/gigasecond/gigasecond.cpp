#include "gigasecond.h"

namespace gigasecond {
	ptime advance(boost::posix_time::ptime time) {
		return time + seconds(1'000'000'000);
	}
}  // namespace gigasecond
