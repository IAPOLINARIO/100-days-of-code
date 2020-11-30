# Dog and Gopher

A large field has a dog and a gopher.

The dog wants to eat the gopher, while the gopher wants to run to safety through one of several gopher holes dug in the surface ofthe field.

Neither the dog nor the gopher is a math major; however, neither is entirely stupid.

The gopher decides on a particular gopher hole and heads for that hole in a straight line at a fixed speed. The dog, which is very good at reading body language, anticipates which hole the gopher has chosen. 

The dog heads at double the speed of the gopher to the hole. If the dog reaches the hole first, the gopher gets gobbled up; otherwise, the gopher escapes.

## Objective
You have been retained by the gopher to **select a hole through which it can escape**, if such a hole exists, by **reading a file with a variable set of scenarios**.

Some sample files are already provided to help the tests:
```text
assets/day-35_sample_1_valid.txt
assets/day-35_sample_2_valid.txt
assets/day-35_sample_3_invalid.txt
assets/day-35_sample_4_invalid.txt
assets/day-35_sample_5_invalid.txt
assets/day-35_sample_6_invalid.txt
``` 

Write a **gopherEscapePlan** function which returns a list/array of strings, with one entry per result of each set of scenarios.

The function has one input parameter:
- **filename**: a string representing the path to the file

The function returns:
- List/array of strings, with one entry per result of each set of scenarios or a BAD FILE! message if the file is invalid or inaccessible. See section **Output** below for more details.

## Input file format

The input file contains several sets of input. The first line of each set contains **one integer** and **four floating point numbers**. 

The integer **n** denotes how many holes are in the set.
The **four floating point numbers** denote the **(x, y) coordinates of the gopher** followed by the **(x, y) coordinates of the dog**. 

The subsequent **n** lines of input each contain **two floating point numbers**: the **(x, y) coordinates of a gopher hole**. All distances are in meters to the nearest millimeter. 

The input is **terminated by end of file** and **there is a blank line between two consecutive sets**.

The input file is still considered **valid** if there is more than one **blank line between two consecutive sets** or if there are **blank lines at the beginning of the file** as well.

## Output
Return a single line for *each set* of input.

If the gopher can escape, the output line should read, _“The gopher can escape through the hole at (x, y).”_ while identifying the appropriate hole to the nearest millimeter. 

Otherwise, the output line should read, _“The gopher cannot escape.”_ 

If the gopher can escape through more than one hole, report the one that appears **first in the input**. 

if the file is **inaccessible or invalid** (for example, **number of holes** found don't match **n** or there are more or less fields found on a line in the file), return just an **["BAD FILE!"]**.



## Constraints
There are at most 1,000 gopher holes in a set of input and all coordinates range between –10,000 and +10,000.



### Example of input file
```text
1.000 1.000 2.000 2.000
1.500 1.500

2 2.000 2.000 1.000 1.000
1.500 1.500
2.500 2.500
```

### Expected return
```text
["The gopher cannot escape.", "The gopher can escape through the hole at (2.500,2.500)."]
```


### Examples with the provided sample files avaliable at 'assets' folder
```text
gopherEscapePlan("...assets/day-35_sample_1_valid.txt") ➞ ["The gopher cannot escape.", "The gopher can escape through the hole at (2.500000,2.500000)."]

gopherEscapePlan("...assets/day-35_sample_2_valid.txt") ➞ ["The gopher cannot escape.", "The gopher can escape through the hole at (2.500000,2.500000)."]

gopherEscapePlan("...assets/day-35_sample_3_invalid.txt") ➞ ["BAD FILE!"]

gopherEscapePlan("...assets/day-35_sample_4_invalid.txt") ➞ ["BAD FILE!"]

gopherEscapePlan("...assets/day-35_sample_5_invalid.txt") ➞ ["BAD FILE!"]
```