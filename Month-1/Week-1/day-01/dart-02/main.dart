import 'dart:io';

const int DAYS_OF_YEAR = 365;
void main() {
  stdout.writeln('Type your age');

  var age = int.tryParse(stdin?.readLineSync()) ?? 0;

  stdout.writeln('$age years has ${calcAge(age)} days');
}

int calcAge(int years) {
  return years * DAYS_OF_YEAR;
}
