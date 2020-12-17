package main

import (
	"context"
	"log"

	"github.com/kr/pretty"

	"googlemaps.github.io/maps"
)

const (
	MY_KEY = "YOUR_SECRET_KEY_GOES_HERE"
)

type Suggestion struct {
	Name      string
	Latitude  float64
	Longitute float64
	Score     float64
}

func main() {
	readGoogleAPI("asd asd63asd ", 0, 0)
}

func readGoogleAPI(query string, latitude float64, longitute float64) []Suggestion {
	c, err := maps.NewClient(maps.WithAPIKey(MY_KEY))
	suggestions := []Suggestion{}

	if err != nil {
		log.Fatalf("fatal error: %s", err)
	}

	r := &maps.QueryAutocompleteRequest{
		Input: query,
	}

	if latitude > 0 && longitute > 0 {
		r.Location = &maps.LatLng{
			Lat: latitude,
			Lng: longitute,
		}
	}

	resp, _ := c.QueryAutocomplete(context.Background(), r)

	for _, v := range resp.Predictions {

		placeID := v.PlaceID

		p := &maps.PlaceDetailsRequest{
			PlaceID: placeID,
		}

		placeDetails, _ := c.PlaceDetails(context.Background(), p)

		s := Suggestion{Name: v.Description, Latitude: placeDetails.Geometry.Location.Lat, Longitute: placeDetails.Geometry.Location.Lng}
		if len(v.Terms) > 3 {
			s.Score = 1
		} else if len(v.Terms) <= 2 {
			s.Score = 0.5
		} else if len(v.Terms) <= 1 {
			s.Score = 0.3
		} else {
			s.Score = 0.1
		}

		suggestions = append(suggestions, s)
	}

	pretty.Println(suggestions)

	return suggestions
}
