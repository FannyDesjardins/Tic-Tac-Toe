#include <iostream>
#include <vector>

void start_game() {
    std::cout << "===========================\n";
    std::cout << "Fanny's Tic-Tac-Toe!\n";
    std::cout << "===========================\n";
}

int prompt_player(std::vector<std::string> board) {
    bool valid_choice = false;
    int choice;
    while (valid_choice == false) {
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input; please enter a number between 1 and 9.\n";
        }
        else if (choice < 1 || choice > 9) {
            std::cout << "Invalid input; please enter a number between 1 and 9.\n";
        }
        else if (board[choice - 1] == " ") {
            valid_choice = true;
            return choice - 1;
        }
        else {
            std::cout << "Invalid input; please enter a number between 1 and 9 corresponding to a free space.\n";
        }
    }
}

void print_board(std::vector<std::string> board) {
    std::cout << "========================\n";
    for (int i = 0; i < board.size() / 3; i++) {

        std::cout << i * 3 + 1 << "      |" << i * 3 + 2 << "      |" << i * 3 + 3 << "      \n";
        std::cout << "   " << board[i * 3] << "   |   " << board[i * 3 + 1] << "   |   " << board[i * 3 + 2] << "   \n";
        std::cout << "       |       |       \n";

        if (i == 0 || i == 1) {
            std::cout << "------------------------\n";
        }
    }
    std::cout << "========================\n";
}

bool check_game_over(std::vector<std::string> board) {
    if (board[0] == board[1] && board[1] == board[2] && board[0] != " ") {
        return true;
    }
    else if (board[3] == board[4] && board[4] == board[5] && board[3] != " ") {
        return true;
    }
    else if (board[6] == board[7] && board[7] == board[8] && board[6] != " ") {
        return true;
    }
    else if (board[0] == board[3] && board[3] == board[6] && board[0] != " ") {
        return true;
    }
    else if (board[1] == board[4] && board[4] == board[7] && board[1] != " ") {
        return true;
    }
    else if (board[2] == board[5] && board[5] == board[8] && board[2] != " ") {
        return true;
    }
    else if (board[0] == board[4] && board[4] == board[8] && board[0] != " ") {
        return true;
    }
    else if (board[2] == board[4] && board[4] == board[6] && board[2] != " ") {
        return true;
    }
    else if (board[0] != " " && board[1] != " " && board[2] != " " && board[3] != " " && board[4] != " " && board[5] != " " && board[6] != " " && board[7] != " " && board[8] != " ") {
        return true; //it's a tie
    }
    else {
        return false;
    }
}

std::string change_player(std::string player) {
    if (player == "O") {
        return "X";
    }
    else {
        return "O";
    }
}

bool play_again() {
    std::string answer;
    bool valid_answer = false;
    while (valid_answer == false) {
        std::cout << "Would you like to play again? y/n \n";
        std::cin >> answer;
        //if (std::cin.fail()) {
          //std::cin.clear();
          //std::cin.ignore();
          //std::cout << "Please enter a valid answer: y or n.\n";
        //}else 
        if (answer == "y" || answer == "Y" || answer == "N" || answer == "n") {
            valid_answer = true;
        }
    }
    if (answer == "y" || answer == "Y") {
        return true;

    }
    else {
        return false;
    }
}

std::vector<std::string> init_board(std::vector<std::string> board) {
    if (board.size() != 9) {
        for (int i = 0; i < 9; i++) {
            board.push_back(" ");
        }
    }
    else {
        for (int j = 0; j < board.size(); j++) {
            board[j] = " ";
        }
    }
    return board;
}