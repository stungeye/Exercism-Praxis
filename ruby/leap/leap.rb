class Year
  def self.leap?(year)
    year.divisible_by?(100) ? year.divisible_by?(400)
                            : year.divisible_by?(4)
  end
end

class Integer
  def divisible_by?(n)
    modulo(n).zero?
  end
end
