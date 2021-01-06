# Garage Door Opener

You just got a new garage door installed by the Automata™ Garage Door Company. You are having a lot of fun playing with the remote clicker, opening and closing the door, scaring your pets and annoying the neighbors.

The clicker is a one-button remote that works like this:

If the door is **OPEN** or **CLOSED**, clicking the button will cause the door to move, until it completes the cycle of opening or closing.

_Door: Closed -> Button clicked -> Door: Opening -> Cycle complete -> Door: Open._

If the door is currently opening or closing, clicking the button will make the door stop where it is. When clicked again, the door will go the opposite direction, until complete or the button is clicked again.

We will assume the initial state is **CLOSED**.

## Input

Array/vector of a series of commands (can be hard coded, no need to parse):

```text
button_clicked
cycle_complete
button_clicked
button_clicked
button_clicked
button_clicked
button_clicked
cycle_complete
```

## Output

Output should be the state of the door and the input commands, such as:

```text
Door: CLOSED
> Button clicked.
Door: OPENING
> Cycle complete.
Door: OPEN
> Button clicked.
Door: CLOSING
> Button clicked.
Door: STOPPED_WHILE_CLOSING
> Button clicked.
Door: OPENING
> Button clicked.
Door: STOPPED_WHILE_OPENING
> Button clicked.
Door: CLOSING
> Cycle complete.
Door: CLOSED
```

## Notes

- This is an example of a simple [Finite State Machine](https://en.wikipedia.org/wiki/Finite-state_machine) with 6 States and 2 inputs.
