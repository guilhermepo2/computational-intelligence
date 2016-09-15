#ifndef CONFIG_HEADER
#define CONFIG_HEADER

#define DEBUG 0
#define PRINT 0
#define SAVE 0
#define SAVE_URL "results/test04.dat"

// selection
#define ROULETTE 1
#define TOURNAMENT 0

// crossover
#define CYCLIC 0
#define PMX 1

// selecao
#define REINSERTION 1
#define ELITISM 0

// sleep
#define SLEEP 0


#endif

#ifndef COMMON_INCLUDES
#define COMMON_INCLUDES

#include <vector>
#include <math.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <thread>
#include <chrono>

#endif
