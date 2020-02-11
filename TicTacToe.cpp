#include <iostream>
#include <stdlib.h>
#include <string>

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

void PlaceMarker( std::string** board, int i, int j, std::string val ) {
	board[i][j] = val;
}

int* GetPlayerChoice(std::string** board, std::string player) {
	std::cout << "Player " << player << ": Which row would you like to play?" << std::endl;
	int i;
	std::cin >> i;
	std::cout << "Player " << player << ": Which column would you like to play?" << std::endl;
	int j;
	std::cin >> j;
	PlaceMarker(board, i, j, player);
	int arr[] = {i,j};
	return arr;
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
