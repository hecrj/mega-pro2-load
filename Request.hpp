#ifndef REQUEST_HPP
#define REQUEST_HPP

#include "Route.hpp"

class Request
{
	private:
		int id;
		int movie_id;
		int t_start;
		int t_end;
		Route route;

	public:
		Request();

		int get_id() const;
		int get_movie_id() const;
		int get_time_start() const;
		int get_time_end() const;
		Route get_route() const;

		void set_time_end(int t_end);
		void set_route(const Route &route);

		void read_request(int id);
		void write_request();
};

#endif
