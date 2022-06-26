#include"../../my_string.h"

int main() {

    string* array = new_string_array(5);
    size_t n = array->array_size;
    
    for(int i = 0; i < n; i++) {
        array[i] = read_line();
    }

    for(int i = 0; i < n; i++) {
        printf("%s\n", to_char_array(&array[i]));
    }

    for(int i = 0; i < n; i++) {
        free_string(&array[i]);
    }
}