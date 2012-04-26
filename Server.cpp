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

void Server::read_server(int id, int n_movies)
{
	movies = vector<bool>(n_movies, false);

	cout << "Input the speed of the server " << id+1 << ": ";
	speed = readint();

	cout << "Input the IDs of the server movies (0 to end):" << endl;
	int movie_id = readint() - 1;

	while(movie_id >= 0)
	{
		enable_movie(movie_id);
		movie_id = readint() - 1;
	}

	cout << "Input the 2 sub-server IDs of the server " << id << " (0 to none):" << endl;
	child1_id = readint() - 1;
	child2_id = readint() - 1;
}

