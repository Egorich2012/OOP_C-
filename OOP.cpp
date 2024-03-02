#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

enum PrintType {
	E_RGB,
	E_RGBA,
	E_HEX,
	E_INT
};

class {
	
}

class RGB {
protected:
	unsigned short r;
	unsigned short g;
	unsigned short b;

public:
	RGB() {
		r = 0;
		g = 0;
		b = 0;
	}

	RGB(unsigned short rr, unsigned short gg, unsigned short bb) {
		r = rr;
		g = gg;
		b = bb;
	}

	RGB(const RGB& color) {
		r = color.r;
		g = color.g;
		b = color.b;
	}

	void setColor(unsigned short rr, unsigned short gg, unsigned short bb) {
		r = rr;
		g = gg;
		b = bb;
	}
	virtual void setColor() {
		r = 0;
		g = 0;
		b = 0;
	}
	const unsigned short red() {
		return (const unsigned short) r;
	}
	const unsigned short green() {
		return (const unsigned short) g;
	}
	const unsigned short blue() {
		return (const unsigned short) b;
	}

	virtual void print(enum PrintType pt) {
		switch (pt) {
		case E_RGB:
			cout << r << " " << g << " " << b << endl;
			break;
		case E_INT:
			cout << r << " " << g << " " << b << endl;
			break;
		case E_HEX:
			cout << setfill('0') << hex << setw(2) << r << " " << setw(2) << g << " " << setw(2) << b;
		default:
			break;
		}
	}

	 RGB sum(const RGB obj) {
		 RGB obj2 = RGB(obj);
		 obj2.r += r;
		 obj2.g += g;
		 obj2.b += b;
		 return obj2;
	}
};

class RGBA : public RGB {
private:
	unsigned short a;

public:
	RGBA() {
		r = 0;
		g = 0;
		b = 0;
		a = 255;
	}

	RGBA(unsigned short rr, unsigned short gg, unsigned short bb, unsigned short aa) {
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}

	RGBA(const RGBA& color) {
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}


	void setColor(unsigned short rr, unsigned short gg, unsigned short bb, unsigned short aa) {
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}

	void setColor() override {
		r = 0;
		g = 0;
		b = 0;
		a = 255;
	}

	const unsigned short alpha() {
		return a;
	}
	
	 void print(enum PrintType pt) override {
		switch (pt) {
		case E_RGBA:
			cout << r << " " << g << " " << b << " " << a << endl;
			break;
		case E_INT:
			cout << r << " " << g << " " << b << " " << a << endl;
			break;
		case E_HEX:
			cout << setfill('0') << hex << setw(2) << r << " " << setw(2) << g << " " << setw(2) << b << " " << setw(2) << a;
		default:
			break;
		}
	}
	RGBA sum(const RGBA obj) {
		RGBA obj2 = RGBA(obj);
		obj2.r += r;
		obj2.g += g;
		obj2.b += b;
		obj2.a += a;
		return obj2;
	}
};

int main() {

	vector <RGB*> Arr;
	RGB obj1 = RGB(1, 2, 3);
	RGBA obj2 = RGBA(3, 2, 1, 100);
	RGBA obj3 = RGBA(obj2).sum(obj2);

	Arr.push_back(&obj1);
	Arr.push_back(&obj2);
	Arr.push_back(&obj3);

	for (RGB * i : Arr) {
		(*i).setColor();
		(*i).print(E_INT);
	}

	return 0;
}

