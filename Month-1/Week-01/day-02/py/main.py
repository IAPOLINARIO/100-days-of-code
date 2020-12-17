import argparse


NEMO = 'Nemo'


def find_nemo(text):
    words = text.split()
    if (NEMO in words):
        return 'I found Nemo at {}!'.format(words.index(NEMO) + 1)

    return "I can't find Nemo :("


if __name__ == "__main__":
    # parsing arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-t", "--text", required=True, help="The text with the Nemo word")
    text = vars(ap.parse_args())['text']

    print(find_nemo(text))
