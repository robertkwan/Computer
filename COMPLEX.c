#include <stdio.h>
#include <conio.h>
//Tugas Coplexity Materi Array

int main(){
	int b[8],i,j;
	int r[8][8];
	int biner[8]={128,64,32,16,8,4,2,1};

	for(i=0;i<8;i++){
		scanf("%d",&b[i]);
	}

	for(i=0;i<8;i++){
		int tot=0;
		for(j=0;j<8;j++){
			r[i][j]=0;
			if(biner[j]<=b[i] && tot<b[i]){
				tot+=biner[j];
				r[i][j]=1;
			}
		}
	}
	int perubahan=0;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			if(r[i][j]==1){
				if(r[i][j-1]==0)perubahan++;
				if(r[i][j+1]==0)perubahan++;
				if(r[i-1][j]==0)perubahan++;
				if(r[i+1][j]==0)perubahan++;
			}
		}
	}
	printf("\nMATRIKS BINER : \n");
	for(i=0;i<8;i++){
		printf("\t");
		for(j=0;j<8;j++){
			printf("%d ",r[i][j]);
		}
		printf("\n");
	}
	printf("\nPerubahan nilai = %d",perubahan);
	printf("\nKompleksitas = %.2f\n",(float)perubahan/112);
	if((float)perubahan/112<0.3)printf("Keterangan = Matriks Tidak Kompleks");
	else printf("Keterangan = Matriks Kompleks");

	getch();
	return 0;
}
