import           Test.Tasty
import           Test.Tasty.HUnit

import           ProgressDays

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup
  "Is Johnny making progress?"
  [ testCase "No runs"       testNoRuns
  , testCase "Single run"    testSingleRun
  , testCase "Progress"      testProgress
  , testCase "No progress"   testNoProgress
  , testCase "Same distance" testSameDistance
  , testCase "Multiple runs" testMultipleRuns
  ]

testNoRuns :: Assertion
testNoRuns = progressDays [] @?= 0

testSingleRun :: Assertion
testSingleRun = progressDays [2] @?= 0

testProgress :: Assertion
testProgress = progressDays [2, 3] @?= 1

testNoProgress :: Assertion
testNoProgress = progressDays [3, 2] @?= 0

testSameDistance :: Assertion
testSameDistance = progressDays [9, 9] @?= 0

testMultipleRuns :: Assertion
testMultipleRuns = map progressDays series @?= [2, 3, 1]
  where series = [[3, 4, 1, 2], [10, 11, 12, 9, 10], [6, 5, 4, 3, 2, 9]]
