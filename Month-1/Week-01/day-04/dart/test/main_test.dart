import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('[[3, 4, 1, 2] should has 2 progress day', () {
    int expected = 2;
    List values = [3, 4, 1, 2];

    expect(progressDays(values), expected);
  });

  test('[10, 11, 12, 9, 10] => 3', () {
    int expected = 3;
    List values = [10, 11, 12, 9, 10];

    expect(progressDays(values), expected);
  });

  test('[6, 5, 4, 3, 2, 9]) ➞ 1', () {
    int expected = 1;
    List values = [6, 5, 4, 3, 2, 9];

    expect(progressDays(values), expected);
  });

  test('[9, 9])  ➞ 0', () {
    int expected = 0;
    List values = [9, 9];

    expect(progressDays(values), expected);
  });
}
