#include<stdexcept/runtime_error>
#include<iostream>
#include<string>

using namespace std;

//Constructor initializes the 3X3 array
//fills with blanks
Board::Board(){
  this->cells = new char*[3];

  for (int i = 0; i < 3; i ++){
    this->cells[i] = new char[3];
    for (int j = 0; j < 3; j++){
      this->cells[i][j] = '_';
    }
  }
}

//Deconstructor
Board::~Board(){
  for (int i =0; i < 3; i ++){
    delete this->cells[i];
  }


char Board::getCell(int row, int col){
  return this->cells[row][col];
}

bool Board::isEmpty(int row, int col){
  return (this->cells[row][col] == '_');
}

void Board::addeX(int row, int col){
  if (this->isEmpty(row, col)){
    this->cells[row][col] = 'X';
  }
  else throw runtime_error("Cell is already occupied");
}

void Board::addOh(int row, int col){
  if (this->isEmpty(row, col)){
    this->cells[row][col] = 'O';
  }
  else throw runtime_error("Cell is already occupied");
}

void Board::printBoard(){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cout << this->cells[i][j] << " ";
    }
    cout << endl;
  }
}

