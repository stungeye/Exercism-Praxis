module IntegerDivisibilityTest
  refine Integer do
    def divisible_by?(n)
      self.modulo(n).zero?
    end
  end
end

class Sieve
  using IntegerDivisibilityTest

  attr_reader :upper_bound
  SMALLEST_PRIME = 2

  def initialize(upper_bound)
    @upper_bound = upper_bound
  end

  def primes
    return [] if upper_bound < SMALLEST_PRIME
    return @primes if @primes # Memoization

    composite_test_range = SMALLEST_PRIME..Math.sqrt(upper_bound)
    potential_primes = (SMALLEST_PRIME..upper_bound).to_a

    composite_test_range.each do |potential_prime|
      next unless potential_primes.include?(potential_prime)

      potential_primes.reject! do |num|
        num.divisible_by?(potential_prime) unless num == potential_prime
      end
    end

    @primes = potential_primes
  end
end
