#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <utility>
#include <vector>

using MovieList = std::vector<std::pair<std::string, double>>;

void addMovie(MovieList& movies, const std::string& name, double rating);
void sortMoviesByName(MovieList& movies);
bool movieStartsWithPrefix(const std::pair<std::string, double>& movie,
                           const std::string& prefix);
MovieList findMoviesWithPrefix(const MovieList& movies, const std::string& prefix);
void sortMoviesByRatingThenName(MovieList& movies);

#endif
