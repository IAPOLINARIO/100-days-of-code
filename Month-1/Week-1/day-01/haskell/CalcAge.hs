module CalcAge
  ( calcAge
  ) where

calcAge :: Int -> Int
calcAge age = age * daysPerYear where daysPerYear = 365
