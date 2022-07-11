#include"../../my_string.h"

int main() {

    int n = 5;
    string* array = new_string_array(n);
    
    for(int i = 0; i < n; i++) {
        array[i] = read_line();
    }

    for(int i = 0; i < n; i++) {
        printf("%s\n", to_char_array(&array[i]));
    }

    free_string_array(array,n);
}