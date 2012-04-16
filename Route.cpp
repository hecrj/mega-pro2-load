#include "Route.hpp"
#include "utils.PRO2"

Route::Route()
{}

Route::Route(int time)
{
	this->time = time;
}

int Route::get_time() const
{
	return time;
}

std::stack<int> Route::get_servers() const
{
	return servers;
}

bool Route::is_empty() const
{
	return servers.size() == 0;
}

void Route::add_server(int server_id)
{
	cout << "[Route] Added server: " << server_id+1 << endl;
	servers.push(server_id);
}