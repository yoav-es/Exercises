//MlpNetwork.h
// yoav eshed
#ifndef MLPNETWORK_H
#define MLPNETWORK_H

#include "Matrix.h"
#include "Dense.h"
#include "Digit.h"

#define MLP_SIZE 4
#define FIRST 0
#define SECOND 1
#define THIRD 2
#define FOURTH 3

const MatrixDims imgDims = {28, 28};
const MatrixDims weightsDims[] = {{128, 784},
								  {64,  128},
								  {20,  64},
								  {10,  20}};
const MatrixDims biasDims[] = {{128, 1},
							   {64,  1},
							   {20,  1},
							   {10,  1}};
/**
 * Mlp network class
 */
class MlpNetwork
{

public:
	/**
	 * A Mlp network constructor
	 * @param weights : weights array
	 * @param biases : biases array
	 * @param layer1 : first layer of the Mlp network
	 * @param layer2 : second layer of the Mlp network
	 * @param layer3 : third layer of the Mlp network
	 * @param layer4 : fourth layer of the Mlp network
	 */
	MlpNetwork(Matrix *weights, Matrix *biases);

/**
     * An overload to the () operator, activates the process on the input matrix and creates the
     * mlp network
     * @param matrix the input matrix
     * @return A digit with the wanted value and probability
     */
	Digit operator()(const Matrix &m);

private:
	Dense _layer1;
	Dense _layer2;
	Dense _layer3;
	Dense _layer4;
};

#endif // MLPNETWORK_H
