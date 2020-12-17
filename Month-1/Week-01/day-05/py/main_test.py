from main import sock_pairs


def test_sock_pairs_with_one_pair():
    assert sock_pairs('AA') == 1


def test_sock_pairs_with_two_pairs():
    assert sock_pairs('ABABC') == 2


def test_sock_pairs_with_four_pairs():
    assert sock_pairs('CABBACCC') == 4


def test_sock_pairs_with_zero_pairs():
    assert sock_pairs('A') == 0


if __name__ == "__main__":
    test_sock_pairs_with_one_pair()
    test_sock_pairs_with_two_pairs()
    test_sock_pairs_with_four_pairs()
    test_sock_pairs_with_zero_pairs()
    print('All test passed')
