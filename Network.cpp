#include "Network.hpp"
#include "utils.PRO2"
#include <stack>
#include <queue>
#include <cmath>

Network::Network()
{}

void handle_request(Request &req)
{
	Route route = get_route(req);
	req.set_route(route);

	int time_end = req.get_time_start() + route.get_time();
	req.set_time_end(time_end);

	set_busy_servers(req);
	rcol.add_request(req);
}

Route Network::get_route(const Request &req) const
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

		if(not servers[serv.id].is_busy() and servers[serv.id].has_movie(req.get_movie_id()))
		{
			serv.speed += servers[serv.id].get_speed();

			cout << "The server is free and has the movie." << endl;
			cout << "Movie size: " << movies[req.get_movie_id()] << endl;
			cout << "Node speed: " << serv.speed << endl;

			if(movies[req.get_movie_id()] <= serv.speed)
				return build_route(req, serv);

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

	return build_route(req, best_server);
}

Route Network::build_route(const Request &req, Node &serv_node) const
{
	int time = int( ceil( double(movies[req.get_movie_id()]) / double(serv_node.speed) ) );
	
	Route route(time);

	while(serv_node.id != -1)
	{
		route.add_server(serv_node.id);
		serv_node.id = servers[serv_node.id].get_parent_id();
	}

	return route;
}

void Network::set_busy_servers(const Request &req)
{
	stack<int> req_servers = req.get_route().get_servers();

	while(not req_servers.empty())
	{
		servers[req_servers.top()].set_request(req.get_id());
		req_servers.pop();
	}
}

void Network::read_network()
{
	read_movies();
	read_servers();
}

void Network::read_movies()
{
	cout << "Input the number of movies in the network: ";
	int n = readint();

	movies = vector<int>(n);

	for(int i = 0; i < n; ++i)
	{
		cout << "Input the size of the movie #" << i+1 << ": ";
		movies[i] = readint();
	}

}

void Network::read_servers()
{
	cout << "Input the number of servers of the system: ";
	int n = readint();
	servers = vector<Server>(n);

	for(int i = 0; i < n; ++i)
	{
		cout << "Input the id of the server #" << i+1 << ": ";
		int id = readint() - 1;

		servers[id].read_server(id, movies.size());

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
