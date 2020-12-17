import org.junit.*

class Tests {

    @Test
    fun `Freed four prisioners`() {
        // GIVEN
        val expected = 4

        // WHEN
        val cells = stringToIntArray("1, 1, 0, 0, 0, 1, 0")
        val result = freePrisioners(cells)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Freed one prisioner`() {
        // GIVEN
        val expected = 1

        // WHEN
        val cells = stringToIntArray("1, 1, 1")
        val result = freePrisioners(cells)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Freed zero prisioners`() {
        // GIVEN
        val expected = 0

        // WHEN
        val cells = stringToIntArray("0, 1, 1")
        val result = freePrisioners(cells)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Freed five prisioners`() {
        // GIVEN
        val expected = 5

        // WHEN
        val cells = stringToIntArray("1, 1, 0, 0, 0, 1, 0, 1")
        val result = freePrisioners(cells)
	
        // THEN
        Assert.assertEquals(result, expected)
    }

    @Test
    fun `Freed eight prisioners`() {
        // GIVEN
        val expected = 8

        // WHEN
        val cells = stringToIntArray("1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0")
        val result = freePrisioners(cells)
	
        // THEN
        Assert.assertEquals(result, expected)
    }
   
     
}