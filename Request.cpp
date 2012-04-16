#include "Request.hpp"
#include "utils.PRO2"

Request::Request()
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

Route Request::get_route() const
{
	return route;
}

void Request::set_time_end(int t_end)
{
	this->t_end = t_end;
}

void Request::set_route(const Route &route)
{
	this->route = route;
	t_end = t_start + route.get_time();
}

void Request::read_request(int id)
{
	this->id = id;

	cout << "Enter the start time of the request: ";
	t_start = readint();

	cout << "Enter the ID of the movie to request: ";
	movie_id = readint() - 1;
}

void Request::write_request()
{
	cout << "Request ID: " << id+1 << endl;
	cout << "Movie ID:   " << movie_id+1 << endl;
	cout << "Start time: " << t_start << endl;
	cout << "End time:   " << t_end << endl;
}
