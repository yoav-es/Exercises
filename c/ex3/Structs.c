#include "Structs.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define SUCCESS 1
#define FAILURE 0
#define  B -1
#define  A 1
#define EQUAL 0
#define SUCCESS 1
#define FAILURE 0

/**
 * CompFunc for Vectors, compares element by element, the vector that has the first larger
 * element is considered larger. If vectors are of different lengths and identify for the length
 * of the shorter vector, the shorter vector is considered smaller.
 * @param a - first vector
 * @param b - second vector
 * @return equal to 0 iff a == b. lower than 0 if a < b. Greater than 0 iff b < a.
 */
int vectorCompare1By1(const void *a, const void *b)
{
	if (a == NULL || b == NULL)
	{
		return FAILURE;
	}
	Vector *vecA = (Vector *) a;
	Vector *vecB = (Vector *) b;
	int longerVector = B;
	int len = vecA->len;
	if (vecA->len > vecB->len)
	{
		len = vecB->len;
		longerVector = A;
	}
	for (int i = 0; i < len; i++)
	{
		if (vecA->vector[i] != vecB->vector[i])
		{
			if (vecA->vector[i] > vecB->vector[i])
			{
				longerVector = A;
			}
			longerVector = B;
		}
		if (vecA->len == vecB->len)
		{
			longerVector = 0;
		}
		return longerVector;
	}
	return FAILURE;
}

/**
 * A function that gets the norm of a given vector
 * @param vector :the vector that norm is going to be calculated
 * @return :the vectors norm
 */
double getNorm(Vector *vector)
{
	double sum = 0;
	for (int i = 0; i < vector->len; i++)
	{
		sum += pow(vector->vector[i], 2);
	}
	return sum;
}

/**
 * copy pVector to pMaxVector if : 1. The norm of pVector is greater then the norm of pMaxVector.
 * 								   2. pMaxVector->vector == NULL.
 * @param pVector pointer to Vector
 * @param pMaxVector pointer to Vector
 * @return 1 on success, 0 on failure (if pVector == NULL: failure).
 */
int copyIfNormIsLarger(const void *pVector, void *pMaxVector)
{
	if (pVector == NULL || pMaxVector == NULL)
	{
		return FAILURE;
	}
	Vector *vecP = (Vector *) pVector;
	Vector *vecMax = (Vector *) pMaxVector;
	if (vecP == NULL || vecMax == NULL)
	{
		return FAILURE;
	}
	if (getNorm(vecP) > getNorm(pMaxVector))
	{
		vecMax->len = vecP->len;
		vecMax->vector = realloc(vecMax->vector, vecMax->len * sizeof(double));
		if (vecMax->vector == NULL)
		{
			return FAILURE;
		}
		memcpy(&vecMax->vector, &vecP->vector, vecP->len * sizeof(double));
	}
	return SUCCESS;
}

/**
 * A function that finds the vector with the maximal norm in an RBtree
 * @param tree a pointer to a tree of Vectors
 * @return pointer to a *copy* of the vector that has the largest norm (L2 Norm).
 */
Vector *findMaxNormVectorInTree(RBTree *tree)
{
	if (tree == NULL)
	{
		return NULL;
	}
	Vector *maxVec = (Vector *) malloc(sizeof(Vector));
	maxVec->vector = malloc(maxVec->len * sizeof(double *));
	maxVec->vector = NULL, maxVec->len = 0;
	if (maxVec == NULL || maxVec->vector == NULL)
	{
		return NULL;
	}
	if (!forEachRBTree(tree, copyIfNormIsLarger,  maxVec))
	{
		freeVector(maxVec);
		return NULL;
	}
	return maxVec;
}


/**
 * FreeFunc for vectors
 */
void freeVector(void *pVector)
{
	if (pVector != NULL)
	{
		Vector *vecP = (Vector *) pVector;
		free(vecP->vector);
		free(pVector);
		pVector = NULL;
	}
}


/**
 * CompFunc for strings (assumes strings end with "\0")
 * @param a - char* pointer
 * @param b - char* pointer
 * @return equal to 0 iff a == b. lower than 0 if a < b. Greater than 0 iff b < a. (lexicographic
 * order)
 */
int stringCompare(const void *a, const void *b)
{
	char *string1 = (char *) a;
	char *string2 = (char *) b;
	return strcmp(string1, string2);
}

/**
 * ForEach function that concatenates the given word and \n to pConcatenated. pConcatenated is
 * already allocated with enough space.
 * @param word - char* to add to pConcatenated
 * @param pConcatenated - char*
 * @return 0 on failure, other on success
 */
int concatenate(const void *word, void *pConcatenated)
{
	char *word1 = (char *) word;
	if (word1 == NULL || pConcatenated == NULL)
	{
		return FAILURE;
	}
	if (strcat(pConcatenated, word1) == NULL)
	{
		return FAILURE;
	}
	strcat(pConcatenated, "\n");
	return SUCCESS;
}

/**
 * A function to free string allocated memory
 * @param s:string to be freed
 */

void freeString(void *s)
{
	char *string = (char *) s;
	if (s != NULL)
	{
		free(string);
	}
}

