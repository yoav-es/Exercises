// RecommendSystem.h

#ifndef RECOMMENDSYSTEM_H
#define RECOMMENDSYSTEM_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <filesystem>
#include <set>

#define DEFAULT 0.0
#define READ_ERROR "Unable to open file "
#define USER_ERROR "USER NOT FOUND"
#define FAILURE -1
#define STANDART -1000
/**
 *Data struct for holding the RecommenderSystem class data
 */
typedef struct Data
{
	std::vector<std::string> titles;
	std::map<std::string, std::vector<double>> movies;
	std::map<std::string, std::vector<double>> attributes;
} Data;

/**
 * RecommenderSystem Class
 */
class RecommenderSystem
{
public:
	/**
	 * default constructor for RecommenderSystem;
	 */
	RecommenderSystem();

	/**
	 * A function  that loads the data from given input files
	 * @param moviesAttributesFilePath: moviesAttributes file path
	 * @param userRanksFilePath: userRanks File Path
	 * @return: 1 if data load was successful 0 if not
	 */
	int loadData(std::string moviesAttributesFilePath, std::string userRanksFilePath);

	/**
	 * A function creates a movie recommendation by movie content
	 * @param userName: the user to recommend to
	 * @return: the name of the movie recommended for the specific user
	 */
	std::string recommendByContent(const std::string &userName);

	/**
	 * A function creates a movie recommendation for a user
	 * @param MovieName: an non-ranked movie that the recommendation will be based on.
	 * @param userName: the user name that the recommendation is for
	 * @param k: number of similar movies to be calculated with
	 * @return: a double that represents prediction of the movie score for the given user
	 */
	double predictMovieScoreForUser(const std::string &MovieName,
									const std::string &userName, int k);

	/**
	 * A function that recommends a movie to a given user
	 * @param userName: the user name that the recommendation is for
	 * @param k: the number of seen movies to refer to while making the preference
	 * @return: a string with the recommendation
	 */
	std::string recommendByCF(const std::string &userName, int k);


private:
	Data _data;

	/**
	 *An aid function that loads the user's rankings to a data map and movie titles into a
	 * vector
	 * @param userRanksFilePath : moviesAttributes file path
	 * @param usersRankingMap: the map that holds the the user's movie rankings while the user name
	 * serves as key
	 * @param titles: a vector which holds the movie titles by order
	 * @return the data map
	 */
	static int _userLoader(std::string &userRanksFilePath,
						   std::map<std::string, std::vector<double>> &usersRankingMap,
						   std::vector<std::string> &titles);

	/**
	 *An aid function that loads the movies attributes to a data map and movie titles into a
	 * vector
	 * @param moviesAttributesFilePath: moviesAttributes file path
	 * @param movieAttributesMap: map for storing movie attributes when the movie title serves as key
	 * @return: the data map
	 */
	static int _movieLoader(std::string &movieFilePath,
							std::map<std::string, std::vector<double>> &movieAttributesMap);

	/**
	 * A function for creating a preference vector
	 * @param norm : the user normalised ranking vector that will be used as the base for the preference
	 * vector
	 * @return: preference vector
	 */
	std::vector<double> _createPreferenceVector(const std::vector<double> &vec);


	/**
	 * A function that normalises a vector by calculating its average and decreasing it from each
	 * of the vector values
	 * @param norm :the user ranking vector to be normalised
	 * @return : a normalised vector
	 */
	static std::vector<double> _normalisedVector(std::vector<double> &norm);

	/**
	 * A function that calculates the angle between two vectors
	 * @param vecA :first vector
	 * @param vecB :second vector
	 * @return: the angle between the vectors
	 */
	static double _getAngle(const std::vector<double> &vecA, const std::vector<double> &vecB);

	/**
	  * a function that finds a set of similar movies to a given movie
	  * @param movie : the given movie
	  * @param user : the current user
	  * @param k: number of similar movies to be calculated with
	  * @return : a vector of pairs that holds the set of similar ranked movies angles
	  */
	std::set<std::pair<double, std::string>> _findSet(const std::vector<double> &movie,
													  const std::string &user, long unsigned int k);


};

#endif //RECOMMENDSYSTEM_H

