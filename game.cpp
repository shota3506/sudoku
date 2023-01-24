#include "game.hpp"

#include <cassert>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "board.hpp"
#include "solver.hpp"

using namespace std;

void Game::Play() {
  Board board = Board(size);

  bool ok = solver->Solve(&board, true);
  assert(ok);

  Board answer = board;

  vector<int> indices(size * size);
  for (int i = 0; i < size * size; i++) {
    indices[i] = i;
  }
  shuffle(indices.begin(), indices.end(), rng);

  for (vector<int>::iterator i = indices.begin();
       i != indices.end() - prefilled; i++) {
    int x = (*i) % size;
    int y = (*i) / size;
    board(x, y) = 0;  // clear cell
  }

  board.Print();

  cout << endl << "show answer y/n: ";
  string resp;
  cin >> resp;
  if (resp == "y" || resp == "yes") {
    cout << endl;
    answer.Print();
  }
}
