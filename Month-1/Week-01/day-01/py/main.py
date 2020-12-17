import argparse


# calculate
def calc_age(age):
    try:
        return int(age.strip()) * 365
    except ValueError:
        return 'Please inform a valid number'


if __name__ == "__main__":
    # parsing arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-a", "--age", required=True, help="The age in years")
    age = vars(ap.parse_args())['age']

    calc_age(age)