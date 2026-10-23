#include "inverted.h"

// function to search the content
int search_database(c_db *hash_t)
{
    char w[30];
    int key;
    printf("Enter the word you want to search : ");
    scanf("%s", w);             // read the word you want to search
    printf("-------------------------------------\n");
    key = toupper(w[0]) % 65;   // calculate the key value
    if (key > 25 || key < 0)
        key = 26;
    m_node *temp = hash_t[key].m_link;
    if (temp == NULL)
        return DATA_NOT_FOUND;
    // loop will iterate till temp not equal to null
    while (temp != NULL)
    {
        // if check the word matrches or not
        if (strcmp(temp->word, w) == 0)
        {
            printf("The '%s' is present in (%d) files\n", w, temp->file_count);
            s_node *stemp = temp->m_sub_link;
            while (stemp != NULL)
            {
                printf("%s -> %d times\n", stemp->file_name, stemp->word_count);
                stemp = stemp->s_sub_link;
            }
            printf("-------------------------------------\n");
            return 1;
        }
        temp = temp->m_main_link;
    }
    return DATA_NOT_FOUND;    // return data not found if condition false
}