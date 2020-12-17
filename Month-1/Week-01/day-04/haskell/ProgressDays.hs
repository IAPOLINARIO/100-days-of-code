module ProgressDays
  ( progressDays
  ) where

progressDays :: [Int] -> Int
progressDays runs = length [ r2 | (r1, r2) <- zip runs (tail runs), r1 < r2 ]
