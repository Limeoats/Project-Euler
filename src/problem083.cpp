/*
 * Problem 83: Path sum: four ways
 * By: Mark Guerra
 * 5/5/2017
*/

#include "main.h"
#include "utils.h"
#include <fstream>

/*
 * I used Dijkstra's algorithm to solve this problem. See the comments
 * throughout the [dijkstra] method for more information. The value
 * returned is the distance to the bottom-right of the matrix,
 * which is the answer. Return it and print.
 */

struct Node {
public:
    int Distance;
    bool Visited = false;
    std::pair<int, int> Position;
    
    Node() { Distance = std::numeric_limits<int>::max(); }
    Node(int distance) { Distance = distance; }
};

int Problem083::dijkstra() {
    std::vector<std::vector<Node>> nodes(this->_original.size());
    for (int i = 0; i < this->_original.size(); ++i) {
        nodes[i] = std::vector<Node>(this->_original.size());
    }
    for (int i = 0; i < this->_original.size(); ++i) {
        for (int j = 0; j < this->_original.size(); ++j) {
            nodes[i][j].Position = std::make_pair(i, j);
        }
    }
    std::vector<std::vector<Node>> unvisited;
    unvisited.assign(nodes.begin(), nodes.end());
    
    //Store and keep track of current node position and a pointer to the current node
    std::pair<int, int> uvp = std::make_pair(0, 0);
    Node* cn = &nodes[0][0];
    
    //Set the starting node's distance to 0
    nodes[0][0].Distance = 0;
    
    while (true) {
        //Get the neighbors of the current node and calculate their tentative distances
        int td = 0;
        //Look to the left
        if (cn->Position.second > 0) {
            td = cn->Distance + this->_original[cn->Position.first][cn->Position.second - 1];
            nodes[cn->Position.first][cn->Position.second - 1].Distance =
                    std::min(td, nodes[cn->Position.first][cn->Position.second - 1].Distance);
        }
        //Look to the right
        if (cn->Position.second < this->_original.size() - 1) {
            td = cn->Distance + this->_original[cn->Position.first][cn->Position.second + 1];
            nodes[cn->Position.first][cn->Position.second + 1].Distance =
                    std::min(td, nodes[cn->Position.first][cn->Position.second + 1].Distance);
        }
        //Look up
        if (cn->Position.first > 0) {
            td = cn->Distance + this->_original[cn->Position.first - 1][cn->Position.second];
            nodes[cn->Position.first - 1][cn->Position.second].Distance =
                    std::min(td, nodes[cn->Position.first - 1][cn->Position.second].Distance);
        }
        //Look down
        if (cn->Position.first < this->_original.size() - 1) {
            td = cn->Distance + this->_original[cn->Position.first + 1][cn->Position.second];
            nodes[cn->Position.first + 1][cn->Position.second].Distance =
                    std::min(td, nodes[cn->Position.first + 1][cn->Position.second].Distance);
        }
        cn->Visited = true;
        unvisited[uvp.first].erase(unvisited[uvp.first].begin() + uvp.second);
        
        //Check if algorithm is finished by checking if destination node was visited
        if (nodes[this->_original.size() - 1][this->_original.size() - 1].Visited) {
            break;
        }
        int ltd = std::numeric_limits<int>::max();
        for (int i = 0; i < unvisited.size(); ++i) {
            for (int j = 0; j < unvisited[i].size(); ++j) {
                auto x = unvisited[i][j].Position.first;
                auto y = unvisited[i][j].Position.second;
                if (nodes[x][y].Distance < ltd) {
                    ltd = nodes[x][y].Distance;
                    cn = &nodes[x][y];
                    cn->Position = std::make_pair(x, y);
                    uvp = std::make_pair(i, j);
                }
            }
        }
        if (ltd == std::numeric_limits<int>::max()) {
            break;
        }
    }
    
    //Add starting position value to the distance at the destination node
    nodes[this->_original.size() - 1][this->_original.size() - 1].Distance += this->_original[0][0];
    return nodes[this->_original.size() - 1][this->_original.size() - 1].Distance;
}

std::string Problem083::get_answer() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream in("data/problem83_data.txt");
    while (!in.eof()) {
        getline(in, line);
        lines.push_back(line);
    }
    in.close();
    this->_original = std::vector<std::vector<int>>(lines.size());
    for (auto i = 0; i < lines.size(); ++i) {
        auto t = utils::split(lines[i], ',');
        std::vector<int> c;
        for (auto x : t) {
            c.push_back(atoi(x.c_str()));
        }
        this->_original[i] = c;
    }
    return std::to_string(dijkstra());
}
