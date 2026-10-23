#ifndef INVERTED_H
#define INVERTED_H

#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include<stdarg.h>
#include<stdlib.h>
#include<ctype.h>

#define DATA_NOT_FOUND 2
#define SUCCESS 1
#define FAILURE -1

// Structure for link table / subnode
typedef struct subnode
{
    int word_count;
    char file_name[30];
    struct subnode *s_sub_link;
}s_node;

// Structure to store word count / mainnode
typedef struct mainnode
{
    int file_count;
    char word[30];
    struct mainnode *m_main_link;
    struct subnode *m_sub_link;
}m_node;

// Structure for file list
typedef struct filenode
{
    char f_name[30];
    struct filenode *link;
}f_list;

// Structure for create database
typedef struct create_db
{
    int key;
    m_node *m_link;
}c_db;

// Function declaration for read and validate
int read_and_validate(int argc, char *argv[], f_list **head);

// Function declaration for open files
int open_files(char *argv);

// Function declaration for create database
int create_database(f_list *head, c_db *arr);

// Function declaration for display database
int display_database(c_db *hash_t);

// Function declaration for search database
int search_database(c_db *hash_t);

// Function declaration for save database
int save_database(c_db *hash_t);

// Function declaration for update database
int update_database(c_db *hash_t);

#endif