#ifndef SERVER_HPP
#define SERVER_HPP

#include "Request.hpp"
#include "Movie.hpp"

class Server
{
	public:
		Server();
		Server(int id, int speed);

		int get_request_id() const;
		int get_speed() const;
		int get_parent_id() const;
		bool is_busy() const;
		bool has_movie(int movie_id) const;
		bool has_parent() const;
		bool has_children() const;

		void set_request(int request_id);
		void enable_movie(int movie_id);
		void disable_movie(int movie_id);
		void children(int &c1, int &c2);
		void read_server(int n_movies);

	private:
		int speed;
		int request_id;
		vector<bool> movies;
		int parent_id;
		int child1_id;
		int child2_id;
};

#endif