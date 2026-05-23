#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <utility>
#include <vector>

using Movie = std::pair<std::string, double>;
using MovieList = std::vector<Movie>;
using MoviePtrList = std::vector<const Movie*>;

void addMovie(MovieList& movies, const std::string& name, double rating);
void sortMoviesByName(MovieList& movies);
bool movieStartsWithPrefix(const Movie& movie, const std::string& prefix);
MovieList findMoviesWithPrefix(const MovieList& movies, const std::string& prefix);
void sortMoviesByRatingThenName(MovieList& movies);
void sortMoviePointersByRatingThenName(MoviePtrList& movies);

#endif
