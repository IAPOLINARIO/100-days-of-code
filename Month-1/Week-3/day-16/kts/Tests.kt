import org.junit.*

class Tests {

    @Test
    fun `Given false 4`() {
        // GIVEN
        val n = 4

        // WHEN
        val result = checkWin(n)
	
        // THEN
        Assert.assertFalse(result)
    }

    @Test
    fun `Given false 8`() {
        // GIVEN
        val n = 8

        // WHEN
        val result = checkWin(n)
	
        // THEN
        Assert.assertFalse(result)
    }

    @Test
    fun `Given false 1500`() {
        // GIVEN
        val n = 1500

        // WHEN
        val result = checkWin(n)
	
        // THEN
        Assert.assertFalse(result)
    }
    
    @Test
    fun `Given true 1`() {
        // GIVEN
        val n = 1

        // WHEN
        val result = checkWin(n)
	
        // THEN
        Assert.assertTrue(result)
    }

    @Test
    fun `Given true 7`() {
        // GIVEN
        val n = 7

        // WHEN
        val result = checkWin(n)
	
        // THEN
        Assert.assertTrue(result)
    }

    @Test
    fun `Given true 10`() {
        // GIVEN
        val n = 10

        // WHEN
        val result = checkWin(n)
	
        // THEN
        Assert.assertTrue(result)
    }

    @Test
    fun `Given true 122`() {
        // GIVEN
        val n = 122

        // WHEN
        val result = checkWin(n)
	
        // THEN
        Assert.assertTrue(result)
    }

    @Test
    fun `Given true 759`() {
        // GIVEN
        val n = 759
        // WHEN
        val result = checkWin(n)
	
        // THEN
        Assert.assertTrue(result)
    }
     
}