#include "Server.hpp"
#include "utils.PRO2"

Server::Server()
{

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

bool Server::is_busy() const
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
	return (child1_id != -1 and child2_id != -1);
}

void Server::set_request(int request_id)
{
	this->request_id = request_id;
}

void Server::set_parent_id(int parent_id)
{
	this->parent_id = parent_id;
}

void Server::enable_movie(int movie_id)
{
	movies[movie_id] = true;
}

void Server::disable_movie(int movie_id)
{
	movies[movie_id] = false;
}

void Server::children(int &c1, int &c2) const
{
	c1 = child1_id;
	c2 = child2_id;
}

void Server::read_server(int n_movies)
{
	movies = vector<bool>(n_movies, false);

	speed = readint();

	int n_movies = readint();

	for(int i = 0; i < n_movies; ++i)
		enable_movie(readint());
}
