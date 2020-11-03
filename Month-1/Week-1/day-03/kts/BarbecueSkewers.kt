object Constants {
    const val VEGAN: String = "o"
    const val NOT_VEGAN: String = "x"

}

fun bbqReader(bbq: String): Pair<Int, Int> {
    var nonVeganSkewerCount = 0
    var veganSkewerCount = 0
    
	val skewers = bbq.replace("[","").replace("]","").replace("\"","").replace(" ","").split(",")
    for (skewer in skewers) {
        if ("x" in skewer) { nonVeganSkewerCount++ }
        else if ("o" in skewer) { veganSkewerCount++ }
    }
    return Pair(veganSkewerCount, nonVeganSkewerCount)
}

fun main() {
    print("Type how your BBQ grill looks like: ")
    val bbq: String = readLine()?.toString() ?: "[]"
    val (vegan, nonVegan) = bbqReader(bbq)
    print("\n\nYou have $vegan vegan and $nonVegan non-vegan skewers")
}