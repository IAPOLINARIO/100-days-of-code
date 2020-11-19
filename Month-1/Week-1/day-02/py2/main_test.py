import unittest
from main import findNemo

class TestFindNemo(unittest.TestCase):

  def testFindNemoCaseIAmFindingNemo(self):
    self.assertEqual(findNemo('I am finding Nemo !'), 'I found Nemo at 4 !')

  def testFindNemoCaseNemoIsme(self):
    self.assertEqual(findNemo('Nemo is me'), 'I found Nemo at 1 !')

  def testFindNemoCaseINemoAm(self):
    self.assertEqual(findNemo('I Nemo am'), 'I found Nemo at 2 !')

  def testFindNemoCaseFailNemos(self):
    self.assertEqual(findNemo('I Nemos am'), "I can't find Nemo :(")

  def testFindNemoCaseFailnemo(self):
    self.assertEqual(findNemo('I nemo am'), "I can't find Nemo :(")

if __name__ == "__main__":
  unittest.main()
  print('All tests passed')
