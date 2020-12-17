fun checkWin(n: Int): Boolean {
    return (n % 4 != 0)
}

fun main() {
    println(":::NIM GAME:::")
    println("\nEnter the number of Stones (you will start the game): ")
    val n = readLine()?.toInt() ?: 4
    if (n == 0) println("\nZero is not a valid game") else {
        val result = checkWin(n)
        if (result) {
            println("You can Win this game")
        } else {
            println("You will probably lose this game")
        }    
    }
}