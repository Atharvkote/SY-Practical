#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

class Player {
public:
    string name;
    int wins;
    int rank;
    string password;

    Player(string name, string password)
        : name(name), wins(0), rank(0), password(password) {}
};

class TicTacToe {
private:
    char board[3][3];
    vector<Player> players;
    vector<string> moveHistory;

public:
    TicTacToe() {
        loadPlayers();
        resetBoard();
    }

    void resetBoard() {
        char start = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = start++;
            }
        }
        moveHistory.clear();
    }

    void displayBoard() {
        cout << "\nCurrent Board:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            if (i < 2) cout << "\n---------\n";
        }
        cout << endl;
    }

    bool addPlayer(const string& name, const string& password) {
        for (const auto& player : players) {
            if (player.name == name) return false; // Player exists
        }
        players.emplace_back(name, password);
        savePlayers();
        return true;
    }

    void displayLeaderboard() {
        cout << "\n--- Leaderboard ---\n";
        cout << left << setw(15) << "Name" << setw(10) << "Wins" << setw(10) << "Rank\n";
        cout << "-----------------------------\n";

        vector<Player> sortedPlayers = players;
        sort(sortedPlayers.begin(), sortedPlayers.end(),
            [](const Player& a, const Player& b) { return a.wins > b.wins; });

        int rank = 1;
        for (const auto& player : sortedPlayers) {
            cout << left << setw(15) << player.name
                 << setw(10) << player.wins
                 << setw(10) << rank++ << endl;
        }
    }

    bool editPlayerName(const string& oldName, const string& newName, const string& password) {
        for (auto& player : players) {
            if (player.name == oldName && player.password == password) {
                player.name = newName;
                savePlayers();
                return true;
            }
        }
        return false;
    }

    Player* searchPlayer(const string& name) {
        for (auto& player : players) {
            if (player.name == name) return &player;
        }
        return nullptr;
    }

    bool checkWin(char symbol) {
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
            if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
        }
        if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
        if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;
        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        return true;
    }

    void playGame(const string& player1Name, const string& player2Name) {
        Player* player1 = searchPlayer(player1Name);
        Player* player2 = searchPlayer(player2Name);

        if (!player1 || !player2) {
            cout << "Both players need to be registered!\n";
            return;
        }

        char playerSymbols[2] = { 'X', 'O' };
        int current = 0;

        resetBoard();
        displayBoard();

        while (true) {
            cout << playerSymbols[current] << "'s turn. Enter the position (1-9): ";
            int position;
            cin >> position;

            if (position < 1 || position > 9) {
                cout << "Invalid position. Try again.\n";
                continue;
            }

            int row = (position - 1) / 3;
            int col = (position - 1) % 3;

            if (board[row][col] == 'X' || board[row][col] == 'O') {
                cout << "Position already taken. Try again.\n";
                continue;
            }

            board[row][col] = playerSymbols[current];
            displayBoard();

            moveHistory.push_back("Player " + string(1, playerSymbols[current]) + " to position " + to_string(position));

            if (checkWin(playerSymbols[current])) {
                cout << "Player " << playerSymbols[current] << " wins!\n";
                if (current == 0) player1->wins++;
                else player2->wins++;
                savePlayers();
                break;
            }

            if (isBoardFull()) {
                cout << "It's a draw!\n";
                break;
            }

            current = 1 - current; // Switch players
        }
    }

    void savePlayers() {
        ofstream file("players.txt");
        for (const auto& player : players) {
            file << player.name << " " << player.wins << " " << player.password << endl;
        }
        file.close();
    }

    void loadPlayers() {
        ifstream file("players.txt");
        if (file.is_open()) {
            string name, password;
            int wins;
            while (file >> name >> wins >> password) {
                players.emplace_back(name, password);
                players.back().wins = wins;
            }
            file.close();
        }
    }

    void showGameReplay() {
        cout << "\n--- Game Replay ---\n";
        for (const auto& move : moveHistory) {
            cout << move << endl;
        }
    }
};

int main() {
    TicTacToe game;
    int choice;
    string name, password, newName;
    string player2;

    do {
        cout << "\n--- Tic-Tac-Toe Menu ---\n";
        cout << "1. Add New Player\n";
        cout << "2. Edit Player Name\n";
        cout << "3. Search Player\n";
        cout << "4. Display Leaderboard\n";
        cout << "5. Play Game\n";
        cout << "6. Show Game Replay\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter player name: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> password;
            if (game.addPlayer(name, password)) {
                cout << "Player added successfully.\n";
            } else {
                cout << "Player already exists!\n";
            }
            break;

        case 2:
            cout << "Enter current player name: ";
            cin >> name;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter new player name: ";
            cin >> newName;
            if (game.editPlayerName(name, newName, password)) {
                cout << "Player name updated successfully.\n";
            } else {
                cout << "Invalid credentials!\n";
            }
            break;

        case 3:
            cout << "Enter player name to search: ";
            cin >> name;
            if (game.searchPlayer(name)) {
                cout << "Player " << name << " found.\n";
            } else {
                cout << "Player not found.\n";
            }
            break;

        case 4:
            game.displayLeaderboard();
            break;

        case 5:
            cout << "Enter Player 1 name: ";
            cin >> name;
            cout << "Enter Player 2 name: ";
            cin >> player2;
            game.playGame(name, player2);
            break;

        case 6:
            game.showGameReplay();
            break;

        case 7:
            cout << "Exiting game. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
