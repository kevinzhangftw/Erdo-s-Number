#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>      /* printf */
#include <stdlib.h>     /* abs */
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <typeinfo>
using namespace std;

map<string,int> ErdosNumbers;
map<string,bool> Visited;

void printVec(vector<string> input){
    for (int i =0; i< input.size(); i++) {
        cout << input.at(i) << " - ";
    }
}

void printMap(map<string,int> input){
    for(auto elem : input){
        cout << elem.first << "\n";
    }
}

void ComputeErdosNumbers(map<string,vector<string> > adjList){
    //                adapted from https://codingstrife.wordpress.com/2013/07/11/solution-uva10044-pc110206-erdos-numbers/
    vector<string> oldList, newList;
    for (int i=0; i<adjList["Erdos, P."].size(); i++)
        ErdosNumbers[adjList["Erdos, P."][i]] = 1;
    newList = adjList["Erdos, P."];
    
    while(!newList.empty()){
        for (int i=0; i<newList.size(); i++)
            for (int j=0; j< adjList[newList[i]].size(); j++)
                if (ErdosNumbers[adjList[newList[i]][j]]  >  ErdosNumbers[newList[i]] + 1
                    || ErdosNumbers[adjList[newList[i]][j]] == -1){
                    ErdosNumbers[adjList[newList[i]][j]] = ErdosNumbers[newList[i]] + 1;
                    oldList.push_back(adjList[newList[i]][j]);
                }
        newList = oldList;
        oldList.clear();
    }
}

vector<string> split(string str, char delimiter){
    stringstream ss(str);
    vector<string> output;
    while (ss.good()) {
        string substr;
        getline(ss, substr, delimiter);
        output.push_back(substr);
    }
    return output;
}


vector < string > extract_name(string &line){
    vector < string > authors;
    vector<string> list = split(line, ',');
    //                adapted from https://codingstrife.wordpress.com/2013/07/11/solution-uva10044-pc110206-erdos-numbers/
    for (int j=0; j<list.size(); j=j+2) {
        string full_name = list[j]+ ',' +list[j+1];
        if(j == 0)
            full_name.erase(remove(full_name.begin(), full_name.end(), '\n'), full_name.end());
        if(full_name[0] == ' ')
            full_name.erase(full_name.begin());

        authors.push_back(full_name);
    }
    return authors;
}

void initializeErdosNumbers(vector<string> PaperAuthors){
    for (int i=0; i<PaperAuthors.size(); i++) {
        ErdosNumbers[PaperAuthors[i]] = -1;
    }
}

map<string,vector<string> > buildList(vector<string> authors, map<string,vector<string> > adjacenylist){
        for (int i =0; i<authors.size(); i++) {
        for (int j=0; j<authors.size(); j++) {
            if (authors[i] != authors[j]) {
//                adapted from https://codingstrife.wordpress.com/2013/07/11/solution-uva10044-pc110206-erdos-numbers/
                vector<string>::iterator it = find(adjacenylist[authors[i]].begin(),
                          adjacenylist[authors[i]].end(), authors[j]);
                if (it == adjacenylist[authors[i]].end()) {
                    //authors[j] not found, safe to add list
                    adjacenylist[authors[i]].push_back(authors[j]);
                }
            }
        }
    }
    return adjacenylist;
}

vector<string> loadQueries(int n){
    vector<string> queries;
    string authorName;
    for (int k=0; k<n; k++){
        getline(cin, authorName);
        queries.push_back(authorName);
    }
    return queries;
}

void printResults(int n, vector<string> queries){
    //adapted from https://codingstrife.wordpress.com/2013/07/11/solution-uva10044-pc110206-erdos-numbers/
    for (int j=0; j<n; j++){
        cout << queries[j] << " ";
        map<string,int>::iterator it = ErdosNumbers.find(extract_name(queries[j])[0]);
        if (it == ErdosNumbers.end() || it->second == -1) cout << "infinity";
        else cout << it->second;
        cout << endl;
    }
}

int main(){
    int scenarioNumber;
    cin >> scenarioNumber;
    for (int i=0; i<scenarioNumber; i++) {
        int p, n;
        cin >> p >> n;
        map<string,vector<string> > AdjacenyList;
        for (int j=0; j<p; j++) {
            vector<string> PaperAuthors;
            string line_part_1, line_part_2;
            getline(cin, line_part_1, ':');
            getline(cin, line_part_2);
            PaperAuthors = extract_name(line_part_1);
            initializeErdosNumbers(PaperAuthors);
            AdjacenyList = buildList(PaperAuthors, AdjacenyList);
        }
        vector<string> queries = loadQueries(n);
        ErdosNumbers["Erdos, P."] = 0;
        ComputeErdosNumbers(AdjacenyList);
//        printMap(ErdosNumbers);
        
        cout << "Scenario " << i+1 << endl;
        printResults(n, queries);
    }
}
