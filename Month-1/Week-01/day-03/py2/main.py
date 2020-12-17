import argparse

parser = argparse.ArgumentParser("Find vegetarian skewers")
parser.add_argument("-g", "--grill", help="Grill to evaluate")
args = parser.parse_args()

def findVeggies(grill):
  veggie, nonVeggie = 0, 0
  for skewer in grill.split():
    if 'x' not in skewer:
      veggie+=1
    else:
      nonVeggie+=1
  return [veggie, nonVeggie]

if __name__ == "__main__":
  print(findVeggies(args.grill))
