#include <iostream>
#include "rectangle.h"
using namespace std;

int main() {
	Rectangle rect;
	Rectangle rect2 = rect; // Creates a copy of 'rect' not just a reference
	Rectangle &refRect = rect; // Creates a reference to 'rect' not a new object
	Rectangle *pRect; // Creates a pointer for an object
	Rectangle *pRect2 = new Rectangle();

	pRect = &rect; // '&rect' returns the memory address of the variable
	pRect2->set_values(7, 8);

	rect.set_values(3, 4);
	rect2.set_values(5, 6);
	refRect.set_values(10, 5); // Changes 'rect' to (10, 5) from (3, 4)

	cout << "area: " << rect.area() << endl;
	cout << "area2: " << rect2.area() << endl;
	cout << "areaRefRect: " << refRect.area() << endl;
	cout << "areapRect2: " << pRect2->area() << endl;
	cout << "pointer to rect: " << pRect << endl;

	return 0;
}
