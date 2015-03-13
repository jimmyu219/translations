// converting roi.m to roi.c

//#pragma warning (disable : 4996)
# include <stdio.h>
int img[480][640];
int binary[480][640];
int rows_Sum[480] = { 0 };
int binary_rows_Sum[480] = { 0 };
int cols_Sum[640] = { 0 };
int binary_cols_Sum[640] = { 0 };
int cols = 0;
int rows = 0;
int rows_level = 0;
int cols_level = 0;
int rows_index_beg, rows_index_end;
int cols_index_beg, cols_index_end;
int i = 0, j = 0;

int main(){
	
	rows_level = 255 * 0.6;
	cols_level = 255 * 0.6;

	FILE *file = fopen("./image2.txt", "r");
	if (file == NULL)
	{
		printf("ERROR!");
		return(1);
	}

	
	 //Generate image in an array
	for (rows = 0; rows < 480; rows++){
		 for (cols = 0; cols < 640; cols++) {
			fscanf(file, "%d", &img[rows][cols]);
		}
	}
	fclose(file);
	
	
	//add up the rows
	for (rows = 0; rows<480; rows++)
	{
		for (cols = 0; cols<640; cols++)
		{
			rows_Sum[rows] += img[rows][cols];
		}
	}

	//based on the sum come up with binary to find the index
	for (rows = 0; rows<480; rows++)
	{
		if (rows_Sum[rows]>89000)
		{
			binary_rows_Sum[rows] = 1;
		}
		else
		{
			binary_rows_Sum[rows] = 0;
		}

	}

	//scan for begin index
	for (j = 0; j < 480; j++)
	{
		if (binary_rows_Sum[j] == 0 && binary_rows_Sum[j-1]== 1)
		{
			rows_index_beg = j;
			break;
		}
	}

	//scan for end index
	for (j = 479; j>0; j--)
	{
		if (binary_rows_Sum[j] == 0 && binary_rows_Sum[j+1]== 1)
		{
			rows_index_end = j;
			break;
		}
	}

	FILE *file2 = fopen("./image1.txt", "r");
	if (file2 == NULL)
	{
		printf("ERROR!");
		return(1);
	}

	
	 //Generate image in an array
	for (cols = 0; cols<640; cols++){
		for (rows = 0; rows<480; rows++){
			fscanf(file, "%d", &img[rows][cols]);
			
		}
	}
	fclose(file2);


	//add up the columns
	for (cols = 0; cols<640; cols++)
	{
		for (rows = 0; rows<480; rows++)
		{
			cols_Sum[cols] += img[rows][cols];
//			printf("cols_sum: %d\n", cols_Sum[cols]);
		}

	}
	
	

	//hardcoding the value only work for this sample
	//base on the sum come up with binary to find the index
	for (cols = 0; cols<640; cols++)
	{
		if (cols_Sum[cols]>79000)
		{
			binary_cols_Sum[cols] = 1;
		}
		else
		{
			binary_cols_Sum[cols] = 0;
		}
	}

	for (cols = 0; cols<640; cols++)
	{
		printf("%d ", binary_cols_Sum[cols]);
	}

	//find the index that has 0
	for (i = 0; i < 640; i++)
	{
		if (binary_cols_Sum[i] == 0 && binary_cols_Sum[i-1] == 1)
		{
			cols_index_beg = i;
			break;
		}
	}

	//scan for the end
	for (i = 639; i > 0; i--)
	{
		if (binary_cols_Sum[i] == 0 && binary_cols_Sum[i+1] == 1)
		{
			cols_index_end = i;
			break;
		}
	}

	

	//use the index to get the region of interest

	int sizeCol = cols_index_end - cols_index_beg;
	int sizeRow = rows_index_end - rows_index_beg;

	int ROIimg[] = {0};

	printf("\n\nsizeCol = %d\n", sizeCol);
	printf("sizeRow = %d\n", sizeRow);

	for (i = cols_index_beg; i<cols_index_end; i++) {
		for (j = rows_index_beg; j<rows_index_end; j++)
		{
			printf("%d ", img[j][i]);	// img[rows][cols]
		}
	}

	printf("\n\nrows_begin:%d\nrows_end:%d\ncols_beg:%d\ncols_end:%d\n\n", rows_index_beg, rows_index_end, cols_index_beg, cols_index_end);
//	printf("%d\n", img[rows_index_beg][cols_index_beg]);
//	printf("%d\n", img[rows_index_end][cols_index_end]);
	

	FILE *file3 = fopen("write1.txt", "w");
	if (file3 == NULL){
		printf("Error opening text file.\n");
		return(1);
	}


	// print img matrix array
	// should be just the black box with the digit
	for (i=cols_index_beg; i<cols_index_end; i++) {
	//	fprintf(file3,"\n");
		for (j=rows_index_beg; j<rows_index_end; j++) {
			fprintf(file2, "%d ", img[j][i]);
		}
	//	fprintf(file3,"\n");
	}
	
	fclose(file3);

	return 0;
}
