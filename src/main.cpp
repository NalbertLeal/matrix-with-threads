#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "readFile.h"
#include "sincronousMatrix.h"
#include "fileWriter.h"

using namespace std;

ReadFile* FilesMatrix(string& matrixSizeString) {
  stringstream ss(matrixSizeString);
  int matrixSizeInt;
  ss >> matrixSizeInt;

  string matrixFileA;
  matrixFileA = "inputs/A" + matrixSizeString + "x" + matrixSizeString + ".txt";
  string matrixFileB;
  matrixFileB = "inputs/B" + matrixSizeString + "x" + matrixSizeString + ".txt";

  return (new ReadFile(matrixFileA, matrixFileB, matrixSizeInt));
}

int main(int argc, char* argv[]) {
  if(argc != 2 && argc != 3) {
  cout << ">>> The command line must receive 1 or 2 inputs.\n";
  cout << ">>> In case of 1 input the matrix multiplication will be sincronous.\n";
  cout << ">>> In case of 2 inputs the matrix multiplication will be parallel.\n";
    return 1;
  }
  if((atoi(argv[1]) % 2) != 0) {
    // error, the input isn't multiple of 2.
    cout << ">>> The command line input isn't multiple of 2.\n";
    return 1;
  }

  string matrixSizeString = argv[1];
  // cin >> matrixSizeString;

  ReadFile* rf = FilesMatrix(matrixSizeString);

  rf->readA();
  rf->readB();

  vector< vector<int> > matrixA = rf->getMatrixA();
  vector< vector<int> > matrixB = rf->getMatrixB();

  cout << matrixA[0][0] << endl;

  if(argc == 2) {
    // Is sequencial.

    // multiply the matrix
    SincronousMatrix* sm = new SincronousMatrix(matrixA, matrixB);
    sm->run();
    vector< vector<int> > matrixC = sm->getMatrixC();

    cout << matrixC[0][0] << endl;

    string fileOutPath = "outputs/Out" + matrixSizeString + "x" + matrixSizeString + ".txt";
    FileWriter fw(matrixC, fileOutPath);

    fw.write();
  }
  if(argc == 3) {
    // Is concurrent.
  }

  delete rf;

  return 0;
}
