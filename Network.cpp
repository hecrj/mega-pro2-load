#include "Network.hpp"
#include "utils.PRO2"
#include <queue>

Network::Network()
{}

int Network::get_best_node(int resource_id, int resource_size, int &node_speed) const
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

		if(not servers[serv.id].is_busy() and servers[serv.id].has_movie(resource_id))
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

	selection_speed = best_server.speed;
	select_from(best_server.id, resource_id);
}

bool Network::is_a_valid_node(int node_id) const
{
	return node_id >= 0;
}

void Network::select_from(int node_id, int resource_id)
{
	selection = list<int>();
	selection.push_back(node_id);

	node_id = servers[node_id].get_parent_id();

	while(node_id >= 0)
	{
		if(servers[node_id].has_movie(resource_id))
			selection.push_back(node_id);

		node_id = servers[node_id].get_parent_id();
	}
}

void Network::set_selection_busy_until(int time, int request_id)
{
	list<int>::iterator it = selection.begin();

	while(it != selection.end())
	{
		servers[*it].set_busy_until(time);
		it++;
	}
}

void Network::print_selection() const
{
	list<int>::iterator it = selection.begin();

	while(it != selection.end())
	{
		cout << " " << *it;
		it++;
	}
}

void Network::set_free_nodes(int node_id, int request_id)
{
	// ...
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

void Network::write_busy_nodes() const
{

}
