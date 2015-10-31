class Prime
  def self.nth(number)
    raise ArgumentError  if number.zero?
    
    primes.first(number).last
  end

  def self.primes
    (2..Float::INFINITY).lazy.select do |prime_suspect| 
      prime_suspect.prime?
    end
  end
end

class Integer
  def prime?
    max_relevant_divisor = Math.sqrt(self)

    (2..max_relevant_divisor).none? do |divisor| 
      self.modulo(divisor).zero?
    end
  end
end

