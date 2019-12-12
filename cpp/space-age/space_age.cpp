#include "space_age.h"

namespace space_age {
    space_age::space_age(int seconds)
    {
        age_in_seconds = seconds;
    }
    int space_age::seconds() const
    {
        return age_in_seconds;
    }
}  // namespace space_age
