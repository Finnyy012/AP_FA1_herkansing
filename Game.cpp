//
// Created by Finn on 25/08/2022.
//

#include "Game.h"

Game::Game(const string &title, int releaseDate, float originalPrice) : title(title), releaseDate(releaseDate),
                                                                        originalPrice(originalPrice) {}

const string &Game::getTitle() const {
    return title;
}

int Game::getReleaseDate() const {
    return releaseDate;
}

float Game::getOriginalPrice() const {
    return originalPrice;
}

void Game::setTitle(const string &title) {
    Game::title = title;
}

void Game::setReleaseDate(int releaseDate) {
    Game::releaseDate = releaseDate;
}

void Game::setOriginalPrice(float originalPrice) {
    Game::originalPrice = originalPrice;
}

float Game::calculateCurrentPrice(){
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int diff = tm_local->tm_year + 1900 - releaseDate;
    return (originalPrice*pow(0.7, diff));
}

bool Game::operator==(const Game &rhs) const {
    return title == rhs.title &&
           releaseDate == rhs.releaseDate &&
           originalPrice == rhs.originalPrice;
}

bool Game::operator!=(const Game &rhs) const {
    return !(rhs == *this);
}

ostream &operator<<(ostream &os, const Game &game) {
    os << "title: " << game.title << " releaseDate: " << game.releaseDate << " originalPrice: " << game.originalPrice;
    return os;
}
