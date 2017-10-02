#ifndef __read_file_h__
#define __read_file_h__

#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ReadFile {
  public:
    ReadFile(string fileName1, string fileName2, int matrixSize);
    ~ReadFile();

    void readA();
    void readB();

    vector< vector<int>* >& getMatrixA();
    vector< vector<int>* >& getMatrixB();

  private:
    ifstream fileMatrixA;
    ifstream fileMatrixB;

    string fileName1;
    string fileName2;

    int matrixSize;

    vector< vector<int>* > matrixA;
    vector< vector<int>* > matrixB;

    string _isOpen(ifstream& filename);
    string _read(ifstream& file);
    void _createMatrix(string fileString, vector< vector<int>* >& vec);
};

#endif
