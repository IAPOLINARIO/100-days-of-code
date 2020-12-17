fun calculatePairs(socks: String): Int {
    var kindOfSocks = hashMapOf<Char, Int>()
    var numberOfPairs = 0
    
    for (sock in socks) {
    	if (kindOfSocks.containsKey(sock)) {
            kindOfSocks[sock] = kindOfSocks[sock]!! + 1
        } else {
            kindOfSocks[sock] = 1
        }
    }
    
    for ((_, amount) in kindOfSocks) {
        numberOfPairs += amount.div(2).toInt()
    }

    return numberOfPairs
}

fun main() {
    print("How are your socks organized?: ")
    val socks: String = readLine()?.toString() ?: ""
    var pairs = calculatePairs(socks)
    print("You have $pairs pair(s) of sock(s)")
}