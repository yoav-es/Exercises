#include <iostream>
#include <cstring>
#include "Matrix.h"

/**
 * Matrix constructor
 * @param rows : matrix number of rows
 * @param cols : matrix number of cols
 */
Matrix::Matrix(int rows, int cols) :
		_dims{rows = rows, cols = cols}
{
	if (rows < MIN_INDEX || cols < MIN_INDEX)
	{
		std::cerr << INPUT_ERROR << std::endl;
		exit(EXIT_FAILURE);
	}
	_data = new float[rows * cols]();
}

/**
 * A default constructor of the matrix
 *  constructs 1 by 1 matrix with single element with zero value
 */
Matrix::Matrix() :
		Matrix(MIN_INDEX, MIN_INDEX)
{
}

/**
 * A constructor for copying a given matrix to the current one.
 * @param m: the matrix to be copied
 */

Matrix::Matrix(const Matrix &m) :
		_dims{m._dims.rows, m._dims.cols}
{
	delete[](_data);
	int new_size = m._dims.rows * m._dims.cols;
	_data = new float[new_size];
	for (int i = 0; i < new_size; ++i)
	{
		_data[i] = m._data[i];
	}
}

/**
 * A destructor for deleting the matrix
 */
Matrix::~Matrix()
{
	delete[](_data);
}


/**
 * A getter for the matrix rows
 * @return : int that indicates the matrix rows
 */
int Matrix::getRows() const
{
	return _dims.rows;
}

/**
 * A getter for the matrix cols
 * @return : int that indicates the matrix rows
 */
int Matrix::getCols() const
{
	return _dims.cols;
}

/**
 * A function that takes a matrix and transforms it into a vector
 * @return a vector in the length of (original matrix length * original matrix width)
 */
Matrix Matrix::vectorize()
{
	int newSize = _dims.rows * _dims.cols;
	_dims.rows = newSize;
	_dims.cols = 1;
	return *this;
}

/**
 * A function that prints the matrix
 */
void Matrix::plainPrint() const
{
	for (int i = 0; i < _dims.rows; ++i)
	{
		for (int j = 0; j < _dims.cols; ++j)
		{
			std::cout << ((*this)(i, j)) << " ";
		}
		std::cout << std::endl;
	}
}

/**
 * An assigment operator that assigns given matrix values into the current matrix
 * @param m: given matrix
 * @return: the current matrix with the given matrix values
 */
Matrix &Matrix::operator=(const Matrix &m)
{
	if (this != &m)
	{
		delete[] _data;
		_dims = m._dims;
		_data = new float[m._dims.rows * m._dims.cols];
		for (int i = 0; i < _dims.rows * _dims.cols; ++i)
		{
			_data[i] = m._data[i];
		}
	}
	return *this;
}

/**
 * An overload to the multiplication operator, which multiplies one matrix with another
 * @param m : a given matrix that will be multiplied by our matrix
 * @return a matrix the is the result of the multiplication between two matrices.
 */
Matrix Matrix::operator*(const Matrix &m) const
{
	if ((m._dims.rows != _dims.cols))
	{
		std::cerr << INPUT_ERROR << std::endl;
		exit(EXIT_FAILURE);
	}
	Matrix result = Matrix(_dims.rows, m._dims.cols);
	for (int i = 0; i < _dims.rows; ++i)
	{
		for (int j = 0; j < m._dims.cols; ++j)
		{
			for (int k = 0; k < _dims.cols; ++k)
			{
				result(i, j) += (*this)(i, k) * m(k, j);
			}
		}
	}
	return result;
}


/**
 * An overload to the multiplication operator, which multiplies the current matrix by a scalar
 * on the right (matrix * scalar)
 * @param c : the scalar to be multiplied by
 * @return : the current matrix after it was multiplied by the scalar
 */
Matrix Matrix::operator*(const float &c) const
{
	Matrix result = *this;
	for (int i = 0; i < _dims.rows * _dims.cols; ++i)
	{
		result._data[i] *= c;
	}
	return result;
}

/**
 *  An overload to the multiplication operator, which multiplies
 *  the current matrix by a scalar on the left (scalar * matrix)
 * @param c : the scalar to be multiplied by
 * @param m : a given matrix that will be multiplied by our matrix
 * @return : the current matrix after it was multiplied by the scalar
 */
Matrix operator*(const float &c, const Matrix &m)
{
	Matrix result = m;
	for (int i = 0; i < m._dims.rows * m._dims.cols; ++i)
	{
		result._data[i] *= c;
	}
	return result;
}

