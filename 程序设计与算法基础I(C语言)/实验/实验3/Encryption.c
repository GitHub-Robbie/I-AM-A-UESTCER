#include <stdio.h>
#include <string.h>

int main()
{
	char passwd[80];
	char encrypted[80];
	int i, n;
	
	printf("Enter message to be encrypted: ");
	gets(passwd);
	printf("Enter shift amount (1-25): ");
	scanf("%d%*c",&n);															//%d%*c意思是跳过前一个字符型输入
	
	for(i = 0; i < strlen(passwd); i++)
	{
		if(passwd[i] >= 'A' && passwd[i] <= 'Z')
			passwd[i] = ((passwd[i] - 'A') + n) % 26 + 'A';
		else if(passwd[i] >= 'a' && passwd[i] <= 'z')
			passwd[i] = ((passwd[i] - 'a') + n) % 26 + 'a';
	} 
	
	printf("Encrypted message: ");
	printf("%s",passwd);
 	printf("\n");
	
	return 0;
}
