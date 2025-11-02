#include <stdio.h>

void encode(){
	
	char usertext[200];
	char thischar;
	char encodedtext[200];
	int i=0;
	int len=0;
	char reversedtext[200];
	
	printf("Enter message: ");
	scanf(" %[^\n]", usertext);
	
	thischar=usertext[i];
	
	while(thischar!='\0'){
		len++;
		i++;
		thischar=usertext[i];
	}
	
	for(i=0; i<len; i++){
		reversedtext[i]=usertext[len-1-i];
	}
	
	reversedtext[len]='\0';

    for (i = 0; i < len; i++) {
        char ch = reversedtext[i];
        ch ^= (1 << 2);
        ch ^= (1 << 5);
        encodedtext[i] = ch;
    }
    encodedtext[len] = '\0';

    printf("Reversed string: %s\n", reversedtext);
    printf("Encoded string: %s\n", encodedtext);
}


void decode(){
	 char encodedtext[200];
    char unToggled[200];
    char decodedtext[200];
    int len = 0, i;

    printf("Enter encoded message to decode: ");
    scanf(" %[^\n]", encodedtext);

    while (encodedtext[len] != '\0')
        len++;

    for (i = 0; i < len; i++) {
        char ch = encodedtext[i];
        ch ^= (1 << 2); 
        ch ^= (1 << 5);
        unToggled[i] = ch;
    }
    unToggled[len] = '\0';

    for (i = 0; i < len; i++)
        decodedtext[i] = unToggled[len - 1 - i];
    decodedtext[len] = '\0';

    printf("Decoded message: %s\n", decodedtext);
}	 

int main(){
	int choice;
	
	do{
		printf("1. Encode Message\n");
		printf("2. Decode Message\n");
		printf("3. Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				encode();
				break;
			case 2:
				decode();
				break;
			case 3:
				printf("Exiting Program...\n");
				break;
			default:
				printf("Invalid Choice.\n");
				break;
		}
	}while(choice!=3);
	return 0;
}
