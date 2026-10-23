#include "inverted.h"

// function to update the database
int update_database(c_db *hash_t)
{
    char newfile[100], c;
    int index;
    printf("Enter the file name to update : ");
    scanf("%s", newfile); // reading the backedup file from user
    FILE *fptr = fopen(newfile, "r");
    // if check file is exist or not
    if (fptr == NULL)
    {
        printf("File not found\n");
        return -1;
    }
    // reading line by line from backup file untill fptr reaches EOF
    while (fscanf(fptr, "%s", newfile) != EOF)
    {
        if (newfile[0] != '#')
            return -1;
        index = atoi(strtok(&newfile[1], ";"));    // Extracting index from the line
        m_node *m_new = malloc(sizeof(m_node));    // Create a new main node and updating the data 
        if (m_new == NULL)
            return -1;
        m_new->m_main_link = NULL;
        strcpy(m_new->word, strtok(NULL, ";"));
        m_new->file_count = atoi(strtok(NULL, ";"));
        s_node *s_new = malloc(sizeof(s_node));    // Creating a new subword node and updating the data
        s_node *stemp;
        if (s_new == NULL)
            return -1;
        s_new->s_sub_link = NULL;
        strcpy(s_new->file_name, strtok(NULL, ";"));
        s_new->word_count = atoi(strtok(NULL, ";"));
        m_new->m_sub_link = s_new;
        stemp = s_new;
        // loop to create more sub nodes based on file count
        for (int i = 0; i < (m_new->file_count) - 1; i++)
        {
            s_node *s_new = malloc(sizeof(s_node));
            if (s_new == NULL)
                return -1;
            s_new->s_sub_link = NULL;
            strcpy(s_new->file_name, (strtok(NULL, ";")));
            s_new->word_count = atoi(strtok(NULL, ";"));
            stemp->s_sub_link = s_new;
            stemp = s_new;
        }
        m_node *temp = hash_t[index].m_link;     // inserting the new main node into the hashtable
        if (temp == NULL)
        {
            hash_t[index].m_link = m_new;
        }
        else
        {
            while (temp->m_main_link)
            {
                temp = temp->m_main_link;
            }
            temp->m_main_link = m_new;
        }
    }
    fclose(fptr);
    return 1;
}
