#include <iostream>

int string_length(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void process_backspaces(const char* input, char* output) {
    int len = string_length(input);
    int output_idx = 0;

    for (int i = 0; i < len; ++i) {
        char current_char = input[i];
        if (current_char != '#') {
            output[output_idx] = current_char;
            output_idx++;
        } else {
            if (output_idx > 0) {
                output_idx--;
            }
        }
    }

    output[output_idx] = '\0';
}

bool are_strings_equal(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    
    return str1[i] == str2[i];
}


const int MAX_LEN = 200005;

char s1[MAX_LEN];
char s2[MAX_LEN];

char final_s1[MAX_LEN];
char final_s2[MAX_LEN];

int main() {
    std::cin >> s1 >> s2;

    process_backspaces(s1, final_s1);
    process_backspaces(s2, final_s2);

    if (are_strings_equal(final_s1, final_s2)) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}