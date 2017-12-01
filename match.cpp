#include "match.h"

using namespace std;

Match::Match(Team* home, Team* away, int number) 
    : first_leg(home, away), second_leg(away, home), match_number(number), first_team(home), second_team(away) {
        winner = NULL;
    }

void Match::simulate() {
    first_leg.simulate();
    second_leg.simulate();
}

void Match::determine_winner() {
    if (first_leg.get_home_goals() + second_leg.get_away_goals() > second_leg.get_home_goals() + first_leg.get_away_goals()) {
        second_team->set_participation_status(false);
        winner = first_team;
    }
    else if (first_leg.get_home_goals() + second_leg.get_away_goals() < second_leg.get_home_goals() + first_leg.get_away_goals()) {
        first_team->set_participation_status(false);
        winner = second_team;
    }
    else if (first_leg.get_home_goals() > second_leg.get_home_goals()) {
        second_team->set_participation_status(false);
        winner = first_team;
    }
    else if (first_leg.get_home_goals() < second_leg.get_home_goals()) {
        first_team->set_participation_status(false);
        winner = second_team;
    }
    else
        penalty_time();
}

void Match::penalty_time() {
    int first_team_fans_impact = second_team->get_fans_impact(first_team); 
    int second_team_fans_impact = second_team->get_fans_impact(); 

    float prob1 = ((float)first_team->get_attack_power() + first_team_fans_impact) / (second_team->get_goalkeeper_power());
    float prob2 = ((float)second_team->get_attack_power() + second_team_fans_impact) / (first_team->get_goalkeeper_power());

    if (prob1 > prob2) {
        second_team->set_participation_status(false);
        winner = first_team;
    }
    else {
        first_team->set_participation_status(false);
        winner = second_team;
    }

}

void Match::print_match() {
    cout << match_number << ":" << endl;
    first_leg.print_leg();
    second_leg.print_leg();
    cout << '\t' << "=> winner: " << winner->get_name() << endl;
}

bool Match::contains(Team* team) {
    return (team == first_team) or (team == second_team);
}
