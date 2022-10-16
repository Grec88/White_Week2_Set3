//============================================================================
// Name        : Week2_Set3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;


void print(const set<string> &a) {
	for (const auto &c : a) {
		cout << " " << c << " ";
	}
	cout << endl;
}

void print(const map<string, set<string>> &dictionary) {
	for (const auto& [key, value] : dictionary) {
		cout << key << " - ";
		print(value);
	}
}

int main() {
	set<vector<string>> temp;
	map<string, set<string>> dictionary;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string operation;
		cin >> operation;
		if (operation == "ADD") {
			string word1, word2;
			set<string> synonyms1, synonyms2;
			cin >> word1 >> word2;
			if (dictionary[word1].empty() == true
					&& dictionary[word2].empty() == true) {
				synonyms1.insert(word2);
				dictionary[word1] = synonyms1;
				synonyms2.insert(word1);
				dictionary[word2] = synonyms2;
			}
			if (dictionary[word1].empty() != true
					&& dictionary[word2].empty() == true) {
				set<string> synonyms;
				dictionary[word1].insert(word2);
				synonyms.insert(word1);
				dictionary[word2] = synonyms;
			}
			if (dictionary[word2].empty() != true
					&& dictionary[word1].empty() == true) {
				set<string> synonyms3;
				dictionary[word2].insert(word1);
				synonyms3.insert(word2);
				dictionary[word1] = synonyms3;
			}
			if(dictionary[word2].empty() != true
					&& dictionary[word1].empty() != true){
				dictionary[word1].insert(word2);
				dictionary[word2].insert(word1);
			}
			temp.insert( { word1, word2 });
		}
		if (operation == "COUNT") {
			string word;
			cin >> word;
			cout << dictionary[word].size() << endl;
		}
		if (operation == "CHECK") {
			string word4, word5;
			cin >> word4 >> word5;
			if (temp.count( { word4, word5 }) == 1
					|| temp.count( { word5, word4 }) == 1) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
		if (operation == "PRINT") {
			print(dictionary);
		}
	}
	return 0;
}
