import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('I Have Nemo', () {
    String expected = 'I found Nemo at 3';
    String sentence = 'I Have Nemo';

    expect(expected, findNemo(sentence));
  });

  test('Nemo Nemo', () {
    String expected = 'I found Nemo at 1';
    String sentence = 'Nemo Nemo';

    expect(expected, findNemo(sentence));
  });

  test('I Have NoNemo', () {
    String expected = 'I can\'t find Nemo';
    String sentence = 'I Have NoNemo';

    expect(expected, findNemo(sentence));
  });
}
