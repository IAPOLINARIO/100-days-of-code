module Skewers
  ( skewers
  ) where

import           Control.Arrow

skewers :: [String] -> (Int, Int)
skewers = count isVegetarian &&& count isNonVegetarian
 where
  count p = length . filter (p . filter (/= '-'))

  isVegetarian    = all (== 'o')
  isNonVegetarian = any (== 'x')
