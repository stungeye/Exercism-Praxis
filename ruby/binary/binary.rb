class Binary
  BASE = 2

  def initialize(binary_string)
    throw ArgumentError unless valid_number(binary_string)
    @binary_string = binary_string
  end

  def to_decimal
    @binary_string.reverse
                  .chars
                  .map(&:to_i)
                  .map.with_index { |numeral, i| numeral * BASE**i }
                  .reduce(:+)
  end

  private

  def valid_number(binary_string)
    valid_numerals = BASE.times.map(&:to_s).join
    binary_string =~ /^[#{valid_numerals}]+$/
  end
end

module BookKeeping
  VERSION = 2 # Where the version number matches the one in the test.
end
