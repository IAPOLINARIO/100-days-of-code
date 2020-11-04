fun calculateProgressDays(miles: List<Int>): Int {
    var previous = Int.MAX_VALUE
    var progressDays = 0
    for (mile in miles) {
        if (mile > previous) progressDays++
        previous = mile
    }
    
    return progressDays
}

fun stringToIntArray(string: String): List<Int> {
    val miles = string.replace("[","").replace("]","").replace("\"","").replace(" ","").split(",").map {
        it.toInt()
    }
    return miles
}

fun main() {
    print("Type the array of miles: ")
    val milesString: String = readLine()?.toString() ?: "[]"
    val miles = stringToIntArray(milesString)
    var progressDays = calculateProgressDays(miles)
    print("You amount of progress days is: $progressDays")
}