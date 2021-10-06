from main import trappedWater

def trappedWater6():
  assert trappedWater([0,1,0,2,1,0,1,3,2,1,2,1]) == 6

def trappedWater9():
  assert trappedWater([4,2,0,3,2,5]) == 9

def trappedWater2():
  assert trappedWater([1,0,1,0,1]) == 2

def trappedWater7():
  assert trappedWater([0,1,0,2,1,0,1,3,2,1,2,1,2]) == 7

if __name__ == "__main__":
  trappedWater6()
  trappedWater9()
  trappedWater2()
  trappedWater7()
  print('All test passed')
