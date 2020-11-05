import 'dart:io';
import 'dart:convert';

void main() {
  stdout.writeln('Gimme the First Array');
  var nums1 = stdin.readLineSync();

  stdout.writeln('Gimme the Second Array');
  var nums2 = stdin.readLineSync();

  stdout.writeln('${sortedArray(nums1, nums2)}');
}

List sortedArray(var nums1, var nums2) {
  List lstnums1 = json.decode(nums1);
  List lstnums2 = json.decode(nums2);

  lstnums1.removeRange(lstnums2.length, lstnums1.length);
  lstnums1.addAll(lstnums2);
  lstnums1.sort();

  return lstnums1;
}
