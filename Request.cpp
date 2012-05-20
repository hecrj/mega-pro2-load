/**
 * @file Request.cpp
 * @brief Request implementation
 */
#include "Request.hpp"

int Request::next_id = 0;

Request::Request()
{
	id = next_id;
	next_id += 1;
}

Request::~Request()
{}

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

void Request::set_duration(int duration)
{
	t_end = t_start + duration;
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
