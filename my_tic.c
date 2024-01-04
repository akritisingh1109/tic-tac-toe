#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print_table(void);
char a[]={'0','1','2','3','4','5','6','7','8','9'};
int check_result(void);
void main(){
	int result,op;
	print_table();
	int player=1;
	char s1[10],s2[10],mark;
	int input;
	printf("this is the game of tic-tac-toe\n");	
	printf("enter 1 if you want to play\n");
	scanf("%d",&op);
	if(op==1)
	{
		printf("enter the name of player 1\n");
		scanf("%s",s1);
		printf("enter the name of player 2\n");
		scanf("%s",s2);
		char s3[10];
		while(1)
		{

			if(player%2==0)
			{
				player=2;
				strcpy(s3,s2);
			}

			else
			{
				player=1;
				strcpy(s3,s1);
			}
			if(player==1)
				mark='X';
			else if(player==2)
  				mark='O';
               
			printf("enter the place where %s want to mark\n",s3);
			scanf("%d",&input);
			if(input<1 || input>9)
				printf("invalid input\n");

			a[input]=mark;
			printf("%c",a[input]);
			print_table();

			result=check_result();
			if(result==1)
			{
				printf("%s is winner\n",s3);
				return ;
			}
			else if(result==0)
			{
				printf("match draw\n");
				return ;
			}



			player++;
		}
	}
}
int check_result(void){
	if(a[1]==a[2]&&a[2]==a[3])
		return 1;
	if(a[4]==a[5]&&a[5]==a[6])
		return 1;
	if(a[7]==a[8]&&a[8]==a[9])
		return 1;
	if(a[4]==a[1]&&a[4]==a[7])
		return 1;
	if(a[2]==a[5]&&a[2]==a[8])
		return 1;
	if(a[9]==a[6]&&a[6]==a[3])
		return 1;
	if(a[1]==a[5]&&a[5]==a[9])
		return 1;
	if(a[3]==a[5]&&a[5]==a[7])
		return 1;
	int count=0;
	for(int i=1;i<=9;i++)
	{
		if(a[i]=='X'||a[i]=='O')
			count++;
	}
	if(count==9)
		return 0;

		return 2;
}
void print_table(void){

               system("clear");
	//	system(cls);
	printf("======= TIC TAC TOE =======");
	printf("\n\n\n\n");

	printf("          |      |    \n");
	printf("       %c  |   %c  |  %c   \n",a[1],a[2],a[3]);
	printf("          |      |    \n");
	printf("    ------|------|-------\n");
	printf("          |      |      \n");
	printf("        %c |   %c  |   %c \n",a[4],a[5],a[6]);
	printf("          |      |    \n");
	printf("    ------|------|-------\n");
	printf("          |      |       \n");
	printf("        %c |    %c |   %c   \n",a[7],a[8],a[9]);
	printf("          |      |        \n");

}

