#include "readFile.h"

//  create Array with rows * cols
float** createArray(int rows, int cols) {
    float** Array = new float*[rows];
    for (int i = 0; i < rows; i++)
    Array[i] = new float[cols];
    return Array;
}

//  free Array with rows * cols
void freeArray(float** Array, int rows) {
    for (int i = 0; i < rows; i++)
        delete [] Array[i];
    delete [] Array;
    //cout << "free Array success!" << endl;
}

//  reverse the char array and turn to int large section rule
int reverseInt(unsigned char* Array, int Length) {
    if (Length < 0) {  
        return -1;
    }
    int result = static_cast<signed int>(Array[0]);  
    for (int i = 1; i < Length; i++) {  
        result = (result << 8) + Array[i];  
    }
    return result;
}

//  read data from file and store in set
void readFromMinst(char* MNIST, float** set, int number) {
    cout << "read data from " << MNIST << "..." << endl;
    ifstream file (MNIST, ios::binary);
    int magic_number = 0;
    int number_of_images = 0;
    int rows = 0;
    int cols = 0;
    file.read((char*) &magic_number, sizeof(magic_number));
    magic_number = reverseInt((unsigned char*)&magic_number,sizeof(magic_number));
    file.read((char*) &number_of_images,sizeof(number_of_images));
    number_of_images = reverseInt((unsigned char*)&number_of_images,sizeof(number_of_images));
    file.read((char*) &rows, sizeof(rows));
    rows = reverseInt((unsigned char*)&rows,sizeof(rows));
    file.read((char*) &cols, sizeof(cols));
    cols = reverseInt((unsigned char*)&cols,sizeof(rows));
    //cout << "magic num " << magic_number << endl << "num " << number_of_images << endl << "rows " << rows << endl << "cols " << cols << endl << endl;
    for(int i = 0; i < number; i++) {
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
            unsigned char temp = 0;
            file.read((char*) &temp, sizeof(temp));
            int t = reverseInt(&temp, sizeof(temp));
            set[i][r * rows + c] = t;
            /*if (t == 0)  //print the num
            cout << "*";
            else 
            cout << " ";*/
            //cout << set[i][r * rows + c] << " ";
            }
            //cout << endl;
        }
        //getchar();
        //system("pause");
    }
    file.close();
    cout << "\tread success!" << endl;
}
