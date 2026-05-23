#include "movies.h"

#include <iomanip>
#include <iostream>

void printMoviesAlphabetically(const MovieList& movies) {
  for (const std::pair<std::string, double>& movie : movies) {
    std::cout << movie.first << ", "
              << std::fixed << std::setprecision(1) << movie.second
              << '\n';
  }
}

void printMoviesForPrefix(const MovieList& movies, const std::string& prefix) {
  if (movies.empty()) {
    std::cout << "No movies found with prefix " << prefix << '\n';
    return;
  }

  for (const std::pair<std::string, double>& movie : movies) {
    std::cout << movie.first << ", "
              << std::fixed << std::setprecision(1) << movie.second
              << '\n';
  }

  std::cout << '\n';
}

void printBestMovieForPrefix(const MovieList& movies, const std::string& prefix) {
  if (!movies.empty()) {
    std::cout << "Best movie with prefix " << prefix << " is: "
              << movies[0].first << " with rating "
              << std::fixed << std::setprecision(1) << movies[0].second
              << '\n';
  }
}
