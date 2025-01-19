#include <iostream>

#include "logger.hpp"
#include "window.hpp"

using namespace icuray;

auto main(int argc, char** argv) -> int
{
	if (argc < 2) {
		std::cerr << "No log file defined!" << '\n';
		return -1;
	}

	Logger logger(argv[1]);
	logger.log_info("App started.");

	Window window;
	window.initialize();
	window.draw();

	logger.log_info("App ended.");

	return 0;
}
