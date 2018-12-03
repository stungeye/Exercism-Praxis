class Bst
  include Enumerable
  attr_reader :data, :left, :right

  def initialize(number)
    @data = number
  end

  # If passed a block, walks tree and applies the block to each element.
  # Otherwise returns an enumerator.
  def each(&block)
    if block_given?
      @left.each(&block) if @left
      yield @data
      @right.each(&block) if @right
    else
      to_enum(:each)
    end
  end

  def insert(number)
    if number > @data
      insert_right(number)
    else
      insert_left(number)
    end
  end

  private

  def insert_right(number)
    if @right
      @right.insert(number)
    else
      @right = Bst.new(number)
    end
  end

  def insert_left(number)
    if @left
      @left.insert(number)
    else
      @left = Bst.new(number)
    end
  end
end

module BookKeeping
  VERSION = 1 # Where the version number matches the one in the test.
end
