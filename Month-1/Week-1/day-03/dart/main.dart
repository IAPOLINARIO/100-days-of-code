import 'dart:io';

void main() {
  stdout.writeln('How do you wanna your skewers');
  String skewers = stdin.readLineSync();

  stdout.writeln('${barbecueSkewers(skewers)}');
}

String barbecueSkewers(String skewers) {
  var skewer = skewers.split(',');
  int meatskewers = skewer.where((element) => element.contains('x')).length;
  int veganskewers = skewer.length - meatskewers;
  return '[${veganskewers} vegetarian skewers, ${meatskewers} non-vegetarian skewers]';
}
