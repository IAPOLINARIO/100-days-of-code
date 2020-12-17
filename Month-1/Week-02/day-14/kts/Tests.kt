import org.junit.*

class Tests {

    @Test
    fun `Given string banana`() {
        // GIVEN
        val string = "banana"

        // WHEN
        val result = karacasEncrypt(string)
	val expected = "0n0n0baca"
	
        // THEN
        Assert.assertEquals(result, expected)
    } 

    @Test
    fun `Given string karaca`() {
        // GIVEN
        val string = "karaca" 

        // WHEN
        val result = karacasEncrypt(string)
	val expected = "0c0r0kaca"
	
        // THEN
        Assert.assertEquals(result, expected)
    } 

    @Test
    fun `Given string burak`() {
        // GIVEN
        val string = "burak" 

        // WHEN
        val result = karacasEncrypt(string)
	val expected = "k0r3baca"
	
        // THEN
        Assert.assertEquals(result, expected)
    } 

    @Test
    fun `Given string alpaca`() {
        // GIVEN
        val string = "alpaca" 

        // WHEN
        val result = karacasEncrypt(string)
	val expected = "0c0pl0aca"
	
        // THEN
        Assert.assertEquals(result, expected)
    }  

    @Test
    fun `Given string apple`() {
        // GIVEN
        val string = "apple" 

        // WHEN
        val result = karacasEncrypt(string)
	val expected = "1lpp0aca"
	
        // THEN
        Assert.assertEquals(result, expected)
    } 
    @Test
    fun `Given string biruliro`() {
        // GIVEN
        val string = "biruliro" 

        // WHEN
        val result = karacasEncrypt(string)
	val expected = "2r2l3r2baca"
	
        // THEN
        Assert.assertEquals(result, expected)
    } 
}