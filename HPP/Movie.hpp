#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <list>

class Movie
{
	private:
		int id;
		int size;
		std::list<int> downloads;

	public:
		/**
		 * Creates a new empty Movie.
		 * \pre True
		 * \post Returns a new empty Movie.
		 */
		Movie();

		/**
		 * Creates a new Movie with **id** and **size**.
		 * \pre True
		 * \post Returns a new Movie with **id** and **size**.
		 */
		Movie(int id, int size);

		/**
		 * Gets the id of the Movie.
		 * \pre The Movie has an id.
		 * \post The id of the Movie is returned.
		 */
		int get_id() const;

		/**
		 * Gets the size of the Movie.
		 * \pre The Movie has a size.
		 * \post The Movie size is returned.
		 */
		int get_size() const;

		/**
		 * Gets the number of downloads between **t1** and **t2**.
		 * \pre True
		 * \post The number of downloads is returned.
		 */
		int how_many_downloads(int t1, int t2);

		/**
		 * Adds a download record to the Movie at **dwl_time**.
		 * \pre True
		 * \post The download record has been added.  
		 */
		void add_download(int dwl_time) const;

		/**
		 * Reads and assigns data to the Movie.
		 * \pre Not determined yet.
		 * \post The read data has been assigned to the Movie.
		 */
		void read_movie();

};

#endif