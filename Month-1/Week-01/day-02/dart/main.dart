import 'dart:io';

void main() {
  stdout.writeln('Make a Sentence - You can use Nemo');
  String sentence = stdin.readLineSync();

  stdout.writeln('${findNemo(sentence)}');
}

String findNemo(String sentence) {
  var foundNemo = 'I found Nemo at';
  var notFoundNemo = 'I can\'t find Nemo';

  var phrase = sentence.split(' ');
  int index = phrase.indexWhere((element) => element == 'Nemo');
  return index == -1 ? notFoundNemo : '${foundNemo} ${index + 1}';
}
