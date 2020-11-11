import 'dart:io';

void main() {
  stdout.writeln('Tell me a number that I\'ll tell you how many BSTs');
  var number = stdin.readLineSync();

  stdout.writeln('${bstSearch(number)}');
}

int bstSearch(var number) {
  number = int.parse(number);
  return (number == 0 || number == 1) ? 1 : bstSearchCalc(number);
}

int bstSearchCalc(int n) {
  if (n == 0 || n == 1) return 1;
  int result = 0;
  for (int i = 1; i <= n; i++)
    result += bstSearchCalc(i - 1) * bstSearchCalc(n - i);
  return result;
}
