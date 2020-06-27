#include <iostream>
#include <limits>
#undef max
#include "deck.h"

using namespace std;

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int validateIntInput(string output)
{
    int input;

    cout << output;
    cin >> input;
    while (1)
    {
        if (cin.fail())
        {
            clearInput();
            cout << "Invalid input" << endl;
            cout << output;
            cin >> input;
        }
        else
        {
            break;
        }
    }

    return input;
}

string validateStringInput(string output)
{
    string input;

    cout << output;
    cin >> input;
    while (1)
    {
        if (cin.fail())
        {
            clearInput();
            cout << "Invalid input" << endl;
            cout << output;
            cin >> input;
        }
        else
        {
            break;
        }
    }

    return input;
}

char validateGuess(string output)
{
    char input;

    cout << output;
    cin >> input;
    while (1)
    {
        if (cin.fail() || (input != '+' && input != '-'))
        {
            clearInput();
            cout << "Invalid input" << endl;
            cout << output;
            cin >> input;
        }
        else
        {
            break;
        }
    }

    return input;
}

int main()
{
    int correctGuess = 0;
    int drinkAmount = 1;
    bool gameOver = false;

    // Create a new deck of cards
    Deck deck = Deck();
    // Shuffle the deck - twice for better results
    deck.shuffle();
    deck.shuffle();

    cout << endl
         << endl;
    cout << "Enter + for higher and - for lower" << endl
         << endl;

    while (!gameOver)
    {
        char currentGuess;
        Card lastCard;
        Card currentCard = deck.drawCard();

        cout << currentCard.getSuit() << currentCard.getName()
             << currentCard.getSuit();

        currentGuess = validateGuess(" - Higher or lower?: ");
        lastCard = currentCard;
        currentCard = deck.drawCard();
        if (currentGuess == '+' && currentCard.getValue() > lastCard.getValue())
        {
            ++correctGuess;
            ++drinkAmount;
            cout << currentCard.getSuit() << currentCard.getName()
                 << currentCard.getSuit();
            cout << " - Correct!" << endl
                 << endl;
        }
        else if (currentGuess == '-' && currentCard.getValue() < lastCard.getValue())
        {
            ++correctGuess;
            ++drinkAmount;
            cout << currentCard.getSuit() << currentCard.getName()
                 << currentCard.getSuit();
            cout << " - Correct!" << endl
                 << endl;
        }
        else
        {
            correctGuess = 0;
            if (drinkAmount == 1)
            {
                cout << currentCard.getSuit() << currentCard.getName()
                     << currentCard.getSuit();
                cout << " - Incorrect - Have " << drinkAmount << " drink!" << endl
                     << endl;
            }

            else
            {
                cout << currentCard.getSuit() << currentCard.getName()
                     << currentCard.getSuit();
                cout << " - Incorrect - Have " << drinkAmount << " drinks!" << endl
                     << endl;
                drinkAmount = 1;
            }
        }

        if (deck.isEmpty())
            gameOver = true;
    }

    return 0;
}