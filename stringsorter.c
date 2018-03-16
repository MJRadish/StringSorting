//For inputs and outputs and file access
# include <stdlib.h>
# include <stdio.h>
//For reading files.
# include <unistd.h>
# include <fcntl.h>
//For boolean expressions.
# include <stdbool.h>

#include <string.h>

//Checks whether character is a letter.
bool isLetter(char c);
//Defining List.
typedef struct List_{
char* entry; long long int entrySize; struct List_* next;
}List;
//Reads data from argument string input.
void ReadDataS(char* arg, List* R);
//Print all contents of the list.
void PrintList(List* N);
//Returns true if character is a capital letter and false if otherwise.
bool isCap(char c);
//Sorts the list in capital first order then alphabetical order.
void SortList(List* Root,List* node, List* temp, List* temp2);
//Start of main function.
List * MSort(List* top);

List * MG(List* O, List*P);

List* GM (List* H);

void freeList(List*R);
int main(int argc, char** argv){
//Check if there is no input for argument 1, if so, exit program.
if(argv[1]==NULL){
printf("No data to read.");
exit(0);
}
//Check there is a second argument, if so, exit program.
if(argv[2]!=NULL){
printf("Too many arguments.");
exit(0);
}

//Defining nodes for list.
List* node=NULL;
//List* temp =NULL;

//Create List.
////Give node a size.
////Create root node, node, and temp2 node.
List * Root = malloc(sizeof(List));
node = malloc(sizeof(List));
node = Root;
//List* temp2 = malloc(sizeof(List));

ReadDataS(argv[1],Root);

Root=node;

//PrintList(Root);
//return 0;
//Iterate through using selection sort.
//Code For Sorting by alphabetical (CAP).
//SortList(Root,node,temp,temp2);
//Sorted List.

//List **R = malloc(sizeof(List*));
Root=(MSort(Root));
//MSort(Root);
//GM(Root);
PrintList(Root);
//Free data used.
freeList(Root);
//free(BRead);
//Quit program.
return 0;
}

void freeList(List* R){
if(R==NULL){
return;
}
//Free List of nodes containing strings.
//Create a List* in order to free the previous node traversed in List.
List* F=malloc(sizeof(List));
//Iterate through entire list. Free each node in list including their data, and free the last node.
F=R->next;
free(R);
R=F;

while(F!=NULL||R!=NULL){
F=R->next;
if(R->entrySize>0)
free(R->entry);
R=F;
}
//Free the List* pointer.
free(F);
return;
}
//If the character is a letter in the alphabet, return true, otherwise, return false.
bool isLetter(char c){
if(((int)c>=97&&(int)c<=122)||((int)c>=65&&(int)c<=90)){
return true;
}
return false;
}
//Read data of the argument.
void ReadDataS(char* arg,List* R){
//Create variables i, which increments across the argument, letterCount, which counts any letter of the alphabet, and charFlag, which is set to true if a letter is foune.
int i=0;
int letterCount =0;
bool charFlag=false;
//Set char C to the first character of the argument.
char C=arg[i];
//Read straight from the argument and store strings into the list.
//////////////////////////////////////////////////
//While haven't fallen off of the input string
while(C!='\0'){
//If the character is letter, set charFlag to true and count this letter.
if(isLetter(C)==true){
charFlag=true;
letterCount++;
}
//If the character is not a letter, set charFlag to false.
//Create integer j, which is used to count up the argument which is a word.
//char D stores the argument's first letter, then implement while loop
//which first stored D into the first character of the subsequent node's entry, and continut the while loop until it passes the end of the word.
else{
charFlag=false;
if(letterCount>=1){
int j=0;
char D= arg[i-letterCount];
//Allocate memory for the amount of words plus one spot for the null terminator.
R->entry=malloc((1+letterCount)*sizeof(char));
//Add each char of word to node entry.
while(isLetter(D)==true){
*(R->entry+j)=D;
j++;
D= arg[i-letterCount+j];
}
//Include null terminator at end of node's entry.
*(R->entry+j)='\0';
R->entrySize=letterCount;
//printf("\n WORD 1: %s\n",R->entry);
//Set the entrySize to the letterCount.
//Initialize the next node.
//Go to the initialized node.
R->entrySize=letterCount;
R->next=malloc(sizeof(List));
R->next->entry=malloc(sizeof(char));
R->next->entry="\0";
R=R->next;
}
//Reset lettercount.
letterCount=0;
}
//Set character to the next character argument and continue the loop.
i++;
C=arg[i];
}

//If reached end of the input stream and did not read the final character.
if(charFlag==true){
//printf("TRUE");
//If a letter was recorded.
if(letterCount>=1){
//Set integer j to iterate through last word of the argument and set char D to first letter of the last argument.
int j=0;
char D= arg[i-letterCount];
//Allocate memory for the amount of words plus one spot for the null terminator.
R->entry=malloc((1+letterCount)*sizeof(char));
//While the character of the argument's last word is true, store each character from the argument's last word into the node entries characters.
while(isLetter(D)==true){
//printf("%c",D);
*(R->entry+j)=D;
j++;
D= arg[i-letterCount+j];
}
//Set the node's entry final character to the null terminator.
*(R->entry+j)='\0';
//printf("\n WORD 2: %s\n",R->entry);
////Set the node's entry size to the amount of letters counted.
R->entrySize=letterCount;
//Set the next node to NULL
R->next=NULL;
}
}
else{
R=NULL;
}
///////////////////////////////////////////////
return;
}

