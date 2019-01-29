//
//  FileIO.cpp
//  Lapum.cpp
//
//  Created by Xiang Cao on 10/18/17.
//  Edited by Blake Lapum on 10/26/17 for the solution of HW4
//

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {


    ifstream inFile;
    ofstream outFile;
    string word;
    inFile.open("input.txt");
    outFile.open("output.txt");
    map<string, int> wordcount;

    while (inFile >> word) {
        for (int i = 0; i < word.length(); i++) {
            char &c = word[i];
            if (ispunct(c) || isdigit(c)) {
                word.erase(i);
            }
            c = tolower(c);
        }
        if (!word.empty() && word.compare("a") != 0 && word.compare("the") != 0) {
            wordcount[word]++;
        }
    }
    map<string, int>::iterator itr;
    for (itr = wordcount.begin(); itr != wordcount.end(); itr++) {
        outFile<<itr->first<<" "<<itr->second<<endl;
    }

    inFile.close();
    outFile.close();
    return 0;
}
