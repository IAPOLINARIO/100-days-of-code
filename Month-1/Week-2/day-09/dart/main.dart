import 'dart:io';
import 'dart:convert';
import 'dart:math';

void main() {
  stdout.writeln('Gimme the Elevation Map');
  var elevMap = stdin.readLineSync();

  stdout.writeln('${elevationMap(elevMap)}');
}

int elevationMap(var arrElevMap) {
  List lstEvelMap = json.decode(arrElevMap);
  int result = 0;
  int size = lstEvelMap.length;

  for (int i = 1; i < size - 1; i++) {
    int left =
        List<int>.from(lstEvelMap.sublist(0, i)).fold(lstEvelMap[i], max);
    int right = List<int>.from(lstEvelMap.sublist(i)).reduce((max));

    result += min(left, right) - lstEvelMap[i];
  }
  return result;
}
