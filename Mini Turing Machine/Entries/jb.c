#include<stdio.h>

int main()
{
	int box[300];
	for (int a = 0; a < 300; a++)
		box[a] = a;
	for (int a = 48; a < 58; a++)
		box[a] = a - 48;
	char tape[30];
	scanf("%s", tape);
	int head = 0;
	int temp1;
	int temp2;
	while (tape[head] != ';') {
		switch (tape[head])
		{
		case '=': box[tape[head + 1]] = tape[head + 2] - 48; head = head + 3; break;
		case '+': box[tape[head + 1]] = box[tape[head + 1]] + box[tape[head + 2]]; head = head + 3; break;
		case '-': box[tape[head + 1]] = box[tape[head + 1]] - box[tape[head + 2]]; head = head + 3; break;
		case '*': box[tape[head + 1]] = box[tape[head + 1]] * box[tape[head + 2]]; head = head + 3; break;
		case '/': box[tape[head + 1]] = box[tape[head + 1]] / box[tape[head + 2]]; head = head + 3; break;
		case ':': box[tape[head + 1]] = head + 2; head = head + 2; break;
		case 'c': temp1 = tape[head + 2];
				  temp2 = tape[head + 3];
				  if (box[tape[head + 1]] != 0)
				  {
					  if (box[tape[head + 2]] < 30)
						  head = box[tape[head + 2]];
					 else 
					 {
						 while (tape[head] != ':'|| tape[head + 1] != temp1)
						 {
							 head++;
						 }
					 }
				  }
				  else
				  {
					  if (box[tape[head + 3]] < 30)
						  head = box[tape[head + 3]];
					  else
					  {
						  while (tape[head] != ':' || tape[head + 1] != temp2)
						  {
							  head++;
						  }
					  }
				  }
				  break;
		case 'p': printf("%d\n", box[tape[head + 1]]); head = head + 2; break;
		}
	}
}