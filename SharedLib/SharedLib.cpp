 #include <string>
 #include <list>
 #include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <iterator>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdio>

//#define _USE_MATH_DEFINES
#include <cmath>
const double MY_PI = asin(1.0) * 2; // sin(PI/2 radians) = 1.0.

#include "../ClassSolver.h"
//using namespace std;
using std::vector;
using std::string;
using std::cout;

int PyGrid::LoadGrid()
{
	std::ifstream input;
	input.open(m_fname);

	if (input.is_open())
	{
		string line;
		while (getline(input, line))
		{
			std::stringstream ssline(line);

			vector<string> result;
			while (ssline.good())
			{
				string substr;
				getline(ssline, substr, ',');
				result.push_back(substr);
			}
			try
			{
				double x = stod(result[0]);
				double y = stod(result[1]);
				m_vPoints.push_back(Point(x, y));
			}
			catch (const std::invalid_argument &ia)
			{
				cout << "Invalid data in file: " << ia.what() << '\n';
				input.close();
				return -1;
			}
		}
	}
	else
	{
		cout << "File Open Error: " << m_fname << " not found\n";
		return -1;
	}
	input.close();

	unsigned int nPoints = m_vPoints.size();
	m_gridSize = 0;
	// grids limited to 2x2 to 10x10
	for (int i = 2; i < 11; i++)
	{
		if (nPoints == i *i)
		{ 
			m_gridSize = i;
			m_bValidData = true;
			m_errorStr = "NoError";
		}
	}
	if (m_gridSize == 0)
	{
		m_bValidData = false;
		m_errorStr = "Invalid Grid Size";
	}

	m_alpha = calcAlpha(m_vPoints);
	calcOffsets();
	m_bVerifyAlpha = CheckAlpha();

	return 0;
}

int PyGrid::SaveGrid()
{
	std::ofstream output;
	output.open("../UnitTest/output.txt");

	output << std::fixed << std::setprecision(1);

	// vector<Point> outPoints{};

	// // Note: Before rotation, the origin must be moved back to (0,0)
	// //cout << "{xOff, yOff} = {" << m_xOffset << ", " << m_yOffset << "}\n";
	// double xOff = m_xOffset;
	// double yOff = m_yOffset;
	// auto shift = [xOff, yOff](const Point& pt)
	// {
	// 	return Point(pt.x - xOff, pt.y - yOff);
	// };
	// std::transform(m_vPoints.begin(), m_vPoints.end(), back_inserter(outPoints), shift);
	// //if (m_alpha != 0) outPoints = Rotate(outPoints, -m_alpha);

	for (auto& v : m_vResets)
	{
		output << v.x << "," << v.y << "\n";
	}
	output.close();

	return 0;
}

void PyGrid::calcOffsets()
{
	m_xOffset = 0.0;
	m_yOffset = 0.0;
	if (m_vPoints.size() != 0)
	{
		for (auto& pt : m_vPoints)
		{
			m_xOffset += pt.x;
			m_yOffset += pt.y;
		}
		m_xOffset /= m_vPoints.size();
		m_yOffset /= m_vPoints.size();
	}
	return;
}

std::pair<double,double> PyGrid::calcOffsets(vector<Point> &v)
{
	double xOff = 0.0;
	double yOff = 0.0;
	if (v.size() != 0)
	{
		for (auto pt : v)
		{
			xOff += pt.x;
			yOff += pt.y;
		}
		xOff /= v.size();
		yOff /= v.size();
	}
	return std::make_pair(xOff, yOff);
}

double PyGrid::calcAlpha(vector<Point> &v)
{
	vector<Point> tmp;
	//vector<size_t> idx_X(m_vPoints.size());
	//vector<size_t> idx_Y(m_vPoints.size());
#if 0
	// Note: Before rotation, the origin must be moved back to (0,0)
	std::pair<double, double> xyOff = calcOffsets(m_vPoints);
	cout << "{xOff, yOff} = {" << xyOff.first << ", " << xyOff.second << "}\n" << std::endl;

	auto shift = [xyOff](const Point& pt)
	{
		double x = pt.x - (xyOff.first > 0) ? xyOff.first : -xyOff.first;
		double y = pt.x - (xyOff.second > 0) ? xyOff.second : -xyOff.second;

		return Point(x, y);
	};
	std::transform(m_vPoints.begin(), m_vPoints.end(), back_inserter(tmp), shift);
#else
	copy(m_vPoints.begin(), m_vPoints.end(), back_inserter(tmp));
#endif
#if 1
	// determine "X" Corner points
	sort(tmp.begin(), tmp.end(), sortMajorD());
	xyLB = tmp[0];
	//cout << "xyLB = {" << xyLB.x << ", " << xyLB.y << "}\n";
	xyRT = tmp[tmp.size() - 1];
	//cout << "xyRT = {" << xyRT.x << ", " << xyRT.y << "}\n";
#endif
	// slope of minor-Diagonal
	double minorAngle = atan2(xyRT.y - xyLB.y, xyRT.x - xyLB.x) * 180.0 / MY_PI;
	// cout << "minorAngle = " << minorAngle << " degrees. " << endl;
#if 1
	// determine "Y" Corner points
	sort(tmp.begin(), tmp.end(), sortMinorD());
	xyLT = tmp[0];
	//cout << "xyLT = {" << xyLT.x << ", " << xyLT.y << "}\n";
	xyRB = tmp[tmp.size() - 1];
	//cout << "xyRB = {" << xyRB.x << ", " << xyRB.y << "}\n";
	//PrintGrid(tmp);
#endif
	// slope of major-Diagonal
	double majorAngle = atan2(xyLT.y - xyRB.y, xyLT.x - xyRB.x) * 180.0 / MY_PI;
	//cout << "majorAngle = " << majorAngle << " degrees. " << endl;

	// bisector of diagnols
	double alpha = ((minorAngle + majorAngle) / 2); 
	// report in range [0, 45.0]
	alpha = 45.0 + std::fmod(alpha, 45.0);
	if (alpha == 45.0) alpha = 0.0;

	return alpha;
}

