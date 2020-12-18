/**
 * DAY-69 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 * 
 * ATTENTION:
 * It needs at least a C++17 compiler because of the usage of magic_enum
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest
#include "../../../../dependencies/c++/magic_enum.hpp" //https://github.com/Neargye/magic_enum

/**
 * Valid commands supported by Door
 */ 
enum class Command {
    button_clicked,
    cycle_complete
};

/**
 * Valid values of the states of the Door
 */ 
enum class State {
    CLOSED,
    OPENING,
    OPEN,
    CLOSING,
    STOPPED_WHILE_CLOSING,
    STOPPED_WHILE_OPENING
};

class Door; //forward declaration needed for DoorState

/**
 * Base class for all the states of the Door.
 * Each subclass understands the transition using the 'toggle'
 */ 
class DoorState {
    protected:
        State value; //defined at private constructor of each subclass
    public:                
        virtual void enter(Door* door);
        virtual void toggle(Door* door) = 0; //pure virtual method
        virtual State getValue() { return this->value; }
};

/**
 * Subclass DoorStoppedWhileOpening 
 */ 
class DoorStoppedWhileOpening : public DoorState {
    public:
        void toggle(Door* door);

        static DoorState& getInstance() {
            static DoorStoppedWhileOpening singleton;
            return singleton;
        }
    private:
        DoorStoppedWhileOpening() { this->value = State::STOPPED_WHILE_OPENING; }
};

/**
 * Subclass DoorOpening 
 */ 
class DoorOpening : public DoorState {
    public:        
        void toggle(Door* door);

        static DoorState& getInstance() {
            static DoorOpening singleton;
            return singleton;
        }
    private:
        DoorOpening() { this->value = State::OPENING; }
};

/**
 * Subclass DoorClosed 
 */ 
class DoorClosed : public DoorState {
    public:
        void toggle(Door* door);

        static DoorState& getInstance() {
            static DoorClosed singleton;
            return singleton;
        }        
    private:
        DoorClosed() { this->value = State::CLOSED; }
};

/**
 * Subclass DoorOpen 
 */ 
class DoorOpen : public DoorState {
    public:
        void toggle(Door* door);

        static DoorState& getInstance() {
            static DoorOpen singleton;
            return singleton;
        }        
    private:
        DoorOpen() { this->value = State::OPEN; }
};

/**
 * Subclass DoorClosing 
 */ 
class DoorClosing : public DoorState {
    public:
        void toggle(Door* door);

        static DoorState& getInstance() {
            static DoorClosing singleton;
            return singleton;
        }
    private:
        DoorClosing() { this->value = State::CLOSING; }
};

/**
 * Subclass DoorStoppedWhileClosing 
 */ 
class DoorStoppedWhileClosing : public DoorState {
    public:        
        void toggle(Door* door);

        static DoorState& getInstance() {
            static DoorStoppedWhileClosing singleton;
            return singleton;
        }        
    private:
        DoorStoppedWhileClosing() { this->value = State::STOPPED_WHILE_CLOSING; }
};

/**
 * The Door
 */ 
class Door {
    public:
        Door() {            
            this->currentState = &DoorClosed::getInstance(); //the last Door state is an instance of DoorClosed
            this->currentCommand = Command::cycle_complete; //the last Door command is 'cycle_complete'
            this->printCurrentState(); //print the current state at initialization
        }
        DoorState* getCurrentState() const {
            return this->currentState;
        }
        void setCurrentCommand(Command command) {
            this->currentCommand = command;
            this->currentState->toggle(this); //delegate the next state to the current state. It will check the door's currentCommand to decide
        }
        Command getCurrentCommand() {
            return this->currentCommand;
        }
        void setCurrentState(DoorState& newState) { //this is called by each DoorState 'toggle' method, using 'this' pointer
            this->currentState = &newState; //change the Door current state
            this->currentState->enter(this); //after changing the state, execute its 'enter'
        }   
        void printCurrentCommand() {
            std::cout << "> " << magic_enum::enum_name(this->getCurrentCommand()) << '\n';
        }
        void printCurrentState() {            
            std::cout << "Door: " << magic_enum::enum_name(this->getCurrentState()->getValue()) << '\n';
        }     
    private:
        Command currentCommand;
        DoorState* currentState;

};


