import           Test.Tasty
import           Test.Tasty.HUnit

import           SockPairs

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup
  "Pair of socks"
  [ testCase "No socks"       testNoSocks
  , testCase "Single sock"    testSingleSock
  , testCase "Single pair"    testSinglePair
  , testCase "Mismatch"       testMismatch
  , testCase "Sorted pairs"   testSortedPairs
  , testCase "Unsorted pairs" testUnsortedPairs
  , testCase "Missing sock"   testMissingSock
  , testCase "Duplicate pair" testDuplicatePair
  ]

testNoSocks :: Assertion
testNoSocks = sockPairs "" @?= 0

testSingleSock :: Assertion
testSingleSock = sockPairs "A" @?= 0

testSinglePair :: Assertion
testSinglePair = sockPairs "AA" @?= 1

testMismatch :: Assertion
testMismatch = sockPairs "AB" @?= 0

testSortedPairs :: Assertion
testSortedPairs = sockPairs "AABB" @?= 2

testUnsortedPairs :: Assertion
testUnsortedPairs = sockPairs "ABAB" @?= 2

testMissingSock :: Assertion
testMissingSock = sockPairs "ABABC" @?= 2

testDuplicatePair :: Assertion
testDuplicatePair = sockPairs "CABBACCC" @?= 4
