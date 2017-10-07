/**
*    Purpose: Class to write the files of result matrixes.
*    @author Juliana Barbosa, Nalbert Gabriel
*    @version 1.0 10/5/2017
*/

#include <fstream>
#include <sstream>

#include "fileWriter.h"

/**
*   Constructor.
*   @param matrixC
*   @param filePath
*/


FileWriter::FileWriter(vector< vector<int> >& matrixC, string filePath) {
  this->matrixC = matrixC;
  this->filePath = filePath;
}

/**
*   Empty.
*/

FileWriter::~FileWriter() {
  
}


/**
*   Method to write the files.
*
*/

void FileWriter::write() {
  ofstream file(this->filePath);

  for(unsigned int index1 = 0; index1 < this->matrixC.size(); index1++) {
    for(unsigned int index2 = 0; index2 < this->matrixC.size(); index2++) {
      file << this->matrixC[index1][index2];
      file << " ";
    }
    file << "\n";
  }

  file.close();
}
