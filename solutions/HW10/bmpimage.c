#include "bmpimage.h"
// Modify all functions in this file
BMPImage *cleanUp(FILE * fptr, BMPImage * img);

#ifdef TEST_HEADERVALID

/* check whether a header is valid or not
 * assume that header has been read from fptr
 * the position of the indicator of fptr is not certain
 * could be at the beginning of the file, end of the file or
 * anywhere in the file
 * note that the check is only for this assignment
 * in general, the format is more complicated and requires more checks
 */

int Is_BMPHeader_Valid(BMPHeader* header, FILE *fptr) {
		// Make sure this is a BMP file -  magic number
  if (header->type != 0x4d42)
    {
      printf("Magic no not right");
      return FALSE;
    }
		// skip the two unused reserved fields
		// check the offset from beginning of file to image data
		// essentially the size of the BMP header
		// BMP_HEADER_SIZE for this exercise/assignment
  if (header->offset != BMP_HEADER_SIZE)
    {
      printf("offset is wrong or somethin");
      return FALSE;
    }
		// printf("header->offset %d\n",header->offset );
  printf("header->offset %d\n",header->offset );
	  // check the DIB header size == DIB_HEADER_SIZE
		// Make sure there is only one image plane
		// Make sure there is no compression
  if (header->DIB_header_size != DIB_HEADER_SIZE)
    {
      printf("dib header size is not correct");
      return FALSE;
    }
		// skip the test for xresolution, yresolution
		// ncolours and importantcolours should be 0
  if ((header->ncolours != 0) || (header->importantcolours != 0))
    {
      printf("ncolours was wrong");
      return FALSE;
    }
		// Make sure we are getting 24 bits per pixel
		// only for this assignment
  if (header->bits != 24)
    {
      printf("bits per pixel is mesed up");
      return FALSE;
    }
		// extra check for file size, image size
		// based on bits, width, and height
  
		// check out the link: https://en.wikipedia.org/wiki/BMP_file_format#Pixel_storage

  return TRUE;
}

#endif



#ifdef TEST_BMPOPENFILE

/* The input argument is the source file pointer.
 * The function returns an address to a dynamically allocated BMPImage
 * only if the file contains a valid image file
 * Otherwise, return NULL
 * If the function cannot get the necessary memory to store the image,
 * also return NULL
 * Any error messages should be printed to stderr
 */
BMPImage *cleanUp(FILE * fptr, BMPImage * img)
{
  if (fptr != NULL)
    {
      fclose (fptr);
    }
  if (img != NULL)
    {
      if (img -> data != NULL)
	{
	  free (img -> data);
	}
      free (img);
    }
  return NULL;
}

BMPImage *BMP_Open(const char *filename) {
  //open file
  //read file
	FILE *fptr = fopen(filename,"r");
	if (fptr == NULL)
	  {
	    cleanUp(fptr, NULL);
	  }
	//Allocate memory for BMPImage*;
	BMPImage *bmpImage = malloc(sizeof(BMPImage));
	//check for memory allocation errors
	if (bmpImage == NULL)
	  {
	    printf("malloc1 error inside BMP_Open failed");
	    cleanUp(fptr, bmpImage);
	  }
	//Read the first 54 bytes of the source into the header
	int read_size = fread(&(bmpImage->header), sizeof(BMPHeader), 1, fptr);
	
	//check if the header is valid
	if (!Is_BMPHeader_Valid(&(bmpImage->header), fptr) || (read_size != 1))
	  {
	    printf("Header Invalid or not reading correctly\n");
	    cleanUp(fptr, bmpImage);
	  }
	// Allocate memory for image data
	//(bmpImage->data = (unsigned char *)malloc(sizeof(unsigned char)*((int)((bmpImage->header).imagesize))))
	bmpImage->data = malloc((bmpImage->header).imagesize);
	//check error
	if (bmpImage->data == NULL)
	  {
	    printf("malloc2 error inside BMP_Open");
	    cleanUp(fptr, bmpImage);
	  }
	// read in the image data
	//check for error while reading
	int readImSize = fread(bmpImage->data, (bmpImage->header).imagesize,1, fptr);
	if (readImSize != 1)
	  {
	    printf("something failed when reading image data in bmp open");
	    cleanUp(fptr, bmpImage);
	  }
	
	fclose(fptr);
	return bmpImage;
}
#endif


#ifdef TEST_BMPWRITEFUNC
/* The input arguments are the destination file , BMPImage *image.
 * The function write the header and image data into the destination file.
 */
int BMP_Write(const char * outfile, BMPImage* image)
{
	FILE *fptr = fopen(outfile, "w");
	//open file and check for error
	if (fptr == NULL)
	  {
	    printf("fptr in bmpwrite is not working");
	    return EXIT_FAILURE;
	  }
	//check error for writing
	// write and check for image data:(fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr) != (image->header).imagesize)
	if (fwrite(& (image->header), sizeof(BMPHeader), 1, fptr) != 1)
	  {
	    fclose(fptr);
	    return EXIT_FAILURE;
	  }
	if (fwrite(image->data, (image->header).imagesize, 1, fptr) != 1)
	  {
	    printf("imwrite is messed up");
	    fclose(fptr);
	    return EXIT_FAILURE;
	  }
	
	fclose(fptr);
	return TRUE;
}

#endif
/* The input argument is the BMPImage pointer. The function frees memory of
 * the BMPImage.
 */
#ifdef TEST_BMPFREEFUNC
void BMP_Free(BMPImage* image) {
	//free image if image is true
  if (sizeof(image->data) > 0)
    {
      free(image->data);
    }
  free(image);
}

#endif

