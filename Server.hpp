#ifndef SERVER_HPP
#define SERVER_HPP

#include "Request.hpp"
#include "Movie.hpp"

class Server
{
	public:
		Server(int speed);

		int get_request_id() const;
		int get_speed() const;
		int get_parent_id() const;
		bool is_busy() const;
		bool has_movie(int movie_id) const;
		bool has_parent() const;
		bool has_children() const;

		void set_request(const Request &req);
		void add_movie(const Movie &mov);
		void delete_movie(const Movie &mov);
		void children(int &c1, int &c2);

	private:
		int speed;
		int request_id;
		vector<int> movie_ids;
		int parent_id;
		int child1_id;
		int child2_id;
};

#endif