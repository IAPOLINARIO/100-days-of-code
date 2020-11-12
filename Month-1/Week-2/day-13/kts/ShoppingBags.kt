fun fitTheItemsInTheBags(allItems: List<Int>, numberOfBags: Int): Boolean {
    val bags = MutableList<Int>(numberOfBags) { 0 }
    val items = allItems.toMutableList()
    items.sortDescending()
    for (b in 0..bags.size-1) {
        var i = 0
        while (i < items.size) {
            val item = items[i]
            if (bags[b] + item <= 10) {
                bags[b] = bags[b] + item
                items.removeAt(i)
            } else {
            	i++
            }
        }
    }
    return items.size == 0
}

fun stringToIntArray(string: String): List<Int> {
    if (string.length == 0) return ArrayList<Int>()
    val list: List<Int> = string.replace("[^0-9\\-\\+\\,]".toRegex(), "").split(",").map { it.toInt() }
    return list
}

fun main() {
    print("\nEnter a sequence of digits that represents the weigth of each item you bought: ")
    val items = stringToIntArray(readLine()?.toString() ?: "")
	print("\nHow many bags do you have?: ")
    val bags = readLine()?.toInt() ?: 4
    
    val canBeStored = fitTheItemsInTheBags(items, bags)
    if (canBeStored) {
        print("\nYou can store all items in the bags")
    } else {
        print("\nUnfortunately you cannot store all your items")
    }
    
}