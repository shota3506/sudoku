#pragma once

#include <random>

#include "board.hpp"
#include "solver.hpp"

using namespace std;

class Game {
  int size;
  int prefilled;
  mt19937 rng;
  BacktrackSolver *solver;

 public:
  Game(int _size, int _prefilled, mt19937 _rng)
      : size(_size), prefilled(min(_size * _size, _prefilled)) {
    rng = mt19937(_rng());  // split rng
    solver = new BacktrackSolver(mt19937(_rng()));
  }

  ~Game() { delete solver; }

  void Play();
};
