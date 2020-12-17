import org.junit.*

class Tests {

    @Test
    fun `Given empty sequence`() {
        // GIVEN
        val sequence = stringToIntArray("")
        val expected = 0

        // WHEN
        val result = calculateTrappedWater(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given invalid sequence`() {
        // GIVEN
        val sequence = stringToIntArray("1*A----01Z")
        val expected = 0

        // WHEN
        val result = calculateTrappedWater(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given simple sequence`() {
        // GIVEN
	val sequence = stringToIntArray("[0,1,0,2,1,0,1,3,2,1,2,1]")
	val expected = 6
        
        // WHEN
        val result = calculateTrappedWater(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given simple sequence two`() {
        // GIVEN
	val sequence = stringToIntArray("[4,2,0,3,2,5]")
	val expected = 9
        
        // WHEN
        val result = calculateTrappedWater(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given complex sequence`() {
        // GIVEN
	val sequence = stringToIntArray("[0,0,1,3,2,1,1,0,3,0,1]")
	val expected = 9
        
        // WHEN
        val result = calculateTrappedWater(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

}