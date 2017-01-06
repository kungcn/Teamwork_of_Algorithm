#include "close_pair_pivot.h"

pair<int, typeOfVector> close_pair_pivot::Select(vector<pair<int, typeOfVector> > &X, int position) {
    vector<pair<int, typeOfVector> > Splus;
    vector<pair<int, typeOfVector> > Sminus;

    pair<int, typeOfVector> splitter = X[0];

    for (vector<pair<int, typeOfVector>>::iterator it = X.begin(); it != X.end(); it++) {
        if (it->second < splitter.second) {
            Splus.push_back(*it);
        }
        else if (it->second > splitter.second) {
            Sminus.push_back(*it);
        }
    }

    if (Sminus.size() == position - 1) {
        return splitter;
    }
    else if (Sminus.size() >= position - 1) {
        return Select(Sminus, position);
    }
    return Select(Splus, position - 1 - (int)Sminus.size());

}

Node close_pair_pivot::closestPairMedian(vector<pair<int, typeOfVector>> &X) {
    //int len = sizeof(X)/sizeof(X[0]);
    int len = (int)X.size();
    if (len == 1) {
        Node temp;
        temp.distance = DBL_MAX;
        // temp.cp = NULL;
        return temp;
    }
    if (len == 2) {
        Node temp;
        if (X[0].second > X[1].second) {
            temp.cp.first = X[1];
            temp.cp.second = X[0];
        }
        else {
            temp.cp.first = X[0];
            temp.cp.second = X[1];
        }
        temp.distance = temp.cp.second.second - temp.cp.first.second;
        return temp;
    }
    return closeByPosition(X, len / 2 + len % 2, &close_pair_pivot::closestPairMedian);

}


Node close_pair_pivot::closeByPosition(vector<pair<int, typeOfVector>> &X, int position, Node(close_pair_pivot::*f)(vector<pair<int, typeOfVector>> &)) {
    int len = (int)X.size();

    pair<int, double>m = Select(X, position);

    vector<pair<int, double>> S1, S2;
    for (int i = 0; i < len; i++) {
        if (X[i].second <= m.second)
            S1.push_back(X[i]);
        else
            S2.push_back(X[i]);
    }
    pair<int, double> m_plus1 = Select(X, position - 1);

    vector<pair<int, double>> v;
    v.push_back(m);
    v.push_back(m_plus1);

    Node temp1 = (this->*f)(S1);
    Node temp2 = (this->*f)(S2);
    Node temp3 = (this->*f)(v);

    if (temp1.distance < temp2.distance) {
        if (temp1.distance < temp3.distance) return temp1;
        return temp3;
    } else {
        if (temp2.distance < temp3.distance) return temp2;
        return temp3;
    }




    /*
    vector<Node> v_temp;
    v_temp.push_back(temp1);
    v_temp.push_back(temp2);
    v_temp.push_back(temp3);
    vector<Node> re;

    while (re.size() < 3) {
        int flag = 0;
        double min = v_temp[0].distance;
        for (int i = 0; i < v_temp.size(); i++) {
            if (v_temp[i].distance != 100 &&v_temp[i].distance < min) {
                flag = i;
                min = v_temp[i].distance;
            }
        }
        re.push_back(v_temp[flag]);
        v_temp[flag].distance = -100;
    }

for (int i = 0; i < re.size(); i++) {
    if (re[i].distance > 0) {
        return re[i];
    }
    return temp1;
}
*/
}

Node close_pair_pivot::closestPairRandom(vector<pair<int, typeOfVector>> &X) {

    int len = (int)X.size();

    if (len == 1) {
        Node temp;
        temp.distance = DBL_MAX;
        // temp.cp = NULL;
        return temp;
    }
    if (len == 2) {
        Node temp;
        if (X[0].second > X[1].second) {
            temp.cp.first = X[1];
            temp.cp.second = X[0];
        }
        else {
            temp.cp.first = X[0];
            temp.cp.second = X[1];
        }
        temp.distance = temp.cp.second.second - temp.cp.first.second;
        return temp;
    }
    int position = rand() % len +1;
    if (position == 1) position += 1;
    else if (position == len) position -= 1;
    return closeByPosition(X, position, &close_pair_pivot::closestPairRandom);

}


vector<pair<int, typeOfVector> > close_pair_pivot::get() {
    if (S.size() == 0) cout << "wrong" << endl;
    return S;
}

void close_pair_pivot::set(vector<pair<int, double> > s_temp, int N) {
    for(vector<pair<int, double> >::iterator it = s_temp.begin(); it != s_temp.end(); ++it) {
        S.push_back((*it));
    }
}
