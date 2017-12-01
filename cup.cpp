#include "cup.h"

using namespace std;

void Cup::add_team(string team_name, string stadium_name, int capacity, float impact, map<string, int> fans_in_stadium) {
    teams.push_back(new Team(team_name, stadium_name, capacity, impact, fans_in_stadium));
}

void Cup::add_player(string team_name, string player_name, int player_power, string player_post) {
    int index = get_team_index(team_name);
    if (index == NOT_FOUND)
        abort();
    teams[index]->add_player(player_name, player_power, player_post);
}

int Cup::get_team_index(string team_name) {
    for (int i = 0; i < teams.size(); i++)
        if (teams[i]->get_name() == team_name)
            return i;
    return NOT_FOUND;
}

void Cup::simulate(){
    check_teams();
    vector<Team*> in_cup_teams = get_in_cup_teams();
    if(validate_number_of_teams(in_cup_teams)){
        int round_number = 1;
        while(in_cup_teams.size() != 1){
            Round new_round(in_cup_teams, round_number);   
            new_round.simulate();
            rounds.push_back(new_round);

            in_cup_teams = get_in_cup_teams();
            round_number++;
        }
    }
}

vector<Team*> Cup::get_in_cup_teams() {
    vector<Team*> in_cup_teams;
    for (int i = 0; i < teams.size(); i++)
        if (teams[i]->is_participating())
            in_cup_teams.push_back(teams[i]);
    return in_cup_teams;
}


void Cup::check_teams() {
    for (int i = 0; i < teams.size() ; i++ ) {
        if (!teams[i]->is_valid()) {
            teams[i]->set_participation_status(false);
            cout << "Inadequate players in " << teams[i]->get_name() << endl;
        }
        else
            teams[i]->generate_squad();
    }
}

bool Cup::validate_number_of_teams(vector<Team*> in_cup_teams) {
    int n = teams.size();
    if ((n == 0) or ((n & (n-1)) != 0)) {
        cout << "Inadequate teams" << endl;
        return false;
    }
    return true;
}

void Cup::print_tournament_results() {
    for (int i = 0; i < rounds.size(); i++)
        rounds[i].print_round();
}

void Cup::print_round_results(int round_number) {
    rounds[round_number-1].print_round();
}

void Cup::print_team_results(string team_name) {
    Team* team = teams[get_team_index(team_name)];
    for (int i = 0; i < rounds.size(); i++)
        rounds[i].print_team_result(team);
}