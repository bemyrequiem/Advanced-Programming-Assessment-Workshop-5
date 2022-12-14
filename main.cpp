#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <class T>

class matrix
{
private:
	// Initialise variables
	// Using double pointer for matrix
	T** mat;
	int rows;
	int cols;
public:
	// Default constructor
	matrix() {
		mat = NULL;
		rows = 0;
		cols = 0;
	}

	// Constructor with arguments
	matrix(const int& rows, const int& cols) {
		mat = NULL;
		this->rows = rows;
		this-> cols = cols;

		// Make array of pointers the size of rows
		mat = new T*[rows];
		for (int i = 0; i < rows; i++) {
			// For each row array make a column array of given datatype
			mat[i] = new T[cols];
		}
	}

	// Deconstructor
	~matrix() {
		for (int i = 0; i < rows; i++)
		{
			delete[] mat[i];
		}
		delete[] mat;
	}

	// Set element in given location to the given value
	void setElement(const int& row, const int& col, const T& val) {
		if (row >= rows || col >= cols) {
			throw std::out_of_range("Error. Index out of range.");
			return;
		}

		mat[row][col] = val;
	}

	// Return the element value at given location
	T getElement(const int& row, const int& col) {
		return mat[row][col];
	}
};

int main()
{
	matrix<int> i_mat(5, 5); // 5x5 matrix
	i_mat.setElement(0, 0, 10);
	cout << i_mat.getElement(0, 0) << endl; // 10.0
	matrix<float> f_mat(5, 5); // 5x5 matrix
	f_mat.setElement(0, 0, 7.5);
	cout << f_mat.getElement(0, 0) << endl; // 7.5
}