module SockPairs
  ( sockPairs
  ) where

import           Data.List

sockPairs :: [Char] -> Int
sockPairs socks = sum [ length g `div` 2 | g <- group (sort socks) ]
