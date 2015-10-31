class Grains
  def self.square( position )
    chessboard[position-1]
  end

  def self.chessboard
    ( 0..63 ).map { |position| 2 ** position }
  end

  def self.total
    chessboard.reduce( :+ )
  end
end
