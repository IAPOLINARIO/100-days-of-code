import org.junit.*

class Tests {

  @Test
  fun `Given Age as 65`() {
    // GIVEN
    val expected = 23725

    // WHEN
    val result = calculateAgeInDays(65)

    // THEN
    Assert.assertEquals(expected, result)
  }

  @Test
  fun `Given Age as 20`() {
    // GIVEN
    val expected = 7300

    // WHEN
    val result = calculateAgeInDays(20)

    // THEN
    Assert.assertEquals(expected, result)
  }

}