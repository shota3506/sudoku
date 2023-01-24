#include "board.hpp"

#include <cassert>
#include <iostream>

using namespace std;

bool Board::Check(int value, int x, int y) {
  for (int i = 0; i < n; i++) {
    // row
    if ((*this)(x, i) == value) return false;
    // column
    if ((*this)(i, y) == value) return false;
  }

  // diag
  if (x == y) {
    for (int i = 0; i < n; i++) {
      if ((*this)(i, i) == value) return false;
    }
  }
  if (x == n - y - 1) {
    for (int i = 0; i < n; i++) {
      if ((*this)(i, n - i - 1) == value) return false;
    }
  }

  // block
  int x_offset = block_size * (x / block_size);
  int y_offset = block_size * (y / block_size);
  for (int i = 0; i < block_size; i++) {
    for (int j = 0; j < block_size; j++) {
      if ((*this)(x_offset + i, y_offset + j) == value) return false;
    }
  }
  return true;
}

void Board::Clear() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      (*this)(i, j) = 0;
    }
  }
}

void Board::Print() {
  int extra_space = n / 10;

  for (int i = 0; i < n; i++) {
    cout << "+---";
    for (int k = 0; k < extra_space; k++) cout << "-";
  }
  cout << "+" << endl;

  for (int i = 0; i < n; i++) {
    cout << "| ";
    for (int j = 0; j < n; j++) {
      if ((*this)(i, j) == 0) {
        cout << ".";
        for (int k = 0; k < extra_space; k++) cout << " ";
      } else {
        cout << (*this)(i, j);

        int num_digits = (*this)(i, j) / 10;
        for (int k = 0; k < (extra_space - num_digits); k++) {
          cout << " ";
        }
      }

      if ((j + 1) % block_size == 0) {
        cout << " | ";
      } else {
        cout << "   ";
      }
    }

    cout << endl;
    if ((i + 1) % block_size == 0) {
      for (int j = 0; j < n; j++) {
        cout << "+---";
        for (int k = 0; k < extra_space; k++) cout << "-";
      }
      cout << "+" << endl;
    }
  }
}
