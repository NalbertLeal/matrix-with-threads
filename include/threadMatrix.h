#ifndef __threadMatrix_h__
#define __threadMatrix_h__

#include <vector>

using namespace std;

class ThreadMatrix {
  public:
    ThreadMatrix(vector< vector<int> >& matrixA, vector< vector<int> >& matrixB);
    ~ThreadMatrix();

    vector< vector<int> >& getMatrixC();

    void run(unsigned int threads_number);
  private:
    static void _thread_run(unsigned int xi, unsigned int yi, unsigned int xf, unsigned int yf, unsigned int line_size, vector< vector<int> >& matrixA, vector< vector<int> >& matrixB, vector< vector<int> >& matrixC);

    vector< vector<int> > matrixA;
    vector< vector<int> > matrixB;
    vector< vector<int> > matrixC;
};

#endif
