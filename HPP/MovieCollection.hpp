/**
 * @file MovieCollection.hpp
 * @brief MovieCollection specification
 */
#ifndef MOVIECOLLECTION
#define MOVIECOLLECTION

#include "Movie.hpp"

/**
 * A MovieCollection represents a collection of movies.
 */
class MovieCollection
{
	public:
		/**
		 * Creates a new empty MovieCollection.
		 * \pre True
		 * \post Returns a new empty MovieCollection.
		 */
		MovieCollection();

		/**
		 * Returns the number of movies of the MovieCollection.
		 * \pre True
		 * \post The number of movies of the MovieCollection is returned.
		 */
		int size() const;

		/**
		 * Returns the Movie with id **movie_id**.
		 * \pre 0 <= id <= MovieCollection::size()
		 * \post The Movie with id **movie_id** is returned.
		 */
		Movie get_movie(int movie_id) const;

		/**
		 * Reads a sequence of Movies from input stream.
		 * \pre True
		 * \post The Movies read from input are added to the MovieCollection.
		 */
		void read_movies();

#endif