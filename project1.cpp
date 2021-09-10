#include<iostream>

using namespace std;

class matrixClass {
protected:
	int numRows; // number of rows 
	int numCols; // number of columns
	int** mat; // 2D dynamic array to store matrix 

public:
	matrixClass(); // default constructor
	matrixClass(int r, int c); // non default constructor
	void display(); // display
	void setValue(int i, int j, int val); // to set the value at location i, j
	int getValue(int i, int j); // return val at i, j
	int getNumRows(); // getter for numRows
	int getNumCols(); // getter for numCols
	matrixClass* multiply(matrixClass* multiplier); // multiply method
};

void matrixClass :: setValue(int i, int j, int val)
{
	mat[i][j] = val;
}

int matrixClass::getValue(int i, int j) {
	return mat[i][j];

}
int matrixClass::getNumRows() {
	return numRows;
}

int matrixClass :: getNumCols() {
	return numCols;
}

matrixClass::matrixClass(int r, int c) {
	numRows = r;
	numCols = c;

	mat = new int* [numRows];

	// For each row, create an array of integers
	for (int i = 0; i < numRows; i++) {
		mat[i] = new int[numCols];

		// Set all values to 0.
		for (int j = 0; j < numCols; j++) {
			mat[i][j] = 0;
		}
	}

}

void matrixClass::display() {
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j< numCols; j++){
			cout << mat[i][j] << " ";
		}
		cout << "\n";

	}

}

matrixClass* matrixClass::multiply(matrixClass* multiplier)
{
	matrixClass* Result = new matrixClass(numRows, multiplier->getNumCols());
	{   int i, j, k;
	for (i = 0; i < numRows; i++)
		for (j = 0; j < numCols; j++)
			for (k = 0; k < numCols; k++)
			{
				int number = Result->getValue(i, j);
				number += getValue(i, k) * multiplier->getValue(k, j);
				Result->setValue(i, j, number);

			}
	return Result;
	}
};

// main function
int main()
{
	int numRows, numCols, numNonZero;

	// read in all the numRows, numCols and numNonZero values from redirected input for matrix A
	cin >> numRows >> numCols >> numNonZero;
	
	// declare object for matrix A
	matrixClass A(numRows, numCols);
	// read in the values and use setValue to set the values read in for A
	int i, r, c, v;
	for (i = 0 ; i < numNonZero; i++)
	{
		cin >> r >> c >> v;
// use the setValue method to put the values in the mat of A
		A.setValue(r, c, v);
}


	// display matrix A
	cout << "A: " << endl; 
	A.display();

	// read in all the numRows, numCols and numNonZero values from redirected input for matrix B
	cin >> numRows >> numCols >> numNonZero;

	// declare object for matrix B
	matrixClass B(numRows, numCols);
	// use the setValue method to put the values in the mat of B
	int a, b, d, e;
	for (a = 0; a < numNonZero; a++)
	{
		cin >> b >> d >> e;
// read in the values and use setValue to set the values read in for B
		B.setValue(b, d, e);
	}
	// display matrix B
	cout << "B: " << endl;
	B.display();
	
 // declare resultant matrix to store A * B
	matrixClass *Result = A.multiply(&B);
	
	// display resultant matrix
	cout << "RESULT: " << endl;
	Result->display();
	return 0;
}