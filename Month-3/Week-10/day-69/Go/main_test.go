package main

import (
	"reflect"
	"strings"
	"testing"
)

func Test_Commands_1(t *testing.T) {
	commands := []string{"button_clicked", "cycle_complete", "button_clicked", "button_clicked", "button_clicked", "button_clicked", "button_clicked", "cycle_complete"}

	var sb strings.Builder

	sb.WriteString("Door: CLOSED\n")
	sb.WriteString("> Button Clicked.\n")
	sb.WriteString("Door: OPENING\n")
	sb.WriteString("> Cycle Complete\n")
	sb.WriteString("Door: OPEN\n")
	sb.WriteString("> Button Clicked.\n")
	sb.WriteString("Door: CLOSING\n")
	sb.WriteString("> Button Clicked.\n")
	sb.WriteString("Door: STOPPED_WHILE_CLOSING\n")
	sb.WriteString("> Button Clicked.\n")
	sb.WriteString("Door: OPENING\n")
	sb.WriteString("> Button Clicked.\n")
	sb.WriteString("Door: STOPPED_WHILE_OPENING\n")
	sb.WriteString("> Button Clicked.\n")
	sb.WriteString("Door: CLOSING\n")
	sb.WriteString("> Cycle Complete\n")
	sb.WriteString("Door: CLOSED\n")

	expectedResult := sb.String()
	result := ControlDoor(commands)

	if !reflect.DeepEqual(result, expectedResult) {
		t.Errorf("Your evaluation was incorrect, got: %v, want: %v", result, expectedResult)
	}
}
