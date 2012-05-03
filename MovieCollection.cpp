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
    int movie_id = -1;
    int movie_dwl = 0;

    for(int i = 0; i < movies.size(); ++i)
    {
        int movie_cur = movies[i].how_many_downloads(t1, t2);

        if(movie_cur > movie_dwl)
        {
            movie_id = i;
            movie_dwl = movie_cur;
        }
    }

    if(movie_id == -1)
        cout << "0 0" << endl;
    else
        cout << movie_id+1 << ' ' << movie_dwl << endl;
}
