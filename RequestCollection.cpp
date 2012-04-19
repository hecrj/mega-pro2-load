#include "RequestCollection.hpp"

RequestCollection::RequestCollection()
{}

int RequestCollection::size() const
{
	return requests.size();
}

Request RequestCollection::get_request(int request_id) const
{
	return requests.top();
}

void RequestCollection::add_request(const Request &req)
{
	requests.push(req);
}