import argparse

parser = argparse.ArgumentParser("Find nemo in words")
parser.add_argument("-p", "--phrase", help="Phrase to look into for Nemo", required=False)
args = parser.parse_args()

def findNemo(text):
  phrase = text.split(" ")
  words = { w: phrase.index(w)+1 for w in phrase }
  find = words.get("Nemo")
  if find != None:
    return "I found Nemo at {} !".format(find)
  return "I can't find Nemo :("

if __name__ == "__main__":
  print(findNemo(args.phrase))