#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';

void drawBoard() {
  cout << "-------------" << endl;
  for (int i = 0; i < 3; i++) {
    cout << "| ";
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " | ";
    }
    cout << endl;
    cout << "-------------" << endl;
  }
}

void getPlayerMove() {
  int x, y;
  cout << "Enter the row (0-2) and column (0-2) where you want to place your " << player << " : ";
  cin >> x >> y;
  if (board[x][y] != ' ') {
    cout << "Invalid move. This position is already occupied. Try again." << endl;
    getPlayerMove();
  } else {
    board[x][y] = player;
  }
}

bool checkForWin() {
  // Check rows for win
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
      return true;
    }
  }
  // Check columns for win
  for (int i = 0; i < 3; i++) {
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
      return true;
    }
  }
  // Check diagonals for win
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
    return true;
  }
  if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
    return true;
  }
  return false;
}

bool checkForDraw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return false;
      }
    }
  }
  return true;
}

void switchPlayer() {
  if (player == 'X') {
    player = 'O';
  } else {
    player = 'X';
  }
}

void resetBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

int main() {
  cout << "Welcome to Tic-Tac-Toe!" << endl;
  while (true) {
    drawBoard();
    getPlayerMove();
    if (checkForWin()) {
      cout << "Player " << player << " wins!" << endl;
      break;
    }
    if (checkForDraw()) {
      cout << "It's a draw!" << endl;
      break;
    }
    switchPlayer();
  }
  resetBoard();
  cout << "Do you want to play again? (y/n)" << endl;
  char response;
  cin >> response;
  if (response == 'y' || response == 'Y') {
    main();
  }
  return 0;
}
