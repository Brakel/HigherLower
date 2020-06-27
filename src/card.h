#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card
{
private:
    string name;
    int value;
    string suit;
    string symbol;

public:
    Card();
    Card(string, int, string, string);
    string getName();
    int getValue();
    string getSuit();
    string getSymbol();
};

#endif