#include "board.h"
#include <string>
#include <iostream>


void getHumanMove(Board* b);
void getComputerMove(Board* b, int turn);
int getRow();
int getCol();
bool gameOver(Board* b, int turn, char player);
int main(){

//initialize the board.
  string name;
  Board* b = new Board();

//greet human player
  cout << "Welcome to TIC TAC TOE!! \n" << endl;
  cout << "Please Enter Your Name: ";
  cin >> name;

  cout << endl << "Thanks! You are X, your computer opponent is O.\n" << endl;

  string winner;
  int turn = 0;

//game loop
  while (true){
    turn ++; //keep track of turn number

    getHumanMove(b);

//check to see if the last human move was conclusive
    if (gameOver(b, turn, 'X')){
      winner = name;
      break;
    } 

//After the human places their 5th X and no one has won, it's a cat's game
    if (turn == 5){
      winner = "Cat's game, no one";
      break; 
    }

    getComputerMove(b, turn);

//check to see if the computer has won
    if (gameOver(b, turn, 'O')){
      winner = "Computer";
      break;
    }
  }

//declare end of game
  cout << endl <<"Game OVER" << endl << endl;
  b->printBoard();
  cout << endl << winner << " has won!" << endl;

}

void getHumanMove(Board* b){
  int row, col;

  cout << "Where would you like to play?" << endl;

  b->printBoard();

  row = getRow();
  col = getCol(); 

//Check to see if play is valic
  if (b->isEmpty(row, col)){
    b->addeX(row, col);
  }
  else { //restart move collecting process
    cout << "That space is not available. Try again." << endl;
    getHumanMove(b);
  }

}

int getRow(){
//get a valid row
  int row;

  cout << "Row (0 to 2): ";
  cin >> row;

  if (row > 2 || row < 0) {
    cout << "Invalid row. Try again." << endl;
    return getRow();
  }

  else return row;
}

int getCol(){
//get a valid column
  int col;

  cout << "Column (0 to 2): ";
  cin >> col;

  if (col > 2 || col < 0) {
    cout << "Invalid column. Try again." << endl;
    return getCol();
  }

  else return col;
}



void getComputerMove(Board* b, int turn){
//A really dumb computer player to start - will be updated with ideal player 
//This player simply goes through all the squares starting at top left and looks for an open spot. 

 cout << "Calculating computer move..." << endl << endl;

 bool done = false;
   for (int i = 0; i < 3; i++){
     for (int j = 0; j < 3; j ++){
       if (b->isEmpty(i, j)){
         b-> addOh(i,j);
   done = true;
         break;
       }
     }
     if (done) {
       break;
     }
   }
}

bool gameOver(Board* b, int turn, char player){
  
//You can't win in less than 3  turns;
  if (turn < 3){
    return false;
  }

  int tot = 0;
 
//Check horizontal wins
  for (int i = 0; i < 3; i ++){
    tot = 0;
    for (int j = 0; j < 3; j++){
      if (b->getCell(i,j) == player){
        tot ++;
      }
    }
    if (tot == 3){
      return true;
    }
  }

 // Check vertical wins
  for (int j = 0; j < 3; j ++){
    tot = 0;
    for (int i = 0; i < 3; i++){
      if (b->getCell(i,j) == player){
        tot ++;
      }
    }
    if (tot == 3){
      return true;
    }
  }

 // Check diagonal wins

 //Top left to bottom right
 
 tot = 0;
 for (int i = 0; i < 3; i ++){
   if (b->getCell(i, i) == player){
     tot ++;
   }
 }

 if (tot == 3){
   return true;
 }
 else tot = 0;
 //Top right to bottom left

 for (int i = 0; i < 3; i ++){
   if (b->getCell(i, 2 - i) == player){
     tot ++;
   }
 }
  if (tot == 3){
    return true;
  }
  return false;
}
