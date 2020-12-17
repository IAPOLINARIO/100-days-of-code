from main import find_nemo


def test_find_nemo_with_nemo():
    assert find_nemo('I am finding Nemo !') == 'I found Nemo at 4!'


def test_find_nemo_without_nemo():
    assert find_nemo('oi') == "I can't find Nemo :("


if __name__ == "__main__":
    test_find_nemo_with_nemo()
    test_find_nemo_without_nemo()
    print('All test passed')