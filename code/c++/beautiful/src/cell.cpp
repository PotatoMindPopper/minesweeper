#include "cell.hpp"
#include <iostream>

/**
 * @brief Convert the cell values to a string
 * 
 * @return std::string String representation of the cell
 */
std::string Cell::to_string() {
    std::string str = "";
    str += "Type: " + Cell::to_string(this->type) + "\n";
    str += "State: " + Cell::to_string(this->state) + "\n";
    str += "Value: " + std::to_string(this->value) + "\n";
    str += "X: " + std::to_string(this->x) + "\n";
    str += "Y: " + std::to_string(this->y) + "\n";
    return str;
}

/**
 * @brief Convert the type to a string
 * 
 * @param type Type of the cell
 * @return std::string String representation of the type
 */
std::string Cell::to_string(Type type) {
    switch (type) {
        case Type::EMPTY:
            return "EMPTY";
        case Type::MINE:
            return "MINE";
        case Type::UNDEFINED:
            return "UNDEFINED";
        case Type::VALUED:
            return "VALUED";
        default:
            return "UNDEFINED";
    }
}

/**
 * @brief Convert the state to a string
 * 
 * @param state State of the cell
 * @return std::string String representation of the state
 */
std::string Cell::to_string(State state) {
    switch (state) {
        case State::FLAG:
            return "FLAG";
        case State::HIDDEN:
            return "HIDDEN";
        case State::QUESTION:
            return "QUESTION";
        case State::REVEALED:
            return "REVEALED";
        case State::UNDEFINED:
            return "UNDEFINED";
        default:
            return "UNDEFINED";
    }
}

/**
 * @brief Change the state of the cell
 * 
 * @param value Value of the state
 */
void Cell::change_state(int value) {
    switch (value) {
        case 0:
            this->state = State::HIDDEN;
            break;
        case 1:
            this->state = State::REVEALED;
            break;
        case 2:
            this->state = State::FLAG;
            break;
        case 3:
            this->state = State::QUESTION;
            break;
        default:
            this->state = State::UNDEFINED;
            break;
    }
}

/**
 * @brief Change the type of the cell
 * 
 * @param value Value of the type
 */
void Cell::change_type(int value) {
    switch (value) {
        case 0:
            this->type = Type::EMPTY;
            break;
        case 1:
            this->type = Type::MINE;
            break;
        case 2:
            this->type = Type::VALUED;
            break;
        default:
            this->type = Type::UNDEFINED;
            break;
    }
}

/**
 * @brief Reveal the cell
 * 
 */
void Cell::reveal() {
    this->state = State::REVEALED;
}

/**
 * @brief Flag the cell
 * 
 */
void Cell::flag() {
    this->state = State::FLAG;
}

/**
 * @brief Question the cell
 * 
 */
void Cell::question() {
    this->state = State::QUESTION;
}
