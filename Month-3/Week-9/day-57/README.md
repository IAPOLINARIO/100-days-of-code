# Magic Sigil Generator

A magic sigil is a glyph which represents a desire one wishes to manifest in their lives. There are many ways to create a sigil, but the most common is to write out a specific desire (e.g. "I HAVE WONDERFUL FRIENDS WHO LOVE ME"), remove all vowels, remove any duplicate letters (keeping the last occurence), and then design a glyph from what remains.

Using the sentence above as an example, we would remove duplicate letters:

```text
AUFRINDSWHLOVME
```
And then remove all vowels, leaving us with:

```text
FRNDSWHLVM
```

Create a function that takes a string and removes its vowels and duplicate letters. The returned string should not contain any spaces and be in uppercase.

## Examples
```text
sigilize("i am healthy") ➞ "MLTHY"

sigilize("I FOUND MY SOULMATE") ➞ "FNDYSLMT"

sigilize("I have a job I enjoy and it pays well") ➞ "HVBJNDTPYSWL"
```

## Notes
- For duplicate letters the last one is kept.