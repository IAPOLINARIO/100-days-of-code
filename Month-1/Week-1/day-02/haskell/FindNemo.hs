module FindNemo
  ( findNemo
  ) where

import           Data.List

findNemo :: String -> String
findNemo sentence = case elemIndex "Nemo" (words sentence) of
  Nothing    -> "I can't find Nemo :("
  Just index -> "I found Nemo at " ++ show (succ index) ++ "!"
