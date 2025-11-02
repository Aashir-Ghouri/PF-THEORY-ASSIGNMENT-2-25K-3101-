#include <stdio.h>

int push(int stack[], int top, int maxsize) {
	
	int value;
	
	if(top == maxsize -1){
		printf("Stack is full.");
	}
	else{
		printf("Enter value to insert: ");
		scanf("%d",&value);
		
		top++;
		stack[top]=value;
	
		
		printf("%d added to the stack.\n",value);
	}
	return top;
}


int pop(int stack[],int top){
	
	int retval;
	
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		retval=stack[top];
		top--;
		printf("%d value popped.\n",retval);
	}
	
	return top;
}

void peek(int stack[],int top){
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		printf("The value at the top of the stack is: %d.\n",stack[top]);
	}
}


void display(int stack[],int top){
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Stack elements:\n");
		for(int i = 0; i<=top; i++){
			printf("Value at index position %d = %d.\n",i,stack[i]);
		}
	}
}


int main(){
	int choice;
	int stack[5];
	int maxsize=5;
	int top=-1;
	
	do{
		printf("\n---ABSTRACT DATA TYPE---\n");
		printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
        	case 1:
        		top = push(stack,top,maxsize);
        		break;
        	case 2:
        		top = pop(stack,top);
        		break;
        	case 3:
        		peek(stack,top);
				break;
			case 4:
				display(stack,top);
				break;
			case 5:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice!");
				break;
		}
	} while(choice != 5);
	
	return 0;
}
