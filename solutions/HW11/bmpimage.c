#include "bmpimage.h"
//Include your own code from HW10 and modify this file
#ifdef TEST_HEADERVALID

BMPImage *cleanUp(FILE * fptr, BMPImage * img);

int Is_BMPHeader_Valid(BMPHeader* header, FILE *fptr) {
  if (header->type != 0x4d42)
    {
      printf("Magic no not right");
      return FALSE;
    }

  if (header->offset != BMP_HEADER_SIZE)
    {
      printf("offset is wrong or somethin");
      return FALSE;
    }

  printf("header->offset %d\n",header->offset );

  if (header->DIB_header_size != DIB_HEADER_SIZE)
    {
      printf("dib header size is not correct");
      return FALSE;
    }

  if ((header->ncolours != 0) || (header->importantcolours != 0))
    {
      printf("ncolours was wrong");
      return FALSE;
    }

  if (header->bits != 24)
    {
      printf("bits per pixel is mesed up");
      return FALSE;
    }

  return TRUE;
}

#endif

#ifdef TEST_BMPOPENFILE

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

	FILE *fptr = fopen(filename,"r");
	if (fptr == NULL)
	  {
	    cleanUp(fptr, NULL);
	  }

	BMPImage *bmpImage = malloc(sizeof(BMPImage));
	if (bmpImage == NULL)
	  {
	    printf("malloc1 error inside BMP_Open failed");
	    cleanUp(fptr, bmpImage);
	  }
	
	int read_size = fread(&(bmpImage->header), sizeof(BMPHeader), 1, fptr);
	
	if (!Is_BMPHeader_Valid(&(bmpImage->header), fptr) || (read_size != 1))
	  {
	    printf("Header Invalid or not reading correctly\n");
	    cleanUp(fptr, bmpImage);
	  }

	bmpImage->data = malloc((bmpImage->header).imagesize);

	if (bmpImage->data == NULL)
	  {
	    printf("malloc2 error inside BMP_Open");
	    cleanUp(fptr, bmpImage);
	  }

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


#ifdef TEST_WRITEFUNC

int BMP_Write(const char * outfile, BMPImage* image){
	FILE *fptr = fopen(outfile, "w");

	if (fptr == NULL)
	  {
	    printf("fptr in bmpwrite is not working");
	    return EXIT_FAILURE;
	  }

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
  if (sizeof(image->data) > 0)
    {
      free(image->data);
    }
  free(image);
}

#endif
