//Dense.cpp
// yoav eshed
#include "Dense.h"


/**
 * Dense constructor
 * @param w: weight matrix
 * @param bias : bias vector
 * @param actType : activation type
 */
Dense::Dense(Matrix &w, Matrix &bias, ActivationType actType) : _weights(w), _bias(bias),
																_activation(actType)
{
}

/**
 * An overload to the () operator ,which applies the activation function to the input matrix
 * modifying cell values
 * @param i: row index
 * @param j: column index
 * @return : the value in the i'j' cell of the matrix
 */
Matrix Dense::operator()(Matrix &input)
{
	Matrix result = ((_weights * input) + _bias);
	result = _activation(result);
	return result;
}

/**
 * An overload to the () operator ,which applies the activation function to the input matrix
 * copying the value for the const operator
 * @param i: row index
 * @param j: column index
 * @return : the value in the i,j element value of the matrix
 */
Matrix Dense::operator()(Matrix &input) const
{
	Matrix result = ((_weights * input) + _bias);
	result = _activation(result);
	return result;
}
