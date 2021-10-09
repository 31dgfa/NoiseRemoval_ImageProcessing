#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 700

//関数
/*--- smooth --- �ړ����ϖ@�ɂ��m�C�Y���� -----------------------------------
	image_in:	���͉摜�z��
	image_out:	�o�͉摜�z��
	type:		�������͈́i3:3x3��f�C5:5x5��f�C7:7x7��f�C�E�E�E�j
-----------------------------------------------------------------------------*/
void smooth(unsigned char image_in[9][9], 
	unsigned char image_out[9][9], int type)
{
	int i, j, m, n, k, x, y;
	double sum, num;

	k = type / 2;
	num = (double)type * type;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			sum = 0.0;
			for (m = -k; m <= k; m++) {
				for (n = -k; n <= k; n++) {
					y = i + m;
					x = j + n;
					if ( y < 0) y = 0;
					if ( x < 0) x = 0;
					if ( y > 9) y = 9;
					if ( x > 9) x = 9;
					sum += image_in[y][x];
				}
			}
			sum = sum / num;
			if (sum <   0) sum =   0;
			if (sum > 255) sum = 255;
			image_out[i][j] = (unsigned char)sum;
		}
	}
}

//メイン文
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
			fscanf(fp,"%d",&input[i][j]);
		}
	}
	fclose(fp);
	printf("ファイル読み込み完了\n");

//ここからプログラムを入れてください

//ここまで

	printf("処理終了\nファイル書き込み開始\n");
	fq=fopen("new-face-zatsuon.dat","w");
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
/*--- smooth 
-----------------------------------------------------------------------------*/
int sum(unsigned char)
{
int i, buf;
buf = 0;
for (i = 0; i < 9; i++)
  buf += (int)c[i];
return(buf / 9);
}