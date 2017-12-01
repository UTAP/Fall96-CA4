#include "stadium.h"

using namespace std;

Stadium::Stadium(string _name, int _capacity, float _impact) 
	: name(_name), capacity(_capacity), impact(_impact) {}

float Stadium::get_impact(int team_fans) {
	return ((float)team_fans * impact) / (float)capacity;
}
