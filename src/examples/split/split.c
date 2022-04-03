#include"../../my_string.h"
#include<string.h>
#include<stdlib.h>

string* split(string* s, const char* pattern) {
    int i = 0;

    char* token = (char*)malloc(sizeof(char)*length(s));
    strncpy(token,s->chars,length(s));
    while(true) {
        i++;

        token = strstr(token+i,pattern);
        if (token == NULL)
            break;
    }
    i++;
    printf("%d\n", i);
    free(token);
    return NULL;
}

int main() {

    string* s = new_string_from_char_array("1,2,3,4,5");

    split(s,",");
}