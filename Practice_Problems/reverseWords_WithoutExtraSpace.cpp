#include<iostream>
#include<string.h>
using namespace std;


void reverseRange(int left, int right, char input[]){


    while(left<=right){
        char c;
        c = input[left];
        input[left] = input[right];
        input[right] = c;
        left++;
        right--;
    }
}



int findEndingIndex(int left, char input[]){
    int right = left;
    for(int i=left; i<strlen(input); i++){
        if(input[i]== ' '){
            break;
        }
        right = i;
    }
    return right;
}


void reverseWords(char input[]){
    //pass by reference
    int ptr = 0;
    while(ptr<strlen(input)){
        if(input[ptr] != ' '){
            int left = ptr;
            int right = findEndingIndex(left, input);
            reverseRange(left, right, input);
            ptr = right+1;
        }else{
            ptr++;
        }
    }

}


int main()
{

    char input[] = "i love    programming hello world";
    reverseWords(input);
    cout<<input<<endl;

    return 0;

}
