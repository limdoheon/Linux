/* 학생수
 * student.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <string.h>

void print_node(const void *, VISIT, int);
struct node
{
	char *name;
	int mid_test;
	int final_test;
};

char nameT[100];
struct node nodeT[50];
struct node *root=NULL;

int compare(const void *cp1, const void *cp2)
{
	return strcmp(((struct node *)cp1)->name,((struct node *)cp2)->name);
}

int main(int argc , char *argv[]){

	int student = 0;
	int index = 0;

	char *nameptr = nameT;
	struct node *nodeptr = nodeT;
	struct node **ret;

	printf("학생 수 : ");
	scanf("%d", &student);

	while(index != student){
		printf("학생 이름 : ");
		scanf("%s",nameptr);

		printf("중간고사 성적입력 : ");
		scanf("%d",&nodeptr->mid_test);
		
		printf("기말고사 성적입력 : ");
		scanf("%d",&nodeptr->final_test);

		nodeptr->name = nameptr;

		ret = (struct node **)tsearch((void *)nodeptr,(void **)&root, compare);

		printf(" %s ", (*ret)->name);
		
		if(*ret == nodeptr){
			printf("학생을 추가하였습니다.\n");
			index++;
		}
		else{
			printf("이미 추가 되어 있습니다.\n");
		}
		nameptr += strlen(nameptr) + 1;
		nodeptr++;
	}
	printf("\n결과 화면\n");
	twalk((void *)root ,print_node);
	return 0;
}

void print_node(const void *nodeptr , VISIT order , int level){
	if(order == preorder || order == leaf){
		printf("이름 = %s, 중간고사 = %d, 기말고사 = %d\n",
		(*(struct node **)nodeptr)->name,
		(*(struct node **)nodeptr)->mid_test,
		(*(struct node **)nodeptr)->final_test);
	}
}

