from main import next_prime


def next_prime_12():
    assert next_prime('12') == 13


def next_prime_24():
    assert next_prime('24') == 29


def next_prime_11():
    assert next_prime('11') == 11


def next_prime_negative():
    assert next_prime('-1') == 2


if __name__ == "__main__":
    next_prime_12()
    next_prime_24()
    next_prime_11()
    next_prime_negative()
    print('All test passed')
