/**
 * @file MovieCollection.hpp
 * @brief MovieCollection specification
 */
#ifndef MOVIECOLLECTION
#define MOVIECOLLECTION

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
		 * Returns the movie size with id **movie_id**.
		 * \pre 0 <= id <= MovieCollection::size()
		 * \post The movie size with id **movie_id** is returned.
		 */
		int get_movie_size(int movie_id) const;

		/**
		 * Adds a download record to the movie with **movie_id** in the time
		 * **dwl_time**.
		 * \pre 0 <= **movie_id** <= MovieCollection::size()
		 *      0 <= **dwl_time**
		 * \post The download record has been added to the desired movie.
		 */
		void add_download(int movie_id, int dwl_time);

		/**
		 * Reads a sequence of movies from input stream.
		 * \pre True
		 * \post The Movies read from input are added to the MovieCollection.
		 */
		void read_movies();

		/**
		 * Prints the most downloaded movie beetween times [t1, t2].
		 * \pre True
		 * \post If found, the id and the download times of the most downloaded
		 *       movie are printed in the output stream.
		 *       If not found, two separated 0s are printed.
		 */
		void write_most_downloaded_movie(int t1, int t2) const;
};

#endif