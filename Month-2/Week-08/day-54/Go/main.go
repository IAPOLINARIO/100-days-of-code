package main

import (
	"fmt"
	"strconv"
)

type RGB struct {
	red, green, blue int64
}

func NewRGB(red, green, blue int64) *RGB {
	rgb := new(RGB)
	rgb.red = red
	rgb.green = green
	rgb.blue = blue

	return rgb
}

func (color RGB) rgb2hex() string {
	r := parseRGBColor(color.red)
	g := parseRGBColor(color.green)
	b := parseRGBColor(color.blue)
	return fmt.Sprintf("#%v%v%v", r, g, b)
}

func main() {
	rgbObj := NewRGB(0, 128, 192)
	fmt.Println(rgbObj.rgb2hex())
}

// If there are values ​​less than 16 in r, g, and b, the bellow method will not work.
// if the obtained string has only one bit, it will be complemented on the left side with 0
func parseRGBColor(t int64) string {
	result := strconv.FormatInt(t, 16) //returns the hexadecimal representation of t
	if len(result) == 1 {
		result = "0" + result
	}
	return result
}
