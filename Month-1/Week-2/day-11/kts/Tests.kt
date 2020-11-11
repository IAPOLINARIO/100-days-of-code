import org.junit.*

class Tests {

    @Test
    fun `Given sequence one`() {
        // GIVEN
        val sequence = "25525511135"
        val expected = "[255.255.11.135, 255.255.111.35]"

        // WHEN
        val result = createAllCombinationsOf(sequence)

        // THEN
        Assert.assertEquals(expected, result.toString())
    }

        @Test
    fun `Given sequence two`() {
        // GIVEN
        val sequence = "0000"
        val expected = "[0.0.0.0]"

        // WHEN
        val result = createAllCombinationsOf(sequence)

        // THEN
        Assert.assertEquals(expected, result.toString())
    }

    @Test
    fun `Given sequence three`() {
        // GIVEN
        val sequence = "1111"
        val expected = "[1.1.1.1]"

        // WHEN
        val result = createAllCombinationsOf(sequence)

        // THEN
        Assert.assertEquals(expected, result.toString())
    }

    @Test
    fun `Given sequence four`() {
        // GIVEN
        val sequence = "010010"
        val expected = "[0.10.0.10, 0.100.1.0]"

        // WHEN
        val result = createAllCombinationsOf(sequence)

        // THEN
        Assert.assertEquals(expected, result.toString())
    }

    @Test
    fun `Given sequence five`() {
        // GIVEN
        val sequence = "101023"
        val expected = "[1.0.10.23, 1.0.102.3, 10.1.0.23, 10.10.2.3, 101.0.2.3]"

        // WHEN
        val result = createAllCombinationsOf(sequence)

        // THEN
        Assert.assertEquals(expected, result.toString())
    }

}