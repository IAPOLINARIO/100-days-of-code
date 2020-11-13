import 'package:test/test.dart';

import '../main.dart';

void main() {
  test('[0,1,0,2,1,0,1,3,2,1,2,1] = 6', () {
    int expected = 6;
    String elevMap = '[0,1,0,2,1,0,1,3,2,1,2,1]';

    expect(elevationMap(elevMap), expected);
  });

  test('[4,2,0,3,2,5] = 9', () {
    int expected = 9;
    String elevMap = '[4,2,0,3,2,5]';

    expect(elevationMap(elevMap), expected);
  });

  test('[3,0,2,0,4] = 7', () {
    int expected = 7;
    String elevMap = '[3,0,2,0,4]';

    expect(elevationMap(elevMap), expected);
  });
}
