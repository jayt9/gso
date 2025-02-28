#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
using namespace std;
//Make sure length of vectors are equal!!! Check independence!!! 

//Return unit vector 
vector<double> normalize(vector<double> a) {
    vector<double> b(a.size());
    double length = 0.0;
    for (int i=0;i<a.size();i++) {
        length += (a[i]*a[i]);
    };
    length = sqrt(length);
    for (int i=0;i<a.size();i++) {
        b[i] = (a[i]/length);
    };
    return b;
};

//Dot product of two vectors
double dot_product(vector<double> a, vector<double> b) {
    double result = 0.0;
    for (int i=0;i<a.size();i++) {
        result += (a[i]*b[i]);
    };
    return result;
};

//When orthogonalizing b to a, the scalar you will multiply a by before subtracting from b
double scalar(vector<double> a, vector<double> b) {
    double result;
    result = dot_product(a,b)/dot_product(a,a);
    return result;
};

//Subtract two vectors
vector<double> subtract(vector<double> a, vector<double> b) {
    vector<double> new_vector(a.size());
    for (int i=0;i<a.size();i++) {
        new_vector[i] = (a[i] - b[i]);
    };
    return new_vector;
};

vector<double> scalar_mult(vector<double> a, double b) {
    vector<double> result;
    for (int i=0;i<a.size();i++) {
        result.push_back(a[i]*b);
    };
    return result;
}

//Make 2 vectors perpendicular
vector<double> orthogonalize(vector<double> a, vector<double> b) {
    vector<double> orthogonal_vector;
    orthogonal_vector = subtract(b,(
        scalar_mult(a,scalar(a,b))
    ));
    return orthogonal_vector;
};

//Requires three independent vectors 
vector<vector<double>> gso(vector<double> a, vector<double> b, vector<double> c) {
    vector<double> v1, v2, v3;
    v1 = a;
    v2 = orthogonalize(a, b);
    v3 = subtract(c, subtract(orthogonalize(a,c), orthogonalize(v2,c)));
    return {v1, v2, v3};
};

int det(vector<double> a, vector<double> b, vector<double> c) {
	double i1, i2, i3, e1, e2, e3, determinant;
	i1 = a[0]*b[1]*c[2];
	i2 = a[1]*b[2]*c[0];
	i3 = a[2]*b[0]*c[1];
	e1 = c[0]*b[1]*a[2];
	e2 = c[1]*b[2]*a[0];
	e3 = c[2]*b[0]*a[1];
	determinant = (i1+i2+i3)-(e1+e2+e3);
	if (determinant == 0) {
		throw runtime_error("Use independent vectors!!!");
	};
	return determinant;
}

int main() {
    vector<vector<double>> result;
	int i = 0;
	int e = 0;
	vector<double> v1(3), v2(3), v3(3);
	cout.precision(6);
	cout << fixed;
	while (i<3) {
		cout << "Row: ";
		cin >> v1[i] >> v2[i] >> v3[i];
		cout << endl;
		i += 1;
	};
	result = gso(v1, v2, v3);
	for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
};
