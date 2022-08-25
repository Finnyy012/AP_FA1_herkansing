//
// Created by Finn on 25/08/2022.
//

#include "Person.h"

Person::Person(const string &name, float budget) : budget(budget), name(name) {}

bool Person::buy(Game& game){
    float price = game.calculateCurrentPrice();
    if(!count(games.begin(), games.end(), game) && price<=budget){
        budget=budget-price;
        games.push_back(game);
        return true;
    }
    return false;
}

bool Person::sell(Game& game, Person& buyer){
    if(count(games.begin(), games.end(), game)) {
        if(buyer.buy(game)){
            games.remove(game);
            budget = budget+game.calculateCurrentPrice();
            return true;
        }
    }
    return false;
}

void Person::addGame(Game game) {
    games.push_back(game);
}

void Person::removeGame(Game game) {
    games.remove(game);
}

float Person::getBudget() const {
    return budget;
}

const string &Person::getName() const {
    return name;
}

const list<Game> &Person::getGames() const {
    return games;
}

void Person::setBudget(float budget) {
    Person::budget = budget;
}

void Person::setName(const string &name) {
    Person::name = name;
}

void Person::setGames(const list<Game> &games) {
    Person::games = games;
}

bool Person::operator==(const Person &rhs) const {
    return budget == rhs.budget &&
           name == rhs.name &&
           games == rhs.games;
}

bool Person::operator!=(const Person &rhs) const {
    return !(rhs == *this);
}

ostream &operator<<(ostream &os, const Person &person) {
    string gameStr;
    for(const auto& i : person.games){
        gameStr += (i.getTitle() + "; ");
    }
    os << "name: " << person.name << " budget: " << person.budget << " games: " << gameStr;
    return os;
}


