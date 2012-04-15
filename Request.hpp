#ifndef REQUEST_HPP
#define REQUEST_HPP

class Request
{
	public:
		Request();
		Request(int id, int t_start, int movie_id);

		int get_id() const;
		int get_movie_id() const;
		int get_time_start() const;
		int get_time_end() const;
		Route get_route() const;

		void read_request(int id);
		void set_route(const Route &route);

	private:
		int id;
		int movie_id;
		int t_start;
		int t_end;
		Route route;
};

#endif
