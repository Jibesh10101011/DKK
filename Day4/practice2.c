// C program for the above approach
#include <conio.h>
#include <stdio.h>
#include <string.h>

// Driver Code
void f1()
{
     // with full path of CSV file
    FILE* fp = fopen("day1.csv", "a+");
 
    char name[50];
    int accountno, amount;
 
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
        return 0;
    }
 
    // Asking user input for the
    // new record to be added
    printf("\nEnter Account Holder Name\n");
    scanf("%s", &name);
    printf("\nEnter Account Number\n");
    scanf("%d", &accountno);
    printf("\nEnter Available Amount\n");
    scanf("%d", &amount);
 
    // Saving data in file
    fprintf(fp, "%s, %d, %d\n", name,
            accountno, amount);
 
    printf("\nNew Account added to record");
 
    fclose(fp);
    return 0;
}
int main()
{
	// Substitute the full file path
	// for the string file_path
    for(int i=0;i<5;i++)
    f1();
	FILE* fp = fopen("day1.csv", "r");

	if (!fp)
		printf("Can't open file\n");

	else {
		// Here we have taken size of
		// array 1024 you can modify it
		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer,
					1024, fp)) {
			column = 0;
			row++;

			// To avoid printing of column
			// names in file can be changed
			// according to need
			if (row == 1)
				continue;

			// Splitting the data
			char* value = strtok(buffer, ", ");

			while (value) {
				// Column 1
				if (column == 0) {
					printf("Name :");
				}

				// Column 2
				if (column == 1) {
					printf("\tAccount No. :");
				}

				// Column 3
				if (column == 2) {
					printf("\tAmount :");
				}

				printf("%s", value);
				value = strtok(NULL, ", ");
				column++;
			}

			printf("\n");
		}

		// Close the file
		fclose(fp);
	}
	return 0;
}
