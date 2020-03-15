#include "ProcFunctions.h"
#define BEG_FORK	0
#define	END_FORK	1

static int pipes;

void ProcessParent(int* childPID, structArgs cmdArgs)
{
	fprintf(stdout, "Child1 PID:\t%i\n", childPID[BEG_FORK]);
	fprintf(stdout, "Child2 PID:\t%i\n", childPID[END_FORK]);

	char*** listCommands = CreateCommandList(cmdArgs);
	fprintf(stdout, "listCommands[0].command = %s\n", listCommands[0][0]);
	fprintf(stdout, "listCommands[1].command = %s\n", listCommands[0][1]);

	int cmdIndex = 0;

	int forkID = BEG_FORK;
	for (cmdIndex = 0; cmdIndex < sizeof(listCommands); cmdIndex++)
	{

	}
}

void ProcessChild(int childNum)
{
	fprintf(stdout, "Child %i beginning processing...\n", childNum);
	switch (childNum)
	{
	case BEG_FORK:
	{

		break;
	}
	case END_FORK:
	{

		break;
	}
	}
}

int main(int argc, char* argv[])
{
	int typeProcess[2] = { PARENT, PARENT };
	int pipes[2];
	int childPID[2] = { PARENT, PARENT };

	int retvalPipe = pipe(pipes);
	childPID[BEG_FORK] = fork();
	typeProcess[BEG_FORK] = GetProcessType(childPID[BEG_FORK]);

	switch (typeProcess[BEG_FORK])
	{
	case CHILD:
	{

		break;
	}
	case PARENT:
	{
		childPID[END_FORK] = fork();
		if (childPID[END_FORK] == CHILD)
		{

			break;
		}


		fprintf(stdout, "Parent beginning processing...\n");
		structArgs originalArgs = { argc, argv, NULL };
		fprintf(stdout, "Original Structure created...\n");
		ProcessParent(childPID, originalArgs);
		break;
	}
	case ERROR: {	break;	}
	}

	return 0;
}