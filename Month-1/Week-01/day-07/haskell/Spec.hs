import           Data.Array.IO
import           Data.Array.MArray
import           Test.Tasty
import           Test.Tasty.HUnit

import           MergeSortedArray

main :: IO ()
main = defaultMain tests

tests :: TestTree
tests = testGroup
  "Merge sorted array"
  [ testCase "Merge empty"      testMergeEmpty
  , testCase "Merge into empty" testMergeIntoEmpty
  , testCase "Merge at start"   testMergeAtStart
  , testCase "Merge at end"     testMergeAtEnd
  , testCase "Merge smaller"    testMergeSmaller
  , testCase "Interleave"       testInterleave
  ]

testMergeEmpty :: Assertion
testMergeEmpty = do
  nums1 <- newListArray (0, 1) [2, 3]
  nums2 <- newListArray (0, -1) []
  mergeSortedArray nums1 nums2
  assertArrayContents [2, 3] nums1

testMergeIntoEmpty :: Assertion
testMergeIntoEmpty = do
  nums1 <- newListArray (0, 1) [0, 0]
  nums2 <- newListArray (0, 1) [2, 3]
  mergeSortedArray nums1 nums2
  assertArrayContents [2, 3] nums1

testMergeAtStart :: Assertion
testMergeAtStart = do
  nums1 <- newListArray (0, 1) [3, 0]
  nums2 <- newListArray (0, 0) [2]
  mergeSortedArray nums1 nums2
  assertArrayContents [2, 3] nums1

testMergeAtEnd :: Assertion
testMergeAtEnd = do
  nums1 <- newListArray (0, 1) [2, 0]
  nums2 <- newListArray (0, 0) [3]
  mergeSortedArray nums1 nums2
  assertArrayContents [2, 3] nums1

testMergeSmaller :: Assertion
testMergeSmaller = do
  nums1 <- newListArray (0, 2) [1, 2, 0]
  nums2 <- newListArray (0, 0) [3]
  mergeSortedArray nums1 nums2
  assertArrayContents [1, 2, 3] nums1

testInterleave :: Assertion
testInterleave = do
  nums1 <- newListArray (0, 5) [1, 2, 3, 0, 0, 0]
  nums2 <- newListArray (0, 2) [2, 5, 6]
  mergeSortedArray nums1 nums2
  assertArrayContents [1, 2, 2, 3, 5, 6] nums1

assertArrayContents :: [Int] -> IOArray Int Int -> Assertion
assertArrayContents elems array = do
  assocs <- getAssocs array
  assocs @?= zip [0 ..] elems
