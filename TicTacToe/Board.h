#ifndef BOARD_H
#define BOARD_H
#include<iostream>
using namespace std;
class Board{
	private:
		char board[3][3];
	public:
		Board(){
			char temp[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					board[i][j] = temp[i][j];
				}
			}
		} 
		void printBoard(){
			for(int i = 0; i < 3; i++){
				for(int j = 0; j < 3; j++){
					cout<<"| "<<board[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		bool isCellAvailabel(int number){
			if(1 <= number && number <= 9){
				int row = (number-1)/3;
				int cell = (number-1)%3;
				if(board[row][cell]=='X' || board[row][cell] == 'O') return false;
				return true;
			}
			return false;
		}	
		void place(int number, char marker){
			int row = (number-1)/3;
			int cell = (number-1)%3;
			board[row][cell] = marker;
		}
		bool isWinner(){
			// column match
	        if(board[0][0]==board[0][1] && board[0][1] == board[0][2])return true;
	        else if(board[1][0]==board[1][1] && board[1][1] == board[1][2])return true;
	        else if(board[2][0]==board[2][1] && board[2][1] == board[2][2])return true;
	        // row match
	        else if(board[0][0]==board[1][0] && board[1][0] == board[2][0])return true;
	        else if(board[0][1]==board[1][1] && board[1][1] == board[2][1])return true;
	        else if(board[0][2]==board[1][2] && board[1][2] == board[2][2])return true;
	        // diagonal match
	        else if(board[0][0]==board[1][1] && board[1][1] == board[2][2])return true;
	        else if(board[0][2]==board[1][1] && board[1][1] == board[2][0])return true;
	        else return false;	
		}
};
#endif