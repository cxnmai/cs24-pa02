#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <utility>
#include <vector>

using MovieList = std::vector<std::pair<std::string, double>>;

void addMovie(MovieList& movies, const std::string& name, double rating);
void sortMoviesByName(MovieList& movies);
void printMoviesAlphabetically(const MovieList& movies);

#endif
