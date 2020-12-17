import unittest
from main import mergeArrays

class TestMergeArrays(unittest.TestCase):

  def testShouldMergeArr1Arr2(self):
    arr1=[1,2,3]
    arr2=[2,5,6]

    mergedArr1Arr2=arr1 + arr2
    mergedArr1Arr2.sort()

    self.assertEqual(mergeArrays(arr1, arr2), mergedArr1Arr2)

  def testShouldMergeArr3Arr4(self):
    arr3=[10,100,200,500]
    arr4=[1,2,3,5]

    mergedArr3Arr3=arr3 + arr4
    mergedArr3Arr3.sort()

    self.assertEqual(mergeArrays(arr3, arr4), mergedArr3Arr3)

if __name__ == "__main__":
  unittest.main()
