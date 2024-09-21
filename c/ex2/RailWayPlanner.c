#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "limits.h"
#include "ctype.h"

#define ARG_ERROR "Usage: RailwayPlanner <InputFile>"
#define FILE_ERROR "File doesn't exists."
#define EMPTY_ERROR "File is empty."
#define NO_SIGN -1
#define INFINITE_MIN_PRICE -1
#define LINE_ERROR "Invalid input in line: "
#define EXIT_FAILURE  1
#define EXIT_SUCCESS  0
#define LIMITERS ",\r\n\0"
#define MAX_LINE_SIZE 1025
#define NUM_OF_PARAMS 4
#define MSG_MIN_PRICE "The minimal price is: "
#define ARG_NUM 2
#define OUTPUT "railway_planner_output.txt"
#define INT_LEN 11

/**
 * yoav eshed 305384869
 */

/**
 * A Struct that represents A rail part by start sign, end sind , part price, prat length
 */
typedef struct RailPart
{
	char s;
	char e;
	long len;
	long price;
} RailPart;

/**
* A struct that contains the railway parameters such as desired railway length, desired
* connections per part, and the connection signs
*/
typedef struct Params
{
	long length;
	long conTypes;
	long numOfParts;
	char *signs;
	RailPart *parts;
} Params;

/**
 * A function That prints strings and numbers to the output file
 * @param txt: the text to be printed
 * @param value: a value to printed if exists
 * @return : if string printed successfully 1 if could not open output file
 */
int printfFunc(char *txt, char *value)
{
	FILE *outputFile = fopen(OUTPUT, "w");
	if (outputFile == NULL)
	{
		return EXIT_FAILURE;
	}
	fprintf(outputFile, "%s%s", txt, value);
	fclose(outputFile);
	return EXIT_SUCCESS;
}

/**
 *  A function that prints a matrix
 * @param row :the number of rows of the matrix
 * @param col :the number of columns of the matrix
 * @return : The matrix as a two dimensional long array
 */
long **creatMatrix(long rows, long cols)
{
	long i, j;
	long **arr = (long **) malloc((rows) * sizeof(long *));
	if (arr == NULL)
	{
		return (long **) EXIT_FAILURE;
	}
	for (i = 0; i < rows; i++)
	{
		arr[i] = (long *) calloc(cols, sizeof(long));
		if (arr[i] == NULL)
		{
			return (long **) EXIT_FAILURE;
		}
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = INT_MAX;
		}
	}
	for (i = 0; i < cols; i++)
	{
		arr[0][i] = 0;
	}
	return arr;
}

/**
 * A function that calculates the minimum between two numbers
 * @param a :first number
 * @param b :second number
 * @return :the smaller number between the two
 */
long minInt(long a, long b)
{
	if (a < b)
	{
		return a;
	}
	return b;
}

/**
 * A function that finds the minimum price for rail in the required length by going over a matrix.
 * if there isn't a minimum value, the function will set the min to be -1.
 * @param mat
 * @param Data
 * @param out :output file
 */
void getPrice(long **mat, Params *Data)
{

	char minPrice[INT_LEN];
	long min = INT_MAX;
	for (long i = 0; i < Data->conTypes; i++)
	{
		if (mat[Data->length][i] < min)
		{
			min = mat[Data->length][i];
		}
	}
	if (min == INT_MAX)
	{
		min = INFINITE_MIN_PRICE;
	}
	sprintf(minPrice, "%ld", min);
	printfFunc(MSG_MIN_PRICE, minPrice);
	free(Data->parts);
	free(Data->signs);
	for (int len = 0; len < Data->length + 1; len++)
	{
		free(mat[len]);
		mat[len] = NULL;
	}
	free(mat);
}

/**
 * A function that retrieves the start index of the part
 * @param sign : the sigh who's index we want
 * @param Data : A struct that holds the rail parameters ,such as total cost, length, parts
 * @return : the wanted index if exists -1 if not (because 0 and 1 could be indexes)
 */

int getInd(char sign, Params *Data)
{
	for (int i = 0; i <= Data->conTypes; i++)
	{
		if (sign == Data->signs[i])
		{
			return i;
		}
	}
	return NO_SIGN;
}

/**
 * A function that assigns the min value per matrix cell
 * @param mat : The matrix
 * @param Data : A struct that holds the rail parameters ,such as total cost, length, parts
 * @param i : row index
 * @param j : column index
 * @param k : part index in parts array
 */
