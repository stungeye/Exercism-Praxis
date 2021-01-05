# Naive code-based implementation:

class Grains
  def self.chessboard
    (0..63).map { |position| 2**position }
  end

  def self.square(position)
    chessboard[position - 1]
  end

  def self.total
    chessboard.reduce(:+)
  end
end

# Math for the win:

class Grains
  def self.square(position)
    2**(position - 1)
  end

  def self.total
    # Shameless green! Chessboards are always the same size. :)
    18_446_744_073_709_551_615
  end
end
