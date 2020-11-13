import unittest
from main import convert

class TestConvertToDays(unittest.TestCase):

  def testShouldConvertWith10(self):
    self.assertEqual(convert(10), 3650)

  def testShouldNotConvertWith10(self):
    self.assertNotEqual(convert(11), 3650)

if __name__ == "__main__":
  unittest.main()
  print("All tests passed")
