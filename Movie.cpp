/**
 * @file Movie.cpp
 * @brief Movie implementation
 */
#include "Movie.hpp"

Movie::Movie()
{
    size = 0;
}

Movie::~Movie()
{}

int Movie::get_size() const
{
    return size;
}

int Movie::how_many_downloads(int t1, int t2) const
{
    int num_downloads = 0;

    list<int>::const_iterator it = downloads.begin();

    // Inv: num_downloads = "downloads started from beginning
    //      of downloads until the previous position that points it"
    //      it is between downloads.begin() and downloads.end()
    while(it != downloads.end() and *it <= t2)
    {
        if(*it >= t1)
            ++num_downloads;

        ++it;
    }

    return num_downloads;
}

void Movie::add_download(int dwl_time)
{
    downloads.push_back(dwl_time);
}

void Movie::read_movie()
{
    size = readint();
}