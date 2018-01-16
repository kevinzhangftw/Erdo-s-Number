//
//  main.cpp
//  ErdosNumberRoutine
//
//  Created by Kai Zhang on 2018-01-15.
//  Copyright © 2018 Kai Zhang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void printVec(vector<string> input){
    for (int i =0; i< input.size(); i++) {
        cout << input.at(i) << endl;
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

int main(int argc, const char * argv[]) {
    int scenario;
    cin >> scenario;
    
    while (scenario--) {
        int P, N;
        cin >> P >> N;
        vector<string> authors[P];
        for (int i =0; i< P ; i++) {
            vector<string> temp_list;
            string line_part_1, line_part_2;
            getline(cin, line_part_1, ':');
            getline(cin, line_part_2);
            temp_list = split(line_part_1, ',');
            for (int j=0; j<temp_list.size(); j=j+2) {
                string full_name = temp_list[j]+ ',' +temp_list[j+1];
//                if(j == 0)
//                    full_name.erase(remove(full_name.begin(), full_name.end(), '\n'), full_name.end());
                
                if(full_name[0] == ' ')
                    full_name.erase(full_name.begin());
                
                authors[i].push_back(full_name);
            }
            
            printVec(authors[i]);

            
        }
    }
}
