#ifndef __TOURNAMENT_H__
#define __TOURNAMENT_H__

#include <iostream>
#include <string>
#include <map>

#include "cup.h"

class Tournament {
public:
    Tournament(){};
    void add_team(std::string team_name, std::string stadium_name, int capacity, float impact, 
    	std::map<std::string, int> fans_in_stadium);
    void add_player(std::string team_name, std::string player_name, int player_power, std::string player_post);
    void simulate();
    void print_round_results(int round_number);
    void print_tournament_results();
    void print_team_results(std::string team_name);
private:
    Cup cup;
};

#endif