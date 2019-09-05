#include "bmpfunc.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef TEST_FUNCGIVEN

int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue){
	// this is a commonly used formula
	int gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return gray;
}

#endif

//Modify below this line and use code from HW10 for IMGTOGRAY()

#ifdef TEST_IMGTOGRAY

BMPImage * ImgToGray(BMPImage * image){

  BMPImage *gray_image = (BMPImage *)malloc(sizeof(BMPImage));
	if (gray_image == NULL)
	  {
	    printf("malloc1 error inside image to gray failed");
	    return NULL;
	  }
	gray_image->header = image->header;
	gray_image->data = malloc((image->header).imagesize);
	if (gray_image->data == NULL)
	  {
	    printf("gray image data malloc failed");
	    return NULL;
	  }
	int pixel=0;
	int gray_val;
	for (pixel = 0; pixel < (image->header).imagesize; pixel += 3)
	  {
	    gray_val = RGB2Gray(image->data[pixel+2], image->data[pixel + 1], image->data[pixel]);
	    gray_image->data[pixel+2] = gray_val;
	    gray_image->data[pixel+1] = gray_val;
	    gray_image->data[pixel] = gray_val;
	  }
		
        return gray_image;
}

#endif

//Write your own code for Adaptive Thresholding Function
#ifdef TEST_ADAPTIVETHRESHOLDING

BMPImage * AdaptiveThresholding(BMPImage * grayImage, int radius, int epsilon){
 	// allocate space for the image
	// the image has the same size(height and width)
	// therefore the header has to stay the same
        BMPImage *adaptive = (BMPImage *)malloc(sizeof(BMPImage));
	adaptive->header = grayImage->header;
	// (gray_image->header).imagesize = (gray_image->header).width*(gray_image->header).height;
	if ((adaptive->data = malloc(sizeof(unsigned char)*(adaptive->header).imagesize)) == NULL) {
		fprintf(stderr, "Error allocating memory\n");
		free(adaptive);
		return NULL;
	}

	int pixel=0;
        int numberOfPixels=0;
	//Run a nested loop for all elements using height and width
        //Find the maximum of top row, bottom rpw, left column and right column using radius
	/*int toprow = MAX(0, row-radius);
     	 int bottomrow = MIN(height-1, row+radius);
     	 int leftcol = MAX(0, col-radius);
     	 int rightcol = MIN(width-1, col+radius);*/
    	//Calculate the avergage of all pixels
	//Run loop from toprow to bottom row
	//Inside which run a loop from left column to right column
		//calculate the location of each pixel using (row2*width + col2)*3;
         	//add all data values at every location point in data
		//keep a counter for averaging
	//Outside the second nested loop: 
	//calculate averge (using int)
	//check if average-epsilon is greater than grayImage->data[at that pixel point]
	//then assign adaptive thresholding image data as 0(black) for data value at pixel, pixel+1, pixel+2
	int upperLeftRow;
     	int upperLeftCol;
     	int lowerRightRow;
     	int lowerRightCol;
	int totalSum = 0;
	int average = 0;
	for (int row = 0; row < (adaptive->header).height; row++){
	  for (int col = 0; col < (adaptive->header).width; col++)
	    {
	      upperLeftRow = row - radius;
	      upperLeftCol = col - radius;
	      lowerRightRow = row + radius;
	      lowerRightCol = col + radius;
	      if (upperLeftRow < 0)
		upperLeftRow = 0;
	      if (upperLeftCol < 0)
		upperLeftCol = 0;
	      if (lowerRightRow > ((adaptive->header).height-1))
		lowerRightRow = (adaptive->header).height-1;
	      if (lowerRightCol > ((adaptive->header).width-1))
		lowerRightCol = (adaptive->header).width-1;
	      
	      totalSum = 0;
	      numberOfPixels = 0;
	      for (int rowa = upperLeftRow; rowa < (lowerRightRow+1); rowa++){
		for (int cola = upperLeftCol; cola < (lowerRightCol+1); cola++)
		  {
		    pixel = (rowa*(adaptive->header).width + cola)*3;
		    totalSum += grayImage->data[pixel];
		    numberOfPixels += 1;
		  }
	      }
	      pixel = (row*(adaptive->header).width + col)*3; //here
	      average = (totalSum / numberOfPixels) - epsilon;
	      if (grayImage->data[pixel] < average)
		{
		  adaptive->data[pixel+2] = 0;
		  adaptive->data[pixel+1] = 0;
		  adaptive->data[pixel] = 0;
		}
	      else
		{
		  adaptive->data[pixel+2] = 255;
		  adaptive->data[pixel+1] = 255;
		  adaptive->data[pixel] = 255;
		}
		  
	    }
	}
	
        // else if average is lower then color shall be white(255) for data value at pixel, pixel+1, pixel+
//return the image after adaptive thresholding
	return adaptive;
}


#endif
