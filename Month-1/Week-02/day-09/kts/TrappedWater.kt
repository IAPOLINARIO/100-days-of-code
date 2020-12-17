fun calculateTrappedWater(heights: List<Int>): Int {
    if (heights.size < 1) return 0     

    var leftIndex = 0
    var rightIndex = heights.size-1
    var leftTop = 0
    var rightTop = 0 
    
    var totalWaterTrapped = 0
    
    while (leftIndex <= rightIndex) {
        
        leftTop = Math.max(leftTop, heights[leftIndex])
        rightTop = Math.max(rightTop, heights[rightIndex])
        
        if (leftTop < rightTop) {
            totalWaterTrapped += (leftTop - heights[leftIndex]) 
            leftIndex++
        } else {
            totalWaterTrapped += (rightTop - heights[rightIndex])
            rightIndex--
        }
    }
    
    return totalWaterTrapped
}

fun stringToIntArray(string: String): List<Int> {
    if (string.isEmpty()) return ArrayList()
    val miles = string.replace("[^0-9\\,]".toRegex(), "").split(",").map { it.toInt() }
    return miles
}
 
fun main() {
    print("\nType a Integer sequence separated by coma (,): ")
    val heights = stringToIntArray(readLine()?.toString() ?: "")
    var trappedWater = calculateTrappedWater(heights)
    print("\n\nHere's the amount of water trapped: $trappedWater\n\n")
}