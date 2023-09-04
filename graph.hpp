#include <iostream>
#include <vector>
#include "vertex.hpp"
#include "edge.hpp"
#include "minheap.hpp"

class graph {
    public:
        graph(){
            for(int i{0}; i<50001; i++){
                wGraph[i].push_back(vertex()); // set each index to default constructor (sentinel)
            }
        }
        void insert(int a, int b, int w, bool outputOff = false){
                for(int i{0}; i<wGraph[a].size(); i++){
                    if(wGraph[a][i].getVertexNum() == b) { // edge from a to b exists
                        if(outputOff == false) std::cout<<"failure"<<std::endl;
                        return;
                    }
                }
                if((wGraph[a].front().getVertexNum()) != 0){
                    wGraph[a].push_back(vertex(b, w)); // insert the edge from a to b with weight w
                }
                else {
                    wGraph[a][0].setVertexNum(b);
                    wGraph[a][0].setWeight(w);
                    vertexList.push_back(vertex(a, 0));
                }
                if((wGraph[b].front().getVertexNum()) != 0){
                    wGraph[b].push_back(vertex(a, w)); // insert the edge from b to a with weight w
                }
                else {
                    wGraph[b][0].setVertexNum(a);
                    wGraph[b][0].setWeight(w);
                    vertexList.push_back(vertex(b, 0));
                }
                if(outputOff == false) std::cout<<"success"<<std::endl;
                return;
        }
        void print(int a){
                if((wGraph[a].front().getVertexNum()) == 0){
                    std::cout<<"failure"<<std::endl;
                    return;
                }
                for(int i{0}; i<wGraph[a].size(); i++){
                    std::cout<<wGraph[a][i].getVertexNum()<<" ";
                }
                std::cout<<std::endl;
                return;
        }
        void deleteVertex(int a){
            if((wGraph[a].front().getVertexNum()) == 0){
                    std::cout<<"failure"<<std::endl;
                    return;
            }
            for(int i{0}; i<wGraph[a].size(); i++){
                int checkIndex = wGraph[a][i].getVertexNum();
                for(int j{0}; j<wGraph[checkIndex].size(); j++){
                    if(wGraph[checkIndex][j].getVertexNum() == a){
                        wGraph[checkIndex].erase(wGraph[checkIndex].begin() + j);
                    }
                }
            }
            for(int i{0}; i<vertexList.size(); i++){
                if((vertexList[i].getVertexNum()) == a) vertexList.erase(vertexList.begin() + i);
            }
            if(wGraph[a].size() > 0){
                int j = wGraph[a].size();
                for(int i{0}; i<j-1; i++){
                    //std::cout<<wGraph[a].back().getVertexNum()<<std::endl;
                    wGraph[a].pop_back();
                }
            }
            wGraph[a][0].setVertexNum(0);
            wGraph[a][0].setWeight(0);
            std::cout<<"success"<<std::endl;
            return;
        };

       /**void printEdgeList() { // for testing
            for(int i{0}; i<edgeList.size(); i++) {
                std::cout<<edgeList[i].geta()<<" "<<edgeList[i].getb()<<" "<<edgeList[i].getWeight()<<std::endl;
            }
            for(int i{0}; i<vertexList.size(); i++) {
                std::cout<<vertexList[i].getVertexNum()<<std::endl;
            }
            std::cout<<std::endl;
        } */
        
        void MST(bool displayCost = false) {
            if(vertexList.size() == 0) {
                if(displayCost) std::cout<<"cost is 0"<<std::endl;
                if(!displayCost) std::cout<<"failure"<<std::endl;
                return;
            }
            int cost{0};
            bool inMST[50001]{false};
            minHeap myMinHeap = minHeap(); // create heap
            std::vector<edge> MST;
            int firstVertex = vertexList[0].getVertexNum(); // select random vertex
            for(int i{0}; i<wGraph[firstVertex].size(); i++) { // push all of its edges to P-que
                myMinHeap.insert(edge(firstVertex, wGraph[firstVertex][i].getVertexNum(), wGraph[firstVertex][i].getWeight()));
            }
            int numTreeVertices{1};
            while(numTreeVertices < vertexList.size()){
                edge addEdge = myMinHeap.getMin();
                while((inMST[addEdge.geta()] == true) && (inMST[addEdge.getb()] == true)){ 
                    addEdge = myMinHeap.getMin();
                }
                MST.push_back(addEdge);
                cost += addEdge.getWeight();
                inMST[addEdge.geta()] = true;
                inMST[addEdge.getb()] = true;
                int vertexAdded = addEdge.getb();
                numTreeVertices++;
                for(int i{0}; i<wGraph[vertexAdded].size(); i++) { 
                    if(!((inMST[vertexAdded] == true) && (inMST[wGraph[vertexAdded][i].getVertexNum()] == true))) {
                        myMinHeap.insert(edge(vertexAdded, wGraph[vertexAdded][i].getVertexNum(), wGraph[vertexAdded][i].getWeight()));
                    }
                }
            }
            if(!displayCost) {
                for(int i{0}; i<MST.size(); i++){
                    std::cout<<MST[i].geta()<<" "<<MST[i].getb()<<" "<<MST[i].getWeight()<<" ";
                }
            }
            if(displayCost) {
                std::cout<<"cost is "<<cost;
            }
            std::cout<<std::endl;
        } 

    private:
        std::vector<vertex> wGraph[50001];
        std::vector<vertex> vertexList;
};