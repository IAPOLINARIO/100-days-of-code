# The Time in Words

Given the time in numerals we may convert it into words, as shown below: 

<p align="left">
  <img src="../../../assets/The Time in Words.png" alt="The Time in Words">
</p>

## Details

At *minutes = 0*, use o' clock. For *1 <= minutes <= 30*, use past, and for *30 < minutes* use to. Note the space between the apostrophe and clock in o' clock. 

Write a **timeInWords** function which prints the time in words for the input given in the format described. 
The function has the following parameters:
- **h**: an integer representing hour of the day
- **m**: an integer representing minutes after the hour

## Constraints
- *1 <= h <= 12*
- *0 <= m < 60*

### Examples
```text
timeInWords(5, 47) ➞ thirteen minutes to six
timeInWords(3, 00) ➞ three o' clock
timeInWords(7, 15) ➞ quarter past seven
timeInWords(5, 30) ➞ half past five
timeInWords(5, 01) ➞ one minute past five
```
