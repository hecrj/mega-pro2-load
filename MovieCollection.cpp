#include "MovieCollection.hpp"
#include "utils.PRO2"

MovieCollection::MovieCollection()
{
	
}

int MovieCollection::size() const
{
	return movies.size();
}

int MovieCollection::get_movie_size(int movie_id) const
{
	return movies[movie_id];
}

void MovieCollection::read_movies()
{
	cout << "Input the total number of movies in the system: ";
    int n = readint();

    movies = vector<int>(n);

    for(int i = 0; i < n; ++i)
    {
        cout << "Input the size in MBytes of the movie #" << i+1 << ": ";
        movies[i] = readint();
    }
}

void MovieCollection::write_movie(int movie_id) const
{
    cout << "The size of the movie with id #" << movie_id << " is ";
    cout << movies[movie_id] << " MBytes." << endl;
}