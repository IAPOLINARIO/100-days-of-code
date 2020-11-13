import org.junit.*

class Tests {

    @Test
    fun `Given empty sequence`() {
        // GIVEN
        val sequence = 1
        val expected = 1

        // WHEN
        val result = calculateBinaryTreeCombinations(sequence)

        // THEN
        Assert.assertEquals(expected, result)
    }

    @Test
    fun `Given invalid sequence`() {
        // GIVEN
        val sequence = 0
        val expected = 1

        // WHEN
        val result = calculateBinaryTreeCombinations(sequence)

        // THEN
        Assert.assertEquals(expected, result)
    }

    @Test
    fun `Given simple sequence`() {
        // GIVEN
        val sequence = 3
        val expected = 5

        // WHEN
        val result = calculateBinaryTreeCombinations(sequence)

        // THEN
        Assert.assertEquals(expected, result)
    }

    @Test
    fun `Given simple sequence two`() {
        // GIVEN
        val sequence = 4
        val expected = 14

        // WHEN
        val result = calculateBinaryTreeCombinations(sequence)

        // THEN
        Assert.assertEquals(expected, result)
    }

    @Test
    fun `Given complex sequence`() {
        // GIVEN
        val sequence = 19
        val expected = 1767263190

        // WHEN
        val result = calculateBinaryTreeCombinations(sequence)

        // THEN
        Assert.assertEquals(expected, result)
    }

}