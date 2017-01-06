#include "project.h"

float gaussian_data() {
    float num;
    num = sqrt((-2) * log(fabs(((double)rand()))/RAND_MAX)) * fabs(sin((double)(2 * PI * rand()) / RAND_MAX));
    //num = sqrt((-2) * log(((double)rand())/RAND_MAX)) * sin((double)(2 * PI * rand() / RAND_MAX));
    // cout << num << endl;
    return num;
}

void Create_random(float** array,int row, int column) {
    cout << "create " << row << " random vectors..." << endl;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            array[i][j] = gaussian_data();
        }
        /*for(int j = 0; j < column; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
            //getchar();
            system("pause");*/
    }
    cout << "\tcreate sucess!" << endl;
}

//algorithm 2
vector<vector<pair<int, double> > > Random_Projection(float** project_array, float** projected_array,
    int num_project_array, int num_projected_array, int d) {
    cout << "project..." << endl;
    vector<vector<pair<int, double> > > S;
    for(int i = 0; i < num_projected_array; i++) {
        vector<pair<int, double> > temp;   //S1 S2 
        for(int j = 0; j < num_project_array; j++) {
            double result = 0.0;
            for (int k = 0; k < d; k++) {
                result += project_array[j][k] * projected_array[i][k];
            }
            temp.push_back(pair<int, double>(j, result));
        }
        S.push_back(temp);
    }
    cout << "\tproject success!" << endl;
    return S;
}
