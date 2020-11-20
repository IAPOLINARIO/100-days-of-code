import argparse

parser = argparse.ArgumentParser("Find next prime")
parser.add_argument("-n", "--number", help="Base number to look for the next prime")
args = parser.parse_args()

def findNextPrime(baseNumber):
  count=0
  divisors=baseNumber
  while(divisors >= 1):
    if baseNumber % divisors == 0:
      count+=1
    divisors=divisors - 1
  if count > 2:
    nextNumber=baseNumber+1
    return findNextPrime(nextNumber)
  return baseNumber

if __name__ == "__main__":
  print(findNextPrime(int(args.number)))
