#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

using namespace std;

const double PI = 3.14;

double myrand(int mymin, int mymax) {
	double x;
	x =  float(((double)(rand()) / RAND_MAX * (mymax - mymin) + mymin)*100)/100;
	return x;
}

class Circle {
	double radius;
public:
	Circle() {
		radius = myrand(2, 5);
	}

	Circle(double Area) {
		double x = Area/PI;
		radius = sqrt(x);
	}

	double get_area() const {
		return round(PI * radius * radius * 100) / 100;
	}
#pragma region operators
	friend ostream& operator<<(ostream& stream, const Circle& circle) {
		stream << circle.get_area(); return stream;
	}
	friend bool operator<(const Circle& f_elem, const Circle& s_elem) {
		return f_elem.get_area() < s_elem.get_area();
	}
	friend bool operator==(const Circle& f_elem, const Circle& s_elem) {
		return f_elem.get_area() == s_elem.get_area();
	}
	friend bool operator>(const Circle& f_elem, const Circle& s_elem) {
		return f_elem.get_area() > s_elem.get_area();
	}
	operator double() const {
		return get_area();
	}
	friend double operator+(const Circle& f_elem, const Circle& s_elem) {
		return f_elem.get_area() + s_elem.get_area();
	}
#pragma endregion
};

class Square {
	double side;
public:
	Square() {
		side = myrand(3, 9);
	}

	Square(double Area) {
		side = sqrt(Area);
	}

	double get_area() const {
		return round(side * side * 100) / 100;
	}
#pragma region operators
	friend ostream& operator<<(ostream& stream, const Square& square) {
		stream << square.get_area(); return stream;
	}
	friend bool operator<(const Square& f_elem, const Square& s_elem) {
		return f_elem.get_area() < s_elem.get_area();
	}
	friend bool operator==(const Square& f_elem, const Square& s_elem) {
		return f_elem.get_area() == s_elem.get_area();
	}
	friend bool operator>(const Square& f_elem, const Square& s_elem) {
		return f_elem.get_area() > s_elem.get_area();
	}
	friend double operator+(const Square& f_elem, const Square& s_elem) {
		return f_elem.get_area() + s_elem.get_area();
	}
	operator double() const {
		return get_area();
	}
#pragma endregion

};


template <class T> void sort(T* arr, int arr_size = 12)
{
	for (int i = 0; i < arr_size; i++) {
		for (int j = 0; j < arr_size - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T buff = arr[j];
				arr[j] = arr[j + 1]; 
				arr[j + 1] = buff; 
			}
		}
	}
}


template <class T>int found_function(T* array, T element, int arr_size = 12) {
	for (int i = 0; i < arr_size; i++) {
		if (array[i] == element) {
			return i;
			break;
		}
	}
	return -1;
}

template <class T> void swap(T* arr, int SIndex1, int SIndex2, int arr_size = 12)
{
	if (SIndex1 >= arr_size || SIndex2 >= arr_size) cout << "Impossible";
	else {
		T buff = arr[SIndex1];
		arr[SIndex1] = arr[SIndex2];
		arr[SIndex2] = buff;

		for (int i = 0; i < arr_size; i++)
			cout << arr[i] << ' ';
	}
}


template <class T> double average(T* arr, int arr_size = 12)
{
	double result = 0;
	for (int i = 0; i < arr_size; i++)
		result += double(arr[i]);
	return (result / arr_size);
}




int main() {
	srand(time(NULL));
	int k = 12, Elem_I = 0;
	double  Elem_D = 0, Elem_S = 0, Elem_C = 0;
	int SIndex1, SIndex2;

	int* integers = new int[k];
	for (int i = 0; i < k; i++)
		integers[i] = rand() % k;
	double* doubles = new double[k];
	for (int i = 0; i < k; i++)
		doubles[i] = round((double)(rand()) / RAND_MAX * 100 * 100) / 100;
	Square* squares = new Square[k];
	Circle* circles = new Circle[k];
	
	cout << "\nIntegers: ";
	for (int i = 0; i < k; i++)
		cout << integers[i] << ' ';
	cout << "\nDoubles: ";
	for (int i = 0; i < k; i++)
		cout << doubles[i] << ' ';
	cout << "\nSquares: ";
	for (int i = 0; i < k; i++)
		cout << squares[i] << ' ';
	cout << "\nCircles: ";
	for (int i = 0; i < k; i++)
		cout << circles[i] << ' ';

	sort(integers);
	sort(doubles);
	sort(squares);
	sort(circles);

	cout << "\n\nSorted Integers: ";
	for (int i = 0; i < k; i++)
		cout << integers[i] << ' ';
	cout << "\nSorted Doubles: ";
	for (int i = 0; i < k; i++)
		cout << doubles[i] << ' ';
	cout << "\nSorted Squares: ";
	for (int i = 0; i < k; i++)
		cout << squares[i] << ' ';
	cout << "\nSorted Circles: ";
	for (int i = 0; i < k; i++)
		cout << circles[i] << ' ';

	cout << "\nEnter number for found_function: ";
	cin >> Elem_I >> Elem_D >> Elem_S >> Elem_C;

	

	cout << "\n\nFound in integers: " << found_function(integers, Elem_I);
	cout <<   "\nFound in doubles: "  << found_function(doubles, Elem_D);
	cout <<   "\nFound in squares: "  << found_function(squares, Square(Elem_S));
	cout <<   "\nFound in circles: "  << found_function(circles, Circle(Elem_C));

	cout << "\n\nEnter indexs for swap: ";
	cin >> SIndex1 >> SIndex2;

	cout << "\n\nSwaped array of Integers: ";
	swap(integers, SIndex1, SIndex2);
	cout <<   "\nSwaped array of Doubles: ";
	swap(doubles, SIndex1, SIndex2);
	cout <<   "\nSwaped array of Squares:";
	swap(squares, SIndex1, SIndex2);
	cout <<   "\nSwaped array of Circles: ";
	swap(circles, SIndex1, SIndex2);
	cout << "\n\n";

	cout << "\n\nAverage of integers: " << average(integers);
	cout << "\nAverage of doubles: " << average(doubles);
	cout << "\nAverage of squares: " << average(squares);
	cout << "\nAverage of circles: " << average(circles) << endl;

	return 0;
}