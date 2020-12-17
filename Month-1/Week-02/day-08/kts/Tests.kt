import org.junit.*

class Tests {

    @Test
    fun `Given empty sequence`() {
        // GIVEN
        val sequence = ""
        val expected = ArrayList<String>()

        // WHEN
        val result = letterCombinations(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given invalid sequence`() {
        // GIVEN
        val sequence = "1*A----01Z"
        val expected = ArrayList<String>()

        // WHEN
        val result = letterCombinations(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given simple sequence`() {
        // GIVEN
	val sequence = "2"
	val expected = listOf("a","b","c")
        
        // WHEN
        val result = letterCombinations(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given simple sequence two`() {
        // GIVEN
	val sequence = "23"
	val expected = listOf("ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf")
        
        // WHEN
        val result = letterCombinations(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given simple sequence with invalid characters`() {
        // GIVEN  
        val sequence = "7-9"
        val expected = listOf("pw", "px", "py", "pz", "qw", "qx", "qy", "qz", "rw", "rx", "ry", "rz", "sw", "sx", "sy", "sz")
        
        // WHEN
        val result = letterCombinations(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

    @Test
    fun `Given complex sequence with invalid characters`() {
        // GIVEN
        val sequence = "3-01*&45^6"
	val expected = listOf("dgjm", "dgjn", "dgjo", "dgkm", "dgkn", "dgko", "dglm", "dgln", "dglo", "dhjm", "dhjn", "dhjo", "dhkm", "dhkn", "dhko", "dhlm", "dhln", "dhlo", "dijm", "dijn", "dijo", "dikm", "dikn", "diko", "dilm", "diln", "dilo", "egjm", "egjn", "egjo", "egkm", "egkn", "egko", "eglm", "egln", "eglo", "ehjm", "ehjn", "ehjo", "ehkm", "ehkn", "ehko", "ehlm", "ehln", "ehlo", "eijm", "eijn", "eijo", "eikm", "eikn", "eiko", "eilm", "eiln", "eilo", "fgjm", "fgjn", "fgjo", "fgkm", "fgkn", "fgko", "fglm", "fgln", "fglo", "fhjm", "fhjn", "fhjo", "fhkm", "fhkn", "fhko", "fhlm", "fhln", "fhlo", "fijm", "fijn", "fijo", "fikm", "fikn", "fiko", "film", "filn", "filo")

        // WHEN
        val result = letterCombinations(sequence)

        // THEN
        Assert.assertEquals(expected.toString(), result.toString())
    }

}