#include<stdio.h>
#include<string.h>
#include<ctype.h>
int isValidKey(char *key){
    int seen[26] = {0};
    if(strlen(key) !=26)
    return 0;
    for(int i = 0; i < 26;i++){
        char ch = tolower(key[i]);
        if(ch < 'a'|| ch > 'z')
        return 0;
        if(seen[ch - 'a'])
        return 0;
        seen[ch - 'a'] = 1;
    }
    return 1;
}
void encrypt(char* text, char *key,char *result){
    for(int i = 0; text[i]!='\0';i++){
        char ch = text[i];
        if(isupper(ch)){
            result[i] = toupper(key[ch - 'A']);
        }else if(islower(ch)){
            result[i] = key[ch - 'a'];
        }else{
            result[i]=ch;
        }
    }
    result[strlen(text)] = '\0';
}
void decrypt(char *text, char *key,char *result){
    char reverseKey[26];
    for (int i = 0; i < 26; i++){
        reverseKey[key[i] - 'a'] = 'a' + i;
    }
    for(int i = 0; text[i] !='\0'; i++){
        char ch = text[i];
        if(isupper(ch)){
            result[i] = toupper(reverseKey[ch - 'A']);
        }else if(islower(ch)){
            result[i] = reverseKey[ch - 'a'];
        }else{
            result[i] = ch;
        }
    }
    result[strlen(text)] = '\0';
}
int main(){
    char text[1000];
    char key[100];
    char result[1000];
    int choice;
    printf("Enter the key : ");
    scanf("%s",key);
    for(int i = 0 ;i < 26 ;i++)
    key[i] = tolower(key[i]);
    if(!isValidKey(key)){
        printf("Invalid key, must contain all 26 letters exactly once.\n");
        return 1;
    }
    printf("Choose an option:\n");
    printf("1.Encrpt\n");
    printf("2.Decrpt\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    getchar();
    printf("Enter the text: ");
    fgets(text,sizeof(text), stdin);
    text[strcspn(text,"\n")] = '\0';
    if (choice == 1){
        encrypt(text,key,result);
        printf("Encrypted text: %s\n",result);
    }else if(choice == 2){
        decrypt(text,key,result);
        printf("Decrypted text: %s\n",result);
    }else{
        printf("Invalid choice.\n");
        return 1;
    }
    return 0;
}