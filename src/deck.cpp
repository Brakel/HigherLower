#include <random>
#include <iostream>
#include "deck.h"

const string names[13] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
                          "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
const int values[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
const string suits[4] = {"\u2665", "\u2666", "\u2660", "\u2663"};
const string symbols[13] = {"2", "3", "4", "5", "6", "7", "8",
                            "9", "10", "J", "Q", "K", "A"};

// Initialise Card array
Deck::Deck()
{
    for (int i = 0; i < 13; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            deck.push_back(Card(names[i], values[i], suits[j], symbols[i]));
        }
    }
}

// Use a random number generator and create a random distribution between 0-51
// Use this distribution to swap cards in the array
void Deck::shuffle()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 51);

    for (int i = 0; i < deck.size(); ++i)
    {
        int r = dist(mt);
        swap(deck[i], deck[r]);
    }
}

// Loop through the array and print out each card
void Deck::printDeck()
{
    for (int i = 0; i < deck.size(); ++i)
    {
        cout << deck[i].getName() << deck[i].getSuit() << endl;
    }
}

Card Deck::drawCard()
{
    Card drawn = deck.back();
    deck.pop_back();

    return drawn;
}

bool Deck::isEmpty()
{
    if (deck.size() != 0)
    {
        return false;
    }
    return true;
}