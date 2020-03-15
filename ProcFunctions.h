#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef PROC_FUNCTIONS_H_INCLUDED
#define PROC_FUNCTIONS_H_INCLUDED


#define INIT		0
#define	READ_PIPE	0
#define SUCCESS		0
#define CHILD		0
#define PARENT		1
#define	WRITE_PIPE	1
#define ERROR		2

typedef struct ARGUMENTS
{
	int		argc;
	char**	argv;
	char*	command;
} structArgs;

int		GetPipeHandle(int pipes[], int typeOfCommunication)
{
	switch (typeOfCommunication)
	{
	case READ_PIPE:
	{
		dup2(stdin, pipes[READ_PIPE]);
		close(pipes[WRITE_PIPE]);
		break;
	}
	case WRITE_PIPE:
	{
		dup2(stdout, pipes[WRITE_PIPE]);
		close(pipes[READ_PIPE]);
		break;
	}
	}
}
int		GetProcessType(int childPID)
{
	if (childPID > 0)		return PARENT;
	else if (childPID == 0)	return CHILD;
	else if (childPID < 0)	return ERROR;
}
char**	CreateNewARGV(int argc, char* argv[])
{
	int		newARGC = 0;
	char**	newARGV = (char**)malloc(sizeof(char*)*(argc - 1));

	for (newARGC = 0; newARGC < argc; newARGC++)
	{
		newARGV[newARGC] = (char*)malloc(sizeof(argv[newARGC + 1]));
		newARGV[newARGC] = argv[newARGC + 1];
	}
	return newARGV;
}

char*	CombineStrings(char** stringsToCombine, int countStrings, int startingPosition)
{
	int newStringSize = 0;
	int index = 0;

	fprintf(stdout, "Calculating the string size\n");

	for (index = 0; index < countStrings; index++)
		newStringSize += (sizeof(stringsToCombine[startingPosition + index]) + 1);

	char* newString = (char*)calloc(newStringSize, NULL);


	fprintf(stdout, "Building the string\n");
	for (index = startingPosition; (index < (startingPosition + countStrings)); index++)
	{
		if (index >= (startingPosition + 1))
			strcat(newString, " ");
		strcat(newString, stringsToCombine[index]);
	}

	fprintf(stdout, "%s\n", newString);
	return newString;
}

char*** CreateCommandList(structArgs args)
{
	int argIndex = 0;
	int cmdIndex = 0;
	char** newCommands = (char**)calloc(3, sizeof(args));
	char* newCommand = (char*)calloc(1, sizeof(args));

	for (argIndex = 0; argIndex < args.argc; argIndex++)
	{
		if (strcmp(args.argv[argIndex], ",") == 0)
		{
			newCommands[cmdIndex] = newCommand;
			cmdIndex++;
		}
		else
		{
			if (argIndex > 0)
				strcat(newCommand, " ");
			strcat(newCommand, args.argv[argIndex]);
		}
	}
	fprintf(stdout, "Command[0] = %s\n", newCommands[0]);
}

void	SendCommand(int destFork, structArgs cmdArgs)
{

}
char*	GetCommand(structArgs cmdArgs)
{
	return NULL;
}
void	RunCommand(structArgs cmdArgs)
{

}

#endif
