import unittest
from main import findVeggies

class TestFindVeggies(unittest.TestCase):
  
  def testShouldFind2Veggies3Non(self):
    grill="--oooo-ooo-- --xx--x--xx-- --o---o--oo-- --xx--x--ox-- --xx--x--ox--"
    self.assertEqual(findVeggies(grill),[2, 3])
  
  def testShouldFind3Veggies2Non(self):
    grill="--oooo-ooo-- --xxxxxxxx-- --o--- -o-----o---x-- --o---o-----"
    self.assertEqual(findVeggies(grill),[3, 2])

  def testShouldNotFind10Veggies10Non(self):
    grill="--oooo-ooo-- --xxxxxxxx-- --o--- -o-----o---x-- --o---o-----"
    self.assertNotEqual(findVeggies(grill),[10, 10])

if __name__ == "__main__":
  unittest.main()
  print("All tests passed")
