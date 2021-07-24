double PyGrid::calcAlpha(vector<Point>& v)
{
	vector<Point> tmp;
#if 0
	// Note: Before rotation, the origin must be moved back to (0,0)
	std::pair<double, double> xyOff = calcOffsets(m_vPoints);
	std::cout << "{xOff, yOff} = {" << xyOff.first << ", " << xyOff.second << "}\n" << std::endl;

	auto shift = [xyOff](const Point& pt)
	{
		double x = pt.x - (xyOff.first > 0) ? xyOff.first : -xyOff.first;
		double y = pt.x - (xyOff.second > 0) ? xyOff.second : -xyOff.second;

		return Point(x, y);
	};
	std::transform(m_vPoints.begin(), m_vPoints.end(), back_inserter(tmp), shift);
#else
	copy(v.begin(), v.end(), back_inserter(tmp));
#endif

	// determine "X" Corner points
	sort(tmp.begin(), tmp.end(), sortMajorD());
	xyLB = tmp[0];
	xyRT = tmp[tmp.size() - 1];

	// slope of minor-Diagonal
	double minorAngle = atan2(xyRT.y - xyLB.y, xyRT.x - xyLB.x) * 180.0 / MY_PI;
	//	cout << "minorAngle = " << minorAngle << " degrees. " << endl;

	// determine "Y" Corner points
	sort(tmp.begin(), tmp.end(), sortMinorD());
	xyLT = tmp[0];
	xyRB = tmp[tmp.size() - 1];

	// slope of major-Diagonal
	double majorAngle = atan2(xyLT.y - xyRB.y, xyLT.x - xyRB.x) * 180.0 / MY_PI;
	//	cout << "majorAngle = " << majorAngle << " degrees. " << endl;

	double alpha = ((minorAngle + majorAngle) / 2); // bisector of diagnols
	// report in range [0, 45.0]
	alpha = 45.0 + std::fmod(alpha, 45.0);
	if (alpha == 45.0) alpha = 0.0;

	return alpha;
}
