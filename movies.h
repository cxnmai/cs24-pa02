#ifndef MOVIES_H
#define MOVIES_H

#include <string>

#include "utilities.h"

void printMoviesAlphabetically(const MovieList& movies);
void printMoviesForPrefix(const MovieList& movies, const std::string& prefix);
void printMoviesForPrefix(const MoviePtrList& movies, const std::string& prefix);
void printBestMovieForPrefix(const MovieList& movies, const std::string& prefix);
void printBestMovieForPrefix(const MoviePtrList& movies, const std::string& prefix);

#endif
