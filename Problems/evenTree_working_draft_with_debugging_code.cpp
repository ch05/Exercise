#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class evenTree{
public:    
    //Zeroth index unused
    vector< vector<int> > graph;
    vector<int> connected;
    // int numNodes;

    //Constructor, size = number of nodes + 1
    evenTree(int size){
        graph = vector< vector<int> >(size);
        connected = vector<int>(size);
        for(int i = 1; i < connected.size(); i++){
            connected[i] = 0;
        }
    }

    //Return the size of the vector, not the number of nodes
    int size(){
        return connected.size();
    }

    void removeEdge(int a, int b){
        auto iterA = std::find(graph[a].begin(), graph[a].end(), b);
        auto iterB = std::find(graph[b].begin(), graph[b].end(), a);
        
        graph[a].erase(iterA);
        graph[b].erase(iterB);

        connected[a]++;    //Number of nodes that are (definitely) connected
        connected[b]++;
    }

    void checkLeaves(){
        for(int i = 1; i < graph.size(); i++){
            if(graph[i].size() == 1){
                int a = i;
                int b = graph[i][0];
                removeEdge(a, b); //In order to form a even forest the edge cannot be cut

            }
        }
    }

    bool existOddSubTree(){
        for(int i = 1; i < connected.size(); i++){
            if(connected[i] % 2 == 0){
                return true;
                break;
            }
        }
        return false;
    }

    //Return -1 if all components are connected, otherwise return the node number of the first node found with 
    //an (non-zero) even number of nodes connected
    int findOddSubTree(){
        for(int i = 1; i < connected.size(); i++){
            if(connected[i] != 0 && connected[i] % 2 == 0){
                return i;
                break;
            }
        }
        return 0;
    }
    
    int findOtherOddTree(){
            
    }
    
    bool isOddSubTree(int node){
        if(connected[node]%2 == 0){
            return true;
        }
        return false;
    }

    bool isPotentialOddSubTree(int node){
        if(connected[node]%2 == 0 || graph[node].size() != 0){
            return true;
        }    
        return false;
    }
    
    int countEdges(){
        int edges = 0;
        for(int i = 1; i < graph.size(); i++){
            edges += graph[i].size();
        }
        return edges/2;
    }
};

int main() {

    //Read the tree from input
    int V, E, a, b;
    cin >> V;
    cin >> E;

    evenTree tree(V+1);
    
    int remain = E;
    
    while(remain--){
        cin >> a;
        cin >> b;
        tree.graph[a].push_back(b);
        tree.graph[b].push_back(a);
    }
    
    //Make sure we don't remove the edges connecting leaves
    tree.checkLeaves();

    
    //Test
    std::cout << "Number of nodes - : " << tree.graph.size() - 1 << std::endl;
    for(int i = 1; i < tree.graph.size(); i++){
        std::cout << "node " << i << ": " << tree.graph[i].size() << std::endl;
    }
            
    for(int i = 1; i < tree.connected.size(); i++){
        std::cout << i << ": " << tree.connected[i] << std::endl;
    }
    //Test
    

    
    while(tree.existOddSubTree()){
        std::cout << "while loop\n";
        int currOddSubTree = tree.findOddSubTree(); //0 is returned if no Odd subtree exists
        std::cout << "current odd subtree is: " << currOddSubTree << std::endl;
        bool progress = false;
        int oddSubRoot;
        for(int i = 0; i < tree.graph[currOddSubTree].size(); i++){
                oddSubRoot = tree.graph[currOddSubTree][i];
                std::cout << "candidate: " << oddSubRoot << std::endl;
            if(tree.isOddSubTree(oddSubRoot)){
                                
                a = currOddSubTree;
                b = oddSubRoot;
                tree.removeEdge(a, b);
                //TEST
                std::cout << "if\n";
                std::cout << "odd subtree is: " << oddSubRoot << std::endl;                                   
                for(int i = 1; i < tree.connected.size(); i++){
                        std::cout << i << ": " << tree.connected[i] << std::endl;
                    }
                //TEST
                progress = true;
                break;
            }
        }
        for(int i = 0; i < tree.graph[currOddSubTree].size(); i++){
            if(tree.graph[currOddSubTree][i] != oddSubRoot)
        }
        else if(!progress){
            for(int i = 0; i < tree.graph[currOddSubTree].size(); i++){
                        int oddSubRoot = tree.graph[currOddSubTree][i];
                if(tree.isPotentialOddSubTree(oddSubRoot)){                  
                    a = currOddSubTree;
                    b = oddSubRoot;
                    tree.removeEdge(a, b);
                
                    //Test
                    std::cout << "else\n";
                    std::cout << "potential odd subtree is: " << oddSubRoot << std::endl;                                 
                    for(int i = 1; i < tree.connected.size(); i++){
                        std::cout << i << ": " << tree.connected[i] << std::endl;
                    }
                    //Test
                    break;
                }
            }    
        }
        
    }
    
    std::cout << "edge" << std::endl;
    int edge = tree.countEdges();
    std::cout << edge << std::endl;
    //Test
    /*
    std::cout << "connected nodes: " << std::endl;
    for(int i = 1; i < c; i++){
        std::cout << connected[i] << std::endl;
    }
    
        std::cout << "remaining edge\n";
    for(int i = 1; i < c; i++){
        std::cout << i << ": " << tree.graph[i].size() << std::endl;
    }
    */
    //Test
    /*
    int result = 0;
    for(int i = 1; i < tree.graph.size(); i++){
        if(tree.graph[i].size() != 0){
            result += tree.graph[i].size();
        }
    }
    result /= 2;    
    std::cout << result << std::endl;
    */
    return 0;
    }

    