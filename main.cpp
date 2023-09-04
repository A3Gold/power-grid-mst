#include <iostream>
#include "graph.hpp"
#include "illegalexception.hpp"
#include <fstream>
#include <iostream>

int main(){
    std::string cmd;
    int a;
    int b;
    int w;
    graph myGraph;
    jump:
    while(std::cin>>cmd) {
        if(cmd == "LOAD") {
            std::string filename;
            std::cin>>filename;
            std::ifstream fin(filename.c_str());
            int size;
            fin>>size;
            while(fin>>a) {
                fin>>b;
                fin>>w;
                myGraph.insert(a,b,w, true);
            }
            std::cout<<"success"<<std::endl;
        }
        else if(cmd == "INSERT") {
            std::cin>>a;
            std::cin>>b;
            std::cin>>w;
            if(a <= 0 || a > 50000 || b <= 0 || b > 50000 || w <= 0) {
                try {
                    throw illegal_exception(); 
                    }
                catch(illegal_exception it) {
                    std::cout<<it.what()<<std::endl;
                    goto jump;
                }
            }
            myGraph.insert(a, b, w, false);
        }
        else if(cmd == "PRINT") {
            std::cin>>a;
            if(a <= 0 || a > 50000) {
                try {
                    throw illegal_exception(); 
                    }
                catch(illegal_exception it) {
                    std::cout<<it.what()<<std::endl;
                    goto jump;
                }
            }
            myGraph.print(a);
        }
        else if(cmd == "DELETE") {
            std::cin>>a;
            if(a <= 0 || a > 50000) {
                try {
                    throw illegal_exception(); 
                    }
                catch(illegal_exception it) {
                    std::cout<<it.what()<<std::endl;
                    goto jump;
                }
            }
            myGraph.deleteVertex(a);
        }
        else if(cmd == "MST") {
            myGraph.MST();
        }
        else if(cmd == "COST") {
            myGraph.MST(true);
        }
        else if(cmd == "END") {
            return 0;
        }
    }
}