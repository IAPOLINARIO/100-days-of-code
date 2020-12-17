module NextPrime
  ( nextPrime
  ) where

nextPrime :: Int -> Int
nextPrime n = head (dropWhile (< n) primes)
 where
  primes = sieve [2 ..]
  sieve (p : qs) = p : sieve [ q | q <- qs, q `mod` p /= 0 ]
