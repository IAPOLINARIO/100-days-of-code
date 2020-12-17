import argparse

parser = argparse.ArgumentParser("Progress evaluator")
parser.add_argument("-p", "--progress-array", help="Progress array")
args = parser.parse_args()

def progressEvaluator(milesArray):
  count=0
  for miles in range(0,len(milesArray)-1):
    if milesArray[miles+1] > milesArray[miles]:
      count+=1
  return count

if __name__ == "__main__":
  print(progressEvaluator(args.progress_array.split()))