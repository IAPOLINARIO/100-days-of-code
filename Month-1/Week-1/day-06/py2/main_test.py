import unittest
from main import findNextPrime

class TestFindNextPrime(unittest.TestCase):

  def testShouldFindNextPrime853(self):
    self.assertEqual(findNextPrime(840),853)

  def testShouldFindNextPrime13(self):
    self.assertEqual(findNextPrime(12),13)

  def testShouldFindNextPrime29(self):
    self.assertEqual(findNextPrime(24),29)

  def testShouldFindNextPrime11(self):
    self.assertEqual(findNextPrime(11),11)

  def testShouldNotReturn13(self):
    self.assertNotEqual(findNextPrime(11),13)

if __name__ == "__main__":
  unittest.main()
