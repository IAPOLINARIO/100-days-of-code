fun checkAnagram(s: String, t: String): Boolean {
   	val sSorted = s.toCharArray().sorted().joinToString("")
    val tSorted = t.toCharArray().sorted().joinToString("")
    
    return sSorted == tSorted
}

fun main() {
    println("\nEnter the first string to be compared: ")
    val s = readLine()?.toString() ?: ""
    
    println("\nEnter the second string to be compared: ")
    val t = readLine()?.toString() ?: ""
	
    val result = checkAnagram(s, t)

    println("\nThe result is: $result")
}