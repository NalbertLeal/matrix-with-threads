#include <thread>
#include <vector>

#include "threadMatrix.h"

using namespace std;

ThreadMatrix::ThreadMatrix(vector< vector<int> >& matrixA, vector< vector<int> >& matrixB) {
  this->matrixA = matrixA;
  this->matrixB = matrixB;

  for(unsigned int index = 0; index < this->matrixA.size(); index++) {
    vector<int> temp;
    temp.resize(this->matrixA.size());

    this->matrixC.push_back(temp);
  }
}

ThreadMatrix::~ThreadMatrix() {
  /* EMPTY */
}

vector< vector<int> >& ThreadMatrix::getMatrixC() {
  return this->matrixC;
}

void ThreadMatrix::run(unsigned int threads_number) {
  unsigned int less = 0;
  unsigned int actual = this->matrixA.size() * this->matrixA.size();
  while(actual % threads_number != 0) {
    actual = actual - 1;
    less = less + 1;
  }

  vector< thread* > thread_vector(threads_number);

  unsigned int counter_x = 0;
  unsigned int counter_y = 0;
  for(unsigned int index = 0; index < threads_number; index++) {

    int xi = counter_x;
    int yi = counter_y;
    int xf;
    int yf;

    unsigned int counter = 0;
    if(index != (threads_number - 1)) {
      while(counter < (actual / threads_number)) {
        counter++;
        counter_x++;
        if(counter_x == this->matrixA.size()) {
          counter_x = 0;
          counter_y++;
        }
      }
    }
    if(index == (threads_number - 1)) {
      counter_x = this->matrixA.size()-1;
      counter_y = this->matrixA.size()-1;
    }
    xf = counter_x;
    yf = counter_y;

    thread_vector[index] = new thread(_thread_run, xi, yi, xf, yf, this->matrixA.size(), ref(this->matrixA), ref(this->matrixB), ref(this->matrixC));;
    // t.join();
    // t.detach();
  }

  for(unsigned int index = 0; index < threads_number; index++) {
    thread_vector[index]->join();
  }
}

void ThreadMatrix::_thread_run(unsigned int xi, unsigned int yi, unsigned int xf, unsigned int yf, unsigned int line_size, vector< vector<int> >& matrixA, vector< vector<int> >& matrixB, vector< vector<int> >& matrixC) {
  unsigned int xn = xi;
  unsigned int yn = yi;
  while(true) {
    if(yn == yf && xn == xf) {

      int counter = 0;
      for(unsigned int index3 = 0; index3 < line_size; index3++) {
        counter = (matrixA[xn][index3] * matrixB[index3][xn]) + counter;
      }
      matrixC[xn][yn] = counter;

      break;
    }
    else if(xn == line_size) {
      yn = yn + 1;
      xn = 0;

      int counter = 0;
      for(unsigned int index3 = 0; index3 < line_size; index3++) {
        counter = (matrixA[xn][index3] * matrixB[index3][xn]) + counter;
      }
      matrixC[xn][yn] = counter;

    }
    else {

      int counter = 0;
      for(unsigned int index3 = 0; index3 < line_size; index3++) {
        counter = (matrixA[xn][index3] * matrixB[index3][xn]) + counter;
      }
      matrixC[xn][yn] = counter;

      xn = xn + 1;
    }
  }
}
