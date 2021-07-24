//#pragma once
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
//#include <stdexcept>

using std::vector;
using std::cout;

struct Point
{
	double x, y;
	Point(double a = 0.0, double b = 0.0) : x{a}, y{b} {};
};

class PyGrid
{
	// Some helpful functors

	// sort grid based on x-coords, smallest to largest
	// Columns go from left to right
	struct sortMajorD //major diagonal
	{
		bool operator()(const Point &a, const Point &b)
		{
			if (a.x < b.x) return true; // 1st criterion
			if (b.x < a.x) return false;
			if (a.y < b.y) return true; // 2nd criterion
			return false;
		}
	};

	// sort the y-coords, largest to smallest
	// Rows go from top to bottom
	struct sortMinorD // minor diagonal
	{
		bool operator()(const Point &a, const Point &b)
		{
			// "Reflect" about y-axis!
			if (-a.x < -b.x) return true; // 1st criterion
			if (-b.x < -a.x) return false;
			if (a.y < b.y) return true; // 2nd criterion
			return false;
		}
	};

	std::string m_fname{};
	double m_alpha = 0.0;
	double m_xOffset = 0.0;
	double m_yOffset = 0.0;
	int m_gridSize=0;
	std::vector<Point> m_vPoints{};
	std::vector<Point> m_vResets{};
	bool m_bVerifyAlpha = true;
	bool m_bValidData=true;
	std::string m_errorStr{"NoError"};
	
	// Corners of the Square
	Point xyLB, xyRT; // points with lowest/highest x-axis values
	Point xyLT, xyRB; // points with lowest/highest y-axis values
						   // Angle of Grid Rotation, wrt X-axis
	int LoadGrid();
	double calcAlpha(vector<Point>&);
	void calcOffsets();
	std::pair<double, double> calcOffsets(std::vector<Point>&);
	void PrintGrid(void);
	void PrintGrid(std::vector<Point>& v);
	std::vector<Point> Rotate(std::vector<Point>& v, double);
	bool CheckAlpha(void);

public:
	PyGrid(std::string str) : m_fname(str)
	{
		m_vPoints.clear();
		m_vResets.clear();
		LoadGrid();
	}
	double getAlpha()
	{
		return m_alpha;
	}
	double getXoffset()
	{
		return m_xOffset;
	}
	double getYoffset()
	{
		return m_yOffset;
	}
	std::pair<double, double> getOffsets()
	{
		return std::make_pair(m_xOffset, m_yOffset);
	}
	friend std::ostream& operator<< (std::ostream& output, PyGrid& pg)
	{ 
		pg.PrintGrid();
		return output;
	}
	 // remove-oofset, counter-rotate m_vPoints to m_vRotated, verify new alpha ~= 0.0.
	bool bVerify() { return m_bVerifyAlpha; }
	bool bValidData() { return m_bValidData; }
	std::string getErrorStr(void) { return m_errorStr;}
	int SaveGrid();
};
