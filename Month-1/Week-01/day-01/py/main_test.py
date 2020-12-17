from main import calc_age


def test_calc_age_with_valid_input():
    assert calc_age('65') == 23725


def test_calc_age_with_invalid_input():
    assert calc_age('oi') == 'Please inform a valid number'


def test_calc_age_with_empty_input():
    assert calc_age('') == 'Please inform a valid number'

if __name__ == "__main__":
    test_calc_age_with_valid_input()
    test_calc_age_with_invalid_input()
    test_calc_age_with_empty_input()
    print('All test passed')