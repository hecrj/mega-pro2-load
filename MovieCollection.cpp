/**
 * @file MovieCollection.cpp
 * @brief MovieCollection implementation
 */
#include "MovieCollection.hpp"

MovieCollection::MovieCollection()
{}

MovieCollection::~MovieCollection()
{}

int MovieCollection::size() const
{
	return movies.size();
}

int MovieCollection::get_movie_size(int movie_id) const
{
	return movies[movie_id].get_size();
}

void MovieCollection::add_download(int movie_id, int time_start)
{
    movies[movie_id].add_download(time_start);
}

void MovieCollection::read_movies()
{
    int n = readint();

    movies = vector<Movie>(n);

    for(int i = 0; i < n; ++i)
        movies[i].read_movie();
}

void MovieCollection::write_most_downloaded_movie(int t1, int t2) const
{
    int movie_id = 0;
    int movie_dwl = 0;
    int i = 0;

    // Inv: movie_id = most downloaded movie id in movies[0..i-1] between t1 and t2
    //      movie_dwl = download times of the most downloaded movie
    //      0 <= i <= movies.size()
    while(i < movies.size())
    {
        int movie_cur = movies[i].how_many_downloads(t1, t2);

        if(movie_cur > movie_dwl)
        {
            movie_id = i+1;
            movie_dwl = movie_cur;
        }

        ++i;
    }

    cout << movie_id << ' ' << movie_dwl << endl;
}
