#include "header.h"
#include "def.h"

int main(int argc, char *argv[]) {
    //  dateFile path
    char MNIST_DS[MAX_ARRAY_NUMBER] = "./Mnist.ds";

    //  decode command line
    for (int i = 0; i < argc; i++) {
	    if (strcmp(argv[i], "-n") == 0) {
	       number_of_dataset = atoi(argv[i+1]);
	      cout << "number_of_dataset = " << number_of_dataset <<endl;
	    } else if (strcmp(argv[i], "-d") == 0) {
	       number_of_pixel = atoi(argv[i+1]);
	      cout << "number_of_pixel = " << number_of_pixel <<endl;
	    } else if (strcmp(argv[i], "-f") == 0) {
	      memcpy(MNIST_DS, argv[i+1], strlen(argv[i + 1]));
	      cout << "MNIST_DS: " << MNIST_DS << endl;
	    }
    }

    //  set the present time as the time seed
    srand((unsigned)time(NULL));
    //  record the start time to run the algorithm
    double start_time = (double)clock();

    //PART 1: read data from mnist.ds
    float** dataset = createArray(number_of_dataset, number_of_pixel);
    readFromMinst(MNIST_DS, dataset, number_of_dataset);

    //PART2: create 100 random vector
    float** random_vector = createArray(number_of_random, number_of_pixel);
    Create_random(random_vector, number_of_random, number_of_pixel);

    //PART3: project dataset to 100 random vector
    vector<vector<pair<int, double> > > S = Random_Projection(dataset, random_vector,
            number_of_dataset, number_of_random, number_of_pixel);

    double part3_time = (double)clock();

    //PART4: find the closest pair with algorithm 3
    double min = INIT_VALUE_FOR_DISTANCE;
    Node closest_pair;

    for(vector<vector<pair<int, double> > >::iterator it = S.begin(); it != S.end(); ++it) {
    	vector<pair<int, double> > s_temp = (*it);
    	close_pair_pivot x;
    	x.set(s_temp, s_temp.size());
    	vector<pair<int, typeOfVector> > y = x.get();
    	vector<pair<int, typeOfVector> > &X = y;
    	Node n = x.closestPairMedian(y);
    	if (n.distance < min) {
    		min = n.distance;
    		closest_pair.distance = min;
    		closest_pair.cp.first.first = n.cp.first.first;
    		closest_pair.cp.first.second = n.cp.first.second;
    		closest_pair.cp.second.first = n.cp.second.first;
    		closest_pair.cp.second.second = n.cp.second.second;
    	}
    }

    //  Eucildean Distance of the vector represented by the closest pair
    double powerSumFirst = 0.0;
    double EucildeanDistanceFirst = 0.0;
    double distanceMin = dataset[closest_pair.cp.first.first][0] - dataset[closest_pair.cp.second.first][0];

    for (int j = 0; j < number_of_pixel; j++) {
        powerSumFirst += (dataset[closest_pair.cp.first.first][j] - dataset[closest_pair.cp.second.first][j]) * (dataset[closest_pair.cp.first.first][j] - dataset[closest_pair.cp.second.first][j]);
    }
    EucildeanDistanceFirst = sqrt(powerSumFirst);

    for (int j = 0; j < number_of_pixel; j++) {
        double tmp = dataset[closest_pair.cp.first.first][j] - dataset[closest_pair.cp.second.first][j];
        if (tmp < distanceMin) {
            distanceMin = tmp;
        }
    }

    cout <<"the closest distance count with algorithm 3 is " << closest_pair.distance
	<< " with the " << closest_pair.cp.first.first << "st node whose value is "
	<< closest_pair.cp.first.second << " and the " <<
	 closest_pair.cp.second.first << " node whose value is " << closest_pair.cp.second.second << ". The Eucildean Distance is " << EucildeanDistanceFirst << ". The smallest pair is : " << abs(distanceMin) << endl;
    double part4_time = (double)clock();
    cout << "the cost time with algorithm 3 is " << (part4_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

    //PART5: find the closest pair with algorithm4
    min = INIT_VALUE_FOR_DISTANCE;
    Node closest_pair_;
    for(vector<vector<pair<int, double> > >::iterator it = S.begin(); it != S.end(); ++it) {
	vector<pair<int, double> > s_temp = (*it);
	close_pair_pivot x;
	x.set(s_temp, s_temp.size());
	vector<pair<int, typeOfVector> > y = x.get();
	vector<pair<int, typeOfVector> > &X = y;
	Node n = x.closestPairRandom(y);
	if (n.distance < min) {
		min = n.distance;
		closest_pair_.distance = min;
		closest_pair_.cp.first.first = n.cp.first.first;
		closest_pair_.cp.first.second = n.cp.first.second;
		closest_pair_.cp.second.first = n.cp.second.first;
		closest_pair_.cp.second.second = n.cp.second.second;
	}
    }

    //  Eucildean Distance of the vector represented by the closest pair
    double powerSumSecond = 0.0;
    double EucildeanDistanceSecond = 0.0;
    double distanceMin_ = dataset[closest_pair.cp.first.first][0] - dataset[closest_pair.cp.second.first][0];

    for (int j = 0; j < number_of_pixel; j++) {
        powerSumSecond += (dataset[closest_pair_.cp.first.first][j] - dataset[closest_pair_.cp.second.first][j]) * (dataset[closest_pair_.cp.first.first][j] - dataset[closest_pair_.cp.second.first][j]);
    }
    EucildeanDistanceSecond = sqrt(powerSumSecond);

    for (int j = 0; j < number_of_pixel; j++) {
        double tmp = dataset[closest_pair_.cp.first.first][j] - dataset[closest_pair_.cp.second.first][j];
        if (tmp < distanceMin_) {
            distanceMin_ = tmp;
        }
    }

    cout <<"the closest distance count with algorithm 4 is " << closest_pair_.distance
	<< " with the " << closest_pair_.cp.first.first << "st node whose value is "
	<< closest_pair_.cp.first.second << " and the " <<
	 closest_pair_.cp.second.first << " node whose value is " << closest_pair_.cp.second.second << ". The Eucildean Distance is " << EucildeanDistanceSecond  << ". The smallest pair is : " << abs(distanceMin_) << endl;
    double part5_time = (double)clock();
    cout << "the cost time with algorithm 4 is " << (part5_time - part4_time + part3_time - start_time) / CLOCKS_PER_SEC << "s" << endl;

    freeArray(dataset, number_of_dataset);
    freeArray(random_vector, number_of_random);
}
