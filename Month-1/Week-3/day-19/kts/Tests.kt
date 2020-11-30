import org.junit.*

class Tests {

    @Test
    fun `Given valid long url`() {
        // GIVEN
        val longURL = "https://github.com/nucci/100-days-of-code"

        // WHEN
        val encoded = encode(longURL)
        val decoded = decode(encoded)

        // THEN
        Assert.assertNotEquals(encoded, "invalid URL")
        Assert.assertEquals(decoded, longURL)
    }

    @Test
    fun `Given valid long url 2`() {
        // GIVEN
        val longURL = "https://g1.globo.com/"

        // WHEN
        val encoded = encode(longURL)
        val decoded = decode(encoded)

        // THEN
        Assert.assertNotEquals(encoded, "invalid URL")
        Assert.assertEquals(decoded, longURL)
    }

    @Test
    fun `Given valid complex url`() {
        // GIVEN
        val longURL = "https://www.uol.com.br/esporte/colunas/pole-position/2020/11/30/pietro-fittipaldi-e-confirmado-como-substituto-de-grosjean-no-gp-de-sakhir.htm"

        // WHEN
        val encoded = encode(longURL)
        val decoded = decode(encoded)

        // THEN
        Assert.assertNotEquals(encoded, "invalid URL")
        Assert.assertEquals(decoded, longURL)
    }

    @Test
    fun `Given valid complex url 2`() {
        // GIVEN
        val longURL = "https://www.youtube.com/watch?v=0ZZTP_hoMPw&t=10540s&ab_channel=10HoursMovies"

        // WHEN
        val encoded = encode(longURL)
        val decoded = decode(encoded)

        // THEN
        Assert.assertNotEquals(encoded, "invalid URL")
        Assert.assertEquals(decoded, longURL)
    }

    @Test
    fun `Given invalid url`() {
        // GIVEN
        val longURL = "https:/www.uol.com.br"

        // WHEN
        val encoded = encode(longURL)
        val decoded = decode(encoded)

        // THEN
        Assert.assertEquals(encoded, "invalid URL")
        Assert.assertEquals(decoded, "URL not found")
    }

    @Test
    fun `Given invalid url 2`() {
        // GIVEN
        val longURL = "www.youtube.com/watch?v=NUYvbT6vTPs&ab_channel=BilalG%C3%B6regen"

        // WHEN
        val encoded = encode(longURL)
        val decoded = decode(encoded)

        // THEN
        Assert.assertEquals(encoded, "invalid URL")
        Assert.assertEquals(decoded, "URL not found")
    }
}
