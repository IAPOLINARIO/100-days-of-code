fun karacasEncrypt(s: String): String {
    var encrypted = s.reversed()
    val encryptKeys = hashMapOf("a" to "0",  "e" to "1", "i" to "2", "o" to "2", "u" to "3")
    for ((k, e) in encryptKeys) {
        encrypted = encrypted.replace(k, e)
    }
    return encrypted + "aca"
}

fun main() {
    println("\nEnter string to be encrypted: ")
    val encrypted = karacasEncrypt(readLine()?.toString() ?: "banana")
	println("\nThe result is: $encrypted")
}