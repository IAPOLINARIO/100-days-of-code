import           Test.Tasty
import           Test.Tasty.HUnit

import           CalcAge

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup
  "Convert age to days"
  [ testCase "Zero" $ calcAge 0 @?= 0
  , testCase "Twenty" $ calcAge 20 @?= 7300
  , testCase "Sixty-five" $ calcAge 65 @?= 23725
  ]
