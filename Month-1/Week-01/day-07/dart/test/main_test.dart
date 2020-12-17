import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('Orderned Array', () {
    List expected = [1, 2, 2, 3, 5, 6];
    String nums1 = '[1, 2, 3, 0, 0, 0]';
    String nums2 = '[2, 5, 6]';

    expect(sortedArray(nums1, nums2), expected);
  });
}
