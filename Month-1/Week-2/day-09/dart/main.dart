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
    int left = lstEvelMap[i];
    for (int j = 0; j < i; j++) {
      left = max(left, lstEvelMap[j]);
    }

    int right = lstEvelMap[i];
    for (int j = i + 1; j < size; j++) {
      right = max(right, lstEvelMap[j]);
    }

    result += min(left, right) - lstEvelMap[i];
  }
  return result;
}
