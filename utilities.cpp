#include "utilities.h"

#include <algorithm>
#include <iomanip>
#include <iostream>

bool compareMoviesByName(const std::pair<std::string, double>& left,
                         const std::pair<std::string, double>& right) {
    return left.first < right.first;
}

void addMovie(MovieList& movies, const std::string& name, double rating) {
  std::pair<std::string, double> movie(name, rating);
  movies.push_back(movie);
}

void sortMoviesByName(MovieList& movies) {
  std::sort(movies.begin(), movies.end(), compareMoviesByName);
}

void printMoviesAlphabetically(const MovieList& movies) {
  for (const auto& movie : movies) {
    std::cout << movie.first << ", "
              << std::fixed << std::setprecision(1) << movie.second
              << std::endl;
  }
}
