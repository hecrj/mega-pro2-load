#include "Route.hpp"

Route::Route()
{
	speed = 0;
	empty = true;
}

Route::Route(int n_nodes)
{
	nodes = vector<bool>(n_nodes, false);
	speed = 0;
	empty = true;
}

bool Route::is_empty()
{
	return empty;
}

int Route::get_next_node(int cur_node) const
{
	int size = nodes.size();

	for(int i = cur_node + 1; i < size; ++i)
		if(nodes[i])
			return i;

	return -1;
}

int Route::get_speed()
{
	return speed;
}

void Route::add_node(int node_id, int node_speed)
{
	nodes[node_id] = true;
	speed += node_speed;
	empty = false;
}

void Route::write_route() const
{
	int size = nodes.size();

	for(int i = 0; i < size; ++i)
	{
		if(nodes[i])
			cout << " " << i;
	}

	cout << endl;
}