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
        std::cout << elem.first << " " << elem.second << "\n";
    }
}

void ComputeErdosNumbers(string FullName, map<string,vector<string> > CoAuthors, bool start){
    
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
//    vector < string > list;
//    string::size_type begin(0);
//    string::size_type end = line.find(".,", begin);
//
//    while (end != string::npos){
//        list.push_back(line.substr(begin, end - begin + 1));
//
//        begin = end + 3;
//        end = line.find(".,", begin);
//    }
//
//    if (begin < (line.length() - 1))
//        list.push_back(line.substr(begin));
//
//    return list;

    vector < string > authors;
    vector<string> list = split(line, ',');
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

vector<string> buildList(vector<string> postPreProcessingList){
    
    return postPreProcessingList;
}

int main(){
    int scenarioNumber;
    cin >> scenarioNumber;
    
    for (int i=0; i<scenarioNumber; i++) {
        int p, n;
        cin >> p;
        cin >> n;
        map<string,vector<string> > AdjacenyList;
        
//        char PaperString[500000];
        
        for (int j=0; j<p; p++) {
//            string Names;
//            gets(PaperString);
//            vector<string> PaperAuthors;
//            stringstream s(PaperString);
//            getline(s,Names,':');
//            cout << "Names: " << Names << endl;
            vector<string> PaperAuthors;
            string line_part_1, line_part_2;
            getline(cin, line_part_1, ':');
            getline(cin, line_part_2);
            PaperAuthors = extract_name(line_part_1);
//            cout<< "-"<< endl;
//            printVec(PaperAuthors);
            initializeErdosNumbers(PaperAuthors);
//            cout<< "-"<< endl;
//            printMap(ErdosNumbers);
            
        }
        

    }
    
}
