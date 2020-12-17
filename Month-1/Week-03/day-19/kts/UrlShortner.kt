val storage: MutableMap<String, String> = mutableMapOf()

fun encode(url: String): String {
    if (!isValid(url)) return "invalid URL"

    var newID = createRandomString()
    while (storage.containsKey(newID)) {
        newID = createRandomString()
    }
    storage.put(newID, url)
    return "http://nuc.ci/$newID"
}

fun decode(url: String): String {
    val tokens = url.split("/")
    if (storage.containsKey(tokens.last())) {
        return storage.get(tokens.last())!!
    }
    return "URL not found"
}

fun createRandomString(): String {
    val randomString = StringBuilder()
    for (i in 0..8) {
        randomString.append('a' + (0..25).random())
    }
    return randomString.toString()
}

fun isValid(url: String): Boolean {
    val regex = "((http|https):\\/\\/)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)".toRegex()
    return regex.containsMatchIn(url)
}

fun main() {
    println(":::URL Shortner:::")
    println("\nEnter a valid URL (starting with http:// or https://): ")
    val url = readLine()?.toString() ?: ""
	val encoded = encode(url)
    println(">> $encoded")

    println("\n\nYou can try to decode it, type de short url you got: ")
    val short = readLine()?.toString() ?: ""
	val decoded = decode(short)
    println(">> $decoded")
}
