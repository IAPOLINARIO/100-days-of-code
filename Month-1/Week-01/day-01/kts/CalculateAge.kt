fun calculateAgeInDays(days: Int?): Int {
    val totalDays = days ?: 0
    return totalDays*365
}

fun main() {
    print("Type your age in years: ")
    var age: Int? = readLine()?.toInt()
    var days = calculateAgeInDays(age)
    print("You age in days are: $days \n")
}