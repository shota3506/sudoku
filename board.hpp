#pragma once

#include <cassert>
#include <cmath>

using namespace std;

class Board {
  int n;
  int block_size;
  int **grid;

 public:
  Board(int _n) : n(_n) {
    block_size = (int)sqrt(n);
    assert(n == block_size * block_size);

    grid = new int *[n];
    for (int i = 0; i < n; i++) {
      grid[i] = new int[n];
      for (int j = 0; j < n; j++) {
        grid[i][j] = 0;
      }
    }
  }

  ~Board() {
    for (int i = 0; i < n; i++) {
      delete[] grid[i];
    }
    delete[] grid;
  }

  Board(const Board &rhs) {
    n = rhs.n;
    block_size = rhs.block_size;

    grid = new int *[n];
    for (int i = 0; i < n; i++) {
      grid[i] = new int[n];
      for (int j = 0; j < n; j++) {
        grid[i][j] = rhs.grid[i][j];
      }
    }
  }

  int &operator()(int x, int y) {
    assert(x < n && y < n);
    return grid[x][y];
  }

  inline int GetSize() { return n; }

  bool Check(int value, int x, int y);
  void Clear();
  void Print();
};
