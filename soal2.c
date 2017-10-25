#include <stdio.h>
#include <windows.h>

int Score1 = 0,Score2 = 0, Round = 1;
int A[17] = {0},B[17] = {0},Turn = 1;

void Rules(char *Name1,char *Name2);

void DisplayMines(char *Name1,char *Name2)
{
	printf ("Pos\t%s\t%s\n",Name1,Name2);
	for (int Count = 1;Count <= 16;Count++)
	{
		printf ("%d\t%d\t%d\n",Count,A[Count],B[Count]);
	}
	Sleep (10000);
	system ("cls");
	Rules(Name1,Name2);
}

void Print(char *Name1,char *Name2)
{
	printf ("%s = %d\n",Name1,Score1);
	printf ("%s = %d",Name2,Score2);
	Sleep (2500);
	system ("cls");
	Rules(Name1,Name2);
}

void Rules(char *Name1,char *Name2)
{
	char Choice[50],C1[20] = "score",C2[20] = "mines";
	printf ("Enter 'score' to display current players' scores\n");
	printf ("Enter 'mines' to display ALL MINES -> Cheating\n");
	printf ("Enter anything else to continue the game\n");
	scanf ("%s",Choice);
	fflush(stdin);
	if (strcmp(Choice,C1)==0)
	{
		Print(Name1,Name2);
	}
	else if (strcmp(Choice,C2)==0)
	{
		DisplayMines(Name1,Name2);
	}
	else
	{
		system ("cls");
		return;
	}
}

void Part1(char *Name1,char *Name2)
{
	int Mines,P,L;
	printf ("Round %d: %s may now set the mines [%d X]\n",Round,Turn?Name1:Name2,Turn?1:2);
	if (Turn == 0) Turn++; else Turn--;
	printf ("Total = ");
	scanf ("%d",&Mines);
	while (Mines--)
	{
		scanf ("%d %d",&P,&L);
		if (P == 1)
		{
			A[L] = 1;
		}
		else
		{
			B[L] = 1;
		}
	}
	system("cls");
}

int Part2(char *Name1,char *Name2)
{
	int Trial = 4,P,L;
	printf ("Round %d: %s may now guess the safe positions [%d X]\n",Round,Turn?Name1:Name2,Turn?2:1);
	if (Turn == 0) Turn++; else Turn--;
	while (Trial--)
	{
		scanf ("%d %d",&P,&L);
		if (P == 2)
		{
			if (B[L]==0)
			{
				Score1++;
			}
		}
		else
		{
			if (A[L]==0)
			{
				Score2++;
			}
		}
		if (Score1 == 10)
		{
			printf ("\n%s wins the game!\n",Name1);
			printf ("%s = %d\n",Name1,Score1);
			printf ("%s = %d",Name2,Score2);
			exit(0);
		}
		else if (Score2 == 10)
		{
			printf ("\n%s wins the game!\n",Name2);
			printf ("%s = %d\n",Name1,Score1);
			printf ("%s = %d",Name2,Score2);
			exit(0);
		}
	}
	system("cls");
}

void Game(char *Name1,char *Name2)
{
	Part1(Name1,Name2);
	Part1(Name1,Name2);
	Part2(Name1,Name2);
	Part2(Name1,Name2);
	Round++;
	Rules(Name1,Name2);
}

int main ()
{
	char Name1[50],Name2[50];
	printf ("\tWelcome to Bomb Guessing game!\n\n");
	printf ("Player 1: ");
	gets(Name1);
	fflush(stdin);
	printf ("Player 2: ");
	gets(Name2);
	fflush(stdin);
	printf ("%s vs %s",Name1,Name2);
	Sleep(2000);
	system("cls");
	
	while(1)
	{
		Game(Name1,Name2);
	}
	return 0;
}
