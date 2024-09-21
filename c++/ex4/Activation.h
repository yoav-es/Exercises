//Activation.h
//yoav
#ifndef ACTIVATION_H
#define ACTIVATION_H

#include "Matrix.h"
#include <cmath>

#define DEFAULT 1

/**
 * @enum ActivationType
 * @brief Indicator of activation function.
 */
enum ActivationType
{
	Relu,
	Softmax
};

/**
 * Activation class
 */
class Activation
{
public:

	/**
	 *Activation Constructor, accept activation type and activate accordingly
	 * @param actType: type of activation, relu or softmax function
	 */
	explicit Activation(ActivationType actType);

	/**
	 * A getter for the activation type of an activation
	 * @return :the activation type of the activation
	 */
	ActivationType getActivationType() const
	{
		return _activationType;
	}

	/**
	 * An overload to the () operator ,which applies the activation function to a matrix
	 * modifying cell values
	 * @param i: row index
	 * @param j: column index
	 * @return : the value in the i'j' cell of the matrix
	 */
	Matrix operator()(const Matrix &input);

	/**
	 * An overload to the () operator ,which applies the activation function to a matrix
	 * copying the value for the const operator
	 * @param i: row index
	 * @param j: column index
	 * @return : the value in the i,j element value of the matrix
	 */
	Matrix operator()(const Matrix &input) const;

private:
	ActivationType _activationType;
};

#endif //ACTIVATION_H
