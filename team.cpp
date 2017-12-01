#include "team.h"

using namespace std;

Team::Team(string team_name, string stadium_name, int capacity, float impact, map<string, int> _fans_in_stadium)
    : stadium(stadium_name, capacity, impact), name(team_name), fans_in_stadium(_fans_in_stadium){
        participating = true;
}

void Team::add_player(string player_name, int power, string player_position) {
    players.push_back(Player (player_name, power, player_position));
}

bool Team::is_valid() {
    if (players.size() < 11)
        return false;
    int goalkeeper_count = 0, midfielders_count = 0, deffender_count = 0, striker_count = 0;
    for (int i = 0; i < players.size(); i++) {
        if (players[i].get_position() == GOALKEEPER) 
            goalkeeper_count++;
        else if (players[i].get_position() == DEFENDER)
            deffender_count++;
        else if (players[i].get_position() == MIDFIELDER)
            midfielders_count++;
        else
            striker_count++;
    }
    if ((goalkeeper_count < GOALKEEPER_MIN_NUMBER) or (deffender_count < DEFENDER_MIN_NUMBER) 
        or (midfielders_count < MIDFIELDER_MIN_NUMBER) or (striker_count < STRIKER_MIN_NUMBER)) 
        return false;
    return true;
}

bool player_sorter(Player const& first, Player const& last) {
    return first.get_power() > last.get_power();
}

void Team::sort_players() {
    sort(players.begin(), players.end(), &player_sorter);
}

void Team::generate_squad() {
    sort_players();
    vector<Player> all_players = players;

    int goal_count = GOALKEEPER_MIN_NUMBER;
    int mid_count = MIDFIELDER_MIN_NUMBER;
    int def_count = DEFENDER_MIN_NUMBER;
    int strike_count = STRIKER_MIN_NUMBER;

    int i = 0; 
    while (i < all_players.size()) {
        if ((all_players[i].get_position() == GOALKEEPER) && (goal_count > 0))
            goal_count--;
        else if ((all_players[i].get_position() == DEFENDER) && (def_count > 0))
            def_count--;
        else if ((all_players[i].get_position() == MIDFIELDER) && (mid_count > 0))
            mid_count--;
        else if ((all_players[i].get_position() == STRIKER) && (strike_count > 0))
            strike_count--;
        else {
            i++;
            continue;
        }
        squad_players.push_back(all_players[i]);
        all_players.erase(all_players.begin() + i);
    }
    for (i = 0; i < SQUAD_PLAYER_NUMBER - FORCED_PLAYER_NUMBER; i++) {
        if ((all_players[i].get_position() != GOALKEEPER))
            squad_players.push_back(all_players[i]);
    }
}

int Team::get_defend_power() {
    int keeper_power = 0;
    int defenders_power = 0;
    int num_of_defenders = 0;
    for (int i = 0; i < squad_players.size() ; i++ ) {
        if (squad_players[i].get_position() == DEFENDER) {
            num_of_defenders++;
            defenders_power += squad_players[i].get_power();
        }
        else if (squad_players[i].get_position() == GOALKEEPER) {
            keeper_power = squad_players[i].get_power();
        }
    }
    float num = (keeper_power + defenders_power)  * sqrt((float)num_of_defenders / 4);
    float den = (((float)num_of_defenders + 1));
    return floor(num/den);
}

int Team::get_goalkeeper_power() {
    for (int i = 0; i < squad_players.size() ; i++)
        if (squad_players[i].get_position() == GOALKEEPER)
            return (float)squad_players[i].get_power();
    return 0;
}

int Team::get_midfield_power() {
    int mid_power = 0;
    int num_of_midfielders = 0;
    for (int i = 0; i < squad_players.size() ; i++ ) {
        if (squad_players[i].get_position() == MIDFIELDER) {
            num_of_midfielders++;
            mid_power += squad_players[i].get_power();
        }
    }
    float num = ((float) mid_power) * sqrt((float)num_of_midfielders / 3);
    float den = (((float)num_of_midfielders ));
    return floor(num/den);
}

int Team::get_attack_power() {
    int strike_power = 0;
    int num_of_strikers = 0;
    for (int i = 0; i < squad_players.size() ; i++ ) {
        if (squad_players[i].get_position() == STRIKER) {
            num_of_strikers++;
            strike_power += squad_players[i].get_power();
        }
    }
    float num = ((float) strike_power) * sqrt(((float)num_of_strikers / 3));
    float den = (((float)num_of_strikers)) ;
    return floor(num/den);
}

void Team::set_participation_status(bool state) {
    participating = state;
}

bool Team::is_participating() {
    return participating;
}

int Team::get_fans_impact(Team* team) {
    int home_fans_num = fans_in_stadium[stadium.get_name()];
    if (team == NULL)
        return stadium.get_impact(home_fans_num);

    int capacity = stadium.get_capacity();
    int away_fans_num = team->fans_in_stadium[stadium.get_name()];
    if (away_fans_num > capacity - home_fans_num)
        away_fans_num = capacity - home_fans_num;
    return stadium.get_impact(away_fans_num);
}

