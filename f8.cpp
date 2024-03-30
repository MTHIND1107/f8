/*
 * FILE :f8.cpp
 * PROJECT : FOCUSSED ASSIGNMENT-8
 * PROGRAMMER :MANREET THIND (Student ID:8982315)
 * FIRSTVERSION :29/03/24
 * DESCRIPTION :
 * The functions in this file that give you practice at working with C-style strings, files, command-line arguments, and structs.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20
#define MAX_FILENAME_LENGTH 62

struct MyData
{
	int howMany;
	char theText[MAX_LENGTH + 1];
	char directoryPath[MAX_LENGTH + 1];
	char fileName[MAX_FILENAME_LENGTH + 1];
};

void createTextFile(struct MyData args)
{
	char fullFilePath[MAX_FILENAME_LENGTH + MAX_LENGTH + 2];

	strcpy_s(fullFilePath, sizeof(fullFilePath), args.directoryPath);
	strcpy_s(fullFilePath, sizeof(fullFilePath), "\\");
	strcpy_s(fullFilePath, sizeof(fullFilePath), args.fileName);

	FILE* outputFile;
	if (fopen_s(&outputFile, fullFilePath, "w") != 0)
	{
		fprintf(stderr, "Error opening file for writing.\n");
		exit(1);
	}

	for (int i = 0; i < args.howMany; ++i)
	{
		fprintf(outputFile, "%s\n", args.theText);
	}

	fclose(outputFile);

	printf("File \"%s\" created successfully.\n", fullFilePath);
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		return 1;
	}
	struct MyData myArgs;
	myArgs.howMany = atoi(argv[1]);
	strncpy_s(myArgs.theText, sizeof(myArgs.theText), argv[2], MAX_LENGTH);
	myArgs.theText[MAX_LENGTH] = '\0';
	strncpy_s(myArgs.directoryPath, sizeof(myArgs.directoryPath), argv[3], MAX_LENGTH);
	myArgs.directoryPath[MAX_LENGTH] = '\0';
	strncpy_s(myArgs.fileName, sizeof(myArgs.fileName), argv[4], MAX_FILENAME_LENGTH);
	myArgs.fileName[MAX_FILENAME_LENGTH] = '\0';

	createTextFile(myArgs);

	return 0;
}