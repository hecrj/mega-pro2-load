#include "Route.hpp"

Route::Route()
{
	speed = 0;
	depth = 0;
	prioritized = false;
}

Route::Route(int n_nodes)
{
	nodes = vector<bool>(n_nodes, false);
	speed = 0;
	depth = 0;
	prioritized = false;
}

bool Route::is_empty() const
{
	return (speed <= 0);
}

bool Route::has_priority() const
{
	return prioritized;
}

void Route::get_next_node(int &cur_node, bool &found) const
{
	int size = nodes.size();
	found = false;

	while(cur_node < size and not found)
	{
		if(nodes[cur_node])
			found = true;

		++cur_node;
	}
}

int Route::get_speed() const
{
	return speed;
}

int Route::get_depth() const
{
	return depth;
}

void Route::add_node(int node_id, int node_speed)
{
	if(node_speed > 0)
	{
		nodes[node_id] = true;
		speed += node_speed;
	}

	depth += 1;
}

void Route::delete_node(int node_id)
{
	nodes[node_id] = false;
	depth -= 1;
}

void Route::prioritize()
{
	prioritized = true;
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