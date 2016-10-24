class RunLengthEncoding
  def self.encode(input)
    input.gsub(/(.)\1+/) do |run_of_chars|
      "#{run_of_chars.length}#{run_of_chars[0]}"
    end
  end

  def self.decode(input)
    input.gsub(/(\d+)(\D)/) do |_|
      run_length = $1.to_i
      letter = $2
      letter * run_length
    end
  end
end

module BookKeeping
  VERSION = 2
end
