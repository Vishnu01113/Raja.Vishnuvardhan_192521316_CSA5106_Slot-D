#include<stdio.h>
#include<string.h>
#include<ctype.h>
void caesarCipher(char *text, int k){
    k = k%26;
    for (int i = 0; text[i] !='\0';i++){
        char ch = text[i];
        if(isupper(ch)){
            ch = ((ch - 'A'+k)%26)+'A';
        }else if(islower(ch)){
            ch = ((ch - 'a'+k)%26) + 'a';
        }
        text[i] = ch;
    }
}
int main(){
    char text[1000];
    int k;
    printf("Enter a text: ");
    fgets(text,sizeof(text),stdin);
    text[strcspn(text,"\n")] = '\0';
    printf("Enter the value for K (1 to 25): ");
    scanf("%d",&k);
    if(k<1 || k>25){
        printf("Please enter a valid value. \n");
        return 1;
        }
        caesarCipher(text,k);
        printf("Encrypted text: %s\n",text);
        return 0;
}