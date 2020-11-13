fun isMountain(s: List<Int>): Boolean {
    val sequence = s.toMutableList()
    var goingUp = true
    var climbing = false
    var result = true
    
    var previous = sequence[0]
    sequence.removeAt(0)
    for (n in sequence) {
        if (goingUp && previous > n && climbing) {
            goingUp = false
        } else if (!goingUp && previous < n || !climbing && previous > n) {
            result = false
            break
        }
        previous = n
        climbing = true
    }
    return result && !goingUp
}

fun isValley(s: List<Int>): Boolean {
    val sequence = s.toMutableList()
    var goingUp = false
    var climbing = false
    var result = true
    
    var previous = sequence[0]
    sequence.removeAt(0)
    println(previous)
    for (j in sequence) {
        print(j)
        if (!goingUp && previous < j && climbing) {
            println("turn around")
            goingUp = true
        } else if (goingUp && previous > j || !climbing && previous < j) {
            println("gotcha!")
            result = false
            break
        }
        previous = j
        climbing = true
    }
    return result && goingUp
}

fun stringToIntArray(string: String): List<Int> {
    if (string.length == 0) return ArrayList<Int>()
    val list: List<Int> = string.replace("[^0-9\\-\\+\\,]".toRegex(), "").split(",").map { it.toInt() }
    return list
}

fun main() {
    print("\nEnter a sequence of digits that will be validated as Mountain or Valley: ")
    val sequence = stringToIntArray(readLine()?.toString() ?: "")
    if (isMountain(sequence)) {
        print("\n\n::This sequence represents a Mountain::\n\n")
    } else if (isValley(sequence)) {
        print("\n\n::This sequence represents a Valley::\n\n")
    } else {
        print("\n\n::This sequence represents neither mountain nor valley::\n\n")    
    }
}