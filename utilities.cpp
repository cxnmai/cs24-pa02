#include "utilities.h"

#include <algorithm>

bool compareMoviesByName(const Movie& left, const Movie& right) {
    return left.first < right.first;
}

void addMovie(MovieList& movies, const std::string& name, double rating) {
  std::pair<std::string, double> movie(name, rating);
  movies.push_back(movie);
}

void sortMoviesByName(MovieList& movies) {
  std::sort(movies.begin(), movies.end(), compareMoviesByName);
}

bool movieStartsWithPrefix(const Movie& movie, const std::string& prefix) {
  if (prefix.length() > movie.first.length()) {
    return false;
  }

  return movie.first.substr(0, prefix.length()) == prefix;
}

MovieList findMoviesWithPrefix(const MovieList& movies, const std::string& prefix) {
  MovieList matches;

  for (const std::pair<std::string, double>& movie : movies) {
    if (movieStartsWithPrefix(movie, prefix)) {
      matches.push_back(movie);
    }
  }

  sortMoviesByRatingThenName(matches);
  return matches;
}

bool compareMoviesByRatingThenName(const Movie& left, const Movie& right) {
  if (left.second == right.second) {
    return left.first < right.first;
  }

  return left.second > right.second;
}

void sortMoviesByRatingThenName(MovieList& movies) {
  std::sort(movies.begin(), movies.end(), compareMoviesByRatingThenName);
}

bool compareMoviePointersByRatingThenName(const Movie* left, const Movie* right) {
  if (left->second == right->second) {
    return left->first < right->first;
  }

  return left->second > right->second;
}

void sortMoviePointersByRatingThenName(MoviePtrList& movies) {
  std::sort(movies.begin(), movies.end(), compareMoviePointersByRatingThenName);
}
