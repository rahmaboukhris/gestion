#pragma once

#define MAP 0
// Define a log function witch exists only if MAP == 1
#if MAP == 1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)	
#endif
