// Winter'24
// Instructor: Diba Mirza
// Student name: Chinmay Khaladkar
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << '\n';
        cerr << "Usage: " << argv[ 0 ] << " moviesFilename prefixFilename " << '\n';
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the movies
    MovieList movies;

    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
            // Use std::string movieName and double movieRating
            // to construct your Movie objects
            // cout << movieName << " has rating " << movieRating << '\n';
            // insert elements into your data structure
            addMovie(movies, movieName, movieRating);
    }

    movieFile.close();

    if (argc == 2){
            //print all the movies in ascending alphabetical order of movie names
            sortMoviesByName(movies);
            printMoviesAlphabetically(movies);
            return 0;
    }

    ifstream prefixFile (argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> prefixes;
    while (getline (prefixFile, line)) {
        if (!line.empty()) {
            prefixes.push_back(line);
        }
    }

    vector<MovieList> moviesByPrefix;
    for (const string& prefix : prefixes) {
        MovieList matches = findMoviesWithPrefix(movies, prefix);
        printMoviesForPrefix(matches, prefix);
        moviesByPrefix.push_back(matches);
    }

    for (int i = 0; i < prefixes.size(); i++) {
        printBestMovieForPrefix(moviesByPrefix[i], prefixes[i]);
    }

    return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/
// Checking whether a movie starts with the prefix can take up to O(l) time since it will compare l chars.
// So matching movies for a prefix is O(n * l)
// Since at most k movies match, they have to be sorted, which is O(k*log(k))
// Multiply that by l since that's the maximum amount of letters that need to be compared
// yielding O(k*log(k) * l)
// Adding those and multiplying by m movies gives O(m(n*l + k*log(k)*l))
bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}
