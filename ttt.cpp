#include <iostream>
#include <vector>
#include "functions.h"
#include "ttt.h"

int main() {
    std::vector<std::string> board;
    int choice;
    bool game_over;
    bool keep_playing = true;
    std::string player = "O";

    while (keep_playing == true) {
        game_over = false;
        start_game();
        board = init_board(board);
        print_board(board);
        while (game_over == false) {
            std::cout << "Player " << player << ": Please choose a position.\n";
            choice = prompt_player(board);
            board[choice] = player;
            print_board(board);

            game_over = check_game_over(board, player);
            if (game_over == true) {
                std::cout << "Game over\n";
            }
            player = change_player(player);
        }
        keep_playing = play_again();
    }
    return 0;
}