/**
*    Purpose: Class to perform the multiplication synchronous.
*    @author Juliana Barbosa, Nalbert Gabriel
*    @version 1.0 10/5/2017
*/

#include <vector>
#include <iostream>

#include "sincronousMatrix.h"

SincronousMatrix::SincronousMatrix(vector< vector<int> >& matrixA, vector< vector<int> >& matrixB) {
  this->matrixA = matrixA;
  this->matrixB = matrixB;
}

/** 
*    Empty constructor 
*/
SincronousMatrix::~SincronousMatrix() {
  
}

vector< vector<int> >& SincronousMatrix::getMatrixC() {
  return this->matrixC;
}

/**
*    It performs the multiplication of two matrices in a synchronous way in order 
*    to analyze the performance of the application.
*    @param
*/

void SincronousMatrix::run() {

  /** 
  *    For to acess the line on matrixA 
  **/
  for(unsigned int index1 = 0; index1 < this->matrixA.size(); index1++) {
    
    vector<int> tempMatrixCLine;

   /** 
   *   For to fix the position of the vector 
   */
    for(unsigned int index2 = 0; index2 < this->matrixB.size(); index2++) {
      unsigned int counter = 0;
     /** 
     *    For to acess the column on matrixB 
     */
      for(unsigned int index3 = 0; index3 < this->matrixB.size(); index3++) {
       
	     /** 
        *  Multiplies the row by column 
        */
        counter = (this->matrixA[index1][index3] * this->matrixB[index3][index2]) + counter;
      }
      tempMatrixCLine.push_back(counter);
    }

    this->matrixC.push_back(tempMatrixCLine);
  }
}
