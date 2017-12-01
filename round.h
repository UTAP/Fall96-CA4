#ifndef __ROUND_H__
#define __ROUND_H__

#include <iostream>
#include <vector>

#include "team.h"
#include "match.h"

#define NOT_FOUND -1

class Round {
public:
    Round(std::vector<Team*> in_cup_teams, int round_number);
    void sort_teams();
    void simulate();

    void print_round();
    void print_team_result(Team* team);
    bool is_team_in_round(Team* team);
private:
    std::vector<Team*> teams;
    std::vector<Match> matches;
    int round_number;
};

bool team_sorter (Team* const& first, Team* const& last);

#endif