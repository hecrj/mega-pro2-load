#include "Movie.hpp"
#include "utils.PRO2"

Movie::Movie()
{
	id = -1;
	size = -1;
}

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

int Movie::how_many_downloads(int t1, int t2) const
{
	int downloads = 0;

	list<int>::const_iterator it = downloads.begin();

	while(it != downloads.end() and *it <= t2)
	{
		if(*it >= t1 and *it <= t2)
			downloads++;

		it++;
	}

	return downloads;
}

void Movie::add_download(int dwl_time)
{
	downloads.push_back(dwl_time);
}

void Movie::read_movie(int id)
{
	this->id = id;

	cout << "Input the size of the movie #" << id << ": ";
	size = readint();
}