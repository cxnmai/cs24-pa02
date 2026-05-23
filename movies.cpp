#include "movies.h"

#include <charconv>
#include <iomanip>
#include <iostream>
#include <system_error>

namespace {

void printRating(double rating) {
  char buffer[32];
  const auto result = std::to_chars(buffer, buffer + sizeof(buffer), rating,
                                   std::chars_format::fixed, 1);
  if (result.ec == std::errc()) {
    std::cout.write(buffer, result.ptr - buffer);
    return;
  }

  std::cout << std::fixed << std::setprecision(1) << rating;
}

void printMovieLine(const Movie& movie) {
  std::cout << movie.first << ", ";
  printRating(movie.second);
  std::cout << '\n';
}

void printMovieLine(const Movie* movie) {
  printMovieLine(*movie);
}

}

void printMoviesAlphabetically(const MovieList& movies) {
  for (const Movie& movie : movies) {
    printMovieLine(movie);
  }
}

void printMoviesForPrefix(const MovieList& movies, const std::string& prefix) {
  if (movies.empty()) {
    std::cout << "No movies found with prefix " << prefix << '\n';
    return;
  }

  for (const Movie& movie : movies) {
    printMovieLine(movie);
  }

  std::cout << '\n';
}

void printMoviesForPrefix(const MoviePtrList& movies, const std::string& prefix) {
  if (movies.empty()) {
    std::cout << "No movies found with prefix " << prefix << '\n';
    return;
  }

  for (const Movie* movie : movies) {
    printMovieLine(movie);
  }

  std::cout << '\n';
}

void printBestMovieForPrefix(const MovieList& movies, const std::string& prefix) {
  if (!movies.empty()) {
    std::cout << "Best movie with prefix " << prefix << " is: "
              << movies[0].first << " with rating ";
    printRating(movies[0].second);
    std::cout << '\n';
  }
}

void printBestMovieForPrefix(const MoviePtrList& movies, const std::string& prefix) {
  if (!movies.empty()) {
    std::cout << "Best movie with prefix " << prefix << " is: "
              << movies[0]->first << " with rating ";
    printRating(movies[0]->second);
    std::cout << '\n';
  }
}
