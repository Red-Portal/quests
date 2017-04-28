
#include <stdio.h>

void getTape(char*);

void cmd_createLabel(char*, int*, int*);
void cmd_colon(char*, int*, int*);
void cmd_plus(char*, int*, int*);
void cmd_minus(char*, int*, int*);
void cmd_division(char*, int*, int*);
void cmd_multiply(char*, int*, int*);
void cmd_condition(char*, int*, int*, int*);
void cmd_print(char*, int*, int*);
void cmd_assign(char*, int*, int*);

int
main(void)
{
	char tape[30];
	getTape(tape);

	int memory[1000] = { 0 };
	int labels[1000] = { 0 };

	int head = 0;
	while (tape[head] != ';')
	{
		switch(tape[head])
		{
		case ':':
			cmd_colon(tape, &head, labels);
			break;
		case '+':
			cmd_plus(tape, &head, memory);
			break;
		case '-':
			cmd_minus(tape, &head, memory);
			break;
		
		case '*':
			cmd_multiply(tape, &head, memory);
			break;

		case '/':
			cmd_division(tape, &head, memory);
			break;

		case 'c':
			cmd_condition(tape, &head, memory, labels);
			break;

		case 'p':
			cmd_print(tape, &head, memory);
			break;

		case '=':
			cmd_assign(tape, &head, memory);
			break;

		default:
			printf("unknown command '%c' error!\n", tape[head]);
			break;
		}
	}
	return 0;
}

void
getTape(char* tape)
{
	printf("Enter tape\n");

	char current = '\0';

	for (int i = 0; current != ';'; ++i)
	{
		scanf(" %c", &current);
		tape[i] = current;
	}
}

void
cmd_colon(char* tape, int* head, int* labels)
{
	int index = (int)tape[*head + 1];
	labels[index] = *head + 2;

	*head += 2;
}

void
cmd_plus(char* tape, int* head, int* memory)
{
	int first = (int)tape[*head + 1];
	int second = (int)tape[*head + 2];

	int firstData = memory[first];
	int secondData;

	// this is checking wether the second argument is a literal
	// or a variable
	if(second - (int)'0' > 10) 
		secondData = memory[second];
	else
		secondData = second - (int)'0';

	memory[first] = firstData + secondData;
	*head += 3;
}

void
cmd_minus(char* tape, int* head, int* memory)
{
	int first = (int)tape[*head + 1];
	int second = (int)tape[*head + 2];

	int firstData = memory[first];
	int secondData;

	// this is checking wether the second argument is a literal
	// or a variable
	if(second - (int)'0' > 10) 
		secondData = memory[second];
	else
		secondData = second - (int)'0';

	memory[first] = firstData - secondData;
	*head += 3;
}

void
cmd_division(char* tape, int* head, int* memory)
{
	int first = (int)tape[*head + 1];
	int second = (int)tape[*head + 2];

	int firstData = memory[first];
	int secondData;

	// this is checking wether the second argument is a literal
	// or a variable
	if(second - (int)'0' > 10) 
		secondData = memory[second];
	else
		secondData = second - (int)'0';

	memory[first] = firstData / secondData;
	*head += 3;
}

void
cmd_multiply(char* tape, int* head, int* memory)
{
	int first = (int)tape[*head + 1];
	int second = (int)tape[*head + 2];

	int firstData = memory[first];
	int secondData;

	// this is checking wether the second argument is a literal
	// or a variable
	if(second - (int)'0' > 10) 
		secondData = memory[second];
	else
		secondData = second - (int)'0';

	memory[first] = firstData * secondData;
	*head += 3;
}

void
cmd_condition(char* tape, int* head, int* memory, int* labels)
{
	
	//the variable containing the condition
	int condVar = (int)tape[*head + 1]; 

	int trueLabel = (int)tape[*head + 2]; 
	int falseLabel = (int)tape[*head + 3];

	int cond = memory[condVar];

	if(cond == 0)
	{
		if(labels[falseLabel] != 0)
			*head = labels[(int) falseLabel];
		else
		{
			int i = 1;
			while(tape[*head + i] != falseLabel)
				++i;
			*head += i + 1;
		}
	}
	else
	{
		if(labels[trueLabel] != 0)
		*head = labels[(int) trueLabel];
		else
		{
			int i = 1;
			while(tape[*head + i] != trueLabel)
				++i;
			*head += i + 1;
		}
	}
}

void
cmd_print(char* tape, int* head, int* memory)
{
	int idx = tape[*head + 1];
	printf("output: %d\n", memory[idx]);
	*head += 2;
}

void
cmd_assign(char* tape, int* head, int* memory)
{
	int name = tape[*head + 1];
	int data = (int)tape[*head + 2] - (int)'0';

	memory[name] = data;
	head += 3;
}
