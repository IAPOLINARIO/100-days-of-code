import 'package:test/test.dart';
import '../main.dart';

void main() {
  test('Given age is 65', () {
    int expected = 23725;
    int age = 65;

    expect(expected, calculateNumberDaysByAge(age));
  });

  test('Given age is 20', () {
    int expected = 7300;
    int age = 20;

    expect(expected, calculateNumberDaysByAge(age));
  });
}
