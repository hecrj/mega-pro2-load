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
	return movies[movie_id].get_size();
}

void MovieCollection::read_movies()
{
	cout << "Input the total number of movies in the system: ";
    int n = readint();

    movies = vector<Movie>(n);

    for(int i = 0; i < n; ++i)
        movies[i].read_movie(i+1);
}

void MovieCollection::print_most_downloaded_movie(int t1, int t2) const
{
    int movie_id = -1;
    int movie_dwl = -1;

    for(int i = size() - 1; i >= 0; --i)
    {
        int movie_cur = movies[i].how_many_downloads(t1, t2);

        if(movie_cur >= movie_dwl)
        {
            movie_id = i;
            movie_dwl = movie_cur;
        }
    }

    if(movie_id == -1)
        cout << "0 0" << endl;
    else
        cout << movies[movie_id].get_id() << ' ' << movie_dwl << endl;
}