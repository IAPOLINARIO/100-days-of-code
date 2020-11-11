import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('3 = 5', () {
    int expected = 5;
    String number = '3';

    expect(bstSearch(number), expected);
  });

  test('2 = 2', () {
    int expected = 2;
    String number = '2';

    expect(bstSearch(number), expected);
  });

  test('5 = 42', () {
    int expected = 42;
    String number = '5';

    expect(bstSearch(number), expected);
  });

  test('9 = 4862', () {
    int expected = 4862;
    String number = '9';

    expect(bstSearch(number), expected);
  });
}