void DoorState::enter(Door* door) {
    //When entering a new state, print the current door command that caused the change
    door->printCurrentCommand();    
    //Print the name of the new state
    door->printCurrentState();
}

/**
 * The toggle logic for DoorStoppedWhileOpening
 */ 
void DoorStoppedWhileOpening::toggle(Door* door) {
    if (door->getCurrentCommand() == Command::button_clicked) {
        door->setCurrentState(DoorClosing::getInstance());
    }
}

/**
 * The toggle logic for DoorOpening
 */ 
void DoorOpening::toggle(Door* door) {    
    switch (door->getCurrentCommand())
    {
    case Command::button_clicked:
        door->setCurrentState(DoorStoppedWhileOpening::getInstance());
        break;
    case Command::cycle_complete:
        door->setCurrentState(DoorOpen::getInstance());
        break;
    }
}

/**
 * The toggle logic for DoorClosed
 */ 
void DoorClosed::toggle(Door* door) {
    if (door->getCurrentCommand() == Command::button_clicked) {
        door->setCurrentState(DoorOpening::getInstance());
    }
}

/**
 * The toggle logic for DoorOpen
 */ 
void DoorOpen::toggle(Door* door) {
    if (door->getCurrentCommand() == Command::button_clicked) {
        door->setCurrentState(DoorClosing::getInstance());
    }
}

/**
 * The toggle logic for DoorClosing
 */ 
void DoorClosing::toggle(Door* door) {
    switch (door->getCurrentCommand())
    {
    case Command::button_clicked:
        door->setCurrentState(DoorStoppedWhileClosing::getInstance());
        break;
    case Command::cycle_complete:
        door->setCurrentState(DoorClosed::getInstance());
        break;
    }
}

/**
 * The toggle logic for DoorStoppedWhileClosing
 */ 
void DoorStoppedWhileClosing::toggle(Door* door) {
    if (door->getCurrentCommand() == Command::button_clicked) {
        door->setCurrentState(DoorOpening::getInstance());
    }
}        

/**
 * Tests
 */
TEST_CASE("Tests")
{
    Door door;

    CHECK(door.getCurrentCommand() == Command::cycle_complete);
    CHECK(door.getCurrentState()->getValue() == State::CLOSED);

    door.setCurrentCommand(Command::button_clicked);

    CHECK(door.getCurrentCommand() == Command::button_clicked);
    CHECK(door.getCurrentState()->getValue() == State::OPENING);

    door.setCurrentCommand(Command::cycle_complete);

    CHECK(door.getCurrentCommand() == Command::cycle_complete);
    CHECK(door.getCurrentState()->getValue() == State::OPEN);

    door.setCurrentCommand(Command::button_clicked);

    CHECK(door.getCurrentCommand() == Command::button_clicked);
    CHECK(door.getCurrentState()->getValue() == State::CLOSING);

    door.setCurrentCommand(Command::button_clicked);

    CHECK(door.getCurrentCommand() == Command::button_clicked);
    CHECK(door.getCurrentState()->getValue() == State::STOPPED_WHILE_CLOSING);

    door.setCurrentCommand(Command::button_clicked);

    CHECK(door.getCurrentCommand() == Command::button_clicked);
    CHECK(door.getCurrentState()->getValue() == State::OPENING);

    door.setCurrentCommand(Command::button_clicked);

    CHECK(door.getCurrentCommand() == Command::button_clicked);
    CHECK(door.getCurrentState()->getValue() == State::STOPPED_WHILE_OPENING);

    door.setCurrentCommand(Command::button_clicked);

    CHECK(door.getCurrentCommand() == Command::button_clicked);
    CHECK(door.getCurrentState()->getValue() == State::CLOSING);

    door.setCurrentCommand(Command::cycle_complete);

    CHECK(door.getCurrentCommand() == Command::cycle_complete);
    CHECK(door.getCurrentState()->getValue() == State::CLOSED);
}


