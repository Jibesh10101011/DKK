// C program to implement
// the above approach
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reading()
{
	FILE* ptr;
	char ch;
	ptr = fopen("file.txt", "r");

	if (!ptr) {
		printf("File doescnot exist \n");
        return;
	}
    printf("content in File\n");
	while (ch != EOF)
    {
        ch = fgetc(ptr);
		printf("%c", ch);
    }
	fclose(ptr);
}
void writing()
{
    char ans[20000];
    FILE *fptr;
    fptr = fopen("file1.txt","w");
    printf("Input : ");
    char ch = getchar();
    while(ch!=EOF)
    {
        fprintf(fptr,"%c",ch);
        ch = getchar();
    }
   fclose(fptr);
}
void readingWriting()
{
    FILE* ptr;
	char ch;
	ptr = fopen("file.txt", "r");

	if (!ptr) {
		printf("File doescnot exist \n");
        return;
	}
    printf("content in File\n");
	while (ch != EOF)
    {
        ch = fgetc(ptr);
		printf("%c", ch);
    }
	fclose(ptr);
}
void menu()
{
    printf("1. Reading a File\n");
    printf("2. Writing a File\n");
    printf("3. Reading and writing strings to file\n");
    printf("4. Reading and writng binary files\n");
    int x;
    scanf("%d",&x);
    // switch (x)
    // {
    //     case 1:
    //     reading();
    //     break;
    //     case 2:
    //     writing();
    //     break;
    //     case 3:
    //     strings_to_file();
    //     break;
    //     case 5:
    //     read_write_bs_file();
    //     break;
    //     default:
    //     exit(0);
    // }
}
int main()
{
//    menu();
   reading();
   return 0;
}
