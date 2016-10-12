class Pangram
  def self.is_pangram?(potential_pangram)
    lower_case_potential_pangram = potential_pangram.downcase

    ('a'..'z').all? do |letter|
      lower_case_potential_pangram.include?(letter)
    end
  end
end

module BookKeeping
  VERSION = 2
end
