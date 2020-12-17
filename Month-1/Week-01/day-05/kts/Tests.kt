import org.junit.*

class Tests {

    @Test
    fun `Given one pair`() {
        // GIVEN
	val given = "AA"
        
        // WHEN
        val result = calculatePairs(given)

        // THEN
        Assert.assertEquals(1, result)
    }

    @Test
    fun `Given two pairs`() {
        // GIVEN
	val given = "ABAB"
        
        // WHEN
        val result = calculatePairs(given)

        // THEN
        Assert.assertEquals(2, result)
    }

    @Test
    fun `Given four pairs`() {
        // GIVEN
	val given = "CABBACCC"
        
        // WHEN
        val result = calculatePairs(given)

        // THEN
        Assert.assertEquals(4, result)
    }

    @Test
    fun `Given no pairs`() {
        // GIVEN
	val given = ""
        
        // WHEN
        val result = calculatePairs(given)

        // THEN
        Assert.assertEquals(0, result)
    }

    @Test
    fun `Given even pairs`() {
        // GIVEN
	val given = "ABABABCCC"
        
        // WHEN
        val result = calculatePairs(given)

        // THEN
        Assert.assertEquals(3, result)
    }
}