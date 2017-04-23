#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "sorting.h"
#include <string>
#include <fstream>

struct Analysis{
	std::string list_type;
	int comp, atrib, size;
	double time;
};

bool is_fempty(std::ifstream& file);
void save_csv(std::string fname, Analysis info);
int load_list(std::string path, Node **arr);
void print_nodes(Node arr[], int n);

#endif
