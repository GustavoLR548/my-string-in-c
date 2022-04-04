#include"../../my_string.h"
#include<string.h>
#include<stdlib.h>

string* split(string* s, const char* pattern) {
    int i = 0;
    int pattern_length = strlen(pattern);

    char* token = (char*)malloc(sizeof(char)*length(s));
    strncpy(token,s->chars,length(s));

    while(true) {
        i++;

        token = strstr(token,pattern);
        if (token == NULL)
            break;
        token += pattern_length;
    }
    printf("%d\n", i);

    string* array = new_string_array(i);
    i = 0;

    int start_index =0, final_index=0;
    free(token);
    token = (char*)malloc(sizeof(char)*length(s));
    strncpy(token,s->chars,length(s));
    while(true) {

        token = strstr(token,pattern);
        printf("token = %s\n", token);
        if (token == NULL)
            break;
        else {
            final_index = length(s) - strlen(token);
            string* tmp = substring(s, start_index,final_index);
            printf("tmp = %s\n", to_char_array(tmp));
            printf("initial = %d\n", start_index);
            printf("final = %d\n\n", final_index);
            array[i++] = *tmp; 
            start_index = final_index + 1;
        }
        token += pattern_length;
    }

    return array;
}

int main() {

    string* s = new_string_from_char_array("1,2,3,4,5");

    split(s,",");
}