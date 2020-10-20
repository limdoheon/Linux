/* main.c */
#include <stdio.h>

int main()
{
	int x , y;

	printf("숫자 2개를 입력하시오 : ");
	scanf("%d %d" , &x , &y);

	printf("덧셈 : %d + %d = %d\n" , x , y , add(x,y));
	printf("뺄셈 : %d - %d = %d\n" , x , y , sub(x,y));
	printf("곱셈 : %d * %d = %d\n" , x , y , mul(x,y));
	printf("나눗셈 : %d / %d = %d\n" , x , y ,div(x,y));

	return 0 ;
}
