#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <math.h>

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

  if(argc == 2) {
    // Is sequencial.

    // vector< double > times(20);
    vector< long int > times(20);

    for(int index = 0; index < 20; index++) {
      // get time when start a iteration
      auto start = std::chrono::high_resolution_clock::now();

      SincronousMatrix* sm = new SincronousMatrix(matrixA, matrixB);
      sm->run();
      vector< vector<int> > matrixC = sm->getMatrixC();

      string fileOutPath = "outputs/Out" + matrixSizeString + "x" + matrixSizeString + ".txt";
      FileWriter fw(matrixC, fileOutPath);

      fw.write();

      // get time when finish a iteration
      auto end = std::chrono::high_resolution_clock::now();

      auto elapsedtime = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
      times[index] = elapsedtime;
    }

    // get averenge time.
    long int averange = 0;
    for(int index = 0; index < 20; index++) {
      averange = averange + times[index];
    }
    averange = averange / 20;
    cout << ">>> Media: " << averange << endl;

    long int dp = 0;
    for(int index = 0; index < 20; index++) {
      dp = dp + (times[index] - averange);
    }
    dp = dp / 20;
    dp = sqrt(dp);
    cout << ">>> Desvio padrão: " << dp << endl;

    ofstream fileData("outputs/measure.dat");
    fileData << "Media: ";
    fileData << averange;
    fileData << " nanoseconds \n";
    fileData << "dp: ";
    fileData << dp;
    fileData << "\n\n";
    fileData << "note: 1 second = 1000000000 nanoseconds = 10^9 nanoseconds";
  }
  if(argc == 3) {
    // Is concurrent.
  }

  delete rf;

  return 0;
}
