object Constants {
    const val WORD_TO_FIND = "Nemo"
}

fun findaWord(sentence: String): String {
	var position: Int = 0
    val wordsList = sentence.split("\\s".toRegex())
    for (word in wordsList) {
        position++
        if (word.equals(Constants.WORD_TO_FIND)) {
            return "I found " + Constants.WORD_TO_FIND + " at position: $position!"
        }
    }
    return "I can't find " + Constants.WORD_TO_FIND + " :("
}

fun main() {
    print("Type the sentence and we'll search for " + Constants.WORD_TO_FIND + ": ")
    val sentence: String = readLine()?.toString() ?: ""
    print("\n\nWe are loofing for " + Constants.WORD_TO_FIND + "...")
    val response = findaWord(sentence) 
    print("\n\n$response")
}