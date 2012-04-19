#include "Network.hpp"
#include "utils.PRO2"
#include <stack>
#include <queue>
#include <cmath>

Network::Network()
{}

int Network::size() const
{
	return servers.size();
}

Route Network::get_route(const Movie &mov) const
{
	queue<Node> qservs;

	Node main_server;
	main_server.id = main_server_id;
	main_server.speed = 0;
	qservs.push(main_server);

	Node best_server;
	best_server.id = -1;
	best_server.speed = 0;

	while(not qservs.empty())
	{
		Node serv = qservs.front();
		qservs.pop();

		cout << "Checking server: " << serv.id+1 << endl;

		if(not servers[serv.id].is_busy() and servers[serv.id].has_movie(mov.get_id()))
		{
			serv.speed += servers[serv.id].get_speed();

			cout << "The server is free and has the movie." << endl;
			cout << "Movie size: " << mov.get_size() << endl;
			cout << "Node speed: " << serv.speed << endl;

			if(mov.get_size() <= serv.speed)
				return build_route(mov, serv);

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

			if(s2 != -1)
			{
				serv_child.id = s2;
				qservs.push(serv_child);
			}
		}

	}

	return build_route(mov, best_server);
}

Route Network::build_route(const Movie &mov, Node &serv_node) const
{
	int time = int( ceil( double(mov.get_size()) / double(serv_node.speed) ) );

	Route route(time);

	while(serv_node.id != -1)
	{
		route.add_server(serv_node.id);
		serv_node.id = servers[serv_node.id].get_parent_id();
	}

	return route;
}

void Network::occupy_servers(const Route &route, int req_id)
{
	// ...
}

void Network::free_servers(const Route &route)
{
	// ...
}

void Network::update_server(int server_id)
{
	// ...
}

void Network::read_network(int n_movies)
{
	cout << "Input the number of servers of the system: ";
	int n = readint();
	servers = vector<Server>(n);

	for(int i = 0; i < n; ++i)
	{
		cout << "Input the id of the server #" << i+1 << ": ";
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
	main_server_id = readint() - 1;
}
