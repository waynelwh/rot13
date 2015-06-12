/*  The program is rot13 which is an encrytion program
	The program is for the Linux Summer Workshop
	The program will only change [a-zA-Z]
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//handle the char change in ASCII
//if the char is not between ' ' and '~', NULL will be returned
//else a changed char will be return
char rotate(char theChar){
	if((theChar>='a'&&theChar<'n')||(theChar>='A'&&theChar<'N'))
		theChar+=13;
	else if((theChar>='n'&&theChar<='z')||(theChar>='N'&&theChar<='Z'))
		theChar-=13;
	else if(theChar<' '||theChar>'~')
		theChar=NULL;
	return theChar;
}

//The is the function that call the rotate() and pass the char
char *process(char *str){
	int num = strlen(str);
	char tmp[num];
	int cnt=0;
	char *result;
	while(cnt<num){
			tmp[cnt]=rotate(str[cnt]);
		cnt++;
	}
	result=tmp;
	return result;
}

int main(){
FILE *fp;	// the pointer to read from a file
FILE *fp2;	// the pointer to write to a file
char *result;
char *tmp=malloc(100);
size_t len=0;

fp=fopen("theText.txt","r");
if(fp==NULL){
printf("Error");
exit(1);
}

fp2=fopen("result.txt","w");
if(fp==NULL){
printf("Error in output");
exit(1);
}

// get line by line from the file
while (getline(&tmp, &len, fp) != -1) {
    //printf("%s", tmp);
    result=process(tmp);
	fprintf(fp2,"%s\n",result);
}

if (tmp)
    free(tmp);

fclose(fp);
fclose(fp2);

return 0;
}