void setMin(long **mat, Params *Data, long i, long j, long k)
{
	long remainingLength = i - Data->parts[k].len;
	if (remainingLength >= 0)
	{
		long sInd = getInd(Data->parts[k].s, Data);
		mat[i][j] = minInt(mat[i][j], (mat[remainingLength][sInd] + Data->parts[k].price));
	}
}

/**
 * A function that goes over a matrix and fills her with the minimum costs for a rail by end sign
 * and length based on the formula we were given in the exerecise
 * @param mat : The matrix
 * @param Data : A  struct that holds the rail parameters ,such as total cost, length, parts
 */
void setPrices(long **mat, Params *Data)
{
	for (long i = 1; i < Data->length + 1; i++)
	{
		for (long j = 0; j < Data->conTypes; j++)
		{
			for (long k = 0; k <= Data->numOfParts; k++)
			{
				if (Data->parts[k].e == Data->signs[j])
				{
					setMin(mat, Data, i, j, k);
				}
			}
		}
	}
}

/**
 * A function that reads a line from a file and returns a number
 * @param inp :the input file
 * @param res: a pointer to a long number
 * @return 0 if it read successfully , 1 if not.
 */
int getNum(FILE *inp, long *res)
{
	char *pEnd = NULL;
	char string[INT_LEN];
	fgets(string, MAX_LINE_SIZE, inp);
	*res = strtol(string, &pEnd, 10);
	if (strcmp(pEnd, "\n") != 0)
	{
		return EXIT_FAILURE;
	}
	if (*res < 0)
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/**
 * A function that retrieves the connectors signs
 * @param inp : the input file
 * @param Data : A struct that holds the rail parameters ,such as total cost, length, parts
 * @return 0 if the function worked successfully, 1 if not
 */
int getSigns(FILE *inp, Params *Data)
{
	int i = 0;
	char string[MAX_LINE_SIZE];
	fgets(string, MAX_LINE_SIZE, inp);
	if (string[0] == 0)
	{
		return EXIT_FAILURE;
	}
	char *ptr = strtok(string, LIMITERS);
	Data->signs = malloc((strlen(string) + 10) * sizeof(char));
	if (Data->signs == NULL)
	{
		return EXIT_FAILURE;
	}
	while (ptr != NULL)
	{
		if (strlen(ptr) != 1)
		{
			return EXIT_FAILURE;
		}
		strcpy(&Data->signs[i], ptr);
		ptr = strtok(NULL, LIMITERS);
		i++;
	}
	Data->conTypes = i;
	return EXIT_SUCCESS;
}

/**
 * A function that checks if a string is valid
 * @param string : current string read from file
 * @return true if the string is in the correct format, 1 if not
 */
int stringCheck(char *string)
{
	if (string[1] != ',')
	{
		return EXIT_FAILURE;
	}
	if (string[3] != ',')
	{
		return EXIT_FAILURE;
	}
	for (unsigned int i = 4; i < strlen(string) - 1; i++)
	{

		if (!isdigit(string[i]) && (string[i] != ','))
		{
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

/**
 * A function that checks if all the parameters of a part are valid
 * @param start: Rail Part start sign
 * @param start: Rail Part end sign
 * @param len : Rail part Length
 * @param cost : rail part cost
 * @param Data : A struct that holds the rail parameters ,such as total cost, length, parts
 * @return : 0 if the part is valid, 1 if not
 */
int partCheck(char start, char end, long len, long cost, Params *Data)
{
	if (cost <= 0)
	{
		return EXIT_FAILURE;
	}
	if (len <= 0)
	{
		return EXIT_FAILURE;
	}
	if (getInd(start, Data) < 0)
	{
		return EXIT_FAILURE;
	}
	if (getInd(end, Data) < 0)
	{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/**
 * A function that reads the rail parts data and inserts in into the data structs
 * @param inp : the input file
 * @param op : the output file
 * @param Data : A struct that holds the rail parameters ,such as total cost, length, parts
 * @return 0 if all the parts entered successfully, one if not.
 */
int readData(FILE *inp, Params *Data)
{
	Data->parts = (RailPart *) calloc(10, sizeof(RailPart));
	if (Data->parts == NULL)
	{
		return EXIT_FAILURE;
	}
	RailPart *moreParts = NULL;
	char start = 0, end = 0;
	char lineIndex[INT_LEN];
	int cost = 0, len = 0;
	int i = 0;
	char string[MAX_LINE_SIZE];
	while (fgets(string, MAX_LINE_SIZE, inp) != NULL)
	{
		if (stringCheck(string))
		{
			sprintf(lineIndex, "%d.", i + 4);
			printfFunc(LINE_ERROR, lineIndex);
			return EXIT_FAILURE;
		}
		if (sscanf(string, "%c,%c,%d,%d", &start, &end, &len, &cost) != NUM_OF_PARAMS)
		{
			sprintf(lineIndex, "%d.", i + 4);
			printfFunc(LINE_ERROR, lineIndex);
			free(Data->parts);
			return EXIT_FAILURE;
		}
		if (partCheck(start, end, len, cost, Data))
		{
			sprintf(lineIndex, "%d.", i + 4);
			printfFunc(LINE_ERROR, lineIndex);
			free(Data->parts);
			return EXIT_FAILURE;
		}
		RailPart newPart = {.s = start, .e = end, .len = len, .price = cost};
		i++;
		moreParts = (RailPart *) realloc(Data->parts, i * sizeof(RailPart));
		if (moreParts != NULL)
		{
			Data->parts = moreParts;
			Data->parts[i - 1] = newPart;
		}
		else
		{
			sprintf(lineIndex, "%d.", i + 4);
			printfFunc(LINE_ERROR, lineIndex);
			return EXIT_FAILURE;
		}
	}
	Data->numOfParts = i;
	return EXIT_SUCCESS;
}

/**
 * A function that acquires all of the data from the file using different function for each part
 * of the file, get num for the length of the rail and the types of connectors, get signs for
 * the types of connectors available, and read data for reading the parts
 * @param input : the input file
 * @param output : the output file
 * @param Data : A struct that holds the rail parameters ,such as total cost, length, parts
 * @return: 0 If data read successfully ,1 if not
 */
int dataAcquisition(FILE *input, Params *Data)
{
	if (getNum(input, &Data->length))
	{
		printfFunc(LINE_ERROR, "1.");
		return EXIT_FAILURE;
	}
	if (getNum(input, &Data->conTypes))
	{
		printfFunc(LINE_ERROR, "2.");
		return EXIT_FAILURE;
	}
	if (Data->conTypes == 0)
	{
		printfFunc(LINE_ERROR, "2.");
		return EXIT_FAILURE;
	}
	if (getSigns(input, Data))
	{
		printfFunc(LINE_ERROR, "3.");
		return EXIT_FAILURE;
	}
	if (readData(input, Data))
	{
		free(Data->signs);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/**
 * A function that checks if the file is valid, by checking if there is a file, and if it isnt empty
 * @param argc : number of arguments entered by the user
 * @param file : the file name as an argument
 * @param input : the input file
 * @param output : the output file
 * @return : 0 if the file has been read successfully 1 , if not
 */
int fileReadTest(FILE *input)
{
	if (input == NULL)
	{
		printfFunc(FILE_ERROR, "");
		return EXIT_FAILURE;
	}
	int c = fgetc(input);
	if (c == EOF)
	{
		printfFunc(EMPTY_ERROR, "");
		return EXIT_FAILURE;
	}
	ungetc(c, input);
	return EXIT_SUCCESS;
}

/**
 * A function that checks if there are enough arguments in
 * @param argc : the number of arguments entered
 * @param output: the output file
 * @return 0 if the argument number is correct, 1 if not
 */
int argCheck(int argc)
{
	if (argc != ARG_NUM)
	{
		printfFunc(ARG_ERROR, "");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

/**
 * A program that gets an input file, reads it and calculates the minimal price for a rail
 * with given length
 * @return :minimal price if successful , or -1 if not
 */
int main(int argc, char *argv[])
{
	if (argCheck(argc))
	{
		return EXIT_FAILURE;
	}
	FILE *inputFile = fopen(argv[1], "r");
	Params Data = {.length = 0, .conTypes = 0, .numOfParts = 0, .signs = NULL, .parts = NULL};
	if (fileReadTest(inputFile))
	{
		return EXIT_FAILURE;
	}
	if (dataAcquisition(inputFile, &Data))
	{
		return EXIT_FAILURE;
	}
	fclose(inputFile);
	long **matr = creatMatrix(Data.length + 1, Data.conTypes);
	setPrices(matr, &Data);
	getPrice(matr, &Data);
	return EXIT_SUCCESS;
}



