#include "nucleotide_count.h"

#include <algorithm>
#include <stdexcept>

namespace nucleotide_count {
    counter::counter(const std::string& sequence) {
        if (std::count_if(sequence.begin(), sequence.end(),
                          [this](char n) { return invalid_nucleotide(n); }) != 0) {
            throw std::invalid_argument("Sequence contains an invalid nucleotide.");
        }

        this->sequence = sequence;
    }

    std::map<char, int> counter::nucleotide_counts() const {
        std::map<char, int> counts;

        for (char nucleotide : possible_nucleotides) {
            counts[nucleotide] = count(nucleotide);
        }

        return counts;
    }

    int counter::count(char nucleotide) const {
        if (invalid_nucleotide(nucleotide)) {
            throw std::invalid_argument("Count requested for invalid nucleotide.");
        }
        return std::count(sequence.begin(), sequence.end(), nucleotide);
    }

    bool counter::invalid_nucleotide(char nucleotide) const {
        return possible_nucleotides.find(nucleotide) == std::string::npos;
    }
} // namespace nucleotide_count
