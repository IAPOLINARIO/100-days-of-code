import unittest
from main import progressEvaluator

class TestProgress(unittest.TestCase):

  def testShouldReturn2(self):
    self.assertEqual(progressEvaluator([3, 4, 1, 2]),2)

  def testShouldReturn3(self):
    self.assertEqual(progressEvaluator([10, 11, 12, 9, 10]),3)

  def testShouldReturn1(self):
    self.assertEqual(progressEvaluator([6, 5, 4, 3, 2, 9]),1)

  def testShouldReturn0(self):
    self.assertEqual(progressEvaluator([9, 9]),0)

  def testShouldNotReturn9(self):
    self.assertNotEqual(progressEvaluator([9, 9, 8, 1, 2]),9)

if __name__ == "__main__":
  unittest.main()