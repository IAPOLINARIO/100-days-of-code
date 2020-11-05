fun mergeAndSort(numbers1: List<Int>, numbers2: List<Int>): List<Int> {
    val merged: MutableList<Int> = ArrayList()
    merged.addAll(numbers1)
    merged.addAll(numbers2)
    return merged.sorted()
}

fun stringToIntArray(string: String): List<Int> {
    val miles = string.replace("[","").replace("]","").replace("\"","").replace(" ","").split(",").map { it.toInt() }
    return miles
}
 
fun main() {
    print("\nType a Integer sequence separated by coma (,): ")
    val intArray1 = stringToIntArray(readLine()?.toString() ?: "")
    print("\n\nType a second Integer sequence separated by coma (,): ")
    val intArray2 = stringToIntArray(readLine()?.toString() ?: "")
    
    var sorted = mergeAndSort(intArray1, intArray2)
    print("\n\nHere is the sorted merged sequence: $sorted\n\n")
}