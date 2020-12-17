import unittest
from main import findSockPairs

class TestFindSockPairs(unittest.TestCase):

  def testShouldFind1Pair(self):
    self.assertEqual(findSockPairs("AA"),1)

  def testShouldFind2Pairs(self):
    self.assertEqual(findSockPairs("ABABC"),2)

  def testShouldFind5Pairs(self):
    self.assertEqual(findSockPairs("CABBACCC"),5)
  
  def testShouldFind1Pair1(self):
    self.assertEqual(findSockPairs("ABCDEFGHIA"),1)

  def testShouldNotFind2Pairs(self):
    self.assertNotEqual(findSockPairs("ABCDEFGHIA"),2)

if __name__ == "__main__":
  unittest.main()
