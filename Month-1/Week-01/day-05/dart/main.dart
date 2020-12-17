import 'dart:io';

void main() {
  stdout.writeln('Lets orginize the socks');
  var socks = stdin.readLineSync();

  stdout.writeln('${sockPairs(socks)}');
}

int sockPairs(var socks) {
  int pairsSocks = 0;
  Map<String, int> mapSocks = Map();
  if (socks.length == 0) return pairsSocks;
  socks.toString().runes.forEach((element) {
    var character = new String.fromCharCode(element);
    mapSocks[character] = (mapSocks[character] ?? 0) + 1;

    mapSocks[character].isEven ? pairsSocks++ : pairsSocks;
  });

  return pairsSocks;
}