/**
 * An overload to the addition operator, which adds two matrices together
 * @param m: the matrix whose values will be added to the current matrix
 * @return: A matrix with the results of (current matrix + other matrix values) as values
 */
Matrix Matrix::operator+(const Matrix &m) const
{
	if ((m._dims.rows != _dims.rows) || ((m._dims.cols != _dims.cols)))
	{
		std::cerr << INPUT_ERROR << std::endl;
		exit(EXIT_FAILURE);
	}
	Matrix result = Matrix(*this);
	for (int i = 0; i < _dims.rows; ++i)
	{
		for (int j = 0; j < _dims.cols; ++j)
		{
			result(i, j) += m(i, j);
		}
	}
	return result;
}

/**
* An overload the += operator , which  adds  matrix with our matrix
* @param other the other matrix we want to add to our
* @return the current matrix with the addition of the given matrix values to its own values
*/
Matrix &Matrix::operator+=(const Matrix &m)
{
	if (_dims.rows != m._dims.rows || _dims.cols != m._dims.cols)
	{
		std::cerr << "INPUT_ERROR" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < _dims.rows; ++i)
	{
		for (int j = 0; j < _dims.cols; ++j)
		{
			(*this)(i, j) += m(i, j);
		}
	}
	return *this;
}

/**
 * An overload to the () operator , which returns the (i,j) cell of the current matrix,
 * modifying cell value
 * @param i: row index
 * @param j: column index
 * @return  the value in the i'j' cell of the matrix
 */
float &Matrix::operator()(const int &i, const int &j)
{
	if ((_dims.rows <= i) || ((_dims.cols <= j)) || i < FIRST_VAL || j < FIRST_VAL)
	{
		std::cerr << INPUT_ERROR << std::endl;
		exit(EXIT_FAILURE);
	}
	return _data[i * _dims.cols + j];
}

/**
 * An overload to the () operator , which returns the (i,j) cell of the current matrix,
 * copying the value for the const operator
 * @param i: row index
 * @param j: column index
 * @return : the value in the i,j element value of the matrix
 */
float Matrix::operator()(const int &i, const int &j) const
{
	if ((_dims.rows <= i) || ((_dims.cols <= j)) || i < FIRST_VAL || j < FIRST_VAL)
	{
		std::cerr << INPUT_ERROR << std::endl;
		exit(EXIT_FAILURE);
	}
	return _data[i * _dims.cols + j];
}

/**
 *An overload to the [] operator , which returns the (i) cell of the matrix, data value,
 * when i is representing the formula [i*rows+j]
 * modifying cell value
 * @param  the matrix idx
 * @return the ith object in teh matrix
 */
float &Matrix::operator[](int i)
{
	if (_dims.rows * _dims.cols <= i || i < FIRST_VAL)
	{
		std::cerr << INPUT_ERROR << std::endl;
		exit(EXIT_FAILURE);
	}
	return _data[i];
}

/**
 *An overload to the [] operator , which returns the (i) cell of the matrix, data value,
 * when i is representing the formula [i*rows+j]
 * copying the value for the const operator
 * @param  the matrix idx
 * @return the ith object in teh matrix
 */
float Matrix::operator[](int i) const
{
	if (_dims.rows * _dims.cols <= i || i < FIRST_VAL)
	{
		std::cerr << INPUT_ERROR << std::endl;
		exit(EXIT_FAILURE);
	}
	return _data[i];
}

/**
 * An overload to the >> operator, that inputs the values into the matrix
 * @param in: the input stream
 * @param m: the matrix that the values will be loaded to
 * @return :the input stream
 */
std::istream &operator>>(std::istream &input, const Matrix &m)
{
	int i = 0;
	int size = m._dims.rows * m._dims.cols + 1;
	while (input.good())
	{
		if (i == size)
		{
			std::cerr << INPUT_ERROR << std::endl;
			exit(EXIT_FAILURE);
		}
		input.read(reinterpret_cast<char *>(&m._data[i]), sizeof(float));
		i++;
	}
	if (i != size)
	{
		std::cerr << INPUT_ERROR << std::endl;
		exit(EXIT_FAILURE);
	}
	return input;
}

/**
 * An overload to the << operator, that inputs the values into the matrix
 * @param out: the output stream
 * @param m: the matrix which values will be the output data
 * @return :the output stream
 */
std::ostream &operator<<(std::ostream &output, const Matrix &m)
{
	for (int i = 0; i < m._dims.rows; ++i)
	{
		for (int j = 0; j < m._dims.cols; ++j)
		{
			if (m(i, j) <= MIN_PROBABILITY)
			{
				output << "  ";
			}
			else
			{
				output << "**";
			}
		}
		output << std::endl;
	}
	return output;
}


