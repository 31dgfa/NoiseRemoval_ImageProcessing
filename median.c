#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 700

void median(unsigned char image_in[9][9], unsigned char image_out[9][9])
{
	int i, j;
	unsigned char c[9];

	for (i = 1; i < 9-1; i++) {
		for (j = 1; j < 9-1; j++) {
			c[0] = image_in[i-1][j-1];
			c[1] = image_in[i-1][j];
			c[2] = image_in[i-1][j+1];
			c[3] = image_in[i][j-1];
			c[4] = image_in[i][j];
			c[5] = image_in[i][j+1];
			c[6] = image_in[i+1][j-1];
			c[7] = image_in[i+1][j];
			c[8] = image_in[i+1][j+1];
			image_out[i][j] = median_value(c);
		}
	}
}

int main(void) {
	FILE *fp,*fq;
	unsigned char input[MAX][MAX]; //入力する画像データ
	unsigned char output[MAX][MAX]; //出力する画像データ
	int height,width;
	int i,j;
	int mode,buf;
		
	printf("最大解像度が %d × %d となっています。\n",MAX,MAX);
	printf("ファイル読み込み開始\n");
	fp=fopen("face-zatsuon.dat","r");
	fscanf(fp,"%d,%d",&width,&height);	
		
	if(height>MAX && width>MAX) {
		printf("処理容量を超えています.解像度を落としてください\n");
		return(0);
	}

	for(i=0;i<height;i++) {
		for(j=0;j<width;j++) {
			fscanf(fp,"%s",&input[i][j]);
		}
	}
	fclose(fp);
	printf("ファイル読み込み完了\n");

	//ここからプログラムを入れてください

	//ここまで

	printf("処理終了\nファイル書き込み開始\n");
	fq=fopen("afterMedian.dat","w");
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

int median_value(unsigned char c[9])
{
	int i, j, buf;
	
	for (j = 0; j < 8; j++) {
		for (i = 0; i < 8; i++) {
			if (c[i+1] < c[i]) {
				buf = c[i+1];
				c[i+1] = c[i];
				c[i] = buf;
			}
		}
	}
	return c[4];
}