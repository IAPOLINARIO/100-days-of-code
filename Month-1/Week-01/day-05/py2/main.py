import argparse

parser = argparse.ArgumentParser("Find sock pairs")
parser.add_argument("-d", "--drawer", help="Drawer to look for sock pairs")
args = parser.parse_args()

def findSockPairs(drawer):

  socks=list(drawer)
  count=0

  for key in range(0, len(socks)):
    sockLetter=socks[key]
    for sockDrawer in socks[key+1:len(socks)]:
      if sockLetter == sockDrawer:
        count+=1
        break

  return count

if __name__ == "__main__":
  print(findSockPairs(args.drawer))
