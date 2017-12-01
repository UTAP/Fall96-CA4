#include "round.h"

using namespace std;

Round::Round(vector<Team*> in_cup_teams, int number) 
    : teams(in_cup_teams), round_number(number){
    sort_teams();
    for (int i = 0, number = 1; i < teams.size(); i += 2, number++)
        matches.push_back(Match(teams[i], teams[i+1], number));
}

void Round::sort_teams() {
    sort(teams.begin(), teams.end(), &team_sorter);
}

bool team_sorter (Team* const& first, Team* const& last) {
    return first->get_name() < last->get_name();
}

void Round::simulate() {
    for (int i = 0; i < matches.size(); ++i) {
        matches[i].simulate();
        matches[i].determine_winner();
    }
}

void Round::print_round() {
    cout << "Round " << round_number << endl;
    for (int i = 0; i < matches.size() ; i++ ){
        matches[i].print_match();
    }
}

void Round::print_team_result(Team* team) {
    if (is_team_in_round(team)) {
        cout << "Round " << round_number << endl;
        for (int i = 0; i < matches.size(); ++i)
            if (matches[i].contains(team))
                matches[i].print_match();
    }
}

bool Round::is_team_in_round(Team* team) {
    for (int i = 0; i < teams.size(); ++i)
        if (teams[i] == team)
            return true;
    return false;
}