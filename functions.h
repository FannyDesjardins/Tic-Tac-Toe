#pragma once
#include <vector>

void start_game();
int prompt_player(std::vector<std::string> board);
void print_board(std::vector<std::string> board);
bool check_game_over(std::vector<std::string> board, std::string player);

std::string change_player(std::string);

bool play_again();

std::vector<std::string> init_board(std::vector<std::string> board);
