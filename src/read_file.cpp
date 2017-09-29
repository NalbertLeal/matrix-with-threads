#include <fstream>
#include <sstream>
#include <vector>

ReadFile::ReadFile(string fileName1, string fileName2, int matrixSize) {
  this->fileName1 = fileName1;
  this->fileName2 = fileName2;
  this->matrixSize = matrixSize;

  this->fileMatrixA.open(this->fileName1);
  cout << fileName1 << ": " << this->_isOpen(this->fileName1);

  this->fileMatrixB.open(this->fileName2);
  cout << fileName2 << ": " << this->_isOpen(this->fileName2);
}

ReadFile::~ReadFile() {
  for(int line = 0; line < this->matrixA.size(); line++) {
    delete this->matrixA[line];
  }

  for(int line = 0; line < this->matrixB.size(); line++) {
    delete this->matrixB[line];
  }
}

void ReadFile::readA() {

}

void ReadFile::readB() {

}

string ReadFile::_isOpen(istream file) {
  if(!(open.is_open())) {
    return "file is open.";
  }
  else {
    return "file not closed.";
  }
}

void ReadFile::_read(ifstream file, vector< Vector<int>* > vec) {
  ostringstream ss;
  ss.read(file);

  string stringLine = "";
  string stringElement = "";

  ss >> stringElement;
  ss >> stringElement;

  stringElement = "";
  for(int line = 0; line < matrixSize; line++) {
    vec.push( new vector<int>(matrixSize) );
    for(int col = 0; col < matrixSize; col++) {
      ss >> stringElement;
      vec[line].push( atoi(stringElement) );
    }
  }
}
