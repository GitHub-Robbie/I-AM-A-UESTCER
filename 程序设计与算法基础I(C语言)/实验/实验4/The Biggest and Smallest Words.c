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
			str[i++] = ch;					//[i++]这样的形式可以实现遍历数组成员，同时语句更简单 
		str[i] = '\0';
		ch = getchar();
	}
}
 
int main()
{
	char smallest_word[WORD_LEN + 1],
	     largest_word[WORD_LEN + 1],
		 current_word[WORD_LEN + 1];		//为末尾的空字符留出一个长度 
		 
		printf("Enter word: ");
		read_line(current_word, WORD_LEN);
		strcpy(smallest_word, strcpy(largest_word, current_word));	//将current依次复制到largest和smallest 
		
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
