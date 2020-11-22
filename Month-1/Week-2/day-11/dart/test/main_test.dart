import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('2 ips', () {
    List<String> expected = ["255.255.11.135", "255.255.111.35"];
    String ip = '25525511135';

    expect(ipAdrresses(ip), expected);
  });

  test('1 ip', () {
    List<String> expected = ["0.0.0.0"];
    String ip = '0000';

    expect(ipAdrresses(ip), expected);
  });

  test('1 ip', () {
    List<String> expected = ["1.1.1.1"];
    String ip = '1111';

    expect(ipAdrresses(ip), expected);
  });

  test('1 ip', () {
    List<String> expected = ["0.10.0.10", "0.100.1.0"];
    String ip = '010010';

    expect(ipAdrresses(ip), expected);
  });

  test('5 ips', () {
    List<String> expected = [
      "1.0.10.23",
      "1.0.102.3",
      "10.1.0.23",
      "10.10.2.3",
      "101.0.2.3"
    ];
    String ip = '101023';

    expect(ipAdrresses(ip), expected);
  });
}
