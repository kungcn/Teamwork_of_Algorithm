#ifndef CLOSE_PAIR_PIVOT
#define CLOSE_PAIR_PIVOT

#include "header.h"
#include "def.h"

using namespace std;

// !CLOSE_PAIR_PIVOT
class close_pair_pivot {
    public:
        close_pair_pivot() { }
        Node closestPairMedian(vector<pair<int, typeOfVector> > &X);
        pair<int, typeOfVector> Select(vector<pair<int, typeOfVector> > &X, int position);
        Node closestPairRandom(vector<pair<int, typeOfVector> > &X);
        Node closeByPosition(vector<pair<int, typeOfVector>> &X, int position, Node (close_pair_pivot::*f)(vector<pair<int, typeOfVector>> &));
        std::vector<std::pair<int, typeOfVector> > get();
        void set(vector<pair<int, double> > s_temp, int N);
 
     private:
        std::vector<pair<int, typeOfVector> > S;
};

#endif
