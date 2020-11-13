import org.junit.*

class Tests {

    @Test
    fun `Given string a`() {
        // GIVEN
        val s = "a"
        val t = "b"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertFalse(result)
    }
    
    @Test
    fun `Given string teste`() {
        // GIVEN
        val s = "teste"
        val t = "taste"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertFalse(result)
    }
    
    @Test
    fun `Given string rat`() {
        // GIVEN
        val s = "rat"
        val t = "cat"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertFalse(result)
    }
    
    @Test
    fun `Given string catinga`() {
        // GIVEN
        val s = "cantiga"
        val t = "catinga"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertTrue(result)
    }
    
    @Test
    fun `Given string galeria`() {
        // GIVEN
        val s = "alegria"
        val t = "galeria"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertTrue(result)
    } 
    
    @Test
    fun `Given string regalia`() {
        // GIVEN
        val s = "alegria"
        val t = "regalia"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertTrue(result)
    } 
    
    @Test
    fun `Given string alegria`() {
        // GIVEN
        val s = "alegria"
        val t = "alergia"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertTrue(result)
    } 
    
    @Test
    fun `Given string carro`() {
        // GIVEN
        val s = "carro"
        val t = "corar"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertTrue(result)
    } 
    
    @Test
    fun `Given string muro`() {
        // GIVEN
        val s = "muro"
        val t = "rumo"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertTrue(result)
    } 
    
    @Test
    fun `Given string anagram`() {
        // GIVEN
        val s = "anagram"
        val t = "nagaram"

        // WHEN
        val result = checkAnagram(s, t)
	
        // THEN
        Assert.assertTrue(result)
    } 
}