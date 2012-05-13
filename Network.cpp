#include "Network.hpp"
#include "utils.PRO2"
#include <cmath>

Network::Network()
{}

int Network::get_download_time(int request_id, int resource_id, int resource_size, int cur_time)
{
	// just to make the recursive function look better
	Resource resource;
	resource.id = resource_id;
	resource.size = resource_size;
	resource.time = cur_time;

	Route route;
	Route current;

	route.depth = current.depth = route.speed = current.speed = 0;
	route.priority = current.priority = false;

	find_route(resource, main_node, route, current);

	int duration = 0;

	if(not route.nodes.empty())
	{
		duration = int(ceil( double(resource.size) / double(route.speed) ));
		set_busy_nodes(route.nodes, request_id, cur_time+duration);
	}

	return duration;
}

void Network::find_route(const Resource &resource, int node_id, Route &route, Route &current) const
{
	if(route.priority and route.depth <= (current.depth - 1))
		return;

	int speed = 0;

	if(not servers[node_id].is_busy_at(resource.time) and servers[node_id].has_movie(resource.id))
	{
		speed = servers[node_id].get_speed();
		
		current.speed += speed;
		current.nodes.push(node_id);

		if(current.speed >= resource.size)
		{
			current.priority = true;
			route = current;
		}
		else if(current.speed > route.speed)
			route = current;
	}
	
	current.depth += 1;
	
	if(nodes[node_id].left != -1) find_route(resource, nodes[node_id].left, route, current);
	if(nodes[node_id].right != -1) find_route(resource, nodes[node_id].right, route, current);

	if(speed > 0)
	{
		current.nodes.pop();
		current.speed -= speed;
	}
	current.depth -= 1;
}

void Network::set_busy_nodes(stack<int> &nodes, int request_id, int end_time)
{
	while(not nodes.empty())
	{
		servers[nodes.top()].set_busy(request_id, end_time);
		
		nodes.pop();
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

void Network::write_request_nodes(int request_id) const
{
	bool space = false;

	for(int i = 0; i < servers.size(); ++i)
	{
		if(servers[i].get_request_id() == request_id)
		{
			if(space) cout << ' ';
			
			cout << i+1;
			space = true;
		}
	}

	cout << endl;
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
