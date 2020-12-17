import           Test.Tasty
import           Test.Tasty.HUnit

import           FindNemo

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup
  "Finding Nemo"
  [ testCase "Nemo at 1"      testNemoAt1
  , testCase "Nemo at 2"      testNemoAt2
  , testCase "Nemo at 4"      testNemoAt4
  , testCase "Nemo not found" testNemoNotFound
  ]

testNemoAt1, testNemoAt2, testNemoAt4 :: Assertion
testNemoAt1 = findNemo "Nemo is me" @?= "I found Nemo at 1!"
testNemoAt2 = findNemo "I Nemo am" @?= "I found Nemo at 2!"
testNemoAt4 = findNemo "I am finding Nemo !" @?= "I found Nemo at 4!"

testNemoNotFound :: Assertion
testNemoNotFound = findNemo "Nemo's NeMo" @?= "I can't find Nemo :("
