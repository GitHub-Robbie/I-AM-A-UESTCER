#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

void read_line(char str[], int n)
{
	char ch;
	int i = 0;

	ch = getchar();
	
	while (ch == ' ' || ch == '\n')
	ch = getchar();
	
	while (ch != '\n')
	{
		if (i < n)
			str[i++] = ch;					//[i++]��������ʽ����ʵ�ֱ��������Ա��ͬʱ������ 
		str[i] = '\0';
		ch = getchar();
	}
}
 
int main()
{
	char smallest_word[WORD_LEN + 1],
	     largest_word[WORD_LEN + 1],
		 current_word[WORD_LEN + 1];		//Ϊĩβ�Ŀ��ַ�����һ������ 
		 
		printf("Enter word: ");
		read_line(current_word, WORD_LEN);
		strcpy(smallest_word, strcpy(largest_word, current_word));	//��current���θ��Ƶ�largest��smallest 
		
		while (strlen(current_word) != 4)
		{
			printf("Enter word: ");
			read_line(current_word, WORD_LEN);
			if (strcmp(current_word, smallest_word) < 0) 
				strcpy(smallest_word, current_word);
			if (strcmp(current_word, largest_word) > 0) 
				strcpy(largest_word, current_word);
		} 
		
		printf("\nSmallest word: %s\n", smallest_word);
		printf("Largest word: %s\n", largest_word);
	return 0;
}
