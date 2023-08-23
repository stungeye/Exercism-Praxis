class Luhn

  def validLuhn?(number) # number is a string of digits like: "055 444 285"
    return false if number.size <= 1

    number.scan(/\d/)    # Regular expression to get the characters that are digits.
          .map(&:to_i)   # Convert all digits to integers.
          .reverse       # Reverse the array.
          .each_slice(2) # Slice the array into groups of two digits.
          # Sum the digits, doubling every other one. Sum digits of the doubled ones.
          .sum { |odd, even = 0| odd + (even * 2).digits.sum }
          .modulo(10)    # Get the remainder of the sum divided by 10.
          .zero?         # If the remainder is zero, the number is valid.
  end

end


