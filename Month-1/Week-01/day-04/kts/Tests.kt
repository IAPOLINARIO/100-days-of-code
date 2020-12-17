import org.junit.*

class Tests {

    @Test
    fun `Given two progress days`() {
        // GIVEN
	val given = listOf(3, 4, 1, 2)
        
        // WHEN
        val result = calculateProgressDays(given)

        // THEN
        Assert.assertEquals(2, result)
    }

    @Test
    fun `Given three progress days`() {
        // GIVEN
	val given = listOf(10, 11, 12, 9, 10)
        
        // WHEN
        val result = calculateProgressDays(given)

        // THEN
        Assert.assertEquals(3, result)
    }

    @Test
    fun `Given one progress day`() {
        // GIVEN
	val given = listOf(6, 5, 4, 3, 2, 9)
        
        // WHEN
        val result = calculateProgressDays(given)

        // THEN
        Assert.assertEquals(1, result)
    }

    @Test
    fun `Given no progress days`() {
        // GIVEN
	val given = listOf(9,9,9)
        
        // WHEN
        val result = calculateProgressDays(given)

        // THEN
        Assert.assertEquals(0, result)
    }
}