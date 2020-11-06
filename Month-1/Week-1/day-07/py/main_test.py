from main import sort_array


def sort_array_test_1():
    assert sort_array('[1,2,3,0,0,0]', '[2,5,6]') == [1,2,2,3,5,6]


def sort_array_test_2():
    assert sort_array('[1,2,3,3,3,4,7,2,0,0,0,0]', '[2,2,5,6]') == [1,2,2,2,2,3,3,3,4,5,6,7]


if __name__ == "__main__":
    sort_array_test_1()
    sort_array_test_2()
    print('All test passed')
