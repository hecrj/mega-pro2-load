#ifndef MOVIECOLLECTION
#define MOVIECOLLECTION

#include "Movie.hpp"

class Movie
{
	public:
		MovieCollection::MovieCollection();

		int MovieCollection::number_of_movies() const;
		Movie MovieCollection::get_movie(int movie_id) const;

		void MovieCollection::read_movies();

	private:
		vector<Movie> movies;
};

#endif