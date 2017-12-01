#ifndef __MATCH_H__
#define __MATCH_H__

#include <iostream>

#include "leg.h"
#include "team.h"

class Match {
public:
    Match(Team* home, Team* away, int match_number);
    void simulate();
    void determine_winner();
    void penalty_time();
    bool contains(Team* team);

    Team* run_match();
    void print_match();
private:
    Leg first_leg;
    Leg second_leg;
    Team* first_team;
    Team* second_team;
    Team* winner;
    int match_number;
};

#endif