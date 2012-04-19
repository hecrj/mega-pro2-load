#include "Movie.hpp"

Movie::Movie()
{}

Movie::Movie(int id, int size)
{
	this->id = id;
	this->size = size;
}

int Movie::get_id() const
{
	return id;
}

int Movie::get_size() const
{
	return size;
}
