package main

import (
	"fmt"
	"strings"
)

type Door struct {
	status         string
	cycleCompleted bool
}

func NewDoor(initialStatus string) *Door {
	return &Door{status: initialStatus, cycleCompleted: true}
}

func (d *Door) SendCommand(command DoorCommand) {
	if command.short_command == button_clicked {
		if d.cycleCompleted {
			if d.status == "CLOSED" || d.status == "STOPPED_WHILE_CLOSING" {
				d.status = "OPENING"
			} else if d.status == "OPEN" || d.status == "STOPPED_WHILE_OPENING" {
				d.status = "CLOSING"
			}
			d.cycleCompleted = false
		} else {
			if d.status == "CLOSING" {
				d.status = "STOPPED_WHILE_CLOSING"
			} else if d.status == "OPENING" {
				d.status = "STOPPED_WHILE_OPENING"
			}
			d.cycleCompleted = true
		}
	} else if command.short_command == cycle_complete {
		if d.status == "OPENING" {
			d.status = "OPEN"
		} else if d.status == "CLOSING" {
			d.status = "CLOSED"
		}
		d.cycleCompleted = true
	}
}

type DoorCommand struct {
	short_command string
	display_name  string
}

func NewDoorComand(command string) *DoorCommand {
	dc := new(DoorCommand)

	dc.short_command = command

	switch command {
	case button_clicked:
		dc.display_name = "Button Clicked."
		break
	case cycle_complete:
		dc.display_name = "Cycle Complete"
		break
	default:
		dc.display_name = "Command Unkown."
		break
	}

	return dc
}

const (
	button_clicked = "button_clicked"
	cycle_complete = "cycle_complete"
)

func main() {

	commands := []string{"button_clicked", "cycle_complete", "button_clicked", "button_clicked", "button_clicked", "button_clicked", "button_clicked", "cycle_complete"}

	fmt.Print(ControlDoor(commands))

}

func ControlDoor(commands []string) string {

	door := NewDoor("CLOSED")
	var sb strings.Builder

	sb.WriteString(fmt.Sprintf("Door: %v\n", door.status))
	for _, c := range commands {

		command := string(c)

		dc := NewDoorComand(command)
		sb.WriteString(fmt.Sprintf("> %v\n", dc.display_name))
		door.SendCommand(*dc)
		sb.WriteString(fmt.Sprintf("Door: %v\n", door.status))
	}

	return sb.String()
}