void PyGrid::PrintGrid(void)
{
	cout << std::setprecision(1) << std::fixed;
	// Output Rows:
	auto it = m_vPoints.begin();
	for (int row = 0; row < m_gridSize; ++row)
	{
		cout << "Row " << row << ": ";
		for (int col = 0; col < m_gridSize; ++col)
		{
			auto it2 = it + row + col*m_gridSize;
			cout << it2->x << "," << it2->y;
			if (col < m_gridSize - 1) cout << " - ";
		}
		cout << std::endl;
	}
	cout << std::endl;

	// Output Columns:
	it = m_vPoints.begin();
	for (int col = 0; col < m_gridSize; ++col)
	{
		cout << "Col " << col << ": ";
		for (int row = 0; row < m_gridSize; ++row)
		{
			auto it2 = it + row + col*m_gridSize;
			cout << it2->x << "," << it2->y;
			if (row < m_gridSize - 1) cout << " - ";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

void PyGrid::PrintGrid(vector<Point>& v)
{
	cout << std::setprecision(1) << std::fixed;
	// Output Rows:
	auto it = v.begin();
	for (int row = 0; row < m_gridSize; ++row)
	{
		cout << "Row " << row << ": ";
		for (int col = 0; col < m_gridSize; ++col)
		{
			auto it2 = it + row + col*m_gridSize;
			cout << it2->x << "," << it2->y;
			if (col < m_gridSize - 1) cout << " - ";
		}
		cout << std::endl;
	}
	cout << std::endl;

	// Output Columns:
	it = v.begin();
	for (int col = 0; col < m_gridSize; ++col)
	{
		cout << "Col " << col << ": ";
		for (int row = 0; row < m_gridSize; ++row)
		{
			auto it2 = it + row + col*m_gridSize;
			cout << it2->x << "," << it2->y;
			if (row < m_gridSize - 1) cout << " - ";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

// 2D-rotation matrix
vector<Point> PyGrid::Rotate(vector<Point>& v, double degrees)
{
	double radians = degrees * MY_PI / 180.0;

	auto rotate = [radians](const Point& pt)
	{
		double x = pt.x*cos(radians) - pt.y*sin(radians);
		double y = pt.x*sin(radians) + pt.y*cos(radians);

		return Point(x, y);
	};
	vector<Point> result;

	std::transform(v.begin(), v.end(), back_inserter(result), rotate);

	return result;
}

bool PyGrid::CheckAlpha()
{
	vector<Point> outPoints{};

	// Note: Before rotation, the origin must be moved back to (0,0)
	//cout << "{xOff, yOff} = {" << m_xOffset << ", " << m_yOffset << "}\n";
	double xOff = m_xOffset;
	double yOff = m_yOffset;
	auto shift = [xOff, yOff](const Point& pt)
	{
		return Point(pt.x - xOff, pt.y - yOff);
	};
	std::transform(m_vPoints.begin(), m_vPoints.end(), back_inserter(m_vResets), shift);
	//std::pair<double, double> xyOff = calcOffsets(outPoints);
	//cout << "{xOff, yOff} = {" << xyOff.first << ", " << xyOff.second << "}\n";

	if (m_alpha == 0.0) return true;
	m_vResets = Rotate(m_vResets, -m_alpha);
	// Now rotate points back to original orientation
//	m_vPoints.clear();
//	m_vPoints = Rotate(outPoints, m_alpha);

	double alpha = calcAlpha(m_vResets);
	//cout << "alpha = " << alpha << "\u00B0\n" << std::endl;
	//PrintGrid(outPoints);
	if (abs(alpha-m_alpha) > 0.01) return false;
	return true;
}

#ifdef WITH_BOOST_PYTHON
//#include <boost/bind/bind.hpp>
//using namespace boost::placeholders;
#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include <boost/python.hpp>
//#include <boost/python/numpy.hpp>
using namespace boost::python;
//using namespace boost::python::numpy;
BOOST_PYTHON_MODULE(PyModule)
{
	// Part of the wrapper for list<int>
	class_<PyGrid>("PyGrid", init<string>())
		.def("angle", &PyGrid::getAlpha)
		.def("xOffset", &PyGrid::getXoffset)
		.def("yOffset", &PyGrid::getYoffset)
		.def("verify", &PyGrid::bVerify)
		.def("validity", &PyGrid::bValidData)
		.def("save", &PyGrid::SaveGrid)
		.def("errorstr", &PyGrid::getErrorStr);
}
#endif
