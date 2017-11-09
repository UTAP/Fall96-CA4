#include "tournament.h"

using namespace std;

#define TEAM_NUMBER 4
#define RANDOM_SEED 12345678

#define GOALKEEPER "goalkeeper"
#define DEFENDER "defener"
#define MIDFIELDER "midfielder"
#define STRIKER "striker"

int main(){
	Tournament ap_cup(TEAM_NUMBER, RANDOM_SEED);

	ap_cup.add_team("Barcelona", "Camp Nou", 5);
	ap_cup.add_player("Barcelona", "Ter Stegen", 85, GOALKEEPER);
	ap_cup.add_player("Barcelona", "Sergi Roberto", 81, DEFENDER);
	ap_cup.add_player("Barcelona", "Pique", 87, DEFENDER);
	ap_cup.add_player("Barcelona", "Umtiti", 83, DEFENDER);
	ap_cup.add_player("Barcelona", "Alba", 85, DEFENDER);
	ap_cup.add_player("Barcelona", "Rakitic", 87, MIDFIELDER);
	ap_cup.add_player("Barcelona", "Busquets", 86, MIDFIELDER);
	ap_cup.add_player("Barcelona", "Iniesta", 87, MIDFIELDER);
	ap_cup.add_player("Barcelona", "Suarez", 92, STRIKER);
	ap_cup.add_player("Barcelona", "Messi", 93, STRIKER);
	ap_cup.add_player("Barcelona", "Dembele", 83, STRIKER);


	// adding other teams

	ap_cup.simulate();

	ap_cup.print_tournament_results();
	ap_cup.print_round_results(1);
	ap_cup.print_team_results("Barcelona");

	return 0;
}