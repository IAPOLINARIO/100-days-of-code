# Zip It!

Most data compression algorithms are pretty complex.

But they all have in common that they are taking data that is repeating and only store it once and have a system of knowing how to uncompress them (putting the repeated segments back in place).

## Objective
Design your own data **compress** and **uncompress** techniques. Create these two functions.

**compress** function signature:
- input parameter _data_ as a string
- return de _compressed_ data as a string

**uncompress** function signature:
- input parameter _compressed_ as a string
- return de _uncompressed_ data as a string

## Notes
- It is OK if not every type of input data is capable of compression, but on the tests, it is important to put some examples that prove the reduction of size of the compressed data, and the ability to uncompress back to the original content.