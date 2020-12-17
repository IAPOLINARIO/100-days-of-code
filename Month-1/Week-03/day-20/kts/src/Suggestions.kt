package nucci.server

import io.ktor.application.*
import io.ktor.features.*
import io.ktor.gson.*
import io.ktor.http.*
import io.ktor.response.*
import io.ktor.routing.*
import kotlinx.coroutines.*
import kotlinx.serialization.*
import kotlinx.serialization.json.*
import java.text.*
import java.time.*
import java.net.*

val format = Json { ignoreUnknownKeys = true }
@Serializable
data class Location(
    @SerialName("display_name") val name: String = "Unknown",
    @SerialName("lat") val latitude: String,
    @SerialName("lon") val longitude: String,
    @SerialName("importance") val score: Double = 1.0)

fun Application.main() {
    install(DefaultHeaders)
    install(Compression)
    install(CallLogging)
    install(ContentNegotiation) {
        gson {
            setPrettyPrinting()
        }
    }
    routing {
        get("/suggestions") {
            val term = call.request.queryParameters["q"] ?: "Brasil"
            val lat = call.request.queryParameters["latitude"]
            val long = call.request.queryParameters["longitude"]
            val limit = call.request.queryParameters["limit"] ?: "10"

            val result = getSuggestions(term, lat, long, limit)
            call.respond(result)
        }
    }
}

fun getSuggestions(q: String, lat: String?, long: String?, limit: String): List<Location> {
    if (lat != null && long != null) {
        val resultString = URL("https://nominatim.openstreetmap.org/reverse?lat=$lat&lon=$long&format=json").readText()
        return listOf(format.decodeFromString<Location>(resultString))
    }
    val resultString = URL("https://nominatim.openstreetmap.org/search?q=$q&format=json&limit=$limit").readText()
    return format.decodeFromString<List<Location>>(resultString)
}
