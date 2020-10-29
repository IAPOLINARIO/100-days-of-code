# API Challenge

## Requirements

Design an API endpoint that provides autocomplete suggestions for large cities.
The suggestions should be restricted to cities in the USA, Brazil and Canada with a population above 5000 people.

- the endpoint is exposed at `/suggestions`
- the partial (or complete) search term is passed as a query string parameter `q`
- the caller's location can optionally be supplied via query string parameters `latitude` and `longitude` to help improve relative scores
- the endpoint returns a JSON response with an array of scored suggested matches
  - the suggestions are sorted by descending score
  - each suggestion has a score between 0 and 1 (inclusive) indicating confidence in the suggestion (1 is most confident)
  - each suggestion has a name which can be used to disambiguate between similarly named locations
  - each suggestion has a latitude and longitude

#### Sample responses

These responses are meant to provide guidance. The exact values can vary based on the data source and scoring algorithm.

**Near match**

    GET /suggestions?q=Londo&latitude=43.70011&longitude=-79.4163

```json
{
  "suggestions": [
    {
      "name": "London, ON, Canada",
      "latitude": "42.98339",
      "longitude": "-81.23304",
      "score": 0.9
    },
    {
      "name": "London, OH, USA",
      "latitude": "39.88645",
      "longitude": "-83.44825",
      "score": 0.5
    },
    {
      "name": "London, KY, USA",
      "latitude": "37.12898",
      "longitude": "-84.08326",
      "score": 0.5
    },
    {
      "name": "Londontowne, MD, USA",
      "latitude": "38.93345",
      "longitude": "-76.54941",
      "score": 0.3
    }
  ]
}
```

**No match**

    GET /suggestions?q=SomeRandomCityInTheMiddleOfNowhere

```json
{
  "suggestions": []
}
```

## Datasource

You can use [Google Geolocation](https://www.googleadservices.com/pagead/aclk?sa=L&ai=DChcSEwiH3ojJ-NrsAhUHt3cKHdWuC0QYABAAGgJlZg&ohost=www.google.com&cid=CAESP-D2vI6oOFB6UkonTsUenG2N8-pZmAiypdXPRE2lSiBXlM1-4706UwapRywBQ96FXr7_rMpRkyIqSmPAvSoWQQ&sig=AOD64_3q0rlOPwXTglNovTTowHbzbFfr6A&q&adurl&ved=2ahUKEwj_z4DJ-NrsAhUHNOwKHcWkBRYQ0Qx6BAgPEAE) API or any other API you'd like
