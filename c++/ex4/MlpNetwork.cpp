//MlpNetwork.cpp
//yoav
#include "MlpNetwork.h"

/**
 * An Mlp network constructor
 * @param weights :weights matrix
 * @param biases :biases matrix
 */
MlpNetwork::MlpNetwork(Matrix *weights, Matrix *biases) :
		_layer1(Dense(weights[FIRST], biases[FIRST], Relu)),
		_layer2(Dense(weights[SECOND], biases[SECOND], Relu)),
		_layer3(Dense(weights[THIRD], biases[THIRD], Relu)),
		_layer4(Dense(weights[FOURTH], biases[FOURTH], Softmax))
{
}


/**
 * An overload to the () operator, activates the process on the input matrix and creates the
 * mlp network
 * @param matrix the input matrix
 * @return A digit with the wanted value and probability
 */
Digit MlpNetwork::operator()(const Matrix &m)
{
	Matrix result = Matrix(m);
	result = _layer1(result);
	result = _layer2(result);
	result = _layer3(result);
	result = _layer4(result);
	int index = 0;
	float probability = 0.0;
	for (int i = 0; i < result.getRows(); ++i)
	{
		if (result[i] > probability)
		{
			probability = result[i];
			index = i;
		}
	}
	Digit digit;
	digit.value = index;
	digit.probability = probability;
	return digit;
}


