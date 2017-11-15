#ifndef __TOURNAMENT_H__
#define __TOURNAMENT_H__

#include "team.h"
#include "round.h"

#include <vector>
#include <string>
#include <map>

class Tournament
{
private:
	std::vector<Team> teams;
	std::vector<Round> rounds;
public:
	Tournament(){};
	void add_team(std::string team_name, std::string stadium_name, int stadium_capacity,
		int stadium_impact, std::map<std::string, int> fans_in_stadium);
	void add_player(std::string team_name, std::string player_name, 
		int player_power, std::string player_post);
	void simulate();
	void print_tournament_results();
	void print_round_results(int round_number);
	void print_team_results(std::string team_name);
};

#endif