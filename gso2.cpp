#include <iostream>
#include <cmath>
#include <array>
#include <vector> 

using namespace std;

using Vector = array<double, 3>;

double dot(const Vector& a, const Vector&b) {
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
};

Vector subtract(const Vector& a, const Vector&b) {
	return {a[0]-b[0],a[1]-b[1],a[2]-b[2]};
};

Vector multiply(double scalar, const Vector&a) {
	return {scalar*a[0],scalar*a[1],scalar*a[2]};
};

double length(const Vector& a) {
	return sqrt(dot(a,a));
};

Vector normalize(const Vector& a) {
	return {a[0]/length,a[1]/length,a[2]/length};
};

int main() {
	Vector v1, v2, v3;
	cout << "Enter first vector components: ";
	cin >> v1[0] >> v1[1] >> v1[2];
	cout << "Enter second vector components: ";
	cin >> v2[0] >> v2[1] >> v2[2];
	cout << "Enter third vector components: ";
	cin >> v3[0] >> v3[1] >> v3[2];

	Vector u2 = subtract(v2, multiply(dot(v2,v1)/dot(v1,v1), v1));
	Vector u3 = subtract(v3, subtract(multiply(dot(v3,v1)/dot(v1,v1), v1),multiply(dot(v3,v2)/dot(v2,v2), v2)));

	cout.precision(6);
    cout << fixed;
    cout << "\nOrthonormal vectors:\n";
    cout << "u1: " << u1[0] << " " << u1[1] << " " << u1[2] << endl;
    cout << "u2: " << u2[0] << " " << u2[1] << " " << u2[2] << endl;
    cout << "u3: " << u3[0] << " " << u3[1] << " " << u3[2] << endl;
	
	return 0;
};