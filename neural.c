// neural network matlab code translated to c

#include <stdio.h>

int main(){

	// Arrays for 1st, 2nd and 3rd layer
	int Z1[200] = {0};	// 200 elements
	int Z2[200] = {0};	// 200 elements
	int Z3[10] = {0};	// 10 elements

	int singleB1L1[200];
	int singleB1L2[200];	
	int singleSoftmaxTheta[200][10];
	int singleW1L1[784][200];	// weight 1, level 1
	int singleW1L2[200][200];	// weight 1, level 2

	int k;


	for(k = 0;k < 200; k++){

