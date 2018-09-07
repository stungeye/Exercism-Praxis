class Array
  def keep(&predicate)
    [].tap do |keepers|
      self.each do |element|
        keepers << element if predicate.call(element)
      end
    end
  end

  def discard(&predicate)
    self - keep(&predicate)
  end
end