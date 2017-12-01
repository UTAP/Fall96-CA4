#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include <cstdlib>

class Player {
public:
    Player(std::string _name, int _power, std::string _position);
    std::string get_name() { return name;}
    int get_power() const { return power;}
    std::string get_position() { return position;}
private:
    std::string name;
    int power;
    std::string position;
};

#endif