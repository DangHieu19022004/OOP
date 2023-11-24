#include <iostream>
using namespace std;

class Circle{
	double radius;
	public:
		Circle(double r){
			// radius = r;
		}
		double getArea(){
			return 3.14 * radius * radius;
		}
		double getCircumference(){
			return 2 * 3.14 * radius;
		}
};