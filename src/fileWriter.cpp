#include <fstream>
#include <sstream>

#include "fileWriter.h"

FileWriter::FileWriter(vector< vector<int> >& matrixC, string filePath) {
  this->matrixC = matrixC;
  this->filePath = filePath;
}

FileWriter::~FileWriter() {
  /* EMPTY */
}

void FileWriter::write() {
  ofstream file(this->filePath);

  for(unsigned int index1 = 0; index1 < this->matrixC.size(); index1++) {
    for(unsigned int index2 = 0; index2 < this->matrixC.size(); index2++) {
      file << this->matrixC[index1][index2];
    }
    file << "\n";
  }

  file.close();
}
