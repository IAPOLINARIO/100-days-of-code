import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('Letters from 23', () {
    List<String> expected = [
      "ad",
      "ae",
      "af",
      "bd",
      "be",
      "bf",
      "cd",
      "ce",
      "cf"
    ];
    String digits = '23';

    expect(combinedNumbers(digits), expected);
  });

  test('Letters from 456', () {
    List<String> expected = [
      "gjm",
      "gjn",
      "gjo",
      "gkm",
      "gkn",
      "gko",
      "glm",
      "gln",
      "glo",
      "hjm",
      "hjn",
      "hjo",
      "hkm",
      "hkn",
      "hko",
      "hlm",
      "hln",
      "hlo",
      "ijm",
      "ijn",
      "ijo",
      "ikm",
      "ikn",
      "iko",
      "ilm",
      "iln",
      "ilo"
    ];
    String digits = '456';

    expect(combinedNumbers(digits), expected);
  });
}
