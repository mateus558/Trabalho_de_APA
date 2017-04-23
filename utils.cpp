#include "utils.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool is_fempty(ifstream& file){
	return file.peek() == ifstream::traits_type::eof();
}

int load_list(string path, Node **arr){
	ifstream file(path.c_str());
	string line;
	int key, size = 1, i = 1, j = 0;
	
	if(!file) return -1;
	
	while(getline(file, line)){ size++; }
	size /= 2;
	
	file.clear();
	file.seekg(0, ios::beg);
	
	*arr = new Node[size];
	
	while(getline(file, line)){
		if(i%2 == 1){
			(*arr)[j].key = stoi(line);
		}else{
			(*arr)[j].info = line;
			j++;
		}
		i++;
	}
	
	file.close();
	
	return size;
}

void save_csv(std::string fname, Analysis info){
	string path = fname + ".csv";
	ofstream file;
	ifstream empty_test(path.c_str());
	
	if(is_fempty(empty_test)){
		empty_test.close();
		file.open(path.c_str());
		file << "N, comparacoes, atribuicoes, tempo, tipo de array\n";
	}else{
		file.open(path.c_str(), ios::app);
	}
	
	file << info.size << ", " << info.comp << ", " << info.atrib << ", " << info.time << ", " << info.list_type << endl;
	
	file.close();
}

void print_nodes(Node arr[], int n){
	int i;
	
	for(i = 0; i < n-1; i++){
		cout << "[" << arr[i].key << ", " << arr[i].info << "], ";
	}
	cout << "[" << arr[i].key << ", " << arr[i].info << "]";
}
