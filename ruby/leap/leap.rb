class Year
  VERSION = 1

  def self.leap?(year)
    year.divisible_by?(100) ? year.divisible_by?(400)
                            : year.divisible_by?(4)
  end
end

class Integer
  def divisible_by?(n)
    self.modulo(n).zero?
  end
end
