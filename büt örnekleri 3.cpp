#include <stdio.h>

/*3) 2 ile 100 arasýnda bir tam sayý giriniz. Girilen sayý 2 ile 100 arasýnda deðilse kullanýcýdan yeniden bir 
sayý girmesi istensin. Girilen bu tam sayýnýn pozitif bölenlerinin sayýsýný bulunuz. 1 deðerini de girilen 
sayýnýn pozitif böleni olarak kabul ediniz.*/

int sayikontrol(){
	int sayi;
	
	printf("bir tam sayý giriniz.(2 ile 100 arasýnda olsun.)\n");
	scanf("%d", &sayi);
	
	if(sayi<2 || sayi>100)
	sayi=sayikontrol();
	
	return sayi;
}
int main(){
	int sayi,i,sayac=0;
	
	sayi=sayikontrol();
	
	for(i=1;i<sayi+1;i++){
		if(sayi%i==0)
		sayac++;
	}
	
	printf("%d sayisini %d sayi bolmektedir.\n",sayi,sayac);
	
	return 0;
}
