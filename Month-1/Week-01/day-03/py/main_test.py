from main import count_vegetarian_skewers


def test_count_vegetarian_skewers_with_two_vegetarian_skewers():
    assert count_vegetarian_skewers('["--oooo-ooo--", "--xx--x--xx--", "--o---o--oo--", "--xx--x--ox--", "--xx--x--ox--"]') == '[2, 3]'


def test_count_vegetarian_skewers_with_one_vegetarian_skewers():
    assert count_vegetarian_skewers('["--oooo-xoo--", "--xx--x--xx--", "--o---o--oo--", "--oo--o--ox-", "--xx--x--ox--", "--xx--x--ox--"]') == '[1, 5]'


def test_count_vegetarian_skewers_with_no_vegetarian_skewers():
    assert count_vegetarian_skewers('["--ooxo-ooo--", "--xx--x--xx--", "--x---o--oo--", "--xx--x--ox--", "--xx--x--ox--"]') == '[0, 5]'


if __name__ == "__main__":
    test_count_vegetarian_skewers_with_two_vegetarian_skewers()
    test_count_vegetarian_skewers_with_one_vegetarian_skewers()
    test_count_vegetarian_skewers_with_no_vegetarian_skewers()
    print('All test passed')