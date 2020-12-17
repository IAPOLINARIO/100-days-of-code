import argparse

parser = argparse.ArgumentParser("Phone letter combinations")
parser.add_argument("-d", "--digits", help="Digits")
args = parser.parse_args()

KEYBOARD = {
  "2": ["a","b","c"],
  "3": ["d","e","f"],
  "4": ["g","h","i"],
  "5": ["j","k","l"],
  "6": ["m","n","o"],
  "7": ["p","q","r", "s"],
  "8": ["t","u","v"],
  "9": ["w","x","y","z"],
}

def findCombinations(digits):

  if len(digits) == 1 and int(digits[0]) > 1:
    return [ x for x in KEYBOARD[digits[0]] ]
  elif len(digits) == 0:
    return []

  tempArr=[]
  for key in digits[1:]:
    tempArr+=KEYBOARD[key]

  try:
    combinations = [ x+y for x in KEYBOARD[digits[0]] for y in tempArr ]
    return combinations
  except KeyError:
    return "Could not find the key informed."

if __name__ == "__main__":
  print(findCombinations(args.digits))
