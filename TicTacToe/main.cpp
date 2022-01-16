#include <iostream>
#include"Board.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	Board *board = new Board;
	string ans = "yes";
	while(!(ans=="no")){
		board->printBoard();
		int moves = 0;
		while(true){
			while(true){
				while(true){
					cout<<"Player 1: Enter your cell: ";
					int cell;
					cin >> cell;
					if(board->isCellAvailabel(cell)){
						board->place(cell,'X');
						board->printBoard();
						moves+=1;
						break;
					}else{
						cout<<"Cell is not available."<<endl;
					}
				}
				if(board->isWinner()){
					cout<<"Player 1 wins."<<endl;
					break;
				}
				if(moves==9){
					cout<<"Draw. Game ended."<<endl;
					break;	
				}	
				while(true){
					cout<<"Player 2: Enter your cell: ";
					int cell;
					cin >> cell;
					if(board->isCellAvailabel(cell)){
						board->place(cell,'O');
						board->printBoard();
						moves+=1;
						break;
					}else{
						cout<<"Cell is not available."<<endl;
					}
				}
				if(board->isWinner()){
					cout<<"Player 2 wins."<<endl;
					break;
				}
				if(moves==9){
					cout<<"Draw. Game ended."<<endl;
					break;	
				}
			}
			cout<<"Do you want to play again:(no for stop/ yes for restart):  ";
			cin >> ans;
			board = new Board;
			cout<<endl;
			break;
		}           
	}
	delete board;
	return 0;
}
   