// ***
// *** Please modify this file, as indicated
// ***

#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "sort.h"


void printArray(int * arr, int size)
{
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      fprintf(stdout, "%d\n", arr[ind]);
    }
}



//============================ONLY EDIT BELOW THIS COMMENT============================//
#ifdef TEST_COMP
int comparator(const void *a, const void *b)
{
    //type cast both the parameters to the type const int*) a:
	//FOR EXAMPLE: const int* ia = (const int *) a;

    	//if parameter2 > parameter1; return -1
	//if parameter2 == parameter1; return 0
	//if parameter2 < parameter1; return 1
	const int *ia = (const int *)a;
	const int *ib = (const int *)b;

	if (ia < ib)
    {
        return -1;
    }
    else if (*ia == *ib)
    {
        return 0;
    }
    else if (*ia > *ib)
    {
        return 1;
    }
    else
    {
        return EXIT_FAILURE;
    }
}
#endif


#ifdef TEST_COUNT
int countFromFile(char* file_name)
{
    FILE * fptr;
    int count;
    int dump;
  // open file to read
    fptr = fopen(file_name, "r");
  // count the number of integers using a loop
  // at the end of the loop close file_pointer
    if (fptr == NULL)
    {
        printf("fopen failed.\n");
        return EXIT_FAILURE;
    }
    count = 0;
    while (fscanf(fptr, "%d", & dump) == 1)
    {
        count += 1;
    }
    fclose(fptr);
    return count;
}
#endif

#ifdef TEST_FILL
void fillArray(int* arr, int count, char* file_name)
{
    FILE * fptr;
  // open file to read
    fptr = fopen(file_name, "r");
  //How to read the file?
	// run a loop, from index = 0 to "count", and use: fscanf(file_pointer, "%d", &arr[index]);
	// at the end of the loop close file_pointer
    for (int i = 0; i < count; i++)
    {
      fscanf(fptr, "%d", &arr[i]);
    }
    fclose(fptr);
}
#endif

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  // input file will be specified from the terminal - test files are made available in inputs folder
  // check for missing input file, if so, "return EXIT_FAILURE;"
    if (argc < 2)
    {
        printf("No file specified.\n");
        return EXIT_FAILURE;
    }
  // use argv[1] to save the file name, you will use this file name to call the countFromFile(), and fillArray() functions
      //FOR EXAMPLE: char* file_name = argv[1];
    char * fileName = argv[1];

  // call the countFromFile(file_name); and store the number of elements in the file.
    int count;
    count = countFromFile(fileName);
  // allocate memory to store the numbers (initialize an array)
    int * arr = malloc(sizeof(int) * count);
  // check for malloc fail, if so, "return EXIT_FAILURE;"
    if (arr == NULL)
    {
      fprintf(stderr, "malloc failed.\n");
      return EXIT_FAILURE;
    }
  // call the fillArray(arr, count, file_name); and store the values from the file in the array.
    fillArray(arr, count, fileName);
  // Use qsort() function, after defining the comparator() function - "qsort (arr, count, sizeof(int), comparator);"
    qsort (arr, count, sizeof(int), comparator);
  // call the printArray() function provided to you.
    printArray(arr, count);

  return EXIT_SUCCESS;
}
#endif

