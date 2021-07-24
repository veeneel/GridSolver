//#pragma once
#include <sstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <numeric>      // std::iota

using std::vector;
using std::cout;

struct Point
{
	double x, y;
	Point(double a = 0.0, double b = 0.0) : x{a}, y{b} {};
};

#include "ClassSolver.h"

// from stackoverflow, C++ sorting and keeping track of indexes
template <typename T>
vector<size_t> sort_indexes(const vector<T> &v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

vector<size_t> sort_X_indexes(const vector<Point>& v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1].x < v[i2].x;});

  return idx;
}

vector<size_t> sort_Y_indexes(const vector<Point>& v) {

  // initialize original index locations
  vector<size_t> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  // using std::stable_sort instead of std::sort
  // to avoid unnecessary index re-orderings
  // when v contains elements of equal values 
  stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1].y > v[i2].y;});

  return idx;
}

bool PyGrid::bVerify()
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
	std::transform(m_vPoints.begin(), m_vPoints.end(), back_inserter(outPoints), shift);
	std::pair<double, double> xyOff = calcOffsets(outPoints);
	//cout << "{xOff, yOff} = {" << xyOff.first << ", " << xyOff.second << "}\n";

	if (m_alpha == 0.0) return true;
	outPoints = Rotate(outPoints, -m_alpha);
#if 0
	// "X-axis" sort all the points in the grid
	sort(outPoints.begin(), outPoints.end(), sortMajorD());
	// "Y-axis" sort within each m_gridSize group
	auto it = outPoints.begin();
	for (int i = 0; i < m_gridSize; ++i)
	{
		sort(it+i*m_gridSize, it+i * m_gridSize + m_gridSize, sortMinorD());
	}
#endif
	// Now rotate points back to original orientation
	m_vPoints.clear();
	m_vPoints = Rotate(outPoints, m_alpha);

	double angle = calcAlpha(m_vPoints);
	//cout << "angle = " << angle << "\u00B0\n" << std::endl;
	//PrintGrid(outPoints);
	if (abs(angle-m_alpha) > 0.01) return false;
	return true;
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
#if 0
	// "X-axis" sort all the points in the grid
	sort(outPoints.begin(), outPoints.end(), sortMajorD());
	// "Y-axis" sort within each m_gridSize group
	auto it = outPoints.begin();
	for (int i = 0; i < m_gridSize; ++i)
	{
		sort(it+i*m_gridSize, it+i * m_gridSize + m_gridSize, sortMinorD());
	}
#endif
	// Now rotate points back to original orientation
	m_vPoints.clear();
	m_vPoints = Rotate(outPoints, m_alpha);

	double angle = calcAlpha(m_vPoints);
	//cout << "angle = " << angle << "\u00B0\n" << std::endl;
	//PrintGrid(outPoints);
	if (abs(angle-m_alpha) > 0.01) return false;
	return true;
}
