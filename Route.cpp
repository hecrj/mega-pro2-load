#include "Route.hpp"
#include "utils.PRO2"

Route::Route()
{
	speed = 0;
	depth = 0;
	prioritized = false;
}

Route::Route(int n_nodes)
{
	nodes = vector<int>(n_nodes, 0);
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
	found = false;

	int size = nodes.size();

	while(cur_node < size and not found)
	{
		++cur_node;

		if(nodes[cur_node] != 0)
			found = true;
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
		nodes[node_id] = node_speed;
		speed += node_speed;
	}

	depth += 1;
}

void Route::delete_node(int node_id)
{
	speed -= nodes[node_id];
	nodes[node_id] = 0;
	depth -= 1;
}

void Route::prioritize()
{
	prioritized = true;
}

void Route::write_route() const
{
	if(is_empty()) return;

	int size = nodes.size();

	bool space = false;

	for(int i = 0; i < size; ++i)
	{
		if(nodes[i] != 0)
		{
			if(space) cout << ' ';
			
			cout << i+1;
			space = true;
		}
	}

	cout << endl;
}