#include <iostream>

std::string** CreateBoard() {
	std::string** board = new std::string*[3];
	for(int i = 0; i < 3; i++) {
		board[i] = new std::string[3];
		for(int j= 0; j < 3; j++) {
			board[i][j] = "";
		}
	}
	return board;
}

void DisplayBoard( std::string** board ) {
	for ( int i = 0; i < 3; i++ ) {
		std::cout << "[ ";
		for ( int j = 0; j < 3; j++ ) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "]" << std::endl;
	}
}


int main() {
	std::string** board = CreateBoard();
	DisplayBoard(board);
}
