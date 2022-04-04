#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"my_string.h"

string* new_string() {
    string* s = (string*)malloc(sizeof(string));
    s->chars  = (char*)malloc(sizeof(char)* MAX_STRING_LENGTH);

    return s;
}

string* new_string_array(int n) {
    string* s = (string*)malloc(sizeof(string) * n);
    
    for(int i = 0 ; i < n ; i++) {
        s[i].chars = (char*)malloc(sizeof(char)* MAX_STRING_LENGTH);
    }

    return s;
}

string* new_string_from_char_array(char* array) {
    string* s = (string*)malloc(sizeof(string));
    s->chars  = (char*)malloc(sizeof(char)* MAX_STRING_LENGTH);
    strncpy(s->chars,array,strlen(array));

    return s;
}

size_t length(string* s) {
    return strlen(s->chars);
}

string* read_line() {
    string* resp = new_string();

    fgets(resp->chars, MAX_STRING_LENGTH, stdin);

    resp->chars[length(resp)-1] = '\0';

    return resp;
}

string* clone(string* s) {

    string* clone = new_string();
    
    strncpy(clone->chars,s->chars,strlen(s->chars));

    return clone;
}

char* to_char_array(string* s) {
    return s->chars;
}


void append_char(string* dest,const char src) {

    if (dest == NULL || &src == NULL)
        return;

    if(length(dest) + 1 >= MAX_STRING_LENGTH - 1) 
        return;

    strncat(dest->chars,&src,1);
}

void append_char_array(string* dest,const char* src) {

    if (dest == NULL || src == NULL)
        return;

    size_t src_length = strlen(src);

    if(length(dest) + src_length >= MAX_STRING_LENGTH - 1 )
        return; 

    strncat(dest->chars,src,strlen(src));
}

bool contains_char_array(const string* str1, const char* str2) {

    if (str1->chars == NULL || str2 == NULL) 
        return false;

    return strstr(str1->chars, str2) != NULL;
}

string* strip(string* s) {
    int i;

    while (isspace (*s->chars)) s->chars++;   
    for (i = strlen(s->chars) - 1; (isspace (s->chars[i])); i--) ;   
    s->chars[i + 1] = '\0';
    return s;
}

string* substring(const string* s, int startIndex, int endIndex) {

    string* result = new_string();

    strncpy(result->chars,s->chars + startIndex,endIndex);

    return result;
}


