char board[3][3];
char currentPlayer;

void setup() {
  Serial.begin(9600);
  resetBoard();
  currentPlayer = 'X';
  printBoard();
}

void loop() {
  if (Serial.available() > 0) {
    int position = Serial.parseInt();
    handleMove(position);
  }
}

void resetBoard() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

void printBoard() {
  Serial.println("Current board:");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      Serial.print(board[i][j]);
      if (j < 2) Serial.print("|");
    }
    Serial.println();
    if (i < 2) Serial.println("-----");
  }
  Serial.print("Player ");
  Serial.print(currentPlayer);
  Serial.println(", enter your move (1-9):");
}

void handleMove(int position) {
  if (position >= 1 && position <= 9) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;
    if (board[row][col] == ' ') {
      board[row][col] = currentPlayer;
      if (checkWin()) {
        printBoard();
        Serial.print("Player ");
        Serial.print(currentPlayer);
        Serial.println(" wins!");
        resetBoard();
      } else if (isBoardFull()) {
        printBoard();
        Serial.println("It's a draw!");
        resetBoard();
      } else {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        printBoard();
      }
    } else {
      Serial.println("Position already taken. Try again.");
    }
  } else {
    Serial.println("Invalid position. Enter a number between 1 and 9.");
  }
}

bool checkWin() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return true; // Check rows
    if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return true;
  }
  if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return true; // Check diagonals
  if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return true;
  return false;
}

bool isBoardFull() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') return false;
    }
  }
  return true;
}
