#include "Movie.hpp"

Movie::Movie()
{}

Movie::Movie(int size)
{
	this->size = size;
}

int Movie::get_size() const
{
	return size;
}

void Movie::write_movie(int movie_id) const
{
	cout << "Movie ID: " << movie_id << endl;
	cout << "Movie size:" << size << endl;
}