#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

class Deck
{

private:
    vector<Card> deck;

public:
    Deck();
    void shuffle();
    void printDeck();
    Card drawCard();
    bool isEmpty();
};

#endif