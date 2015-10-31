require 'benchmark'
 
# returns lazy enumerator
def primes_lazy_but_stupid
  (2..Float::INFINITY).lazy.reject{ |i| (2..Math.sqrt(i)).any?{ |j| i % j == 0 } }
end
 
# returns just array of primes <= n
def primes_just_stupid(n)
  (2..n).reject{ |i| (2..Math.sqrt(i)).any?{ |j| i % j == 0 } }
end
 
# returns custom lazy enumerator doing some stupid optimizations
def primes_lazy_and_smarter
  Enumerator.new do |e|
    e.yield 2
    (3..Float::INFINITY).step(2).lazy.reject{ |i| (3..Math.sqrt(i)).step(2).any?{ |j| i % j == 0 } }.map(&:to_i).each(&e.method(:yield).to_proc)
  end.lazy
end
 
# returns just array of primes <= n but it's fast
def primes_eratosthenes(n)
  sieve = []
  (3..Math.sqrt(n)).step(2) do |i|
    unless sieve[i]
      (i*i..n).step(i) do |j|
        sieve[j] = true
      end
    end
  end
  [2] + (3..n).step(2).select{ |i| !sieve[i] }
end
 
# checks n for primality by just trial division
def prime?(n)
  bound = Math.sqrt(n)
  n > 1 and primes_lazy_and_smarter.take_while{ |i| i <= bound }.none?{ |i| n % i == 0 }
end
 
# benchmarks that show the truth
n = 100000
puts 'primes_lazy_and_stupid'
puts Benchmark.measure{ primes_lazy_but_stupid.take_while{ |x| x <= n }.to_a }
puts 'primes_just_stupid'
puts Benchmark.measure{ primes_just_stupid(n) }
puts 'primes_lazy_and_smarter'
puts Benchmark.measure{ primes_lazy_and_smarter.take_while{ |x| x<= n }.to_a }
puts 'primes_eratosthenes'
puts Benchmark.measure{ primes_eratosthenes(n) }
 
puts primes_lazy_and_smarter.take_while{ |x| x <= 100 }.to_a.join ','
