// Matrix.h

#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

#define FIRST_VAL 0
#define MIN_INDEX 1
#define INPUT_ERROR "ERROR: invalid input"
#define MIN_PROBABILITY 0.1f
/**
 * @struct MatrixDims
 * @brief Matrix dimensions container
 */
typedef struct MatrixDims
{
	int rows, cols;
} MatrixDims;

/**
 * Matrix Class
 */
class Matrix
{
public:
	/**
	 * Matrix constructor
	 * @param rows : matrix number of rows
	 * @param cols : matrix number of cols
	 */
	Matrix(int rows, int cols);

	/**
	 * A default constructor of the matrix
	 *  constructs 1 by 1 matrix with single element 0
	 */
	Matrix();

	/**
	 * A constructor for copying a given matrix to the current one.
	 * @param m: the matrix to be copied
	 */
	Matrix(const Matrix &m);

	/**
	 * A destructor for the function
	 */
	~Matrix();


	/**
	 * A getter for the matrix rows
	 * @return : int that indicates the matrix rows
	 */
	int getRows() const;

	/**
	 * A getter for the matrix columns
	 * @return : int that indicates the matrix columns
	 */
	int getCols() const;

	/**
	 * A function that takes a matrix and transforms it into a vector
	 * @return a vector in the length of (original matrix length * original matrix width)
	 */
	Matrix vectorize();

	/**
	 * A function that prints the matrix
	 */
	void plainPrint() const;

	/**
	 * An assigment operator that assigns given matrix values into the current matrix
	 * @param m: given matrix
	 * @return: the current matrix with the given matrix values
	 */
	Matrix &operator=(const Matrix &m);


	/**
	 * An overload to the multiplication operator, which multiplies one matrix with another
	 * @param m : a given matrix that will be multiplied by our matrix
	 * @return a matrix the is the result of the multiplication between two matrices.
	 */
	Matrix operator*(const Matrix &m) const;

	/**
	 * An overload to the multiplication operator, which multiplies the current matrix by a scalar
	 * on the right (matrix * scalar)
	 * @param c : the scalar to be multiplied by
	 * @return : the current matrix after it was multiplied by the scalar
	 */
	Matrix operator*(const float &c) const;


	/**
	 *  An overload to the multiplication operator, which multiplies
	 *  the current matrix by a scalar on the left (scalar * matrix)
	 * @param c : the scalar to be multiplied by
	 * @param m : a given matrix that will be multiplied by our matrix
	 * @return : the current matrix after it was multiplied by the scalar
	 */
	friend Matrix operator*(const float &c, const Matrix &matrix);

	/**
	 * An overload to the addition operator, which adds two matrices together
	 * @param m: the matrix whose values will be added to the current matrix
	 * @return: A matrix with the results of (current matrix + other matrix values) as values
	 */
	Matrix operator+(const Matrix &m) const;

	/**
	* An overload the ++ operator , which  adds  matrix with our matrix
	* @param other the other matrix we want to add to our
	* @return the current matrix with the addition of the given matrix values to its own values
	*/
	Matrix &operator+=(const Matrix &m);

	/**
	 * An overload to the () operator , which returns the (i,j) cell of the current matrix,
	 * modifying cell value
	 * @param i: row index
	 * @param j: column index
	 * @return : the value in the i'j' cell of the matrix
	 */
	float &operator()(const int &i, const int &j);

	/**
	 * An overload to the () operator , which returns the (i,j) cell of the current matrix,
	 * copying the value for the const operator
	 * @param i: row index
	 * @param j: column index
	 * @return : the value in the i,j element value of the matrix
	 */
	float operator()(const int &i, const int &j) const;

	/**
	*An overload to the [] operator , which returns the (i) cell of the matrix, data value,
	* when i is representing the formula [i*rows+j]
	* copying the value for the const operator
	* @param  the matrix idx
	* @return the ith object in teh matrix
	*/
	float &operator[](int i);

	/**
	*An overload to the [] operator , which returns the (i) cell of the matrix, data value,
	* when i is representing the formula [i*rows+j]
	* copying the value for the const operator
	* @param  the matrix idx
	* @return the ith object in teh matrix
	*/
	float operator[](int i) const;

	/**
	 * An overload to the >> operator, that inputs the values into the matrix
	 * @param in: the input stream
	 * @param m: the matrix that the values will be loaded to
	 * @return :the input stream
	 */
	friend std::istream &operator>>(std::istream &input, const Matrix &m);

	/**
	 * An overload to the << operator, that inputs the values into the matrix
	 * @param out: the output stream
	 * @param m: the matrix which values will be the output data
	 * @return :the output stream
	 */
	friend std::ostream &operator<<(std::ostream &output, const Matrix &m);

private:
	MatrixDims _dims;
	float *_data{};
};

#endif //MATRIX_H
