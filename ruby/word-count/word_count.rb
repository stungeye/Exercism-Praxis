class Phrase
  WORD_REGEX = /\w+'\w+|\w+/

  def initialize(phrase)
    @phrase = phrase
  end

  def word_count
    all_words.each_with_object(Hash.new(0)) do |word, word_count|
      word_count[word] += 1
    end
  end

  private

  def all_words
    @phrase.scan(WORD_REGEX).map(&:downcase)
  end
end

module BookKeeping
  VERSION = 1
end
