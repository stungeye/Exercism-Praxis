#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age {
    class space_age {
        int age_in_seconds;
    public:
        space_age(int seconds);
        int seconds() const;
    };
}  // namespace space_age

#endif // SPACE_AGE_H