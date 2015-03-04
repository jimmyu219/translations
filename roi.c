// C version of roi.m
// Finds region of interest from input image

# include <stdio.h>
# include <math.h>
# include <iostream.h>
# include <fstream.h>


// ------------------------------------------
// Get white projector image
// ------------------------------------------
int main(){
	int imgTop, imgBot, imgLeft, imgRight;	
	int imgROWS, imgCOLS;
	int row, row_max;
	int col, col_max;
	
	// Get image
	

	// Get image dimensions


	// Create edge buffer of 10%
	imgTop = round(imgROWS * .1);
	imgBot = imgROWS - imgTop;
	imgLeft = round(imgCOLS * .1);
	imgRight = imgCOLS - imgLeft;



	// generate summations of rows and cols
	// this generates a numROWS x 1 matrix of the sum of all rows



	// This generates a 1 x numCOLS matrix of the sum of all cols



	// Normalize rows and cols
	row = row/row_max;
	col = col/col_max;	

	
	// Convert to binary to show light distribution
	// All pretty black areas will be represented by 0's
	// All white areas will be 1's
	


	// Get array where row_ind(1) == first part of white area
	// row_ind(end) should be the end of the projector area
	

	// Get array where col_ind(1) == first part of white area
	// col_ind(end) should be the end of the projector area
	
	// Create crop, region of the projector
	
	// Get cropped image dimensions
	
	// Create edge buffer of 10%
	cropTop = round(cropROWS * .1);
	cropBot = cropROWS - cropTop;
	cropLeft = round(cropCOLS * .1);
	cropRight = cropCOLS - cropLeft;

	// New image with 5% edge buffer
	

	// --------------------------------------------------
	// Get Black ROI image
	// --------------------------------------------------
	
	// Generate summations of rows and cols
	// This generated a matrix of the sum of all rows
	


	// This generates a matrix of the sum of all cols
	
	// Normalize row and col
	
	row = row/row_max;
	col = col/col_max;

	// Convert to binary 
	
	// Invert bits
	row = ~row;
	col = ~col;

	// Get array where row_ind(1) == first part of white area
	// row_ind(end) should be the end of the projector area
	


	// Get array where col_ind(1) == first part of white area
	// col_ind(end should be the end of the projector area
	


	// Create crop, region of the projector
	

	
	// Get cropped image dimensions
	


	// Create edge buffer of 5%
	


	// New image with 5% edge buffer
	


	// Show final ROI
	



	return 0;
}
