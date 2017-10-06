#ifndef __filewriter_h__
#define __filewriter_h__

#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class FileWriter {
  public:
    FileWriter(vector< vector<int> >& matrixC, string filePath);
    ~FileWriter();

    void write();
  private:
    vector< vector<int> > matrixC;
    string filePath;
};

#endif
