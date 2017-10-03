#include <iostream>
#include <memory>
#include <sstream>

#include "readFiles.h"

using namespace std;

int main() {
  cout << "write here the matrix size: ";

  string matrixSizeString;
  cin >> matrixSizeString;

  stringstream ss(matrixSizeString);
  int matrixSizeInt;
  ss >> matrixSizeInt;

  string matrixFileA;
  matrixFileA = "inputs/A" + matrixSizeString + "x" + matrixSizeString + ".txt";
  string matrixFileB;
  matrixFileB = "inputs/B" + matrixSizeString + "x" + matrixSizeString + ".txt";

  unique_ptr<ReadFile> rf(new ReadFile(matrixFileA, matrixFileB, matrixSizeInt));

  rf->readA();
  rf->readB();

  vector< vector<int>* > matrixA = rf->getMatrixA();
  vector< vector<int>* > matrixB = rf->getMatrixB();

  cout << matrixB[0][0][0] << std::endl;

  for(unsigned int line = 0; line < matrixA.size(); line++) {
    delete matrixA[line];
  }

  for(unsigned int line = 0; line < matrixB.size(); line++) {
    delete matrixB[line];
  }

  return 0;
}
