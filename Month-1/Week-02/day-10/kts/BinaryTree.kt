fun calculateBinaryTreeCombinations(n: Int): Int {
	val combinations = MutableList(n + 1) { 1 }
	
    for (i in 2..n) {
        var result = 0
        for (j in 0..(i - 1)) {
            result += combinations[j] * combinations[i - j - 1]
        }
        combinations[i] = result
    }

    return combinations[n]
}

fun main() {
    print("\nType a number o itens in the tree: ")
    val combinations = calculateBinaryTreeCombinations(readLine()?.toInt() ?: 0)
    print("\n\nThe total number of unique combinations is: $combinations\n\n")
}