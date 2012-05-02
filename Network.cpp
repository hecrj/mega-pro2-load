#include "Network.hpp"
#include "utils.PRO2"
#include <queue>

Network::Network()
{}

Route Network::get_route(int resource_id, int resource_size, int cur_time) const
{
	Route route(servers.size());
	Route current(servers.size());

	// Just to make the recursive function look better
	Resource resource;
	resource.id = resource_id;
	resource.size = resource_size;
	resource.time = cur_time;

	find_route(route, current, resource, nodes);

	return route;
}

void Network::find_route(Route &route, Route &current, Resource &resource, Tree& node) const
{
	if(route.has_priority() and route.get_depth() <= current.get_depth())
		return;

	int node_id = node.get_root();

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

	Tree node_left;
	Tree node_right;

	node.children(node_left, node_right);

	if(not node_left.is_empty()) find_route(route, current, resource, node_left);
	if(not node_right.is_empty()) find_route(route, current, resource, node_right);

	current.delete_node(node_id);
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
	int n = readint();
	servers = vector<Server>(n);

	read_nodes(nodes);

	for(int i = 0; i < n; ++i)
		servers[id].read_server(n_movies);
}

void Network::read_nodes(Tree<int> &nodes)
{
	int id = readint();

	if(id == 0)
		return;

	Tree<int> t_left;
	Tree<int> t_right;

	read_nodes(t_left);
	read_nodes(t_right);

	nodes.plant(id, t_left, t_right);
}

void Network::write_busy_nodes(int cur_time) const
{
	int n_servers = servers.size();

	for(int i = 0; i < n_servers; ++i)
		if(servers[i].is_busy(cur_time))
			cout << "Server #" << i << "is busy.";
		// ...
}
