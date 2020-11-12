import org.junit.*

class Tests {

    @Test
    fun `Given fit one bag`() {
        // GIVEN
        val sequence = "[5]"

        // WHEN
        val result = fitTheItemsInTheBags(stringToIntArray(sequence), 1)
	
        // THEN
        Assert.assertTrue(result)
    } 

    @Test
    fun `Given not fit one bag`() {
        // GIVEN
        val sequence = "[5, 6]"

        // WHEN
        val result = fitTheItemsInTheBags(stringToIntArray(sequence), 1)
	
        // THEN
        Assert.assertFalse(result)
    }  

    @Test
    fun `Given fit four bags`() {
        // GIVEN
        val sequence = "[2, 1, 2, 5, 4, 3, 6, 1, 1, 9, 3, 2]"

        // WHEN
        val result = fitTheItemsInTheBags(stringToIntArray(sequence), 4)
	
        // THEN
        Assert.assertTrue(result)
    } 
 
    @Test
    fun `Given not fit four bags`() {
        // GIVEN
        val sequence = "[2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2]"

        // WHEN
        val result = fitTheItemsInTheBags(stringToIntArray(sequence), 4)
	
        // THEN
        Assert.assertFalse(result)
    }  

    @Test
    fun `Given fit five bags`() {
        // GIVEN
        val sequence = "[2, 7, 1, 3, 3, 4, 7, 4, 1, 8, 2]"

        // WHEN
        val result = fitTheItemsInTheBags(stringToIntArray(sequence), 5)
	
        // THEN
        Assert.assertTrue(result)
    } 

    @Test
    fun `Given not fit five bags`() {
        // GIVEN
        val sequence = "[8, 7, 1, 6, 3, 4, 7, 4, 8, 8, 7]"

        // WHEN
        val result = fitTheItemsInTheBags(stringToIntArray(sequence), 5)
	
        // THEN
        Assert.assertFalse(result)
    } 

    @Test
    fun `Given fit six bags`() {
        // GIVEN
        val sequence = "[2, 7, 1, 6, 3, 4, 7, 8, 8, 7]"
	
        // WHEN
        val result = fitTheItemsInTheBags(stringToIntArray(sequence), 6)
	
        // THEN
        Assert.assertTrue(result)
    } 
}