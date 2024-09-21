//Activation.cpp
//yoav eshed
#include "Activation.h"


/**
 *Activation Constructor, accept activation type and activate accordingly
 * @param actType: type of activation, relu or softmax function
 */
Activation::Activation(ActivationType activationType)
{
	_activationType = activationType;
}

/**
 * A function that preforms the Relu function on the matrix data values, by going over the matrix
 * replaces each value that smaller than zero with zero
 * @param m : the matrix that the relu function will be applied to
 * @return: A matrix with the values of m after relu function has been applied to it.
 */
Matrix reluFunc(const Matrix &m)
{
	{
		int ROWS = m.getRows();
		int COLS = m.getCols();
		Matrix result(m.getRows(), m.getCols());
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (m(i, j) <= 0)
				{
					result(i, j) = 0;
				}
				else
				{
					result(i, j) = m(i, j);
				}
			}
		}
		return result;
	}
}

/**
 * A function that preforms the Softmax function on the matrix data values, by going over the matrix
 * calculating the sum of the exponents of all the matrix values, and then multiply all the matrix
 * by 1/sum , as in the given formula
 * @param m : the matrix that the softMax function will be applied to
 * @return: A matrix with the values of m after softmax function has been applied to it.
 */
Matrix softMaxFunc(const Matrix &m)
{
	int ROWS = m.getRows();
	int COLS = m.getCols();
	float sum = 0;
	Matrix result(m.getRows(), m.getCols());
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			result(i, j) = std::exp(m(i, j));
			sum += result(i, j);
		}
	}
	float scalar = (1.f / sum);
	return scalar * result;
}

/**
 * An overload to the () operator ,which applies the activation function to a matrix
 * modifying cell values
 * @param i: row index
 * @param j: column index
 * @return : the value in the i'j' cell of the matrix
 */
Matrix Activation::operator()(const Matrix &input)
{
	if (_activationType == Relu)
	{
		return reluFunc(input);
	}
	return softMaxFunc(input);
}

/**
 * An overload to the () operator ,which applies the activation function to a matrix
 * copying the value for the const operator
 * @param i: row index
 * @param j: column index
 * @return : the value in the i,j element value of the matrix
 */
Matrix Activation::operator()(const Matrix &input) const
{
	if (_activationType == Relu)
	{
		return reluFunc(input);
	}
	return softMaxFunc(input);
}

