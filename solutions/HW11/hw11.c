#include "hw11.h"
//Modify this file
#ifdef TEST_MAIN

int main(int argc, char **argv){
  // check the arguments - please read readme about validity of arguments
  if (argc != 5)
    {
      printf("Wrong arguments\n");
      return EXIT_FAILURE;
    }
  // check radius and epsilon values -  read readme for the validity of argument
  int radius = atoi(argv[3]);
  int epsilon = atoi(argv[4]);

  //check radius and epsilon print Wrong arguments\n
  
  // open the BMP file
  BMPImage * image = BMP_Open(argv[1]);
  // convert to gray scale
	// check for error in converting to gray scale
  BMPImage * gray_image = ImgToGray(image);
  if (gray_image == NULL)
    {
      printf("gray img returned NULL\n");
      return EXIT_FAILURE;
    }
  // call adaptive threshold function
  BMPImage * adaptive = AdaptiveThresholding(gray_image, radius, epsilon);
  // check for errors after calling adaptive threshold
  if (adaptive == NULL)
    {
      printf("adaptive returned NULL\n");
      return EXIT_FAILURE;
    }
    // write the adaptive threshold image to file
  if (!BMP_Write(argv[2], adaptive))
    {
      printf("bmp write failed\n");
        BMP_Free(image);
	BMP_Free(gray_image);
	BMP_Free(adaptive);
	return EXIT_FAILURE;
    }
	// free all the images
  BMP_Free(image);
  BMP_Free(gray_image);
  BMP_Free(adaptive);
  
  return EXIT_SUCCESS;
}

#endif
