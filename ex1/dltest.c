/* dltest.c */
#include <stdio.h>
#include <dlfcn.h>

int main()
{
	void *handle;
	int (*add)(int, int);
	int (*sub)(int, int);
	int (*mul)(int, int);
	int (*div)(int, int);

	char *error;
	int a,b;
	handle =dlopen("./libtest.so",RTLD_LAZY);

	if(!handle) {
		fputs(dlerror(), stderr);
	}

	add=dlsym(handle, "add");	
	sub=dlsym(handle, "sub");
	mul=dlsym(handle, "mul");
	div=dlsym(handle, "div");
	printf("숫자를 입력하세요 : ");
	scanf("%d %d",&a,&b);
	printf("%d + %d = %d\n", a, b, (*add)(a,b));
	printf("%d - %d = %d\n", a, b, (*sub)(a,b));
	printf("%d * %d = %d\n", a, b, (*mul)(a,b));
	printf("%d / %d = %d\n", a, b, (*div)(a,b));
	dlclose(handle);
}
