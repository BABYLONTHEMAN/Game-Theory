#include <iostream>
#include <ctime>
#include <cstdlib>

enum class Choice { COOPERATE, DEFECT };

// Payoff matrix for Prisoner's Dilemma
const int payoff_cooperate = 3;
const int payoff_defect_self = 5;
const int payoff_defect_other = 0;

// Function to simulate a player's choice
Choice makeChoice() {
    return (rand() % 2 == 0) ? Choice::COOPERATE : Choice::DEFECT;
}

// Function to calculate payoff for a player
int calculatePayoff(Choice playerChoice, Choice opponentChoice) {
    if (playerChoice == Choice::COOPERATE && opponentChoice == Choice::COOPERATE) {
        return payoff_cooperate;
    }
    else if (playerChoice == Choice::COOPERATE && opponentChoice == Choice::DEFECT) {
        return payoff_defect_other;
    }
    else if (playerChoice == Choice::DEFECT && opponentChoice == Choice::COOPERATE) {
        return payoff_defect_self;
    }
    else { // Both players defect
        return 1;
    }
}

int main() {
    srand(time(nullptr));

    const int numRounds = 1000;
    int totalPayoffPlayer1 = 0, totalPayoffPlayer2 = 0;

    for (int i = 0; i < numRounds; ++i) {
        Choice player1Choice = makeChoice();
        Choice player2Choice = makeChoice();

        int payoffPlayer1 = calculatePayoff(player1Choice, player2Choice);
        int payoffPlayer2 = calculatePayoff(player2Choice, player1Choice);

        totalPayoffPlayer1 += payoffPlayer1;
        totalPayoffPlayer2 += payoffPlayer2;
    }

    std::cout << "Total payoff for Player 1: " << totalPayoffPlayer1 << std::endl;
    std::cout << "Total payoff for Player 2: " << totalPayoffPlayer2 << std::endl;

    if (totalPayoffPlayer1 > totalPayoffPlayer2) {
        std::cout << "Player 1 wins!" << std::endl;
    }
    else if (totalPayoffPlayer1 < totalPayoffPlayer2) {
        std::cout << "Player 2 wins!" << std::endl;
    }
    else {
        std::cout << "It's a tie!" << std::endl;
    }

    return 0;
}
