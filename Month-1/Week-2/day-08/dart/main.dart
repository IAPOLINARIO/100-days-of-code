import 'dart:io';

void main() {
  stdout.writeln('Lets combine your Phone Number');
  var numbers = stdin.readLineSync();

  stdout.writeln('${combinedNumbers(numbers)}');
}

List<String> combinedNumbers(String digits) {
  var result = new List<String>();
  if (digits == null || digits.length == 0) return result;

  Map map = Map<String, List<String>>();

  map['0'] = [''];
  map['1'] = [''];
  map['2'] = ['a', 'b', 'c'];
  map['3'] = ['d', 'e', 'f'];
  map['4'] = ['g', 'h', 'i'];
  map['5'] = ['j', 'k', 'l'];
  map['6'] = ['m', 'n', 'o'];
  map['7'] = ['p', 'q', 'r', 's'];
  map['8'] = ['t', 'u', 'v'];
  map['9'] = ['w', 'x', 'y', 'z'];

  result.add("");

  for (int i = 0; i < digits.length; i++) {
    var tempList = new List<String>();
    var mapLetters = map[digits[i]];
    for (int j = 0; j < result.length; j++) {
      for (int k = 0; k < mapLetters.length; k++) {
        tempList.add(result[j] + mapLetters[k]);
      }
    }
    result = tempList;
  }
  return result;
}
