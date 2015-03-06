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
	int finalROWS, finalCOLS;
	int finalTop, finalBot, finalLeft, finalRight;
	

	FILE *file = fopen("img17.txt", "r");
	int image[307200];	// 480 x 640
	int i=0;
	int j=0;
	int k=0;
	int num;

	// Get image
	while(fscanf(file, "%d", &num) == 1) {
		image[i] = num;
		i++;
		if(image[i] == ' '){
			imgCOLS = j;
			j++;
		else if(image[i] == '\n'){
			imgROWS = k;
			k++;
		}
			
	}
	fclose(file);
//	Debugging reading text file
	printf("%d\n", imgCOLS);	// should be 640 columns
	printf("%d\n", imgROWS);	// should be 480 rows
//	printf("%d", image);
	

/*
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
	row_level = ((row_max+row_avg)/2)/row_max;
//	row = im2bw(row, row_level);
	if (row >= row_level){
		row = 1;
	}
	else if (row < row_level){
		row = 0;
	}
	
	col_level = ((col_max+col_avg)/2)/col_max;
//	col = im2bw(col, col_level);
	if (col >= col_level){
		col = 1;
	}
	else if (col < col_level){
		col = 0;
	}

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
	
*/
	// --------------------------------------------------
	// Get Black ROI image
	// --------------------------------------------------
	
	// Generate summations of rows and cols
	// This generated a matrix of the sum of all rows
//	row = sum(crop, 2);

	row_max = max(row);
	row_avg = mean(row);

	// This generates a matrix of the sum of all cols
//	col = sum(crop, 1);
	col_max = max(col);
	col_avg = mean(col);	

	// Normalize row and col
	
	row = row/row_max;
	col = col/col_max;

	// Convert to binary
	if (row >= 0.9){
		row = 1;
	}im2bw
	else if (row < 0.9){
		row = 0;
	}

	if (col >= 0.9){
		col = 1;
	}
	else if (col < 0.9){
		col = 0;
	}

	
	// Invert bits
	row = ~row;
	col = ~col;

	// Get array where row_ind(1) == first part of white area
	// row_ind(end) should be the end of the projector area
//	row_indices = find(row);	


	// Get array where col_ind(1) == first part of white area
	// col_ind(end should be the end of the projector area
//	col_indices = find(col);	


	// Create crop, region of the projector
//	final = crop(row_indices(1):row_indices(end), col_indices(1):col_indices(end));	

	
	// Get cropped image dimensions
	


	// Create edge buffer of 5%
	finalTop = round(finalROWS * 0.05);
	finalBot = finalROWS - finalTop;
	finalLeft = round(finalCOLS * 0.025);
	finalRight = finalCOLS - finalLeft;



	// New image with 5% edge buffer
//	final = final(finalTop:finalBot, finalLeft:finalRight);


	if (final >= 0.85){
		final = 1;
	}
	else if (final < 0.85){
		final = 0;
	}

	// Show final ROI
//	imshow(final);	



	return 0;
}
