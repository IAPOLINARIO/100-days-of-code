import org.junit.*

class Tests {

    @Test
    fun `Given two vegan scenario`() {
        // GIVEN
	val given = "[\"--oooo-ooo--\", \"--xx--x--xx--\", \"--o---o--oo--\", \"--xx--x--ox--\", \"--xx--x--ox--\"]"
        
        // WHEN
        val (vegan, nonVegan) = bbqReader(given)

        // THEN
        Assert.assertEquals(2, vegan)
        Assert.assertEquals(3, nonVegan) 
    }

    @Test
    fun `Given one vegan scenario`() {
        // GIVEN
	val given = "[\"--oooo-ooo--\", \"--xx--x--xx--\", \"--x---x--xx--\", \"--xx--x--ox--\", \"--xx--x--ox--\"]"
        
        // WHEN
        val (vegan, nonVegan) = bbqReader(given)

        // THEN
        Assert.assertEquals(1, vegan)
        Assert.assertEquals(4, nonVegan) 
    }

    @Test
    fun `Given no vegan scenario`() {
        // GIVEN
	val given = "[\"--oooo-xxx--\", \"--xx--x--xx--\", \"--x---x--xx--\", \"--xx--x--ox--\", \"--xx--x--ox--\"]"
        
        // WHEN
        val (vegan, nonVegan) = bbqReader(given)

        // THEN
        Assert.assertEquals(0, vegan)
        Assert.assertEquals(5, nonVegan) 
    }

    @Test
    fun `Given full vegan scenario`() {
        // GIVEN
	val given = "[\"--oooo-ooo--\", \"--oo--o--oo--\", \"--o---o--oo--\", \"--oo--o--oo--\", \"--o--o--oo--\"]"
        
        // WHEN
        val (vegan, nonVegan) = bbqReader(given)

        // THEN
        Assert.assertEquals(5, vegan)
        Assert.assertEquals(0, nonVegan) 
    }

    @Test
    fun `Given empty stewer scenario`() {
        // GIVEN
	val given = "[\"---------\", \"--oo--o--oo--\", \"--o---o--xo--\", \"--oo--o--oo--\", \"--o--o--oo--\"]"
        
        // WHEN
        val (vegan, nonVegan) = bbqReader(given)

        // THEN
        Assert.assertEquals(3, vegan)
        Assert.assertEquals(1, nonVegan) 
    }

}