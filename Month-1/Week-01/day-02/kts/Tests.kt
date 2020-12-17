import org.junit.*

class Tests {

    @Test
    fun `Given Sentence I am finding Nemo !`() {
        // GIVEN
	val given = "I am finding Nemo !"
        val expected = "I found Nemo at position: 4!"

        // WHEN
        val result = findaWord(given)

        // THEN
        Assert.assertEquals(expected, result)
    }

    @Test
    fun `Given Sentence Nemo is me`() {
        // GIVEN
	val given = "Nemo is me"
        val expected = "I found Nemo at position: 1!"

        // WHEN
        val result = findaWord(given)

        // THEN
        Assert.assertEquals(expected, result)
    }

    @Test
    fun `Given Sentence I Nemo am`() {
        // GIVEN
	val given = "I Nemo am"
        val expected = "I found Nemo at position: 2!"

        // WHEN
        val result = findaWord(given)

        // THEN
        Assert.assertEquals(expected, result)
    }

    @Test
    fun `Given wrong Sentence I am Memo`() {
        // GIVEN
	val given = "I am Memo"
        val expected = "I can't find Nemo :("

        // WHEN
        val result = findaWord(given)

        // THEN
        Assert.assertEquals(expected, result)
    }

}