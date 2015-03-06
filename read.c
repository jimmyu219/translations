# include <stdio.h>


int main(){

	FILE *file = fopen("img17.txt", "r");
	int img[480][640];
	int rows_sum[480] = {0};
	int cols_sum[640] = {0};
	int rows_binary[480] = {0};
	int cols_binary[640] = {0};
	int cols=0, rows=0;
	int col_max = 0, cols_avg = 0;
	int row_max = 0, rows_avg = 0;
	int rows_level = 0;
	int cols_level = 0;

	// Generate image in an array
	// sum rows and cols in arrays
	for (cols = 0; cols < 640; cols++) {
		for (rows = 0; rows < 480; rows++) {
			fscanf(file, "%d", &img[rows][cols]);
			cols_sum[cols] += img[rows][cols];
			rows_sum[rows] += img[rows][cols];
		}
	}

	// Find row_max and col_max
	// Calculate row_avg and col_avg
	for (cols = 0; cols < 640; cols++) {
		
		cols_avg += cols_sum[cols];

		if (col_max < cols_sum[cols])
			col_max = cols_sum[cols];
	}
	cols_avg = cols_avg/640;
		

	for (rows = 0; rows < 480; rows++) {
		rows_avg += rows_sum[rows];

		if (rows_max < rows_sum[rows])
			rows_max = rows_sum[rows];
	}
	rows_avg = rows_avg/480;


	// Generate levels for im2bw
	cols_level = (cols_max + cols_avg)/2;
	rows_level = (rows_max + rows_avg)/2;

	// Make im2bw arrays for rows and cols
	for (cols = 0; cols < 640; cols++) {
		if (cols_level <= cols_sum[cols])
			cols_binary[cols] = 1;
		else if (cols_level > cols_sum[cols])
			cols_binary[cols] = 0;
	}
		

	for (rows = 0; rows < 480; rows++) {
		if (rows_level <= rows_sum[rows])
			rows_binary[rows] = 1;
		else if (rows_level > rows_sum[rows])
			rows_binary[rows] = 0;
	}




	fclose(file);
	for (cols = 0; rows < 640; cols++) {
		printf("\n");
		for (rows = 0; rows < 480; rows++) {
			printf("%d ", img[rows][cols]);
		}
		printf("\n");
	}
	


	return 0;
}
