import 'dart:io';

List<String> phoneLetters = [
  '0',
  '1',
  'abc',
  'def',
  'ghi',
  'jkl',
  'mno',
  'pqrs',
  'tuv',
  'wxyz'
];
void main() {
  stdout.writeln('Lets combine your Phone Number');
  var numbers = stdin.readLineSync();

  stdout.writeln('${combinedNumbers(numbers)}');
}

List<String> letterCombinations(String digits) {
  var result = new List<String>();
  if (digits == null || digits.length == 0) return result;

  var map;

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
    var new_result = new List<String>();
    var alphabates = map[digits[i]];
    for (int j = 0; j < result.length; j++) {
      for (int k = 0; k < alphabates.length; k++) {
        new_result.add(result[j] + alphabates[k]);
      }
    }
    result = new_result;
    print(result);
  }

  return result;
}