//Function that determines if the character is capital. If the character is capital, return true. If not, return false. 
bool isCap(char c){
if((int)c>=65&&(int)c<=90){
return true;
}
return false;
}
void PrintList(List* N){
//If the root node is null.
if( N ==NULL){
return;
}
//If there is no string entry, "".
if(N->entry==NULL){
//N->entry="\0";
return;
}
//printf("SIZE: %d, NAME: %s\n", N->entrySize, N->entry);
//Print the string entry and go to next node in List.
printf("%s\n",N->entry);
PrintList(N->next);
}



//Merge Sort
List* MSort(List* T){

if(T==NULL||T->next==NULL){
return T;
}
//Set Middle node which is the end of the first half of the separated lists.
List* M = malloc(sizeof(List));
M=GM(T);
//Second half of the separated lists is always set to the next node of middle.
List* SH = malloc(sizeof(List));
SH=M->next; 

//Set M->next to NULL in order to end the first half of the lists, Second half of the lists already has a NULL at the end.
M->next=NULL;

//Implement merge function which takes multiple halves of the list using the head and then the second half. First the nodes are separated until there are pairs and either 1 extra node or not, then these pairs are compared first, then they are connected and compared until the entire list is connected and the list is then sorted.
return MG(MSort(T),MSort(SH));

}

//Merge 
List* MG(List* O, List* P){
//Initialize nodes which point to the same address.
List * D = malloc(sizeof(List));
List * C = malloc(sizeof(List));
C=D;
//While Havent reached end of first and second half
while(O!=NULL&&P!=NULL){
//If the node entry of the first piece is equivalent or of less weight that the node entry of the second piece, set the next node of C to the first node. If the size of both pieces of the list are 1, then C would be NULL.
if(strcmp(O->entry,P->entry)<=0){
C->next=O;
O=O->next;
}
//If node entry is of greater weight than the entry it is compared to, set C to the node that the first node is compared to. again, if the size of each piece is 1, C will be NULL.
else{ 
C->next = P; 
P=P->next;
}
C=C->next;
}

//If the first node is NULL, then set the next node of C to P, otherwise, set the next node of C to O.
//Example case1:  
//		O->entry= "H"
//		P->entry= "h"
//		C->next->entry="h"
//		C->next->next->entry="H"
//		D->next->entry="H"
//
C->next=(O==NULL) ? P:O;

//printf("\n\nCurrent is: %s\n\n",C->entry);
//Return the greater part of the block
return D->next;
}

//Get middle node
List* GM(List* H){
if(H==NULL){return H;}
//Initialize a node which is located at the current head that goes to next node each iteration..
//Initialize node to head that goes to next next node each iteration.
//By the time the F node reaches end of list, S node will always be in the middle or appropriate location of the list in order to merge sort to work.
List* S = malloc(sizeof(List));
List* F = malloc(sizeof(List));
S=F=H;
//Iterate through list.
while(F->next!=NULL&&F->next->next!=NULL){
S=S->next;
F=F->next->next;
}
//Return the Node which arrived at the middle.
return S;
}







