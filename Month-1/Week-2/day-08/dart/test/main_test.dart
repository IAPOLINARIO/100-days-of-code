import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('Orderned Array', () {
    List expected = [1, 2, 2, 3, 5, 6];
    String nums1 = '23';

    expect(combinedNumbers(nums1), true);
  });

  test('Orderned Array2 ', () {
    List expected = [1, 2, 2, 3, 5, 6];
    String nums1 = '234';

    expect(letterCombinations(nums1), true);
  });
}
