#include "Request.hpp"
#include "utils.PRO2"

Request::Request()
{
	id = static::count;
	movie_id = -1;
	t_start = -1;
	t_end = -1;

	static::count += 1;
}

Request::Request(int id, int movie_id, int t_start, int t_end)
{
	this->id = id;
	this->movie_id = movie_id;
	this->t_start = t_start;
	this->t_end = t_end;
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

void Request::set_lifespan(int lifespan)
{
	t_end = t_start + lifespan;
}

void Request::read_request()
{
	cout << "Input the time when to start the request #" << request_id << ": ";
    t_start = readint();

    cout << "Input the movie id you want to download: ";
    movie_id = readint() - 1;
}

void Request::write_request()
{
	cout << endl;
	cout << "Request ID: " << id << endl;
	cout << "Movie ID:   " << movie_id+1 << endl;
	cout << "Start time: " << t_start << endl;
	cout << "End time:   " << t_end << endl;
	cout << endl;
}
