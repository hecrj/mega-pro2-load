#include "Network.hpp"
#include "utils.PRO2"
#include <queue>

Network::Network()
{}

Route Network::get_route(int resource_id, int resource_size, int cur_time) const
{
	Route route;
	Route temp;
	find_route(resource_id, resource_size, cur_time, nodes, route, temp);

	return route;
}

void Network::find_route(int mv_id, int mv_size, int c_time, const Tree &node,
	Route &route, Route &temp) const
{
	if(temp.get_depth() >= route.get_depth())
		return;
	
	int node_id = node.get_root();

	if(not servers[node_id].is_busy(c_time) and servers[node_id].has_movie(mv_id))
	{
		temp.add_node(node_id, servers[node_id].get_speed());

		if(temp.get_travel_time() >= mv_size)
		{
			route = temp;
			return;
		}
	}

	if(node.has_children())
	{
		find_route(mv_id, mv_size, c_time, temp, nodes.get_left());
		
		if(node.has_right())
		{
			find_route(mv_id, mv_size, c_time, route, nodes.get_right());

			if(left.get_travel_time() >= route.get_travel_time())
				node = node.get_left();
			else
				node = node.get_right();
		}
		else
			node = node.get_left();

	}
}

Route Network::get_route(int resource_id, int resource_size, int cur_time) const
{
	Node best_server;
	best_server.id = -1;
	best_server.speed = 0;

	Node serv;
	serv.id = main_server_id;
	serv.speed = 0;

	queue<Node> qservs;
	qservs.push(serv);

	bool found = false;

	while(not qservs.empty() and not found)
	{
		serv = qservs.front();
		qservs.pop();

		cout << "Checking server: " << serv.id+1 << endl;

		if(not servers[serv.id].is_busy(cur_time) and servers[serv.id].has_movie(resource_id))
		{
			serv.speed += servers[serv.id].get_speed();

			cout << "The server is free and has the movie." << endl;
			cout << "Movie size: " << resource_size << endl;
			cout << "Node speed: " << serv.speed << endl;

			if(resource_size <= serv.speed)
				found = true;

			if(serv.speed > best_server.speed)
				best_server = serv;
		}

		if(not found and servers[serv.id].has_children())
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

	return build_route(best_server.id);
}

void Network::set_busy_nodes(const Route &route, int request_id, int end_time)
{
	int node_id = route.get_next_node(-1);

	while(node_id != -1)
	{
		servers[node_id].set_busy(request_id, end_time);
		node_id = route.get_next_node(node_id);
	}
}

void Network::update_node(int node_id)
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

void Network::write_busy_nodes(int cur_time) const
{
	int n_servers = servers.size();

	for(int i = 0; i < n_servers; ++i)
		if(servers[i].is_busy(cur_time))
			cout << "Server #" << i << "is busy.";
		// ...
}
