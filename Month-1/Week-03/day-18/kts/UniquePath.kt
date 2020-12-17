fun combination(m: Int, n: Int): Int {
    val result = IntArray(m) { 0 }
    result[result.lastIndex] = 1

    for (row in (n-1) downTo 0){
       	for (col in (m-1) downTo 0){
        	result[col] += result.getOrElse(col + 1) { 0 }
        }
    }

    return result[0]
}


fun main() {
    println(":::Unique Paths:::")
    println("\nEnter the representation of a M x N matix - M: ")
    val m = readLine()?.toInt() ?: 10
    print("   N: ")
    val n = readLine()?.toInt() ?: 10
    val combinations = combination(m, n)
    
    println("\n\nThe number of combinations is: $combinations")
}