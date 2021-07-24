// cin with strings
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

using pd = std::pair<double, double>;
vector<pd> vPoints;

int main()
{
	int gridSize = 4;
#ifdef PROMPT
	cout << "The Grid has NxN points. Enter a value for N=[1,10]: ";
	cin >> gridSize;
	if (gridSize < 1 || gridSize > 10)
	{
		gridSize = 5;
		cout << "Invalid input. Defaults to 5x5 grid." << endl;
	}
#endif

	double xOffset = 10.0, yOffset= 10.0;
#ifdef PROMPT
	cout << "The grid's left, bottom corner defaults to (0.0, 0.0). To change this," << endl;
	cout << "specify an X offset, in the [-20.0, 10.0] range: ";
	cin >> xOffset;
	if ((xOffset < -20.0) || (xOffset > 10.0))
	{
		xOffset = 0.0;
		cout << "Invalid X input. Defaults to 0.0." << endl;
	}
	cout << "specify an Y offset, in the [-20.0, 10.0] range: ";
	cin >> yOffset;
	if ((yOffset < -20.0) || (yOffset > 10.0))
	{
		yOffset = 0.0;
		cout << "Invalid Y input. Defaults to 0.0." << endl;
	}
#endif

	double gridDelta = 0.1;
#ifdef PROMPT
	cout << "The Grid's spacing defaults to 1.0,"
		 << "so length of X- andY-Axes are 4.0 units for default 5x5 grid." << endl;
	cout << "To change this, specify an gridDelta, in the [0.1, 1.0] range: ";
	cin >> gridDelta;
	if ((gridDelta < 0.0) || (gridDelta > 1.0))
	{
		gridDelta = 1.0;
		cout << "Invalid X input. Defaults to 0.0." << endl;
	}
#endif

	double angle = 40.0;
#ifdef PROMPT
	cout << "The Grid axes align with those of the window."
		 << "To change this," << endl;
	cout << "Specify an angle of rotation, in degrees, in the [-90.0,+90.0] range:";
	cin >> angle;
	if ((angle < -90.0) || (angle > 90.0))
	{
		angle = 0.0;
		cout << "Invalid Angle input. Defaults to 0.0." << endl;
	}
#endif

	string fname = "Data0";
#ifdef PROMPT
	cout << "The default file name is 'grid_data.txt'. To change this," << endl;
	cout << "Specify a file name (ignore the '.txt' part): ";
	cin >> fname;
#endif

	ofstream outfile;
	outfile.open(string(fname + ".txt"));
	outfile << setprecision(4) << fixed;

	double sqSize = gridDelta * (gridSize - 1); // #intervals is 1 less than #points
	double xStart = -sqSize/2; // left most column
	double yStart = sqSize/2; // top most row

	double pi = atan2(1.0, 1.0) * 4; // tan(90deg) = 1.0
	angle *= (pi / 180.0); // convert to radians
	// Generate the grid
	for (int row = 0; row < gridSize; ++row)
	{
		double y = yStart - row * gridDelta;
		for (int col = 0; col < gridSize; ++col)
		{
			double x = xStart + col * gridDelta;
			double x1 = x * cos(angle) - y * sin(angle) + sqSize/2 + xOffset;
			double y1 = x * sin(angle) + y * cos(angle) + sqSize/2 + yOffset;
			vPoints.push_back(make_pair(x1, y1));
			outfile << x1 << "," << y1 << endl;
		}
	}
	outfile.close();

	return 0;
}
