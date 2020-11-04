import 'dart:async';
import 'package:FindingNemo/FindingNemo.dart';
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
    NemoFinder().findIn([]);
    expect(printedOutput, ["I can't find Nemo :("]);
  }));

  test('could not find nemo validation', testablePrintZone(() {
    NemoFinder().findIn(["128421 9s0f 8a8812 aaa"]);
    expect(printedOutput, ["I can't find Nemo :("]);
  }));

  test('nemo lookalike validation', testablePrintZone(() {
    NemoFinder().findIn(["Trust me I'm NeMo"]);
    expect(printedOutput, ["I can't find Nemo :("]);
  }));

  test('found nemo validation', testablePrintZone(() {
    NemoFinder().findIn(["Where would Nemo be?"]);
    expect(printedOutput, ["I found nemo at 3!"]);
  }));
}
