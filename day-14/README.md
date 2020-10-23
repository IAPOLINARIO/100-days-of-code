## The Karaca's Encryption Algorithm

Make a function that encrypts a given input with these steps:

Input: `"apple"`

Step 1: Reverse the input: `"elppa"`

Step 2: Replace all vowels using the following chart:

```text
a => 0
e => 1
i => 2
o => 2
u => 3

// "1lpp0"
```

Step 3: Add "aca" to the end of the word: `"1lpp0aca"`

Output: `"1lpp0aca"`

### Example

```text
Encrypt("banana") ➞ "0n0n0baca"

Encrypt("karaca") ➞ "0c0r0kaca"

Encrypt("burak") ➞ "k0r3baca"

Encrypt("alpaca") ➞ "0c0pl0aca"
```

---

### Notes

- All inputs are strings, no uppercases and all output must be strings.
