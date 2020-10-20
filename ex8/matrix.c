/* 행렬
 * matrix.c
 */
#include <stdio.h>
#include <stdlib.h>

void input( int **m , int first , int second);
void output( int **m , int first , int second);

int main(int args , int argv[])
{
	int a , b;
	int first , second;
	printf("행 입력 : ");
	scanf(" %d", &first);

	printf("열 입력 : ");
	scanf(" %d", &second);
	int **d_array = malloc(sizeof(int *) *first);
	int **c_array = malloc(sizeof(int *) *first);
	int **out = malloc(sizeof(int *) *first);

	for(a=0 ; a<first ; a++){
		d_array[a]=malloc(sizeof(int) *second);
		c_array[a]=malloc(sizeof(int) *second);
		out[a]=malloc(sizeof(int) *second);
	}

	printf("첫 번째 행렬 : \n");
	input(d_array, first, second);
	output(d_array , first , second);
	printf("\n\n");
	
	printf("두 번째 행렬 : \n");
	input(c_array, first, second);
	output(c_array , first , second);
	printf("\n\n");
	printf("두 개의 행렬의 합 : \n");

	for(a=0 ; a<first ; a++){
		for(b = 0 ; b<second ; b++){
			out[a][b] = d_array[a][b] + c_array[a][b];
		}
	}

	for(a=0 ; a<first ; a++){
		for(b = 0 ; b<second ; b++){
			printf("%.2d " , out[a][b]);
		
		}
		printf("\n");
	}

	for(a=0 ; a<second ; a++){
		free(d_array[a]);
		free(c_array[a]);
		free(out[a]);
	}

	free(d_array);
	free(c_array);
	free(out);

	return 0;
}

void input(int **m , int first , int second)
{
	int a, b;
	for(a=0; a<first ; a++){
		for(b=0; b<second ; b++){
			m[a][b] = a+b;
		}
	}
}
void output(int **m , int first , int second)
{
	int a, b;
	for(a=0; a<first ; a++){
		for(b=0; b<second ; b++){
			printf("%d " , m[a][b]);
		}
		printf("\n");
	}
}
