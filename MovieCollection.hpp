#ifndef MOVIECOLLECTION
#define MOVIECOLLECTION

#include "Movie.hpp"

class Movie
{
	public:
		MovieCollection::MovieCollection()
		{}

		Movie MovieCollection::get_movie(int movie_id);

		void MovieCollection::read_movies();

	private:
		vector<Movie> movies;
};

#endif