#ifndef __read_file_h__
#define __read_file_h__

#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class ReadFile {
  public:
    ReadFile(string fileName1, string fileName2);
    ~ReadFile();

    void readA();
    void readB();

  private:
    istream fileMatrixA;
    istream fileMatrixB;

    string fileName1;
    string fileName2;

    int matrixSize;

    vector< vector<int>* > matrixA;
    vector< vector<int>* > matrixB;

    string _isOpen(istream file);
    void _read(ifstream file, vector< Vector<int> > vec);
};

#endif
