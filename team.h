#ifndef _TEAM_H__
#define _TEAM_H__

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#include "player.h"
#include "stadium.h"

#define GOALKEEPER "goalkeeper"
#define DEFENDER "defender"
#define MIDFIELDER "midfielder"
#define STRIKER "striker"

#define GOALKEEPER_MIN_NUMBER 1
#define DEFENDER_MIN_NUMBER 3
#define MIDFIELDER_MIN_NUMBER 3
#define STRIKER_MIN_NUMBER 2
#define FORCED_PLAYER_NUMBER 9
#define SQUAD_PLAYER_NUMBER 11


class Team {
public:
    Team(std::string team_name, std::string stadium_name, int capacity, float impact, 
    	std::map<std::string, int> _fans_in_stadium);
    void add_player(std::string player_name, int power, std::string player_position);
    bool is_valid();
    void generate_squad();

    void set_participation_status(bool state);
    bool is_participating();
    std::string get_name() {return name;}
	
	int get_defend_power();
    int get_midfield_power();
    int get_attack_power();
    int get_goalkeeper_power();
    void sort_players();

    int get_fans_impact(Team* team = NULL);
private:
    std::string name;
    Stadium stadium;
    std::map<std::string, int> fans_in_stadium;
    bool participating;
    std::vector<Player> players;
    std::vector<Player> squad_players;
};

bool player_sorter(Player const& first, Player const& last);


#endif