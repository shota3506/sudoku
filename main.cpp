#include <iostream>
#include <random>
#include <sstream>
#include <string>

#include "game.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  random_device seed_gen;

  int seed = seed_gen();
  int gamesize = 9;    // game size
  int prefilled = 30;  // number of prefilled cells

  for (int i = 1; i < argc; ++i) {
    if (string(argv[i]) == "--seed" || string(argv[i]) == "-s") {
      if (i + 1 < argc) {
        istringstream ss(argv[++i]);
        if (!(ss >> seed)) {
          cerr << "invalid number: " << argv[i] << endl;
          return 1;
        }
      } else {
        cerr << "--seed option requires one argument" << endl;
        return 1;
      }
    }

    if (string(argv[i]) == "--gamesize" || string(argv[i]) == "-g") {
      if (i + 1 < argc) {
        istringstream ss(argv[++i]);
        if (!(ss >> gamesize)) {
          cerr << "invalid number: " << argv[i] << endl;
          return 1;
        }
      } else {
        cerr << "--gamesize option requires one argument" << endl;
        return 1;
      }
    }

    if (string(argv[i]) == "--prefilled") {
      if (i + 1 < argc) {
        istringstream ss(argv[++i]);
        if (!(ss >> prefilled)) {
          cerr << "invalid number: " << argv[i] << endl;
          return 1;
        }
      } else {
        cerr << "--gamesize option requires one argument" << endl;
        return 1;
      }
    }
  }

  Game game(gamesize, prefilled, mt19937(seed));
  game.Play();

  return 0;
}
