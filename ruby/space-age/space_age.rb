class SpaceAge
  EARTH_ORBITAL_PERIOD = 31557600 # Seconds

  ORBITAL_RATIO = {
    earth:   1.0,
    mercury: 0.2408467,
    venus:   0.61519726,
    mars:    1.8808158,
    jupiter: 11.862615,
    saturn:  29.447498,
    uranus:  84.016846,
    neptune: 164.79132
  }

  # Generate all the required "on_planet" methods.
  ORBITAL_RATIO.each_key do |planet|
    define_method("on_#{planet}") { age_in_seconds_on(planet) }
  end

  def initialize(age_in_seconds)
    @age_in_seconds = age_in_seconds
  end

  private
  def age_in_seconds_on(planet)
    orbital_period = EARTH_ORBITAL_PERIOD * ORBITAL_RATIO[planet]
    @age_in_seconds / orbital_period
  end
end