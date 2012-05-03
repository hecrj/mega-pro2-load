#include "Network.hpp"
#include "utils.PRO2"
#include <queue>

Network::Network()
{}

Route Network::get_route(int resource_id, int resource_size, int cur_time) const
{
	Route route(servers.size());
	Route current(servers.size());

	// just to make the recursive function look better
	Resource resource;
	resource.id = resource_id;
	resource.size = resource_size;
	resource.time = cur_time;

	find_route(route, current, resource, main_node);

	return route;
}

void Network::find_route(Route &route, Route &current, Resource &resource, int node_id) const
{
	if(route.has_priority() and route.get_depth() <= current.get_depth())
		return;

	if(not servers[node_id].is_busy_at(resource.time) and servers[node_id].has_movie(resource.id))
	{
		current.add_node(node_id, servers[node_id].get_speed());

		if(current.get_speed() >= resource.size)
		{
			current.prioritize();
			route = current;

			return; // to avoid some instructions and unnecessary recursive calls
		}

		if(current.get_speed() > route.get_speed())
			route = current;
	}
	else
		current.add_node(node_id, 0);

	if(nodes[node_id].left != -1) find_route(route, current, resource, nodes[node_id].left);
	if(nodes[node_id].right != -1) find_route(route, current, resource, nodes[node_id].right);

	current.delete_node(node_id);
}

void Network::set_busy_nodes(const Route &route, int request_id, int end_time)
{
	int node_id = -1;
	bool found;

	route.get_next_node(node_id, found);

	while(found)
	{
		servers[node_id].set_busy(request_id, end_time);
		
		route.get_next_node(node_id, found);
	}
}

void Network::edit_node(int node_id)
{
	int n_movies = readint();

	for(int i = 0; i < n_movies; ++i)
		servers[node_id].enable_movie(readint() - 1);

	n_movies = readint();

	for(int i = 0; i < n_movies; ++i)
		servers[node_id].disable_movie(readint() - 1);
}

void Network::read_network(int n_resources)
{
	int n = readint();
	servers = vector<Server>(n);
	nodes = vector<Node>(n);

	read_nodes(main_node);

	for(int i = 0; i < n; ++i)
		servers[i].read_server(n_resources);
}

void Network::read_nodes(int &node_id)
{
	node_id = readint() - 1;

	if(node_id == -1)
		return;

	int n_left;
	int n_right;

	read_nodes(n_left);
	read_nodes(n_right);

	nodes[node_id].left = n_left;
	nodes[node_id].right = n_right;
}

void Network::write_busy_nodes(int cur_time) const
{
	int n_servers = servers.size();

	for(int i = 0; i < n_servers; ++i)
	{
		if(servers[i].is_busy_at(cur_time))
		{
			cout << i+1 << ' ' << servers[i].get_request_id() << ' ';
			cout << servers[i].get_time_left(cur_time) << endl;
		}
	}
}
