#ifndef PROJECT_H
#define PROJECT_H

#include "header.h"
#include "def.h"

using namespace std;

float gaussian_data();
void Create_random(float** array,int row, int column);
vector<vector<pair<int, double> > > Random_Projection(float** project_array, float** projected_array,
            int num_project_array, int num_projected_array, int d);

#endif
