#include "stdafx.h" 
#include "math.h" 
#include "iostream" 

#define N_EQ 2 
#define LIN_EQ -2 

const int NO_SOLUTIONS = 0;
const int INF_SOLUTIONS = -1;

double EqEquation(double a, double b, double c, double x[N_EQ]);
double LiEquation(double b, double c, double x[N_EQ]);
void EqEquationTest();
bool TestFunc(double val);

int main() {
	double x[N_EQ];
	EqEquationTest();
	system("pause");
	return 0;
}

double EqEquation(double a, double b, double c, double x[N_EQ]) {
	if (!TestFunc(a) && !TestFunc(b) && !TestFunc(c)) return INF_SOLUTIONS;
	if (!TestFunc(a) && !TestFunc(b)) return NO_SOLUTIONS;
	if (!TestFunc(a)) return LiEquation(b, c, x);
	double d = b*b - 4 * a*c;
	if (!d) {
		x[0] = -b / (2 * a);
		x[1] = x[0];
		return 1;
	}
	else if (d > 0) {
		x[0] = (-b + sqrt(d)) / (2 * a);
		x[1] = (-b - sqrt(d)) / (2 * a);
		return 2;
	}
	else return NO_SOLUTIONS;
}
double LiEquation(double b, double c, double x[N_EQ]) {
	x[0] = -c / b;
	return LIN_EQ;
}

void EqEquationTest() {
	const int N_Eq = 12;
	double A[N_Eq] = { 0, 0, 0, 0, 4, -10, 5, -5, 7, 2, -5 , 1 },
		B[N_Eq] = { 0, 3, -3, 3, 0, 0, 8, -8, 14, 6, 5, 2 },
		C[N_Eq] = { 0, 6, 6, -6, -64, 1000, 6, -6, 0, 4, 10, 1 };
	double x[N_EQ];
	int val = 0;
	for (int i = 0; i < N_Eq; ++i) {
		val = EqEquation(A[i], B[i], C[i], x);
		if (val == LIN_EQ) printf("Linear equation : X = %f\n", x[0]);
		else if (val == INF_SOLUTIONS) printf("An infinite number of solutions\n");
		else if (!val) printf("No solutions\n");
		else if (val == 1) printf("Two identical solutions: X1 = %f\tX2 = %f\n", x[0], x[1]);
		else printf("Square Equation : X1 = %f\tX2 = %f\n", x[0], x[1]);
	}
}

bool TestFunc(double val) {
	if (abs(val) <= std::numeric_limits<double>::epsilon()) return false;
	return true;
}