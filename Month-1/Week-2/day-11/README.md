## Restore IP Addresses

Given a string s containing only digits, return all possible valid IP addresses that can be obtained from s. You can return them in **any** order.

A **valid IP address** consists of exactly four integers, each integer is between 0 and 255, separated by single dots and cannot have leading zeros. For example, "0.1.2.201" and "192.168.1.1" are **valid** IP addresses and "0.011.255.245", "192.168.1.312" and "192.168@1.1" are **invalid** IP addresses.

### Examples

**Example 1:**

```text
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
```

**Example 2:**

```text
Input: s = "0000"
Output: ["0.0.0.0"]
```

**Example 3:**

```text
Input: s = "1111"
Output: ["1.1.1.1"]
```

**Example 4:**

```text
Input: s = "010010"
Output: ["0.10.0.10","0.100.1.0"]
```

**Example 5:**

```text
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

### Constraints

- `0 <= s.length`
- `s consists of digits only.`
- `Ipv4 format only.`

---

### Notes

- `All digits in string s MUST be used to obtain each valid IP`
