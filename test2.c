#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define length 50
#define width 256
void main(){
	FILE *fp;
	char ch;
	int l=0;
	int w=0;
	char arr[length][width]={0};
	char filename[128]={'\0'};
	printf("请输入文件名：");
	scanf("%s",filename);
	if((fp=fopen(filename,"r"))==NULL){
		printf("can not open!");
		exit(0);	
	}
	while(!feof(fp)){
		ch=fgetc(fp);
		if(ch!='\n'){
			arr[l][w]=ch;
			w++;
			}
		else {l++;w=0;}	
	}
	for(int i=l-1;i>=0;i--){
		for(int j=0;j<width;j++){
			printf("%c",arr[i][j]);				
		}
		printf("\n");
	}
}
