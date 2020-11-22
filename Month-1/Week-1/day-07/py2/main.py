import argparse

parser = argparse.ArgumentParser("Manually merge arrays")
parser.add_argument("-a1", "--array1", help="Array 1")
parser.add_argument("-a2", "--array2", help="Array 2")
args = parser.parse_args()

def mergeArrays(targetArray, sourceArray):

  for x in range(0, len(sourceArray)):
    for y in range(0, len(targetArray)):
      if sourceArray[x] <= targetArray[y]:
        targetArray.insert(targetArray.index(targetArray[y]),sourceArray[x])
        break
      elif sourceArray[x] >= targetArray[y] and y == len(targetArray)-1:
        targetArray.append(sourceArray[x])
        break
  return targetArray

if __name__ == "__main__":

  targetArray = [int(x) for x in args.array1.split(',')]
  sourceArray = [int(x) for x in args.array2.split(',')]

  print(mergeArrays(targetArray, sourceArray))
