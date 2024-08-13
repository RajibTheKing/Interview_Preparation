int strlen(char *);

void strrev(char* s) {
    int right = strlen(s) - 1;
    int left = 0;

    while (left < right)
    {
        // swap
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }
}

// "foo" -> "oof"
// "hous"

// s[left]  = 'f'
// s[right] = '0'

// left++
// right--
