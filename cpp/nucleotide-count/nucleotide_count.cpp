#include "nucleotide_count.h"

#include <algorithm>
#include <stdexcept>


namespace nucleotide_count {
    counter::counter(const std::string& sequence) {
        if (std::count_if(sequence.begin(), sequence.end(),
                          [](char n) { return invalid_nucleotide(n); }) != 0) {
            throw std::invalid_argument("Sequence contains an invalid nucleotide.");
        }
        assemble_nucleotide_counts(sequence);
    }

    std::map<char, int> counter::nucleotide_counts() const {
        return counts;
    }

    int counter::count(char nucleotide) const {
        if (invalid_nucleotide(nucleotide)) {
            throw std::invalid_argument("Count requested for invalid nucleotide.");
        }
        return counts.at(nucleotide);
    }

    // Private Methods

    bool counter::invalid_nucleotide(char nucleotide) {
        return possible_nucleotides.find(nucleotide) == std::string::npos;
    }

    void counter::assemble_nucleotide_counts(const std::string& sequence) {
        for (auto nucleotide : possible_nucleotides) {
            counts[nucleotide] = std::count(sequence.begin(), sequence.end(), nucleotide);
        }
    }

} // namespace nucleotide_count
