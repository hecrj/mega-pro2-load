#include "System.hpp"
#include "Movie.hpp"
#include "Route.hpp"

System::System()
{
	movs.read_movies();
	router.read_network();
}

void System::new_request()
{
	Request req;
	req.read_request();

	Movie req_movie = movs.get_movie(req.get_movie_id());
	Route route = router.get_route(req_movie);
	
	req.set_route(route);
	router.set_busy_servers(route, req.get_id(), );

	rcol.add_request(req);
	req.write_request();
}

void System::write_unfinished_requests()
{

}

void System::write_busy_servers()
{

}

void System::update_server()
{

}

void System::write_most_downloaded_movie()
{

}