#include "System.hpp"

System::System()
{
	network.read_network();
}

void System::new_request()
{
	Request req;
	req.read_request(reqs.size());

	Route route = network.get_route(req);
	req.set_route(route);
	
	network.set_busy_servers(req);

	req.write_request();
	reqs.push(req);
}

void System::unfinished_requests()
{}

void System::most_downld_movie()
{

}