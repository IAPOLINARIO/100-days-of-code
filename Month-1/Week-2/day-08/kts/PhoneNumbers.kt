fun lettersFromDigit(digit: Char): List<Char> {
    val from = 97 + (3 * (digit - '2')) + if (digit.toInt() > 55) 1 else 0
    val to = from + if (digit == '7' || digit == '9') 3 else 2
    val letters: MutableList<Char> = ArrayList()
    for (i in from..to) letters.add(i.toChar())
    return letters
}
    
fun createCombitaion(listOfCombinations: List<String>, chars: List<Char>): List<String> {
    val result: MutableList<String> = ArrayList()
    for (comb in listOfCombinations) for (char in chars) result.add(comb + char)
    return result
}

fun letterCombinations(digits: String): List<String> {
    var listOfCombinations: List<String> = listOf("")
    val chars = digits.replace("[^2-9]".toRegex(), "").toCharArray()
    for (c in chars) listOfCombinations = createCombitaion(listOfCombinations, lettersFromDigit(c))
    return listOfCombinations
}

fun main() {
    print("\nType a sequence of numbers: ")
    val sequence = readLine()?.toString() ?: "0123"
    var result = letterCombinations(sequence)
    print("\n\nHere's the list of all possible combinations: $result\n\n")
}