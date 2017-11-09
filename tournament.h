#ifndef __TOURNAMENT_H__
#define __TOURNAMENT_H__

#include "team.h"
#include "round.h"

#include <vector>
#include <string>

class Tournament
{
private:
	std::vector<Team> teams;
	std::vector<Round> rounds;
public:
	Tournament(int num_of_teams, int random_seed);
	void add_team(std::string team_name, std::string stadium_name, int stadium_impact);
	void add_player(std::string team_name, std::string player_name, 
		std::string player_power, std::string player_post);
	void simulate();
	void print_tournament_results();
	void print_round_results(int round_number);
	void print_team_results();
};

#endif