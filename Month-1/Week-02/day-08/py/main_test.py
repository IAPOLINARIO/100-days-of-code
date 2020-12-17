from main import combine_letters


def combine_letters_empty_input():
    assert combine_letters('') == []


def combine_letters_one_digit():
    assert combine_letters('2') == ['a', 'b', 'c']


def combine_letters_two_digits():
    assert combine_letters('23') == ['ad','ae','af','bd','be','bf','cd','ce','cf']


def combine_letters_three_digits():
    assert combine_letters('456') == ['gjm', 'gjn', 'gjo', 'gkm', 'gkn', 'gko', 'glm', 'gln', 'glo', 'hjm', 'hjn', 'hjo', 'hkm', 'hkn', 'hko', 'hlm', 'hln', 'hlo', 'ijm', 'ijn', 'ijo', 'ikm', 'ikn', 'iko', 'ilm', 'iln', 'ilo']


if __name__ == "__main__":
    combine_letters_empty_input()
    combine_letters_one_digit()
    combine_letters_two_digits()
    combine_letters_three_digits()
    print('All test passed')
