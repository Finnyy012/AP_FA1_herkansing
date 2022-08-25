#include <iostream>
#include "Game.h"
#include "Person.h"

using namespace std;

int main() {
    time_t result = time(NULL);
    cout << asctime(localtime(&result));
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int releaseDate1 = tm_local->tm_year + 1899; // 1 jaar geleden
    int releaseDate2 = tm_local->tm_year + 1898; // 2 jaar geleden

    Game g1("Just Cause 3", releaseDate1 , 49.98);
    Game g2("Need for Speed: Rivals", releaseDate2 , 45.99);
    Game g3("Need for Speed: Rivals", releaseDate2 , 45.99);

    Person p1("Eric", 200);
    Person p2("Hans", 55);
    Person p3("Arno", 185);

    // Druk de volgende transacties af (pas de code aan)
    cout << p1.buy(g1) << endl;
    cout << p1.buy(g2) << endl;
    cout << p1.buy(g3) << endl;
    cout << p2.buy(g2) << endl;
    cout << p2.buy(g1) << endl;
    cout << p3.buy(g3) << endl;

    // Druk personen p1, p2 en p3 nu af naar de console
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;


    // Druk de volgende transacties af (pas de code aan)
    cout << p1.sell(g1, p3) << endl;
    cout << p2.sell(g2, p3) << endl;
    cout << p2.sell(g1, p1) << endl;

    // Druk personen p1, p2 en p3 nu af naar de console
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
}
