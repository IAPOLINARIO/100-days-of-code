import 'dart:io';

int _YEARINDAYS = 365;
void main() {
  stdout.writeln('Type your age');
  int age = int.tryParse(stdin.readLineSync()) ?? 0;

  stdout.writeln('Number of days: ${calculateNumberDaysByAge(age)}');
}

int calculateNumberDaysByAge(int age) {
  return age * _YEARINDAYS;
}
