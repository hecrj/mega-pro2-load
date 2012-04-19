#include "utils.PRO2"
#include "MovieCollection.hpp"

MovieCollection::MovieCollection()
{
	
}

int MovieCollection::size() const
{
	return movies.size();
}

Movie MovieCollection::get_movie(int movie_id) const
{
	return movies[movie_id];
}

void MovieCollection::read_movies()
{
	cout << "Input the number of movies in the network: ";
    int n = readint();

    movies = vector<Movie>(n);

    for(int i = 0; i < n; ++i)
    {
        cout << "Input the size of the movie #" << i+1 << ": ";
        int size = readint();

        Movie mov(i, size);
        movies[i] = mov;
    }
}

void MovieCollection::write_most_downloaded_movies(const RequestCollection &rcol, int t1, int t2) const
{
    // ...
}