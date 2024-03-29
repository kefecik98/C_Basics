//
// MODIFY THIS FILE AS DIRECTED
//
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "vector.h"



#ifdef TEST_COMP
int cmp(const void *a, const void *b) 
{ 
        //typecast the inputs into Vector * form.
        //For example: Vector *typecasted_b = (Vector *)b;
    Vector * va = (Vector *)a;
    Vector * vb = (Vector *)b;
    
    //compare typecased_a->x and typecasted_b->x, and return appropriate values.
    if (va->x < vb->x)
    {
        return -1;
    }
    else if (va->x == vb->x)
    {
        return 0;
    }
    return 1;
} 
#endif

#ifdef TEST_COUNT
int numberOfElements(char* in_file_name)
{
    //initialize file_pointer, and open file in read mode.
        //Please note that we are working with binary files.
    FILE * bfp = fopen(in_file_name, "r");
    
    //use fseek(file_pointer, 0, SEEK_END); to point to the end of the file.
    fseek(bfp, 0, SEEK_END);
    
    //use long where = ftell(file_pointer); to get the size of the file.
    int where = ftell(bfp);
    
    //use float numelem = where / sizeof(Vector); to obtain the number of elements
    float numelem = where / sizeof(Vector);
    
    //return numelem; to send the number of elements back to main().
    return numelem;
}
#endif

#ifdef TEST_FILL
void fillVector(Vector* vector, int count, char * in_file_name)
{
    // open binary file to read after initializing file_pointer
    FILE * bfp = fopen(in_file_name, "r");
    
    //How to read the file?
    //use fread(vector, sizeof(Vector), count, file_pointer)
    fread(vector, sizeof(Vector), count, bfp);
}
#endif

#ifdef TEST_WRITE
void writeFile(Vector* vector, int count, char* out_file_name)
{
    // open binary file to write after initializing file_pointer
    FILE * bfp = fopen(out_file_name, "w");
    
    //How to write to the file?
    //use fwrite(vector, sizeof(Vector), count, file_pointer)
    fwrite(vector, sizeof(Vector), count, bfp);
}
#endif
