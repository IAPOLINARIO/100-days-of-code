import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('[2, 3]', () {
    String expected = '[${2} vegetarian skewers, ${3} non-vegetarian skewers]';
    String skewers =
        '["--oooo-ooo--","--xx--x--xx--","--o---o--oo--","--xx--x--ox--","--xx--x--ox--"]';

    expect(expected, barbecueSkewers(skewers));
  });

  test('[3, 2]', () {
    String expected = '[${3} vegetarian skewers, ${2} non-vegetarian skewers]';
    String skewers =
        '["--oooo-ooo--", "--xxxxxxxx--", "--o---", "-o-----o---x--", "--o---o-----"]';

    expect(expected, barbecueSkewers(skewers));
  });
}
