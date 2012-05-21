/**
 * @file Network.hpp
 * @brief Network specification.
 */
#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "Server.hpp"
#include "Arbre.hpp" //
#include "utils.PRO2" //
#include <vector>  //
#include <list> //

/**
 * A Network consists of a set of nodes connected with each other in a binary
 * tree structure.
 */
class Network
{
    private:
        /**
         * Vector of servers where the position is the id of the server - 1.
         */
        vector<Server> servers;

        /**
         * Binary tree of server connections. The nodes in the tree represent
         * the position in the servers vector.
         */
        Arbre<int> nodes;

        /**
         * Represents a resource requested to the Network. 
         */
        struct Resource
        {
            /**
             * Represents the Resource identifier.
             */
            int id;

            /**
             * Represents the Resource size.
             */
            int size;

            /**
             * Represents the Resource request time.
             */
            int time;
        };

        /**
         * Represents a Route of nodes, with its speed and depth.
         */
        struct Route {
            /**
             * Represents the selected nodes of the Route.
             */
            list<int> nodes;

            /**
             * Represents the speed of the Route.
             */
            int speed;

            /**
             * Represents the depth of the Route.
             */
            int depth;
        };

        /**
         * Finds the **Route** that can serve the **Resource** in 1 ut, following the first criterion.
         * It uses **speed** and **depth** as possible **route** values, if the speed isn't enough then
         * uses them as accumulated values to find the best Route in A.
         * \pre
         *       - a = A
         *       - resource.id is a valid movie identifier
         *       - resource.time >= 0
         *       - resource.size > 0
         *       - routes.nodes are empty
         *       - speed >= 0
         *       - depth >= 0
         * \post
         *       - If found in A, the best Route, following the first criterion, is set in **route** (speed,
         *       depth and selected nodes).
         *       - If not found in A, an empty Route is set in **route** (speed = 0, depth = 0, nodes empty).
         *       - a = A
         */
        void route_instant_mindepth(Arbre<int> &a, const Resource &resource, Route &route, int speed, int depth);

        /**
         * Finds the **Route** that can serve the **Resource** in the shortest time possible, following the
         * second criterion.
         * \pre  
         *       - a = A
         *       - resource.id is a valid movie identifier
         *       - resource.time >= 0
         *       - resource.size > 0
         *       - route.nodes are empty
         * \post
         *       - If found in A, the fastest Route, following the second criterion, is set in **route** (speed,
         *       - depth and selected nodes).
         *       - If not found in A, an empty Route is set in **route** (speed = 0, depth = 0, nodes empty).
         *       - a = A
         */
        void route_maxspeed_mindepth(Arbre<int> &a, const Resource &resource, Route &route);

        /**
         * Sets the **nodes** as busy (serving **request_id**) until **end_time**.
         * \pre **end_time** >= 0
         * \post The **nodes** are busy (serving **request_id**) until **end_time**.
         */
        void set_busy_nodes(list<int> &nodes, int request_id, int end_time);

        /**
         * Private function that reads recursively a binary tree structure of nodes, using **mark**
         * as non-children indicator.
         * \pre The input stream is prepared with a binary tree sequence in preorder.
         * \post **a** is a binary tree that represents the data read from the input stream.
         */
        void read_tree(Arbre<int> &a, int mark);

    public:
        /**
         * Creates a new empty Network.
         * \pre True
         * \post Returns a new empty Network.
         */
        Network();

        /**
        * Default destructor.
        */
        ~Network();

        /**
         * Processes a download if possible and returns its duration.
         * This function tries to find the best set of servers to serve the download.
         * If the download can be served, then the selected servers are set as busy until
         * the download is finished.
         * \pre
         *      - **resource_id** is a valid movie id
         *      - **resource_size** >= 0
         *      - **cur_time** >= 0
         * \post
         *       - If the download can be served, duration is the time that will take this download
         *       to finish and the selected servers are set as busy until the download is finished.
         *       - If the download can not be served, duration equals to 0 and no servers are set as
         *       busy.
         */
        void process_download(int request_id, int resource_id, int resource_size, int cur_time, int &duration);

        /**
         * Edits the node of the Network with id **node_id**.
         * \pre Network::is_a_valid_node(node_id)
         * \post The node with id **node_id** has been edited.
         */
        void edit_node(int node_id);

        /**
         * Reads a Network given a number of resources **n_resources**.
         * \pre Not determined yet.
         * \post The Network has been read from the input stream.
         */
        void read_network(int n_resources);

        /**
         * Writes the nodes ids which served **request_id** as last request.
         * \pre The output stream is ready.
         * \post The nodes ids that served **request_id** as last request are printed
         *       in the output stream.
         */
        void write_request_nodes(int request_id) const;

        /**
         * Prints in the output stream the nodes that are busy at
         * **cur_time**.
         * \pre **cur_time** >= 0
         * \post Information about the busy nodes at **cur_time** has
         *       been printed in the output stream:
         *       - The node id
         *       - The request served
         *       - The time left until the node is free
         */
        void write_busy_nodes(int cur_time) const;
};

#endif