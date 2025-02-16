#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Return unit vector 
vector<float> normalize(vector<float> a) {
    vector<float> b(a.size());
    float length = 0.0;
    for (int i=0;i<a.size();i++) {
        length += (a[i]*a[i]);
    };
    length = sqrt(length);
    for (int i=0;i<a.size();i++) {
        b[i] = (a[i]/length);
    };
    return b;
};