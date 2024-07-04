#include "RandomForest.h"

int main() {
  auto *forest = new RandomForest("iris.csv");
  forest->predict();
}
