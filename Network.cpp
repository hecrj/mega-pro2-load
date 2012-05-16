#include "Network.hpp"
#include "utils.PRO2"
#include <cmath>

Network::Network()
{}

void Network::process_download(int request_id, int resource_id, int resource_size, int cur_time, int &duration)
{
	// just to make the recursive function look better
	Resource resource;
	resource.id = resource_id;
	resource.size = resource_size;
	resource.time = cur_time;

	Route route;

	route_instant_mindepth(nodes, resource, route, 0, 0);

	if(route.nodes.empty())
		route_maxspeed_mindepth(nodes, resource, route);

	duration = 0;

	if(not route.nodes.empty())
	{
		duration = int(ceil( double(resource.size) / double(route.speed) ));
		set_busy_nodes(route.nodes, request_id, cur_time+duration);
	}
}

void Network::route_instant_mindepth(Arbre<int> &a, const Resource &resource, Route &route, int speed, int depth)
{
	route.depth = depth;

	if(speed >= resource.size) route.speed = speed;
	else if(a.es_buit()) route.speed = 0;
	else
	{
		int node_id = a.arrel();

		bool available = (not servers[node_id].is_busy_at(resource.time) and servers[node_id].has_movie(resource.id));
		
		if(available) speed += servers[node_id].get_speed();

		Arbre<int> a1, a2;
		a.fills(a1, a2);

		Route left, right;

		route_instant_mindepth(a1, resource, left, speed, depth+1);
		route_instant_mindepth(a2, resource, right, speed, depth+1);

		bool best_left;

		if(left.speed > 0 and right.speed > 0) best_left = (left.depth <= right.depth);
		else best_left = (left.speed > 0);

		if(best_left)
		{
			route.speed = left.speed;
			route.depth = left.depth;
			route.nodes.splice(route.nodes.begin(), left.nodes);
		}
		else
		{
			route.speed = right.speed;
			route.depth = right.depth;
			route.nodes.splice(route.nodes.begin(), right.nodes);
		}

		if(route.speed > 0 and available)
			route.nodes.push_front(node_id);

		a.plantar(node_id, a1, a2);
	}
}

void Network::route_maxspeed_mindepth(Arbre<int> &a, const Resource &resource, Route &route)
{
	if(a.es_buit())
	{
		route.speed = 0;
		route.depth = 0;
	}
	else
	{
		int node_id = a.arrel();

		Arbre<int> a1, a2;
		a.fills(a1, a2);

		Route left, right;

		route_maxspeed_mindepth(a1, resource, left);
		route_maxspeed_mindepth(a2, resource, right);

		bool best_left;

		if(left.speed == right.speed) best_left = (left.depth <= right.depth);
		else best_left = (left.speed > right.speed);

		if(best_left)
		{
			route.speed = left.speed;
			route.depth = left.depth;
			route.nodes.splice(route.nodes.begin(), left.nodes);
		}
		else
		{
			route.speed = right.speed;
			route.depth = right.depth;
			route.nodes.splice(route.nodes.begin(), right.nodes);
		}

		if(not servers[node_id].is_busy_at(resource.time) and servers[node_id].has_movie(resource.id))
		{
			route.speed += servers[node_id].get_speed();
			route.nodes.push_front(node_id);
		}

		if(route.speed > 0) route.depth += 1;

		a.plantar(node_id, a1, a2);
	}
}

void Network::set_busy_nodes(list<int> &nodes, int request_id, int end_time)
{
	while(not nodes.empty())
	{
		servers[nodes.front()].set_busy(request_id, end_time);
		
		nodes.pop_front();
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

	read_tree(nodes, 0);

	for(int i = 0; i < n; ++i)
		servers[i].read_server(n_resources);
}

void Network::read_tree(Arbre<int> &a, int marca)
{
	int node_id = readint();

	if(node_id != marca)
	{
		Arbre<int> a1, a2;
		read_tree(a1, marca);
		read_tree(a2, marca);

		a.plantar(node_id - 1, a1, a2);
	}
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
