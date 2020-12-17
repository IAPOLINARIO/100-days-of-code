import org.junit.*

class Tests {

    @Test
    fun `Given Neither`() {
        // GIVEN
        val sequence = "[9, 8, 9, 8]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertFalse(mountain)
        Assert.assertFalse(valley)
    } 

    @Test
    fun `Given Neither one`() {
        // GIVEN
        val sequence = "[0, -1, -1, 0, -1, -1]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertTrue(mountain)
        Assert.assertFalse(valley)
    } 

    @Test
    fun `Given Neither two`() {
        // GIVEN
        val sequence = "[5, 4, 3, 2, 1]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertFalse(mountain)
        Assert.assertFalse(valley)
    } 

    @Test
    fun `Given Neither three`() {
        // GIVEN
        val sequence = "[1, 2, 3, 2, 4, 1]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertFalse(mountain)
        Assert.assertFalse(valley)
    } 

    @Test
    fun `Given Valley`() {
        // GIVEN
        val sequence = "[9, 8, 9]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertFalse(mountain)
        Assert.assertTrue(valley)
    } 

    @Test
    fun `Given Valley one`() {
        // GIVEN
        val sequence = "[9, 7, 3, 1, 2, 4]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertFalse(mountain)
        Assert.assertTrue(valley)
    } 

    @Test
    fun `Given Valley two`() {
        // GIVEN
        val sequence = "[350, 100, 200, 400, 700]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertFalse(mountain)
        Assert.assertTrue(valley)
    } 

    @Test
    fun `Given Valley three`() {
        // GIVEN
        val sequence = "[10, 9, 8, 7, 2, 3, 4, 5]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertFalse(mountain)
        Assert.assertTrue(valley)
    }    

    @Test
    fun `Given mountaion`() {
        // GIVEN
        val sequence = "[1, 3, 5, 4, 3, 2]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertTrue(mountain)
        Assert.assertFalse(valley)
    }    


    @Test
    fun `Given mountaion one`() {
        // GIVEN
        val sequence = "[3, 4, 5, 4, 3]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertTrue(mountain)
        Assert.assertFalse(valley)
    }    

    @Test
    fun `Given mountaion two`() {
        // GIVEN
        val sequence = "[-1, -1, 0, -1, -1]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertTrue(mountain)
        Assert.assertFalse(valley)
    }

    @Test
    fun `Given mountaion tree`() {
        // GIVEN
        val sequence = "[-1, 0, -1]"

        // WHEN
        val mountain = isMountain(stringToIntArray(sequence))
	val valley = isValley(stringToIntArray(sequence))

        // THEN
        Assert.assertTrue(mountain)
        Assert.assertFalse(valley)
    }
}