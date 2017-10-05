#ifndef __sincronousMatrix_h__
#define __sincronousMatrix_h__

#include <vector>

using namespace std;

class SincronousMatrix {
  public:
    SincronousMatrix(vector< vector<int> >& matrixA, vector< vector<int> >& matrixB);
    ~SincronousMatrix();

    vector< vector<int> >& getMatrixC();

    void run();
  private:

    vector< vector<int> > matrixA;
    vector< vector<int> > matrixB;
    vector< vector<int> > matrixC;
};

#endif
