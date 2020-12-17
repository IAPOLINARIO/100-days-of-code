import 'package:test/test.dart';
import '../main.dart';

void main() {

  test('Expected 365 when parse 1', () {
    var expected = 365;
    var years = 1;
    expect(expected, calcAge(years));
  });

   test('Expected 730 when parse 2', () {
    var expected = 730;
    var years = 2;
    expect(expected, calcAge(years));
  });
}