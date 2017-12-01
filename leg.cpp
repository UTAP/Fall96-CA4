#include "leg.h"

using namespace std;

Leg::Leg(Team* _home, Team* _away) 
    : home(_home), away(_away){
    home_goals = 0;
    away_goals = 0;
}

void Leg::simulate() {
    int home_fans_impact = home->get_fans_impact(); 
    int away_fans_impact = home->get_fans_impact(away); 

    int home_deffend = home->get_defend_power() + home_fans_impact;
    int home_midfield = home->get_midfield_power() + home_fans_impact;
    int home_attack = home->get_attack_power() + home_fans_impact;

    int away_deffend = away->get_defend_power() + away_fans_impact;
    int away_midfield = away->get_midfield_power() + away_fans_impact;
    int away_attack = away->get_attack_power() + away_fans_impact;

    home_goals = get_num_of_goals(home_attack, home_midfield, away_deffend, away_midfield);
    away_goals = get_num_of_goals(away_attack, away_midfield, home_deffend, home_midfield);
}

int Leg::get_num_of_goals(int home_attack, int home_midfield, int away_deffend, int away_midfield) {
    float result = (float)(home_attack * home_midfield) / (float)(away_midfield * away_deffend);
    return floor(3 * result * sqrt(result));
}

void Leg::print_leg() {
    cout << '\t' << home->get_name() << ' ' << home_goals << " - " << away_goals << ' ' << away->get_name() << endl;
}
