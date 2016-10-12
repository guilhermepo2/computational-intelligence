#ifndef CONFIG_HEADER
#define CONFIG_HEADER

#define DEBUG 0
#define DEBUG_PMX 1
#define PRINT 0
#define PRINT_ESSENTIAL 1
#define SAVE 0
#define SAVE_URL "results/test04.dat"

// selection
#define ROULETTE 1
#define TOURNAMENT 0

// crossover
#define CYCLIC 0
#define PMX 1

// selecao
#define REINSERTION 0
#define ELITISM 1

// sleep
#define SLEEP 0

// fitness
#define REGULAR_FITNESS 1

// other options
#define MUTATE_ONLY_IF_BETTER 0
#define CROSSOVER_ONLY_BETTER 0


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
