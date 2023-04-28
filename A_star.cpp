#include<bits/stdc++.h>
using namespace std;

unordered_map<string,vector<pair<string,int>>> graph={
    {"S", {{"G", 10}, {"A", 1}}},
    {"A", {{"B", 2}, {"C", 1}}},
    {"B", {{"D", 3}}},
    {"C", {{"D", 3}, {"G", 4}}},
    {"D", {{"G", 2}}},
    {"G", {}}
};

unordered_map<string,int> heuristic={
    {"S", 5},
    {"A", 3},
    {"B", 4},
    {"C", 2},
    {"D", 6},
    {"G", 0}
};

int main(){
    string node="S";
    string goal="G";
    vector<string> visited={node};
    while(node!=goal){
        int fn=0;
        unordered_map<int,string> currentgraph;

        for(auto it:graph[node]){
            string currNode=it.first;
            int cost=it.second;

            fn=cost+heuristic[currNode];

            currentgraph[fn]=currNode;
        }

        int mn=INT_MAX;

        string nextNode;
        
        for(auto it:currentgraph){
            if(it.first<mn){
                mn=it.first;
                nextNode=it.second;
            }
        }

        node=nextNode;

        cout<<"Minimum:"<<mn<<"\n";
        cout<<"Selecting Node:"<<node<<"\n";
        visited.push_back(node);
    }

    cout << "Path is: ";
    for (int i = 0; i < visited.size(); i++) {
        cout << visited[i];
        if (i != visited.size() - 1) {
            cout << " -> ";
        }
    }
    return 0;
}