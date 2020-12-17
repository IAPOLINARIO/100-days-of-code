import io.ktor.application.*
import io.ktor.http.*
import nucci.server.*
import io.ktor.server.testing.*
import kotlin.test.*

class Tests {
    @Test
    fun testLatLong(): Unit = withTestApplication(Application::main) {
        handleRequest(HttpMethod.Get, "/suggestions?latitude=48.35&longitude=2.45").apply {
            assertEquals(200, response.status()?.value)
            assertEquals(
                """
                    |[
                    |  {
                    |    "name": "D 63, Tousson, Fontainebleau, Seine-et-Marne, Île-de-France, France métropolitaine, 77123, France",
                    |    "latitude": "48.34940884922344",
                    |    "longitude": "2.4496214710569624",
                    |    "score": 1.0
                    |  }
                    |]
                """.trimMargin(),
                response.content
            )
        }
    }

    @Test
    fun testSearch(): Unit = withTestApplication(Application::main) {
        handleRequest(HttpMethod.Get, "/suggestions?q=Brasil&limit=3").apply {
            assertEquals(200, response.status()?.value)
            assertEquals(
                """
                |[
                |  {
                |    "name": "Brasil",
                |    "latitude": "-10.3333333",
                |    "longitude": "-53.2",
                |    "score": 0.9555773423061166
                |  },
                |  {
                |    "name": "Brasil, Cantón Santa Ana, Provincia San José, 10906, Costa Rica",
                |    "latitude": "9.936217",
                |    "longitude": "-84.2239353",
                |    "score": 0.45999999999999996
                |  },
                |  {
                |    "name": "Brasil, Parroquia Las Parcelas, Municipio Mara, Zulia, Zuliana, Venezuela",
                |    "latitude": "11.0025436",
                |    "longitude": "-71.83235679497547",
                |    "score": 0.43500000000000005
                |  }
                |]
                """.trimMargin(),
                response.content
            )
        }
    }
}
