import           Test.Tasty
import           Test.Tasty.HUnit

import           NextPrime

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup
  "Next prime"
  [ testCase "One"         testOne
  , testCase "Two"         testTwo
  , testCase "Eleven"      testEleven
  , testCase "Twelve"      testTwelve
  , testCase "Twenty-four" testTwentyFour
  ]

testOne, testTwo, testEleven, testTwelve, testTwentyFour :: Assertion
testOne = nextPrime 1 @?= 2
testTwo = nextPrime 2 @?= 2
testEleven = nextPrime 11 @?= 11
testTwelve = nextPrime 12 @?= 13
testTwentyFour = nextPrime 24 @?= 29
