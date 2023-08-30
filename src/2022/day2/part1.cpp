// Copyright 2023 Dylan Thomas
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../include/cli.hpp"
#include "day2.hpp"  // NOLINT(build/include_subdir)

enum class Hand {
    Rock,
    Paper,
    Scissors,
};

const std::unordered_map<Hand, uint64_t> HAND_SCORE = {
    {Hand::Rock, 1},
    {Hand::Paper, 2},
    {Hand::Scissors, 3},
};

enum class Outcome {
    Loss,
    Tie,
    Win,
};

const std::unordered_map<Outcome, uint64_t> OUTCOME_SCORE = {
    {Outcome::Loss, 0},
    {Outcome::Tie, 3},
    {Outcome::Win, 6},
};

Hand decodeHand(const char shape) {
    switch (shape) {
        case 'A':
        case 'X':
            return Hand::Rock;
            break;
        case 'B':
        case 'Y':
            return Hand::Paper;
            break;
        case 'C':
        case 'Z':
            return Hand::Scissors;
            break;
        default:
            throw std::runtime_error("Bad shape value: " + shape);
            break;
    }
}

Outcome getOutcome(const Hand my_hand, const Hand other_hand) {
    if (my_hand == other_hand) {
        return Outcome::Tie;
    }

    if (my_hand == Hand::Rock) {
        return other_hand == Hand::Scissors ? Outcome::Win : Outcome::Loss;
    }

    if (my_hand == Hand::Paper) {
        return other_hand == Hand::Rock ? Outcome::Win : Outcome::Loss;
    }

    if (my_hand == Hand::Scissors) {
        return other_hand == Hand::Paper ? Outcome::Win : Outcome::Loss;
    }

    throw std::runtime_error("Bad outcome");
}

int main(int narg, char const* argv[]) {
    int error = aoc::check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    const std::string filename(argv[1]);
    std::vector<day2::Round> rounds = day2::parse_input(filename);

    uint64_t total_score = 0;
    for (auto iter = rounds.begin(); iter != rounds.end(); iter++) {
        Hand other_hand = decodeHand(std::get<0>(*iter));
        Hand my_hand = decodeHand(std::get<1>(*iter));
        Outcome round_outcome = getOutcome(my_hand, other_hand);

        uint64_t current_score = HAND_SCORE.at(my_hand) + OUTCOME_SCORE.at(round_outcome);
        total_score += current_score;
    }

    std::cout << "Calculated score " << total_score << std::endl;

    return EXIT_SUCCESS;
}
