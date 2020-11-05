import 'dart:io';

void main() {
  stdout.writeln('Tell me a number and Ill give you the next Prime');
  var number = stdin.readLineSync();

  stdout.writeln('${nextPrime(number)}');
}

int nextPrime(var number) {
  int nextPrimeNumber = number;
  while (!isPrime(nextPrimeNumber)) {
    nextPrimeNumber += 1;
  }
  return nextPrimeNumber;
}

bool isPrime(int nextPrimeNumber) {
  for (var i = 2; i < nextPrimeNumber; i++) {
    if (nextPrimeNumber % i == 0) return false;
  }
  return true;
}
