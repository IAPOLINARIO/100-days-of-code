# Zip It!

Most data compression algorithms are pretty complex.

But they all have in common that they are taking data that is repeating and only store it once and have a system of knowing how to uncompress them (putting the repeated segments back in place).

## Objective
Design your own data **compress** and **uncompress** techniques. Create these two functions.

**compress** function signature:
- input parameter _sourceFilename_ with the source filename to compress
- input parameter _targetFilename_ with the target filename compressed

The **compress** function should generate a _targetFilename_ file, compressed.

**uncompress** function signature:
- input parameter _sourceFilename_ with the compressed source filename
- input parameter _targetFilename_ with the target filename uncompressed

The **compress** function should generate a _targetFilename_ file, uncompressed.

## Notes
- It is OK if not every type of input data is capable of compression, but on the tests, it is important to garantee the generated compressed file is smaller than the original and also garantee the uncompress process, from a compressed file to its uncompressed, original version.