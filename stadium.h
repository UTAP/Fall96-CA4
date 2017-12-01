#ifndef __STADIUM_H__
#define __STADIUM_H__

#include <iostream>
#include <string>
#include <cstdlib>

class Stadium {
public:
    Stadium(std::string _name, int _capacity, float _impact);
    float get_impact(int team_fans);
    std::string get_name() { return name;}
    int get_capacity() { return capacity;}
private:
    std::string name;
    int capacity;
    float impact;
};

#endif