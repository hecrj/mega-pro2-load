#ifndef ROUTE_HPP
#define ROUTE_HPP

#include <stack>

class Route
{
	private:
		int time;
		std::stack<int> servers;

	public:
		Route();
		Route(int time);

		int get_time() const;
		std::stack<int> get_servers() const;
		bool is_empty() const;

		void add_server(int server_id);
};

#endif