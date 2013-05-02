#ifndef BOARD_H_
#define BOARD_H_

/**
 * A Tic Tac Toe board to keep track of the game
 */

class Board {
  private:
    char** cells; //A 3x3 array of chars containing X, O, or _

  public:
    Board(); //constructor
    ~Board(); //deconstructor
    char getCell (int row, int col); //returns occupant of cell, _ X or O
    bool isEmpty (int row, int col); //return true if _, else false
    void addeX (int row, int col); //Returns true and adds X to cell if empty, returns false if full
    void addOh (int row, int col); //Returns treu and adds Y to cell im empty, returns false if full
    void printBoard(); //couts image of board

};

#include "board.inl"

#endif

