#include "tournament.h"

using namespace std;

void Tournament::add_team(string team_name, string stadium_name, int capacity, float impact,
 	map<string, int> fans_in_stadium) {
    cup.add_team(team_name, stadium_name, capacity, impact, fans_in_stadium);
}

void Tournament::add_player(string team_name, string player_name, int player_power, string player_post) {
    cup.add_player(team_name, player_name, player_power, player_post);
}

void Tournament::simulate() {
    cup.simulate();
}

void Tournament::print_round_results(int round_number) {
    cup.print_round_results(round_number);
}

void Tournament::print_tournament_results() {
    cup.print_tournament_results();
}

void Tournament::print_team_results(string team_name) {
    cup.print_team_results(team_name);
}
