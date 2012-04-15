#include "Router.hpp"
#include <queue>

Router::Router()
{}

Route Router::get_route(const Movie &movie) const
{
	queue<Node> qservs;

	Node main_server;
	main_server.id = main_server_id;
	main_server.speed = servers[main_server_id].get_speed();
	qservs.push(main_server);

	Node best_server;
	best_server.id = 0;
	best_server.speed = 0;

	while(not qservs.empty())
	{
		Node serv = qservs.front();
		qservs.pop();

		if(not servers[serv.id].is_busy() and servers[serv.id].has_movie(movie.get_id()))
		{
			serv.speed += servers[serv.id].get_speed();

			if(movie.get_size() / serv.speed <= 1)
				return build_route(serv);

			else if(serv.speed > best_server.speed)
				best_server = serv;
		}

		if(servers[serv.id].has_children())
		{
			int s1, s2;
			servers[serv.id].children(s1, s2);

			Node serv_child;
			serv_child.id = s1;
			serv_child.speed = serv.speed;

			qservs.push(serv_child);

			if(s2 != 0)
			{
				serv_child.id = s2;
				qservs.push(serv_child);
			}
		}

	}

	return build_route(best_server);
}

Route Router::build_route(const Node &serv_node)
{
	Route route(serv_node.speed);

	while(serv_node.id != -1)
	{
		route.add_server_id(serv_node.id);
		serv_node.id = servers[serv_node.id].get_parent_id();
	}

	return route;
}

void Router::read_servers(int n_movies)
{
	cout << "Input the number of servers of the system: ";
	int n = read_int() - 1;
	servers = vector<Server>(n);

	for(int i = 0; i < n; ++i)
	{
		cout << "Input the id of the server #" << i << ": ";
		int id = readint() - 1;

		servers[id].read_server(id, n_movies);

		if(servers[id].has_children())
		{
			int s1, s2;
			servers[id].children(s1, s2);

			servers[s1].set_parent_id(id);

			if(s2 != -1)
				servers[s2].set_parent_id(id);
		}
	}

	cout << "Input the id of the main server: ";
	main_server_id = readint();
}
