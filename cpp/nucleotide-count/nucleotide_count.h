#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <string>
#include <map>

namespace nucleotide_count {
    class counter {
        const std::string possible_nucleotides = "ATCG";
        std::string sequence;
    public:
        counter(const std::string& sequence);
        std::map<char, int> nucleotide_counts() const;
        int count(char nucleotide) const;
        bool invalid_nucleotide(char nucleotide) const;
    };
}  // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H