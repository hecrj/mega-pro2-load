#ifndef MOVIE_HPP
#define MOVIE_HPP

class Movie
{
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

};

#endif