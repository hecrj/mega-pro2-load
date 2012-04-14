#include "Server.hpp"

Server::Server()
{
	parent_id = -1;
	child1_id = -1;
	child2_id = -1;
	request_id = -1;
}

int Server::get_request_id() const
{
	return request_id;
}

int Server::get_speed() const
{
	return speed;
}

int Server::get_parent_id() const
{
	return parent_id;
}

bool Server::is_busy()
{
	return request_id != -1;
}

bool Server::has_movie(int movie_id) const
{
	return movies[movie_id];
}

bool Server::has_parent() const
{
	return parent_id != -1;
}

bool Server::has_children() const
{
	return (child1_id != -1 and child2_id != -2);
}

void Server::set_request(int request_id)
{
	this->request_id = request_id;
}

void Server::enable_movie(int movie_id)
{
	movies[movie_id] = true;
}

void Server::disable_movie(int movie_id)
{
	movies[movie_id] = false;
}

void Server::children(int &c1, int &c2)
{
	c1 = child1_id;
	c2 = child2_id;
}

void Server::read_server(int n_movies)
{
	movies = vector<int>(n_movies, false);
	speed = readint();
}
