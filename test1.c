#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define length 128
#define number 128
void main(){
	char word[length][number]={'\0'};
	char filename[128]={'\0'};
	int word_num[length];
	for(int i=0;i<length;i++)
		word_num[i]=1;
	char ch;
	printf("请输入文件名：");
	scanf("%s",filename);
	FILE *fp;
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("can not open");
		exit(0);
	}
	while(!feof(fp)){
		for(int i=0;i<length;i++){
			for(int j=0;j<number;j++){
			ch=fgetc(fp);
			if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
				word[i][j]=ch;
				}
			else break;
			}
		}	
	}
	for(int i=0;i<length;i++){
		for(int j=i+1;j<length;j++){
			if(strcasecmp(word[i],word[j])==0){
				word_num[i]++;
				memset(word[j],0x00,number);       //把该行数据置为'\0'
				}
		}
	}
	printf("单词                出现次数\n");
	for(int i=0;i<length;i++){
		for(int j=0;j<number;j++){
			if(word[i][j]!='\0'){
				printf("%c",word[i][j]);				
				}
		}
		if(word[i][0]!='\0'){
			printf("%20d\n",word_num[i]);
			}
	}
}

