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

		void set_time_end(int t_end);

	private:
		int id;
		int movie_id;
		int t_start;
		int t_end;
};

#endif
