#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include"my_string.h"

string new_string() {
    string s;
    s.chars  = (char*)calloc(1, sizeof(char));

    return s;
}

string* new_string_array(int n) {
    string* s = (string*)malloc(sizeof(string) * n);

    for(int i = 0 ; i < n ; i++) {
        s[i].chars = (char*)calloc(1,sizeof(char));
    }

    return s;
}

string new_string_from_char_array(char* array) {
    string s = new_string();
    strncpy(s.chars,array,strlen(array));

    return s;
}

size_t length(string* s) {
    return strlen(s->chars);
}

string read_line() {
    string resp = new_string();
    size_t string_size = sizeof(resp.chars);

    getline(&resp.chars, &string_size, stdin);

    resp.chars[length(&resp)-1] = '\0';

    return resp;
}

string clone(string* s) {

    string clone = new_string();
    
    strncpy(clone.chars,s->chars,length(s));

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

void strip(string* s) {
    int i;

    while (isspace (*s->chars)) s->chars++;   
    for (i = length(s) - 1; (isspace (s->chars[i])); i--) ;   
    s->chars[i + 1] = '\0';
}

string substring(const string* s, int startIndex, int endIndex) {

    string result = new_string();
    
    for (int i = startIndex; i < endIndex; i++)
        append_char(&result,s->chars[i]);

    return result;
}

string* split(string* s, const char* pattern) {
    
    int i = 0;
    int pattern_length = strlen(pattern);
    int start_index =0, final_index=0;

    char* token = (char*)malloc(sizeof(char)*length(s));
    strncpy(token,s->chars,length(s));

    while(true) {
        i++;

        token = strstr(token,pattern);
        if (token == NULL)
            break;
        token += pattern_length;
    }
    string* array = new_string_array(i);
    i = 0;

    free(token);
    token = (char*)malloc(sizeof(char)*length(s));
    strncpy(token,s->chars,length(s));

    while(true) {

        char* token_copy= (char*)malloc(sizeof(char)*length(s));
        strncpy(token_copy, token, strlen(token));
        token_copy[strlen(token)]='\0';

        token = strstr(token,pattern);
        if (token == NULL) {
            if ( strlen(token_copy + pattern_length) >= 0 ) {

                string tmp = new_string_from_char_array(token_copy);
                array[i++] = tmp; 
            }
            break;
            
        } else {
            final_index = length(s) - strlen(token);
            string tmp = substring(s, start_index,final_index);
            array[i++] = tmp; 
            start_index = final_index + pattern_length;

        }
        token += pattern_length;
        free(token_copy);
    }
    free(token);

    return array;
}

bool equals(const string* s, const char* arr) {
    return strcmp(s->chars,arr) == 0;
}

void free_string(string* s) {
    free(s->chars);
}

void free_string_array(string* s, int n) {

    for(int i = 0; i < n; i++) {
        free_string(&s[i]);
    }

    free(s);
}