#include <vector>
#include <iostream>

#include "sincronousMatrix.h"

SincronousMatrix::SincronousMatrix(vector< vector<int> >& matrixA, vector< vector<int> >& matrixB) {
  this->matrixA = matrixA;
  this->matrixB = matrixB;
}

SincronousMatrix::~SincronousMatrix() {
  /* EMPTY */
}

vector< vector<int> >& SincronousMatrix::getMatrixC() {
  return this->matrixC;
}

void SincronousMatrix::run() {
  cout << this->matrixA.size() << endl;
    cout << this->matrixA[0].size() << endl;
  for(unsigned int index1 = 0; index1 < this->matrixA.size(); index1++) {
    // line on matrixA

    vector<int> tempMatrixCLine;

    for(unsigned int index2 = 0; index2 < this->matrixB.size(); index2++) {
      unsigned int counter = 0;
      for(unsigned int index3 = 0; index3 < this->matrixB.size(); index3++) {
        // col on matrixB
        counter = (this->matrixA[index1][index3] * this->matrixB[index3][index2]) + counter;
      }
      cout << counter << " ";
      tempMatrixCLine.push_back(counter);
    }

    cout << "\n";

    this->matrixC.push_back(tempMatrixCLine);
  }
}
