class Bob
  def hey(remark)
    if shouting?(remark)
      'Whoa, chill out!'
    elsif question?(remark)
      'Sure.'
    elsif silence?(remark)
      'Fine. Be that way!'
    else
      'Whatever.'
    end
  end

  private

  def shouting?(remark)
    remark == remark.upcase &&
      remark.match(/\p{Alpha}/)
  end

  def question?(remark)
    remark.end_with?('?') &&
      !shouting?(remark) # Ensure it works regardless of if/elsif order.
  end

  def silence?(remark)
    remark.strip.empty?
  end
end
