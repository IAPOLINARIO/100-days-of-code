import 'dart:async';
import 'package:SkewerAnalyzer/SkewerAnalyzer.dart';
import 'package:test/test.dart';

var printedOutput = [];

testablePrintZone(testFn()) => () {
  printedOutput = [];
  var spec = new ZoneSpecification(print: (_, __, ___, String msg) {
    printedOutput.add(msg);
  });
  return Zone.current.fork(specification: spec).run(testFn);
};

void main() {
  test('empty parameter validation', testablePrintZone(() {
    SkewerAnalyzer().analyze([]);
    expect(printedOutput, ["There are no skewers in your barbecue..."]);
  }));

  test('mixed validation', testablePrintZone(() {
    SkewerAnalyzer().analyze([
      "----o-o-ox---",
      "----o-o-o----",
      "----x-x-xx---",
    ]);
    expect(printedOutput, ["Your barbecue has 1 vegetarian skewers and 2 non-veggie skewers."]);
  }));
}
