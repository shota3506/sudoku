#include "solver.hpp"

#include <random>
#include <vector>

#include "board.hpp"

using namespace std;

bool BacktrackSolver::inner(Board *board, int x, int y, bool random) {
  const int size = board->GetSize();

  if (x >= size || y >= size) return true;

  if ((*board)(x, y) != 0) {
    return inner(board, (x + 1) % size, y + (x + 1) / size, random);
  }

  vector<int> perm(size);
  for (int i = 0; i < size; i++) {
    perm[i] = i + 1;
  }
  if (random) {
    shuffle(perm.begin(), perm.end(), rng);
  }

  for (vector<int>::iterator i = perm.begin(); i != perm.end(); i++) {
    int value = *i;
    if (board->Check(value, x, y)) {
      (*board)(x, y) = value;
      if (inner(board, (x + 1) % size, y + (x + 1) / size, random)) {
        return true;
      }
      (*board)(x, y) = 0;
    }
  }
  return false;
}

bool BacktrackSolver::Solve(Board *board, bool random) {
  return inner(board, 0, 0, random);
}
