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
    double space_age::on_earth() const
    {
        return double(age_in_seconds) / 31557600;
    }
}  // namespace space_age
