#include <iostream>
#include <stdlib.h>
#include <string>

/**
 * Creates 3x3 string matrix with spaces in each slot
 */
std::string** CreateBoard() {
	std::string** board = new std::string*[3];
	for(int i = 0; i < 3; i++) {
		board[i] = new std::string[3];
		for(int j= 0; j < 3; j++) {
			board[i][j] = " ";
		}
	}
	return board;
}

/**
 * Places passed string "val" into given coordinates
 */
void PlaceMarker( std::string** board, int i, int j, std::string val ) {
	board[i][j] = val;
}

/**
 * Prompts a given player for where on the board they'd like to place their marker.
 * The marker of the player and coordinates will be passed to a PlaceMarker() call.
 */
int* GetPlayerChoice(std::string** board, std::string player) {
	std::cout << "Player " << player << ": Which row would you like to play?" << std::endl;
	int i;
	std::cin >> i;
	std::cout << "Player " << player << ": Which column would you like to play?" << std::endl;
	int j;
	std::cin >> j;
	PlaceMarker(board, i - 1, j - 1, player);
	int* arr = new int[2];
	arr[0] = i;
	arr[1] = j;
	return arr;
}

/**
 * Displays all 9 pieces of the board as a 3x3 matrix
 */
void DisplayBoard( std::string** board ) {
	for ( int i = 0; i < 3; i++ ) {
		std::cout << "[ ";
		for ( int j = 0; j < 3; j++ ) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "]" << std::endl;
	}
}


/**
 * Runs through 9 turns to fill the tic tac toe board.
 * Displays board a final time after the game ends
 */
int main() {
	std::string** board = CreateBoard();
	int* choice;
	for ( int i = 0; i < 9; i++ ) {
		DisplayBoard(board);
		if ( (i % 2) == 0 ) {
			choice = GetPlayerChoice(board, "X");
		}
		else {
			choice = GetPlayerChoice(board, "O");
		}
	}
	DisplayBoard(board);
}
