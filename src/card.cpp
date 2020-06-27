#include "card.h"

Card::Card()
{
}

Card::Card(string name, int value, string suit, string symbol)
{
    Card::name = name;
    Card::value = value;
    Card::suit = suit;
    Card::symbol = symbol;
}

string Card::getName()
{
    return name;
}

int Card::getValue()
{
    return value;
}

string Card::getSuit()
{
    return suit;
}

string Card::getSymbol()
{
    return symbol;
}