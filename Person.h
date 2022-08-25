//
// Created by Finn on 25/08/2022.
//

#ifndef AP_FA1_PERSON_H
#define AP_FA1_PERSON_H

#include <string>
#include <list>
#include <algorithm>
#include <ostream>

#include "Game.h"

using namespace std;

class Person {
private:
    float budget;
    string name;
    list<Game> games;

public:
    Person(const string &name, float budget);

    bool buy(Game& game);

    bool sell(Game& game, Person& buyer);

    void addGame(Game game);

    void removeGame(Game game);

    float getBudget() const;

    const string &getName() const;

    const list<Game> &getGames() const;

    void setBudget(float budget);

    void setName(const string &name);

    void setGames(const list<Game> &games);

    bool operator==(const Person &rhs) const;

    bool operator!=(const Person &rhs) const;

    friend ostream &operator<<(ostream &os, const Person &person);
};


#endif //AP_FA1_PERSON_H
