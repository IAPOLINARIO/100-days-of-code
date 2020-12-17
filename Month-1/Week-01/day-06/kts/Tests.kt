import org.junit.*

class Tests {

    @Test
    fun `Given a prime number 13`() {
        // GIVEN
	val given = 13
        
        // WHEN
        val result = nextPrime(given)

        // THEN
        Assert.assertEquals(13, result)
    }

    @Test
    fun `Given a non-prime number 900`() {
        // GIVEN
	val given = 900
        
        // WHEN
        val result = nextPrime(given)

        // THEN
        Assert.assertEquals(907, result)
    }

    @Test
    fun `Given a non-prime number 24`() {
        // GIVEN
	val given = 24
        
        // WHEN
        val result = nextPrime(given)

        // THEN
        Assert.assertEquals(29, result)
    }

    @Test
    fun `Given a non-prime number 0`() {
        // GIVEN
	val given = 0
        
        // WHEN
        val result = nextPrime(given)

        // THEN
        Assert.assertEquals(2, result)
    }

    @Test
    fun `Given a non-prime number 1321234`() {
        // GIVEN
	val given = 1321234
        
        // WHEN
        val result = nextPrime(given)

        // THEN
        Assert.assertEquals(1321247, result)
    }
}