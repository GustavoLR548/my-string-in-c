#ifndef MY_STRING_H
#define MY_STRING_H

#define bool int
#define true 1
#define false 0

#define MAX_STRING_LENGTH 500

#include<stdio.h>

typedef struct string {
    char* chars;
    size_t split_length;
}string;

string* new_string();
string* new_string_from_char_array();
string* new_string_array(int n);
string* read_line();
string* clone(string* s);
char* to_char_array(string* s);
size_t length(string* s);
void append_char(string* dest,const char src);
void append_char_array(string* dest,const char* src);
bool contains_char_array(const string* str1, const char* str2);
string* strip(string* s);
string* substring(const string* s, int startIndex, int endIndex);
string* split(string* s, const char* pattern);
bool equals(const string* s,const char* arr);

#endif