#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

class Player {
private:
    string password;

public:
    string name;
    double wins; // Wins can now be fractional
    int rank;
    int gamesPlayed; // Total games played
    double winPercentage; // Calculated win percentage

    Player(const string& name, const string& password)
        : name(name), wins(0.0), rank(0), gamesPlayed(0), winPercentage(0.0), password(password) {}

    bool verifyPassword(const string& pass) const {
        return password == pass;
    }

    void updateWinPercentage() {
        if (gamesPlayed > 0) {
            winPercentage = (wins / gamesPlayed) * 100;
        } else {
            winPercentage = 0.0; // No games played, set to 0%
        }
    }

    void incrementGames() {
        gamesPlayed++;
    }

    void addWin(double increment = 1.0) {
        wins += increment;
        incrementGames();
        updateWinPercentage();
    }

    void addDraw() {
        incrementGames();
        updateWinPercentage();
    }
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
        cout << "\n";
        for (int i = 0; i < 3; i++) {
            cout << "\t     |     |     \n";
            cout << "\t  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  \n";
            if (i < 2) {
                cout << "\t_____|_____|_____\n";
            } else {
                cout << "\t     |     |     \n";
            }
        }
        cout << "\n";
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
        cout << "\n--------- Leaderboard ------------\n";
        cout << left << setw(15) << "Name" << setw(10) << "Wins" << setw(10) << "Win %" << setw(10) << "Rank\n";
        cout << "------------------------------------\n";

        // Sort players by win percentage, then by wins, then by name
        vector<Player> sortedPlayers = players;
        sort(sortedPlayers.begin(), sortedPlayers.end(),
            [](const Player& a, const Player& b) {
                if (a.winPercentage != b.winPercentage)
                    return a.winPercentage > b.winPercentage; // Descending order of win percentage
                if (a.wins != b.wins)
                    return a.wins > b.wins; // Descending order of wins
                return a.name < b.name;    // Stable sort by name
            });

        // Assign ranks dynamically
        double lastWinPercentage = -1;
        int currentRank = 0;
        for (size_t i = 0; i < sortedPlayers.size(); i++) {
            if (sortedPlayers[i].winPercentage != lastWinPercentage) {
                currentRank = i + 1;
                lastWinPercentage = sortedPlayers[i].winPercentage;
            }
            sortedPlayers[i].rank = currentRank;
            cout << left << setw(15) << sortedPlayers[i].name
                 << setw(10) << sortedPlayers[i].wins
                 << setw(10) << fixed << setprecision(2) << sortedPlayers[i].winPercentage
                 << setw(10) << sortedPlayers[i].rank << endl;
        }
    }

    bool editPlayerName(const string& oldName, const string& newName, const string& password) {
        for (auto& player : players) {
            if (player.name == oldName && player.verifyPassword(password)) {
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
                if (current == 0) player1->addWin();
                else player2->addWin();
                savePlayers();
                break;
            }

            if (isBoardFull()) {
                cout << "It's a draw!\n";
                player1->addDraw();
                player2->addDraw();
                savePlayers();
                break;
            }

            current = 1 - current; // Switch players
        }
    }

    void savePlayers() {
        ofstream file("players.txt");
        for (const auto& player : players) {
            file << player.name << " " << player.wins << " " << player.gamesPlayed << " " << player.winPercentage << "\n";
        }
        file.close();
    }

    void loadPlayers() {
        ifstream file("players.txt");
        if (file.is_open()) {
            string name, password;
            double wins;
            int gamesPlayed;
            double winPercentage;
            while (file >> name >> wins >> gamesPlayed >> winPercentage) {
                players.emplace_back(name, password);
                players.back().wins = wins;
                players.back().gamesPlayed = gamesPlayed;
                players.back().winPercentage = winPercentage;
            }
            file.close();
        }
    }

    void showGameReplay() {
        cout << "\n--- Game Replay ---\n";
        for (const auto& move : moveHistory) {
            cout << move << "\n";
        }
    }
};

int main() {
    TicTacToe game;
    int choice;
    string name, player2, password;

    do {
        cout << "\n1. Add New Player\n2. Edit Player Name\n3. Search Player\n4. Show Leaderboard\n5. Play Game\n6. Show Game Replay\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Player Name: ";
            cin >> name;
            cout << "Enter Password: ";
            cin >> password;
            if (game.addPlayer(name, password)) {
                cout << "Player added successfully!\n";
            } else {
                cout << "Player already exists.\n";
            }
            break;

        case 2:
            cout << "Enter Player Name to Edit: ";
            cin >> name;
            cout << "Enter New Name: ";
            cin >> player2;
            cout << "Enter Password: ";
            cin >> password;
            if (game.editPlayerName(name, player2, password)) {
                cout << "Player name updated successfully!\n";
            } else {
                cout << "Failed to edit player name.\n";
            }
            break;

        case 3:
            cout << "Enter Player Name to Search: ";
            cin >> name;
            if (game.searchPlayer(name)) {
                cout << "Player found!\n";
            } else {
                cout << "Player not found!\n";
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
            cout << "Exiting game.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}
