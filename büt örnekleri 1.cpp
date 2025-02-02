#include <stdio.h>

// 0 ve 9 arasýnda 20 tane tam sayý giriniz ve en çok kez geçen sayýlarý bulup ekrana basýnýz.
int main(){
	int sayi,i,dizi[20]={0}, miktar[10]={0},mod=0;
	
	printf("0 ile 9 arasýnda 20 tane sayý giriniz.\n");
	
	for (i=0;i<20;i++)
	scanf("%d", &dizi[i]);
	
	for(i=0;i<20;i++)
	miktar[dizi[i]]++;

	for(i=0;i<10;i++){
		if(miktar[i]>mod)
		mod=miktar[i];
	}
	
	    printf(" mod=");
	for(i=0;i<10;i++){
		if(mod==miktar[i])
		printf(" %d", i);	
	}

	return 0;
}
