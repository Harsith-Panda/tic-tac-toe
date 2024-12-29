#include <bits/stdc++.h>
using namespace std;

char board[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void print() {
	cout << "   |   |   " << endl;
        cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
        cout << "___|___|___" << endl;
        cout << "   |   |   " << endl;
        cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
        cout << "   |   |   " << endl;
		cout << endl;
}

void placer(int in, int steps) {
	if (steps%2 != 0) {
			cout << "Select Position to place 'X': ";
			cin >> in;
			if (in <= 3) {
				if (board[0][(in-1)%3] != 'X' && board[0][(in-1)%3] != 'O') {
					board[0][(in-1)%3] = 'X';
				} else {
					cout << "Position already choosen!" << endl;
					placer(in,steps);
				}
			} else if (in > 3 && in <= 6) {
				if (board[1][(in-1)%3] != 'X' && board[1][(in-1)%3] != 'O') {
					board[1][(in-1)%3] = 'X';
				} else {
					cout << "Position already choosen!" << endl;
					placer(in,steps);
				}
			} else if (in > 6 && in <= 9) {
				if (board[2][(in-1)%3] != 'X' && board[2][(in-1)%3] != 'O') {
					board[2][(in-1)%3] = 'X';
				} else {
					cout << "Position already choosen!" << endl;
					placer(in,steps);
				}
			} else {
				cout << "Please enter a correct value" << endl;
				placer(in,steps);
			}
		} else {
			cout << "Select Position to place 'O': ";
			cin >> in;
			if (in <= 3) {
				if (board[0][(in-1)%3] != 'X' && board[0][(in-1)%3] != 'O') {
					board[0][(in-1)%3] = 'O';
				} else {
					cout << "Position already choosen!" << endl;
					placer(in,steps);
				}
			} else if (in > 3 && in <= 6) {
				if (board[1][(in-1)%3] != 'X' && board[1][(in-1)%3] != 'O') {
					board[1][(in-1)%3] = 'O';
				} else {
					cout << "Position already choosen!" << endl;
					placer(in,steps);
				}
			} else if (in > 6 && in <= 9) {
				if (board[2][(in-1)%3] != 'X' && board[2][(in-1)%3] != 'O') {
					board[2][(in-1)%3] = 'O';
				} else {
					cout << "Position already choosen!" << endl;
					placer(in,steps);
				}
			} else {
				cout << "Please enter a correct value" << endl;
				placer(in,steps);
			}
		}
	cout << endl;
}

bool checker() {
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

	for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }

	return false;
}

int main() {
	string p1,p2;
	cout << "Enter Name of Player 1: ";
	cin >> p1;
	cout << endl;
	cout << "Enter Name of Player 2: ";
	cin >> p2;
	cout << endl;
	int steps = 1;
	bool won = false;
	while (steps <= 9) {
		print();
		int in;
		placer(in,steps);
		if (steps >= 5) {
			if (checker()) {
				won = true;
				break;
			}
		}
		steps++;
	}
	if (!won) {
		cout << "DRAW !! BETTER LUCK NEXT TIME !! 👍" << endl;
	} else {
		if (steps % 2 == 0) {
			cout << p2 << " " << "Has Won The Game ! 👑" << endl;
		} else {
			cout << p1 << " " << "Has Won The Game ! 👑" << endl;
		}
	}

	return 0;
}
