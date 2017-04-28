
#include <stdio.h>

void getTape(char*);

int main(void)
{
	char tape[30];
	getTape(tape);

	int memory[1000] = { 0 };
	int labels[1000] = { 0 };

	int head = 0;
	while (tape[head] != ';')
	{
		if (tape[head] == ':')  // if it is a colon, this is a label definition statement 
		{
			int label = (int)tape[head + 1];
			labels[label] = head + 2; // the position after the label is the start position of the label

			head += 2;
		}

		else if (tape[head] == '+') // if this is a plus, this is an addition operation statement
		{
			char firstVar = tape[head + 1];
			char secondVar = tape[head + 2];

			int firstData = memory[(int)firstVar];
			int secondData;

			if ((int)secondVar - '0' > 10)
				secondData = memory[(int)secondVar];
			else
				secondData = (int)secondVar - '0';


			memory[(int)firstVar] = firstData + secondData;

			head += 3;
		}

		else if (tape[head] == '-') // if this is a minux, this is an substraction opertion statement
		{
			char firstVar = tape[head + 1];
			char secondVar = tape[head + 2];

			int firstData = memory[(int)firstVar];

			int secondData;

			if ((int)secondVar - '0' > 10)
				secondData = memory[(int)secondVar];
			else
				secondData = (int)secondVar - '0';

			memory[(int)firstVar] = firstData - secondData;

			head += 3;
		}

		else if (tape[head] == '*') // if this is a asterix, this is a product operation statement
		{
			char firstVar = tape[head + 1];
			char secondVar = tape[head + 2];

			int firstData = memory[(int)firstVar];
			int secondData;

			if ((int)secondVar - '0' > 10)
				secondData = memory[(int)secondVar];
			else
				secondData = (int)secondVar - '0';

			memory[(int)firstVar] = firstData * secondData;

			head += 3;
		}

		else if (tape[head] == '/') // if this is a slash, this is a division operation statement
		{
			char firstVar = tape[head + 1];
			char secondVar = tape[head + 2];

			int firstData = memory[(int)firstVar];
			int secondData;

			if ((int)secondVar - '0' > 10)
				secondData = memory[(int)secondVar];
			else
				secondData = (int)secondVar - '0';

			memory[(int)firstVar] = firstData / secondData;

			head += 3;
		}

		else if (tape[head] == 'c') // if this is a c, this is a conditional operation statement
		{
			char condition = tape[head + 1];
			char trueLabel = tape[head + 2];
			char falseLabel = tape[head + 3];

			int condInt = memory[(int)condition];

			if (condInt == 0)
			{
				if (labels[(int)falseLabel] != 0)
					head = labels[(int)falseLabel];
				else
				{
					int i = 1;
					while (tape[head + i] != falseLabel)
						++i;

					head += i + 1;
				}
			}
			else
			{
				if (labels[(int)trueLabel] != 0)
					head = labels[(int)trueLabel];
				else
				{
					int i = 1;
					while (tape[head + i] != trueLabel)
						++i;

					head += i + 1;
				}
			}
		}

		else if (tape[head] == 'p') // if this is a p, this is a print statement
		{
			char var = tape[head + 1];
			printf("output: %d\n", memory[(int)var]);
			head += 2;
		}

		else if (tape[head] == '=') // if this is an equal, this is an assignment statement
		{
			char varName = tape[head + 1];
			char data = tape[head + 2];

			memory[(int)varName] = (int)data - (int)'0';
			head += 3;
		}
		else
			printf("unknown command '%c' error!\n", tape[head]);

	}
	return 0;
}

void getTape(char* tape)
{
	printf("Enter tape\n");

	char current = '\0';

	for (int i = 0; current != ';'; ++i)
	{
		scanf(" %c", &current);
		tape[i] = current;
	}
}
