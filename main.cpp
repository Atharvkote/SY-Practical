#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_PLAYERS = 10;

class Board {
private:
    char board[3][3];
    char lastBoard[3][3];  // To store the last game's board state

public:
    Board() { reset(); }

    void reset() {
        char cell = '1';
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = cell++;
            }
        }
    }

    void saveLastState() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                lastBoard[i][j] = board[i][j];
            }
        }
    }

    void replayLastGame() const {
        cout << "\nReplaying the last game:\n";
        for (int i = 0; i < 3; i++) {
            cout << "\t     |     |     \n";
            cout << "\t  " << lastBoard[i][0] << "  |  " << lastBoard[i][1] << "  |  " << lastBoard[i][2] << "  \n";
            if (i < 2) {
                cout << "\t_____|_____|_____\n";
            } else {
                cout << "\t     |     |     \n";
            }
        }
        cout << "\n";
    }

    void display() const {
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

    bool update(int choice, char symbol) {
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = symbol;
            return true;
        }
        return false;
    }

    bool checkWin(char symbol) const {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) ||
                (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)) {
                return true;
            }
        }
        return (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) ||
               (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol);
    }

    bool checkDraw() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
            }
        }
        return true;
    }
};

class PlayerInfo {
private:
    string name;
    int wins;
    int rank;
    string password;

public:
    PlayerInfo() : wins(0), rank(0) {}

    PlayerInfo(string n, string pass) : name(n), password(pass), wins(0), rank(0) {}

    string getName() const { return name; }
    int getWins() const { return wins; }
    int getRank() const { return rank; }
    bool checkPassword(const string &pass) const { return pass == password; }

    void editName(const string &newName, const string &pass) {
        if (checkPassword(pass)) {
            name = newName;
            cout << "Name updated successfully.\n";
        } else {
            cout << "Incorrect password. Unable to update name.\n";
        }
    }

    void incrementWins() { wins++; }
    void addDrawPoint() { wins += 0.5; }
    void setRank(int r) { rank = r; }
};

class PlayerDatabase {
private:
    PlayerInfo players[MAX_PLAYERS];
    int playerCount;

public:
    PlayerDatabase() : playerCount(0) {}

    void addNewPlayer(const string &name, const string &password) {
        if (playerCount < MAX_PLAYERS) {
            players[playerCount++] = PlayerInfo(name, password);
            cout << "Player added: " << name << "\n";
        } else {
            cout << "Player database is full.\n";
        }
    }

    PlayerInfo *searchPlayer(const string &name) {
        for (int i = 0; i < playerCount; i++) {
            if (players[i].getName() == name) {
                return &players[i];
            }
        }
        cout << "Player not found.\n";
        return nullptr;
    }

    void displayLeaderboard() const {
        cout << "\n+-------------------------------+\n";
        cout << "|         Leaderboard           |\n";
        cout << "+-------------------------------+\n";
        cout << "| " << left << setw(15) << "Name" << setw(10) << "Wins" << "Rank |\n";
        cout << "+-------------------------------+\n";
        for (int i = 0; i < playerCount; i++) {
            cout << "| " << left << setw(15) << players[i].getName()
                 << setw(10) << players[i].getWins()
                 << players[i].getRank() << " |\n";
        }
        cout << "+-------------------------------+\n";
    }

    void updateRanks() {
        // Sort players by wins and assign ranks
        for (int i = 0; i < playerCount - 1; i++) {
            for (int j = i + 1; j < playerCount; j++) {
                if (players[j].getWins() > players[i].getWins()) {
                    swap(players[i], players[j]);
                }
            }
        }

        for (int i = 0; i < playerCount; i++) {
            if (i > 0 && players[i].getWins() == players[i - 1].getWins()) {
                players[i].setRank(players[i - 1].getRank());
            } else {
                players[i].setRank(i + 1);
            }
        }
    }
};

class Game {
private:
    Board board;
    PlayerDatabase db;

public:
    void setupPlayers() {
        int numPlayers;
        cout << "Enter the number of players: ";
        cin >> numPlayers;
        for (int i = 0; i < numPlayers; i++) {
            string name, password;
            cout << "Enter player " << i + 1 << " name: ";
            cin >> name;
            cout << "Enter player " << i + 1 << " password: ";
            cin >> password;
            db.addNewPlayer(name, password);
        }
    }

    void playRound(PlayerInfo *player1, PlayerInfo *player2) {
        board.reset();
        bool turn = true;  // true for player1, false for player2
        int choice;
        char symbol = 'X';

        cout << "Starting a new game between " << player1->getName() << " and " << player2->getName() << "!\n";
        board.display();

        while (true) {
            symbol = turn ? 'X' : 'O';
            cout << (turn ? player1->getName() : player2->getName()) << " (" << symbol << "), enter your move (1-9): ";
            cin >> choice;

            if (choice < 1 || choice > 9 || !board.update(choice, symbol)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            board.display();
            if (board.checkWin(symbol)) {
                cout << (turn ? player1->getName() : player2->getName()) << " wins this round!\n";
                (turn ? player1 : player2)->incrementWins();
                break;
            } else if (board.checkDraw()) {
                cout << "It's a draw!\n";
                player1->addDrawPoint();
                player2->addDrawPoint();
                break;
            }
            turn = !turn;
        }

        board.saveLastState();
        db.updateRanks();
        db.displayLeaderboard();
    }

    void play() {
        setupPlayers();
        char choice;
        do {
            string name1, name2;
            cout << "\nEnter the name of player 1: ";
            cin >> name1;
            PlayerInfo *player1 = db.searchPlayer(name1);
            if (!player1) continue;

            cout << "Enter the name of player 2: ";
            cin >> name2;
            PlayerInfo *player2 = db.searchPlayer(name2);
            if (!player2) continue;

            playRound(player1, player2);

            cout << "Replay last game? (y/n): ";
            cin >> choice;
            if (choice == 'y') {
                board.replayLastGame();
            }

            cout << "Do you want to play another game? (y/n): ";
            cin >> choice;
        } while (choice == 'y');
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
