/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** .h file to stock all functions from our librairy
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#ifndef MY_H_
#define MY_H_

#ifndef READ_SIZE
#define READ_SIZE (1)
#endif

int my_strlen(char *str);
int my_lstrlen(char *str, char chr);

int my_nbrlen(int nbr);

int my_llnbrlen(int nbr);

int reduceneg(int nb);
int reducepos(int nb);
int my_put_nbr(int nb);

void my_putstrror(char *str);

int llreduceneg(long long int nb);
int llreducepos(long long int nb);
int my_put_llnbr(long long int nb);

int reducenegror(int nb);
int reduceposror(int nb);
int my_put_nbrror(int nb);

void my_putchar(char c);
char **create_table(char *str);

void my_putstr(char *str);
char *get_str_untill(char *str, char chr);
char *rm_str_untill(char *str, char chr);

int sum_stdarg(int i, int nb, ...);
char *my_strcat(char *str1, char *str2);

int is_number(char *str);

int is_letter(char chr);
void my_putcharror(char chr);

void printchr(char *str);

int str_to_int(char *str);

int disp_stdarg(char *s, ...);
int my_str_chrpos(char *str, char chr);

void replace_chr(char *str, char replace, char with);

int is_nbr(char *str);
int my_strchr(char *str, char chr);

int count_lines(char **tbl);
int count_chr(char *str, char chr);
int count_chr_tbl(char **tbl, char chr);

char **my_sort_params(char **table);

char *get_next_line(int fd);
char *int_to_str(int nbr);

int my_abs(int nbr);

char *my_re_alloc(char *str, int value);
void *my_calloc(int size);
void free_tbl(char **tbl);

int recu_power(int nb, int p, int i);
int my_compute_power_rec(int nb, int p);

char *my_revstr(char *str);
int count_nbr_str(char **table);
int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char *src);
char *my_strdup(char const *src);
char **my_tbldup(char **tbl);

char **my_tbl_append(char **tbl, char *to_add);
char **my_tbl_rm(char **tbl, int nbr);

char *my_str_minimalize(char *str);

#endif
