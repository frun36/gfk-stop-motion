#pragma once

#include <memory>
#include <stdexcept>
#include <string>
#include <iostream>
#include <wx/wx.h>

class ShapeToParse {
public:
	static std::unique_ptr<ShapeToParse> fromStrings(std::string name, std::vector<std::string> params) {
		if (name == "circle") {
			return Circle::fromParams(params);
		}
		else {
			throw std::runtime_error("Invalid shape name");
		}
	}
};

class Circle : public ShapeToParse {
private:
	double _x0, _y0, _r;
public:
	Circle(double x0, double y0, double r) : _x0(x0), _y0(y0), _r(r) {}

	static std::unique_ptr<Circle> fromParams(std::vector<std::string> params) {
		if (params.size() < 3)
			throw std::runtime_error("Too few parameters for parsing circle");

		return std::make_unique<Circle>(stof(params[0]), stof(params[1]), stof(params[2]));
	}
};