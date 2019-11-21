#include <vector>
#include <iostream>

using namespace std;

const bool CLEAR_SCREEN = true;

/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen() {
    cout << endl;

    if (CLEAR_SCREEN) {
        cout << "\033c";
    }

    cout << endl;

    return;
}


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
    clearScreen();
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6) {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;

    return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {
    
    v.at(0) = 'a';
    v.at(1) = 'b';
    v.at(2) = 'c';
    v.at(3) = 'd';
    v.at(4) = 'e';
    v.at(5) = 'f';
    v.at(6) = 'g';
    v.at(7) = 'h';
    v.at(8) = 'i';
    return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
    // Return the vector index of the associated letter
    if (boardPosition == 'a') {
        return 0;
    }
    if (boardPosition == 'b') {
        return 1;
    }
    if (boardPosition == 'c') {
        return 2;
    }
    if (boardPosition == 'd') {
        return 3;
    }
    if (boardPosition == 'e') {
        return 4;
    }
    if (boardPosition == 'f') {
        return 5;
    }
    if (boardPosition == 'g') {
        return 6;
    }
    if (boardPosition == 'h') {
        return 7;
    }
    if (boardPosition == 'i') {
        return 8;
    }
    else {
        return -1;
    }
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
    // Check range of vecter
    if ((positionIndex >= 0) && (positionIndex <= 8)) {
        // Check the cell is not already chosen
        if ((gameBoard.at(positionIndex) != 'X') && (gameBoard.at(positionIndex) != 'O')){
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard) {
    char boardPosition = ' ';

    cout << "Please choose a position: ";
    cin >> boardPosition;
    
    int posIndex = convertPosition(boardPosition);
    return posIndex;

}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard) {
    
    // All win cases for 'X'
    if (gameBoard.at(0) == 'X' && gameBoard.at(1) == 'X' && gameBoard.at(2) == 'X'){
        return true;
    }
    if (gameBoard.at(0) == 'X' && gameBoard.at(3) == 'X' && gameBoard.at(6) == 'X'){
        return true;
    }
    if (gameBoard.at(0) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(8) == 'X'){
        return true;
    }
    if (gameBoard.at(1) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(7) == 'X'){
        return true;
    }
    if (gameBoard.at(2) == 'X' && gameBoard.at(5) == 'X' && gameBoard.at(8) == 'X'){
        return true;
    }
    if (gameBoard.at(2) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(6) == 'X'){
        return true;
    }
    if (gameBoard.at(3) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(5) == 'X'){
        return true;
    }
    if (gameBoard.at(6) == 'X' && gameBoard.at(7) == 'X' && gameBoard.at(8) == 'X'){
        return true;
    }
    
    // All win cases for 'O'
    if (gameBoard.at(0) == 'O' && gameBoard.at(1) == 'O' && gameBoard.at(2) == 'O'){
        return true;
    }
    if (gameBoard.at(0) == 'O' && gameBoard.at(3) == 'O' && gameBoard.at(6) == 'O'){
        return true;
    }
    if (gameBoard.at(0) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(8) == 'O'){
        return true;
    }
    if (gameBoard.at(1) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(7) == 'O'){
        return true;
    }
    if (gameBoard.at(2) == 'O' && gameBoard.at(5) == 'O' && gameBoard.at(8) == 'O'){
        return true;
    }
    if (gameBoard.at(2) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(6) == 'O'){
        return true;
    }
    if (gameBoard.at(3) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(5) == 'O'){
        return true;
    }
    if (gameBoard.at(6) == 'O' && gameBoard.at(7) == 'O' && gameBoard.at(8) == 'O'){
        return true;
    }
    return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard) {
    // Check that every cell has an 'X' or 'O'
    if ((gameBoard.at(0) == 'X' || gameBoard.at(0) == 'O')
        && (gameBoard.at(1) == 'X' || gameBoard.at(1) == 'O')
        && (gameBoard.at(2) == 'X' || gameBoard.at(2) == 'O')
        && (gameBoard.at(3) == 'X' || gameBoard.at(3) == 'O')
        && (gameBoard.at(4) == 'X' || gameBoard.at(4) == 'O')
        && (gameBoard.at(5) == 'X' || gameBoard.at(5) == 'O')
        && (gameBoard.at(6) == 'X' || gameBoard.at(6) == 'O')
        && (gameBoard.at(7) == 'X' || gameBoard.at(7) == 'O')
        && (gameBoard.at(8) == 'X' || gameBoard.at(8) == 'O')
        ) {
        return true;
    }
    return false;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
    // Initialize variables
    vector<char> gameBoard(9);
    int curPlay = 1;
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'
    int boardPosition = 0;

    // Initalize gameBoard vector and draw the board
    initVector(gameBoard);
    drawBoard(gameBoard);
    
    // Loop until a player wins or the board is full
    while (!gameWon(gameBoard) && !boardFull(gameBoard)) {
        if (curPlay % 2 == 1) {
            whosTurn = PLAYER1;
        }
        else {
            whosTurn = PLAYER2;
        }
    
        boardPosition = getPlay(gameBoard);
        // Get valid input
        while (!validPlacement(gameBoard, boardPosition)){
            cout << endl;
            boardPosition = getPlay(gameBoard);
        }

        if (whosTurn == PLAYER1) {
            gameBoard.at(boardPosition) = 'X';
        }
        else {
            gameBoard.at(boardPosition) = 'O';
        }

        cout << endl;
        drawBoard(gameBoard); // Redraw game board with updated values
        
        ++curPlay; // Increment current play to change player
    }

    // End game outcomes
    if (gameWon(gameBoard) && whosTurn == PLAYER1) {
        cout << "PLAYER 1 WINS!" << endl;
    }
    if (gameWon(gameBoard) && whosTurn == PLAYER2) {
        cout << "PLAYER 2 WINS!" << endl;
    }
    if (boardFull(gameBoard) && !gameWon(gameBoard)) {
        cout << "No one wins" << endl;
    }

    return 0;
}
