import org.junit.*

class Tests {

    @Test
    fun `Test 28 paths`() {
        // GIVEN
        val expected = 28

        // WHEN
        val result = combination(3, 7)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Test 6 paths`() {
        // GIVEN
        val expected = 6

        // WHEN
        val result = combination(3, 3)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Test 3 paths`() {
        // GIVEN
        val expected = 3

        // WHEN
        val result = combination(3, 2)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Test 1352078 paths`() {
        // GIVEN
        val expected = 1352078

        // WHEN
        val result = combination(12, 13)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Test 70 paths`() {
        // GIVEN
        val expected = 70

        // WHEN
        val result = combination(5, 5)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Test 330 paths`() {
        // GIVEN
        val expected = 330

        // WHEN
        val result = combination(8, 5)
	
        // THEN
        Assert.assertEquals(result, expected)
    }
}