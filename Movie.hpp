#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <list>

class Movie
{
	private:
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
		int how_many_downloads(int t1, int t2) const;

		/**
		 * Adds a download record to the Movie at **dwl_time**.
		 * \pre True
		 * \post The download record has been added.  
		 */
		void add_download(int dwl_time);

		void read_movie();

};

#endif