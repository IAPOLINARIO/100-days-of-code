import 'dart:io';
import 'dart:convert';

void main() {
  stdout.writeln('Let me know your Progress');
  var running = stdin.readLineSync();
  var lists = jsonDecode(running);

  stdout.writeln('${progressDays(lists)}');
}

int progressDays(List lists) {
  int totalProgressDay = 0;
  Iterator<dynamic> iterator = lists.iterator;
  iterator.moveNext();
  int currentDay = iterator.current;
  while (iterator.moveNext()) {
    if (iterator.current > currentDay) {
      totalProgressDay++;
    }
    currentDay = iterator.current;
  }
  return totalProgressDay;
}
