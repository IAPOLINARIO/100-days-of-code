import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('SockPairs("AA") ➞ 1', () {
    int expected = 1;
    String values = 'AA';

    expect(sockPairs(values), expected);
  });

  test('SockPairs("ABABC") ➞ 2', () {
    int expected = 2;
    String values = 'ABABC';

    expect(sockPairs(values), expected);
  });

  test('SockPairs("CABBACCC") ➞ 4', () {
    int expected = 4;
    String values = 'CABBACCC';

    expect(sockPairs(values), expected);
  });
}
