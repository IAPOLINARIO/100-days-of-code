fun createAllCombinationsOf(ipAddress: String): List<String> {
    val result: MutableList<String> = ArrayList()

    for (i in 1..3)
    for (j in 1..3)
    for (k in 1..3)
    for (l in 1..3) {
        if (i+j+k+l == ipAddress.length) {
            val a = ipAddress.substring(0, i)
            val b = ipAddress.substring(i, i+j)
            val c = ipAddress.substring(i+j, i+j+k)
            val d = ipAddress.substring(i+j+k, i+j+k+l)
            if (valid(a) && valid(b) && valid(c) && valid(d)) 
            	result.add(listOf(a,b,c,d).joinToString(separator = "."))
        }    
    }

    return result
}

fun valid(number: String): Boolean {
    val n = number.toInt()
    if (number.get(0) == '0' && number.length > 1) return false
    return n > -1 && n < 256
}

fun clearString(string: String): String {
    val clearString = string.replace("[^0-9]".toRegex(), "")
    return clearString
}

fun main() {
    print("\nEnter a sequence of digits that will be validated in IP adresses: ")
    val clearString = clearString(readLine()?.toString() ?: "")
    val ips = createAllCombinationsOf(clearString)
    print("\n\nthis are all the possivel IP adresses: $ips\n\n")
}