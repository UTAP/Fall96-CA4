#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include <cmath>

#include "team.h"

class Leg {
public:
    Leg(Team* _home, Team* _away);
    void simulate();
    int get_num_of_goals(int home_attack, int home_midfield, int away_deffend, int away_midfield);
    int get_home_goals() {return home_goals;};
    int get_away_goals() {return away_goals;};
    void print_leg();
private:
    Team* home;
    Team* away;

    int home_goals;
    int away_goals;
};

#endif