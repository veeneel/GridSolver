#include "../ClassSolver.h"
#include <string>
#include <iostream>

int  main(int argc, char **argv)
{
	// Load & Validate Grid Data
	if (argc < 2)
	{
		std::cout << "Please specify an input file name\n";
		return -1;
	}
	std::string fname = std::string(argv[1]);
	PyGrid pg = PyGrid(fname);
	//std::cout << ">>> Grid Data: <<<\n" << pg;

	double alpha = pg.getAlpha();
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "Alpha = " << alpha << "\u00B0\n";

	bool bVerify = pg.bVerify();
	std::cout << std::boolalpha << "bVerify = " << bVerify << "\n";

	return 0; // success
}
