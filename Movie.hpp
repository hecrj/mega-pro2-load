/**
 * @file Movie.hpp
 * @brief Movie specification
 */
#ifndef MOVIE_HPP
#define MOVIE_HPP

#include "utils.PRO2" //
#include <list> //

/**
 * A Movie consists of a size and downloads.
 */
class Movie
{
    private:
        /**
         * Represents the size of the Movie.
         */
        int size;

        /**
         * Represents the time of every occasion that the movie has been
         * downloaded.
         */
        list<int> downloads;
        
    public:
        /**
         * Creates a new empty Movie with size 0.
         * \pre True
         * \post Returns a new empty Movie with size 0.
         */
        Movie();

        /**
         * Default destructor.
         */
        ~Movie();

        /**
         * Gets the size of the Movie.
         * \pre The Movie has a size.
         * \post The Movie size is returned.
         */
        int get_size() const;

        /**
         * Gets the number of downloads between **t1** and **t2**.
         * \pre 0 <= **t1** <= **t2**
         * \post The number of downloads is returned.
         */
        int how_many_downloads(int t1, int t2) const;

        /**
         * Adds a download record to the Movie at **dwl_time**.
         * \pre 0 <= **dwl_time**
         * \post The download record has been added.  
         */
        void add_download(int dwl_time);

        /**
         * Reads a Movie from the input stream.
         * \pre The size of the Movie is prepared in the input stream.
         * \post The Movie size read from input stream has been set.
         */
        void read_movie();

};

#endif