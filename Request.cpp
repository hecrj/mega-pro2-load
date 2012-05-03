#include "Request.hpp"
#include <cmath>
#include "utils.PRO2"

int Request::next_id = 0;

Request::Request()
{
	id = next_id;
	movie_id = -1;
	t_start = -1;
	t_end = -1;

	next_id += 1;
}

int Request::get_id() const
{
	return id;
}

int Request::get_movie_id() const
{
	return movie_id;
}

int Request::get_time_start() const
{
	return t_start;
}

int Request::get_time_end() const
{
	return t_end;
}

void Request::set_lifespan(int size, int speed)
{
	int lifespan = int(ceil( double(size) / double(speed) ));
	t_end = t_start + lifespan;
}

void Request::read_request()
{
    movie_id = readint() - 1;
    t_start = t_end = readint();
}

void Request::write_request() const
{
	cout << id << ' ' << movie_id+1 << ' ' << t_start << ' ' << t_end << endl;
}

void Request::set_next_id(int id)
{
	next_id = id;
}
