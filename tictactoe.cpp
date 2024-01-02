#include<iostream>
using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

int checkwin() {
    for (int i = 1; i <= 3; i++) {
        if (square[i] == square[i + 3] && square[i + 3] == square[i + 6])
            return 1;  // Vertical win
    }

    for (int i = 1; i <= 7; i += 3) {
        if (square[i] == square[i + 1] && square[i + 1] == square[i + 2])
            return 1;  // Horizontal win
    }

    if (square[1] == square[5] && square[5] == square[9])
        return 1;  // Diagonal win

    if (square[3] == square[5] && square[5] == square[7])
        return 1;  // Diagonal win

    for (int i = 1; i <= 9; i++) {
        if (square[i] != 'X' && square[i] != 'O')
            return -1;  // Continue the game
    }

    return 0;  // It's a draw
}

void board() {
    system("cls");  // Clear the console screen (for Windows)
    cout << "\n\n TIC TAC TOE \n\n";
    cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "   |   |   " << endl;
    cout << " " << square[1] << " | " << square[2] << " | " << square[3] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << square[4] << " | " << square[5] << " | " << square[6] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << square[7] << " | " << square[8] << " | " << square[9] << endl;
    cout << "   |   |   " << endl << endl;
}

int main() {
    int player = 1, choice;
    char mark;

    do {
        board();
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter the number: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
            square[choice] = mark;
            int result = checkwin();

            if (result == 1) {
                board();
                cout << "\aCongratulations!! Player " << player << " WINS!!" << endl;
                break;
            } else if (result == 0) {
                board();
                cout << "\aGame Draw!!" << endl;
                break;
            }

            player++;
        } else {
            cout << "Invalid Move!! Try again." << endl;
            cin.ignore();
            cin.get();
        }

    } while (true);

    cin.ignore();
    cin.get();
    return 0;
}
