fun isPrime(number: Int): Boolean {
    for (i in 2..number-1) if (number.rem(i.toDouble()) == 0.0) return false
    return number > 1
}

fun nextPrime(number: Int): Int {
    var prime = number
    while (!isPrime(prime)) prime++
    return prime
}
 
fun main() {
    print("\nType a number: ")
    val number: Int = readLine()?.toString()?.toInt() ?: 0
    var prime = nextPrime(number)
    print("\n\nThe next possible prime is: $prime\n\n")
}