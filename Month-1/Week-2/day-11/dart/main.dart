import 'dart:io';

void main() {
  stdout.writeln('Tell me a number that I\'ll tell you how many BSTs');
  var ip = stdin.readLineSync();

  stdout.writeln('${ipAdrresses(ip)}');
}

bool isValid(String s) {
  if (s.startsWith('0') && s != '0') {
    return false;
  }

  return (int.parse(s) >= 0) && (int.parse(s) <= 255);
}

List<String> ipAdrresses(String ip) {
  if (ip == null || int.tryParse(ip) == null) {
    return null;
  }

  ip = ip.replaceAll(new RegExp('[^0-9]'), '');
  List<String> result = new List<String>();

  for (int i = 1; i < 4 && i + 3 <= ip.length; i++) {
    for (int j = 1; j < 4 && i + j + 2 <= ip.length; j++) {
      for (int k = 1; k < 4 && i + j + k + 1 <= ip.length; k++) {
        var first = ip.substring(0, i);
        var second = ip.substring(i, i + j);
        var third = ip.substring(i + j, i + j + k);
        var fourth = ip.substring(i + j + k);
        if (isValid(first) &&
            isValid(second) &&
            isValid(third) &&
            isValid(fourth))
          result.add('${first}.${second}.${third}.${fourth}');
      }
    }
  }
  return result;
}
