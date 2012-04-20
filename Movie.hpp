/**
 * @file Movie.hpp
 * @brief Movie specification.
 */
#ifndef MOVIE_HPP
#define MOVIE_HPP

/**
 * A Movie has an id and a size.
 */
class Movie
{
	private:
		int id;
		int size;

	public:
		/**
		 * Creates an empty Movie.
		 * \pre True
		 * \post Returns a new empty Movie.
		 */
		Movie();
		
		/**
		 * Creates a new Movie with the **size** specified.
		 * \pre size > 0
		 * \post Returns a new Movie with **size**.
		 */
		Movie(int size);

		/**
		 * Returns the size of the Movie.
		 * \pre Movie size is defined.
		 * \post The size of the Movie is returned.
		 */
		int get_size() const;

		/**
		 * Reads size from input stream and sets it to the Movie.
		 * \pre Movie size is not defined
		 * \post The Movie has the size read from input stream.
		 */
		void read_movie();

		/**
		 * Outputs information of the Movie.
		 * \pre True
		 * \post Information about the Movie has been printed.
		 */
		void write_movie();
};

#endif