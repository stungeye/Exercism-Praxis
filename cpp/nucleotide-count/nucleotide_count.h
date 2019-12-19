#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace nucleotide_count {
	class counter {
	    inline static const std::string possible_nucleotides{"ATCG"};
		std::map<char, int> counts;
	public:
		explicit counter(const std::string& sequence);
		[[nodiscard]] std::map<char, int> nucleotide_counts() const;
		[[nodiscard]] int count(char nucleotide) const;
	private:
		static bool invalid_nucleotide(char nucleotide);
		void assemble_nucleotide_counts(const std::string& sequence);
	};

} // namespace nucleotide_count

#endif // NUCLEOTIDE_COUNT_H
