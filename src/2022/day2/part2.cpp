// Copyright 2023 Dylan Thomas
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include "../include/cli.hpp"
#include "day2.hpp"  // NOLINT(build/include_subdir)

enum Hand : int64_t {
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
            return Hand::Rock;
            break;
        case 'B':
            return Hand::Paper;
            break;
        case 'C':
            return Hand::Scissors;
            break;
        default:
            throw std::runtime_error("Bad shape value: " + shape);
            break;
    }
}

Outcome decodeRound(const char round) {
    switch (round) {
        case 'X':
            return Outcome::Loss;
            break;
        case 'Y':
            return Outcome::Tie;
            break;
        case 'Z':
            return Outcome::Win;
            break;
        default:
            throw std::runtime_error("Bad outcome value: " + round);
            break;
    }
}

int64_t mod(int64_t a, int64_t b) { return ((a % b) + b) % b; }

Hand getHand(const Outcome round, const Hand other_hand) {
    if (round == Outcome::Tie) {
        return other_hand;
    }
    int64_t hand_val;
    if (round == Outcome::Loss) {
        hand_val = mod((other_hand - 1), 3);
    } else if (round == Outcome::Win) {
        hand_val = mod((other_hand + 1), 3);
    }

    return static_cast<Hand>(hand_val);
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
        Outcome round_outcome = decodeRound(std::get<1>(*iter));
        Hand my_hand = getHand(round_outcome, other_hand);

        uint64_t current_score = HAND_SCORE.at(my_hand) + OUTCOME_SCORE.at(round_outcome);
        total_score += current_score;
    }

    std::cout << "Calculated score " << total_score << std::endl;

    return EXIT_SUCCESS;
}
