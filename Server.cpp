#include "Server.hpp"
#include "utils.PRO2"

Server::Server()
{
	request_id = -1;
	speed = 0;
	end_time = -1;
}

int Server::get_speed() const
{
	return speed;
}

bool Server::is_busy_at(int cur_time) const
{
	return cur_time < end_time;
}

int Server::get_time_left(int cur_time) const
{
	return end_time - cur_time;
}

int Server::get_request_id() const
{
	return request_id;
}

bool Server::has_movie(int movie_id) const
{
	return movies[movie_id];
}

void Server::set_busy(int request_id, int end_time)
{
	this->request_id = request_id;
	this->end_time = end_time;
}

void Server::enable_movie(int movie_id)
{
	movies[movie_id] = true;
}

void Server::disable_movie(int movie_id)
{
	movies[movie_id] = false;
}

void Server::read_server(int total_movies)
{
	movies = vector<bool>(total_movies, false);

	speed = readint();

	int n_movies = readint();

	for(int i = 0; i < n_movies; ++i)
		enable_movie(readint() - 1);
}
