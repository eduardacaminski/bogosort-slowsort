#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void slowSort(int v[], int i, int j){
	if(i >= j){
		printf("\nPosition %d is greater than or equal to %d, returning...", i, j);
		return;
	}
	
	int m = floor((i + j) / 2);
	printf("\nMiddle position of the array is %d", m);
	
	printf("\n@@@@@Now sorting the first half... [%d - %d] ...", i, m);
	slowSort(v, i, m);
	
	printf("\n@@@@@Now sorting the second half... [%d - %d] ...", m+1, j);
	slowSort(v, m+1, j);
	
	int temp;
	
	if(v[j] < v[m]){
		printf("\n/////Swapping %d and %d...", v[j], v[m]);
		temp = v[j];
		v[j] = v[m];
		v[m] = temp;
	}
	
	printf("\n@@@@@Now sorting the rest...");
	slowSort(v, i, j-1);
}

int main(){
	int vetor[10] = {1, 3, 4, 2, 93, 32, 496, 12, 4, 5};
	
	printf("Initial vector = [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n\n", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4], vetor[5], vetor[6], vetor[7], vetor[8], vetor[9]);
	
	slowSort(&vetor, 0, 9);
	
	printf("\n\n\nResulting vector = [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]", vetor[0], vetor[1], vetor[2], vetor[3], vetor[4], vetor[5], vetor[6], vetor[7], vetor[8], vetor[9]);
	
	return 0;
}
