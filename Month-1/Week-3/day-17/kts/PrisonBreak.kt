fun Boolean.toInt() = if (this) 1 else 0

fun freePrisioners(cells: List<Int>): Int {
    if (cells.first() == 0) {
        return 0
    }
    
    var unlock = true
    var count = 0
    
    for (cell in cells) {
    	if (cell == unlock.toInt()) {
            count++
            unlock = !unlock
        }   
    }
    
    return count
}

fun stringToIntArray(string: String): List<Int> {
    if (string.length == 0) return ArrayList<Int>()
    val list: List<Int> = string.replace("[^0-9\\-\\+\\,]".toRegex(), "").split(",").map { it.toInt() }
    return list
}

fun main() {
    println(":::Prison Break:::")
    println("\nEnter the representation of cells: ")
    val cells = stringToIntArray(readLine()?.toString() ?: "[1, 1, 0, 0, 0, 1, 0]")
    
    val freedPrisioners = freePrisioners(cells)

    if (freedPrisioners > 0) {
	println("\n$freedPrisioners prisioners was freed!")
    } else {
       println("\nNo one was freed")
    }   
}