//
// Created by Finn on 25/08/2022.
//

#ifndef AP_FA1_GAME_H
#define AP_FA1_GAME_H

#include <string>
#include <cmath>
#include <ostream>

using namespace std;

class Game {
private:
    string title;
    int releaseDate;
    float originalPrice;

public:
    Game(const string &title, int releaseDate, float originalPrice);

    const string &getTitle() const;

    int getReleaseDate() const;

    float getOriginalPrice() const;

    void setTitle(const string &title);

    void setReleaseDate(int releaseDate);

    void setOriginalPrice(float originalPrice);

    float calculateCurrentPrice();

    bool operator==(const Game &rhs) const;

    bool operator!=(const Game &rhs) const;

    friend ostream &operator<<(ostream &os, const Game &game);
};


#endif //AP_FA1_GAME_H
