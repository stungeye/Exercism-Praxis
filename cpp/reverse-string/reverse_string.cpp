#include "reverse_string.h"
#include <algorithm>

namespace reverse_string {
    string reverse_string(const string& input) {
        string output(input);

        reverse(output.begin(), output.end());

        return output;
    }
} // namespace reverse_string
