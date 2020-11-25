import unittest
import main as prog

class TestFindCombinations(unittest.TestCase):

  def testShouldReturnCorrectly(self):
    self.assertEqual(prog.findCombinations("23"), ["ad","ae","af","bd","be","bf","cd","ce","cf"])
  
  def testShouldReturnKey4(self):
    self.assertEqual(prog.findCombinations("4"), prog.KEYBOARD["4"])
  
  def testShouldReturn0(self):
    self.assertEqual(len(prog.findCombinations("")), 0)

  def testShouldReturnErrorMsg(self):
    self.assertEqual(prog.findCombinations("1"), "Could not find the key informed.")

if __name__ == "__main__":
  unittest.main()
