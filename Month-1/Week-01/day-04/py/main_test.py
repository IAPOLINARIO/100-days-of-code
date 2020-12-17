from main import progress_days


def test_progress_days_with_two_progress_days():
    assert progress_days('[3, 4, 1, 2]') == 2


def test_progress_days_with_three_progress_days():
    assert progress_days('[10, 11, 12, 9, 10]') == 3


def test_progress_days_with_one_progress_day():
    assert progress_days('[6, 5, 4, 3, 2, 9]') == 1


def test_progress_days_with_no_progress_day():
    assert progress_days('[9, 9]') == 0


if __name__ == "__main__":
    test_progress_days_with_two_progress_days()
    test_progress_days_with_three_progress_days()
    test_progress_days_with_one_progress_day()
    test_progress_days_with_no_progress_day()
    print('All test passed')
