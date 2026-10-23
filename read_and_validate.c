#include "inverted.h"

int flag = 0;
// function definition for read and validate
int read_and_validate(int argc, char *argv[], f_list **head)
{
	for (int i = 1; i < argc; i++)
	{
		if (open_files(argv[i]) == 1)
		{
			f_list *new = malloc(sizeof(f_list));
			if (*head == NULL)
			{
				*head = new;
				strcpy(new->f_name, argv[i]);
				new->link = NULL;
			}
			else
			{
				f_list *temp = *head;
				f_list *prev = NULL;
				while (temp != NULL)
				{
					if (strcmp(temp->f_name, argv[i]) == 1)
					{
						printf("Duplicate filename \"%s\" found and removed.\n", argv[i]);
						flag = 1;
						break;
					}
					prev = temp;
					temp = temp->link;
				}
				if (flag == 0)
				{
					strcpy(new->f_name, argv[i]);
					prev->link = new;
					new->link = NULL;
				}
				flag = 0;
			}
		}
	}
	printf("\n....... Open files are successfully ......\n");
	return 1;
}
/*open file function definition*/
int open_files(char *argv)
{
	FILE *fptr = fopen(argv, "r");
	if (fptr != NULL)
	{
		if (strcmp((strstr(argv, ".")), ".txt") == 0)
		{
			fseek(fptr, 0, SEEK_END);
			if (ftell(fptr) != 0)
			{
				fclose(fptr);
				return 1;
			}
			else
			{
				printf("Error :file is empty %s\n", argv);
				return 1;
			}
		}
		else
		{
			printf("Error : file does not have .txt extension %s\n", argv);
			return 1;
		}
	}
	else
	{
		printf("Error : file does not exist %s\n", argv);
		return 1;
	}
}
