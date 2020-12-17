## Traffic Light Checker

A three-color traffic light must switch lights in the following order: red, green, yellow, red.

To indicate when crossing slowly without a stop is permitted, the yellow signal may be flashed. To indicate when crossing immediately after a full stop is permitted, the red signal may be flashed.

Either flash sequence may only be started after the red light is lit and must be followed with a red. All lights are initially off. All sequences must begin a red light. Lighting any light causes all other lights to turn off. No color may be repeated: e.g., red, red is not allowed.

## The problem

Write a program that checks a sequence of light codes and determines if that sequence follows or violates the traffic light rules.

Input Read from STDIN a sequence of the follow codes: R (red), Y (yellow), G (Green), P (Pause - flash red), C (Caution - flash yellow), and X (off). Each code must be separated with a space. The entire sequence is submitted by an end-of-line (e.g., pressing the Enter key.) A sequence must have no more than 15 codes in total.

## Examples

```text
1 - Input: R G Y R C R G Y R                  Output: ACCEPT
2 - Input: G Y R G Y R                        Output: REJECT
3 - Input: R Y G P                            Output: REJECT
4 - Input: R G Y                              Output: ERROR
5 - Input: X 8 S                              Output: ERROR
6 - Input: R G Y R C R P R G Y R G Y R G Y R  Output: ERROR
```

**Explanation**
1 - Correct
2 - Doesn’t start with R
3 - Invalid sequence
4 - Undefined code
5 - Undefined Codes e.g. X is not part of the grammar
6 - The input is malformed – undefined code, too short, too long, etc

## Contraints

Output Write to STDOUT an evaluation of the sequence:

- ACCEPT >> The entire input sequence meets all rules.

- REJECT >> The input sequence violates any sequence constraint; for example G Y.

- ERROR >> The input is malformed – undefined code, too short, too long, etc.
