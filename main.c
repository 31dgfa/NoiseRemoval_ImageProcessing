#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 700
int mean(unsigned char c);
int median(unsigned char c);

int main(void) {
FILE *fp,*fq;
int input[MAX][MAX]; //入力する画像データ
int output[MAX][MAX]; //出力する画像データ
int height,width;
int i,j;
int mode,buf;
		
	printf("最大解像度が %d × %d となっています。\n",MAX,MAX);
	printf("ファイル読み込み開始\n");
	fp=fopen("data.dat","r");
	fscanf(fp,"%d %d",&width,&height);	
		
	if(height>MAX && width>MAX) {
		printf("処理容量を超えています\n解像度を落としてください\n");
		return(0);
	}
	
	for(i=0;i<height;i++) {
		for(j=0;j<width;j++) {
			fscanf(fp,"%d ",&input[i][j]);
		}
	}
	fclose(fp);
	printf("ファイル読み込み完了\n");
	
	
	//ここからプログラムを入れてください

int which;   /* which= 1 > 移動平均  2 > メディアンフィルタ */
{
int i, j,q,buf,e,a,s,d,f;
unsigned char  c[9];
printf("移動平均法なら１、メディアンフィルタなら２を入力\n");
scanf("%d",&which);
for (i = 1; i < height; i++) {
for (j = 1; j < width; j++) {
    c[0] = input[i-1][j-1];
    c[1] = input[i-1][j];
    c[2] = input[i-1][j+1];
    c[3] = input[i][j-1];
    c[4] = input[i][j];
    c[5] = input[i][j+1];
    c[6] = input[i+1][j-1];
    c[7] = input[i+1][j];
    c[8] = input[i+1][j+1];
    switch (which) { 
    case 1:
     //int q,buf,e;
     buf = 0;
     e=0;
     for(q=0;q<9;q++){
     buf +=c[q];
     }
     e = (buf/9);
     output[i][j] = e;
    break;
    case 2:
    // int a,s,d,f;
    d = 0;
      for(s=0;s<8;s++){
          for(a=0;a<8;a++){
              if(c[a+1]<c[a]){
                  d = c[a+1];
                  c[a+1] = c[a];
                  c[a] = d;
                
              }
          }
      }
      output[i][j] = c[4];
    break;
    } 
    
     }
}	

	//ここまで
	printf("処理終了\nファイル書き込み開始\n");
	fq=fopen("after.dat","w");
	fprintf(fq,"%d %d\n",width,height);
	for( i=0;i<height;i++) {
		for(j=0;j<width;j++) {
			fprintf(fq,"%3d ",output[i][j]);
		}
		fprintf(fq,"\n");
	}
	fclose(fq);
	printf("ファイル書き込み終了\n全行程完了\n");
	
	return(0);
}
}

