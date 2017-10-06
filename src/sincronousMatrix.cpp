#include <vector>

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
  for(unsigned int index1 = 0; index1 < this->matrixA.size(); index1++) {
    // line on matrixA

    vector<int> tempMatrixCLine;

    for(unsigned int index2 = 0; index2 < this->matrixA[index1].size(); index2++) {
      // col on matrixB

      unsigned int counter = 0;
      for(unsigned int index3 = 0; index3 < this->matrixB.size(); index3++) {
        counter = (this->matrixA[index1][index2] * this->matrixB[index3][index1]) + counter;
      }
      tempMatrixCLine.push_back(counter);
      counter = 0;

    }
    this->matrixC.push_back(tempMatrixCLine);
  }
}
