#pragma once

#include <random>

#include "board.hpp"

using namespace std;

class BacktrackSolver {
  mt19937 rng;

  bool inner(Board *board, int x, int y, bool random);

 public:
  BacktrackSolver(mt19937 _rng) : rng(_rng){};
  bool Solve(Board *board, bool random = false);
};
