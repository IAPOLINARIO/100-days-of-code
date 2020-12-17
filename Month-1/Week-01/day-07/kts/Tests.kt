import org.junit.*

class Tests {

    @Test
    fun `Given two ordened lists`() {
        // GIVEN
	val array1 = listOf(1,2,3,4)
	val array2 = listOf(5,6,7,8)
	var expected = listOf(1,2,3,4,5,6,7,8)
        
        // WHEN
        val result = mergeAndSort(array1, array2)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given two unordened lists`() {
        // GIVEN
	val array1 = listOf(6,2,4,1)
	val array2 = listOf(8,5,3,7)
	var expected = listOf(1,2,3,4,5,6,7,8)
        
        // WHEN
        val result = mergeAndSort(array1, array2)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given two diferent lists`() {
        // GIVEN
	val array1 = listOf(2,2,1,1)
	val array2 = listOf(6,5)
	var expected = listOf(1,1,2,2,5,6)
        
        // WHEN
        val result = mergeAndSort(array1, array2)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }
}