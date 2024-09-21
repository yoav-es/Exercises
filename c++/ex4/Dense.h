//Dense.h
//yoav eshed
#ifndef DENSE_H
#define DENSE_H

#include "Matrix.h"
#include "Activation.h"

/**
 * Dense Class
 */
class Dense
{
public:
	/**
	 * Dense constructor
	 * @param w: weight matrix
	 * @param bias : bias vector
	 * @param actType : activation type
	 */

	Dense(Matrix &w, Matrix &bias, ActivationType actType);

	/**
	 * A getter for the weights matrix
	 * @return : int that indicates the matrix columns
	 */
	inline const Matrix &getWeights()
	{ return _weights; }

	/**
	 * A getter for the bias vector
	 * @return : int that indicates the matrix columns
	 */
	inline const Matrix &getBias()
	{ return _bias; }

	/**
	 * A getter for the current layer Activation type
	 * @return : int that indicates the matrix columns
	 */
	inline Activation getActivation()
	{ return _activation; }

	/**
	 * An overload to the () operator ,which applies the activation function to the input matrix
	 * modifying cell values
	 * @param i: row index
	 * @param j: column index
	 * @return : the value in the i'j' cell of the matrix
	 */
	Matrix operator()(Matrix &input);

	/**
	 * An overload to the () operator ,which applies the activation function to the input matrix
	 * copying the value for the const operator
	 * @param i: row index
	 * @param j: column index
	 * @return : the value in the i,j element value of the matrix
	 */
	Matrix operator()(Matrix &input) const;


private:
	Matrix _weights;
	Matrix _bias;
	Activation _activation;
};

#endif //DENSE_H
