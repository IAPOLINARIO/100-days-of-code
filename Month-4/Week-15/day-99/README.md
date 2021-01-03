## How is the Weather?

You intend to visit **Brazil** and get to know its main tourist spots on your well-deserved vacation.

To make the most of this period, from the list of municipalities in your travel itinerary, you would like to know the weather conditions for the next 5 days (including the current day) of each municipality informed.

Write a function that displays the weather forecast for a municipality informed for the next 5 days (including the current day).

### Input parameters:
- Name of the municipality (it can be a partial name, the system must do a best guess)
- State abbreviation (all uppercase, 2 characters long)

## Output:
Object with the following structure:
- Name of the municipality
- State abbreviation
- List/Vector/Array containing 5 forecasts (one for each day, including today). Each forecast has:
    - Morning:
        - Minimum Temperature (° C)
        - Maximum Temperature (° C)
        - Resume
    - Afternoon:
        - Minimum Temperature (° C)
        - Maximum Temperature (° C)
        - Resume
    - Evening:
        - Minimum Temperature (° C)
        - Maximum Temperature (° C)
        - Resume    

### Notes:
- You can make use of the public [API](https://servicodados.ibge.gov.br/api/v1/localidades/municipios) of the Brazilian Institute of Geography and Statistics (IBGE) to get more information about municipalities and states. This API was used on [day-98 challenge](../../Week-14/day-98/README.md).

- You can make use of the public [weather forecast API](https://portal.inmet.gov.br/manual/manual-de-uso-da-api-de-previs%C3%A3o) of the Brazilian Institute of Geography and Statistics (IBGE).

- If the forecast is not available in all three times of the day, use a single forecast for the whole day. This is specially common for days after day 3.