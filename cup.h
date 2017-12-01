#ifndef __CUP_H__
#define __CUP_H__

#include <iostream>
#include <vector>
#include <cstdlib>

#include "team.h"
#include "round.h"

#define NOT_FOUND -1

class Cup {
public:
    Cup(){};
    void add_team(std::string team_name, std::string stadium_name, int capacity, float impact,
        std::map<std::string, int> fans_in_stadium);
    void add_player(std::string team_name, std::string player_name, int player_power, std::string player_post);
    void simulate();
    void print_round_results(int round_number);
    void print_tournament_results();
    void print_team_results(std::string team_name);

    int get_team_index(std::string team_name);
    bool validate_number_of_teams(std::vector<Team*> in_cup_teams);
    void check_teams();
    std::vector<Team*> get_in_cup_teams();
    void check_num_of_teams();
private:
    std::vector<Team*> teams;
    std::vector<Round> rounds;
};

#endif