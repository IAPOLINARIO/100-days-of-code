import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('NextPrime(12) ➞ 13', () {
    int expected = 13;
    int values = 12;

    expect(nextPrime(values), expected);
  });

  test('NextPrime(24) ➞ 29', () {
    int expected = 13;
    int values = 12;

    expect(nextPrime(values), expected);
  });

  test('NextPrime(11) ➞ 11', () {
    int expected = 13;
    int values = 12;

    expect(nextPrime(values), expected);
  });
}
