#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define POPULATION_SIZE 100

/*
  SEND + MORE = MONEY
  
  candidate -> vector with 8 elements, each one representing the value of a character (in order: s e n d m o r y), the value of each character should be one that satisfies send + more = money

 */

/*
  VECTOR:
  0 1 2 3 4 5 6 7
  S E N D M O R Y
 */
typedef struct
{
  int vet[8];
  int fitness;
} solution;

void calculate_fitness(solution sol[])
{
  int i;
  for(i = 0; i < POPULATION_SIZE; i++)
    {
      sol[i].fitness = ((sol[i].vet[0]*1000 +  // S
			 sol[i].vet[1]*100 +   // E
			 sol[i].vet[2]*10 +    // N
			 sol[i].vet[3])        // D
			+
			(sol[i].vet[4]*1000 +  // M
			 sol[i].vet[5]*100+    // O
			 sol[i].vet[6]*10+     // R
			 sol[i].vet[1])        // E
			-
			(sol[i].vet[4]*10000 + // M
			 sol[i].vet[5]*1000 +  // O 
			 sol[i].vet[2]*100 +   // N
			 sol[i].vet[1]*10 +    // E
			 sol[i].vet[7]));      // Y
      sol[i].fitness = labs(sol[i].fitness);
    }
}

void tournment_selection(solution sol[])
{
  printf("Selecting three candidates\n");
  int c1 = rand() % POPULATION_SIZE;
  int c2 = rand() % POPULATION_SIZE;
  int c3 = rand() % POPULATION_SIZE;

  printf("Selecteds:\n");
  printf("Candidate1: %d with fitness %d\n", c1, sol[c1].fitness);
  printf("Candidate2: %d with fitness %d\n", c2, sol[c2].fitness);
  printf("Candidate2: %d with fitness %d\n", c3, sol[c3].fitness);
}

solution random_candidate()
{
  solution s;
  int i;
  int myVet[10] = {0,0,0,0,0,0,0,0,0,0};
  
  for(i = 0; i < 8; i++)
    {
      int choice = (rand() % 10);
      if(myVet[choice] == 0)
	{
	  myVet[choice] = 1;
	  s.vet[i] = choice;
	}
      else // random number already exist on my candidate
	{
	  i--;
	}
    }

  return s;
}

void print_candidates(solution sol[])
{
  int i;
  for(i = 0; i < POPULATION_SIZE; i++)
    {
      printf("Candidate: %d %d %d %d %d %d %d %d\n",
	     sol[i].vet[0],
	     sol[i].vet[1],
	     sol[i].vet[2],
	     sol[i].vet[3],
	     sol[i].vet[4],
	     sol[i].vet[5],
	     sol[i].vet[6],
	     sol[i].vet[7]);
      printf("Fitness: %d\n", sol[i].fitness);
    }
}

void bubble_sort(solution sol[])
{
  solution s;
  int i, j;
  for(i = 0; i < POPULATION_SIZE; i++)
    {
      for(j = 0; j < POPULATION_SIZE; j++)
	{
	  if(sol[i].fitness < sol[j].fitness)
	    {
	      s = sol[i];
	      sol[i] = sol[j];
	      sol[j] = s;
	    }
	}
    }
}

int main()
{
  srand(time(NULL));
  // generate POPULATION_SIZE random solutions
  solution sol[POPULATION_SIZE];
  int i;
  for(i = 0; i < POPULATION_SIZE; i++)
    {
      sol[i] = random_candidate();
    }
  //calculate fitness
  calculate_fitness(sol);
  //test tournment selection
  tournment_selection(sol);
  //sort
  bubble_sort(sol);
  // print candidates
  print_candidates(sol);
  
  return 0;
}
