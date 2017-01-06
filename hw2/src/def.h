#ifndef DEF_H__
#define DEF_H__

// -----------------------------------------------------------------------------
//  Typedefs
// -----------------------------------------------------------------------------
typedef double typeOfVector;

// -----------------------------------------------------------------------------
//  Macros
// -----------------------------------------------------------------------------
#define PI 3.1415926
#define DBL_MAX 1.7976931348623158e+308
#define MAX_ARRAY_NUMBER 999
#define INIT_VALUE_FOR_DISTANCE 23332333

// -----------------------------------------------------------------------------
//  Constants
// -----------------------------------------------------------------------------

    //const int number_of_dataset = 60000;  //dataset size
    //const int number_of_pixel = 784;      //pixel size
    static int number_of_dataset;  //dataset size
    static int number_of_pixel;      //pixel size
    const int number_of_random = 100;      //num of random = m

struct node {
	double distance;
	std::pair< std::pair<int, double>, std::pair<int, double> > cp;
}typedef Node;

#endif
