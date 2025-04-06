#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0m"
#define PURPLE "\033[0;35m"

struct otel {
	char tc[12];
	char isim[30];
	char soyisim[15];
	char tarih[11];
	int odadoluluk;
	int odano;
};
	struct otel otel[10];
	
void menu();
void arama();

bool tcrakam(const char *girilenTC){
	while(*girilenTC){
		if(!isdigit(*girilenTC)){
			return false;
		}
		girilenTC++;
	}
	return true;
}

int tarihkontrol(char *tarih){
	int igun,iay,iyil;
	
	
	if(tarih[2] =='.' && tarih[5]=='.'){
		
		igun= atoi(tarih);
		iay= atoi(tarih+3);
		iyil= atoi(tarih+6);
		
			if((iay==1 || iay==3 || iay==5 || iay==7 || iay==8 || iay==10 || iay==12) && (igun>=1 && igun <=31)) {
				return 1;
			}
			if((iay==4 || iay==6 || iay==9 || iay==11)  && (igun>=1 && igun<=30) ){
		        return 1;
			}
			if(iay==2){
				if(igun==29 && ((iyil%4==0 && iyil%100!=0) || iyil%400==0 )||(igun>=1 && igun<=28))
				return 1;
			}
	}
	else 
	printf("Lütfen geçerli bir tarih giriniz.\n");
	return 0;
	
}
			
void musterikaydi(){
    char girilenTC[12];
	int i,odanumarasi;
	
	
	printf("Lütfen 11 basamaklý T.C. kimlik numaranýzý giriniz.\n");
	scanf(" %11s", girilenTC);
	while (getchar() != '\n');
	
    if (strlen(girilenTC) == 11 && tcrakam(girilenTC)) {
		
		for(i=0;i<10;i++){
			if(strcmp(otel[i].tc,girilenTC)==0){
				printf("Girilen T.C.nin %d numaralý odamýzda kaydý bulunmaktadýr.\n",otel[i].odano);
				return;				
		}
	}

	printf("1 ile 10 arasýndan kayýt yapmak istediðiniz oda numarasýný giriniz.\n");
	scanf(" %d",&odanumarasi);
	
	if(odanumarasi>=1 && odanumarasi<=10){
	int i=odanumarasi-1;
			if(otel[i].odadoluluk==1)
			printf("Maalesef bu oda dolu.\n");
			else {
				printf("Kayýt yaptýðýnýz tarihi gün.ay.yýl þeklinde giriniz.\n");
				scanf(" %10s",otel[i].tarih);
				if(tarihkontrol(otel[i].tarih)==1){
					otel[i].odano=i+1;
					strcpy(otel[i].tc,girilenTC);
					printf("Ýsminizi girniz.\n");
					scanf(" %s",otel[i].isim);
					printf("Soy isminizi giriniz.\n");
					scanf(" %s",otel[i].soyisim);
					otel[i].odadoluluk = 1;
			}
			else menu();
			}	
	}
	else 
	   printf("Geçersiz oda numarasý!\n");	
}   else 
       printf("Lütfen geçerli bir T.C. kimlik numarasý giriniz.\n");   
}

void odadegistirme(){
	char secenek,girilenTC[12];
	int i,io,tcvar=0; //io istenen oda demek

	printf("Lütfen 11 basamaklý T.C. kimlik numaranýzý giriniz.\n");
	scanf(" %11s",girilenTC);
    if(strlen(girilenTC)==11 && tcrakam(girilenTC)){	
		for(i=0;i<10;i++){
			if(strcmp(otel[i].tc,girilenTC)==0){
				tcvar=1;
				break;
			}
		}
		if(tcvar==1){
			printf("Geçiþ yapmak istediðiniz oda numarasýný giriniz.\n");
			scanf(" %d", &io);
				--io;
				if(io>=0 && io<=9){
				if(otel[io].odadoluluk==0){
					strcpy(otel[io].isim,otel[i].isim);
					strcpy(otel[io].soyisim,otel[i].soyisim);
					strcpy(otel[io].tc,otel[i].tc);
					strcpy(otel[io].tarih,otel[i].tarih);
					otel[io].odadoluluk=1;
				
				memset(&otel[i],0,sizeof(otel[i]));
						
					
					printf("Oda deðiþikliðiniz baþarýyla tamamlandý. Ýyi günler dileriz.\n");			
			}
				else
				printf("Geçiþ yapmak istediðiniz oda dolu.\n");
			}
			else
				printf("Lütfen 1 ile 10 arasýnda bir sayý giriniz.\n");
		}
		
	
		if(tcvar==0){
			do{
			printf("Maalesef girdiðiniz TC. kimlik numarasýnýn kayýtlý olduðu bir oda yok.\n");
	        printf("Yeni bir giriþ yapmak istiyorsanýz Y harfine ana menüye dönmek istiyorsanýz A harfine basýnýz.\n");
			scanf(" %c",&secenek);
			if(secenek=='Y'|| secenek=='y')
			odadegistirme();
			if(secenek=='A' || secenek=='a')
			menu();
			else
			printf("Lütfen geçerli bir harf giriniz.\n");
			}while(secenek!='Y' || secenek!='y'||secenek!='a'||secenek!='A');
	}
}
	else
	printf("Lütfen geçerli bir T.C. kimlik numarasý giriniz.\n");
}

void kayitlar(){
	int i,j=0;
	for(i=0;i<10;i++){
		if(otel[i].odadoluluk==1){
			j++;
		 printf(" Oda no: %d\n Ýsim: %s\n Soy isim: %s\n TC.: %s\n Otele girþ tarihi: %s\n", otel[i].odano, otel[i].isim, otel[i].soyisim, otel[i].tc, otel[i].tarih );	
		}
	}
	if(j==0)
	printf("Dolu oda yok.\n");
	}

void mustericikisi(){
	int i;
	char secenek,girilenTC[12];
	
	printf("Çýkýþ yapmak istediðiniz oda numarasýný girniz.\n");
	scanf(" %d",&i);
	i--;
	
	if(i>=0 && i< 10){
		
		if(otel[i].odadoluluk == 1){
			printf("Lütfen TC. kimlik numaranýzý girniz.\n");
			scanf(" %11s",girilenTC);
			
		    if(strlen(girilenTC)==11 && tcrakam(girilenTC)){
				if(strcmp(otel[i].tc, girilenTC)==0){
					otel[i].odadoluluk = 0;
					strcpy(otel[i].tc,"");
					strcpy(otel[i].isim,"");
					strcpy(otel[i].soyisim,"");
					strcpy(otel[i].tarih,"");
	printf("Çýkýþýnýz baþarýyla yapýldý. Ýyi günler, tekrar bekleriz.\n");	
	}
	        else{
	        	printf("Girdiðiniz T.C. kimlik numarasý hatalý.\n");
	        	printf("Yeni bir giriþ yapmak istiyorsanýz Y harfine ana menüye dönmek istiyorsanýz A harfine basýnýz.\n");
				scanf(" %c",&secenek);
				if(secenek=='Y'|| secenek=='y')
					mustericikisi();
				if(secenek=='A' || secenek=='a')
					menu();
				else
					printf("Lütfen geçerli bir harf giriniz.\n");
		}
	}
			else 
				printf("Lütfen geçerli bir T.C. kimlik numarasý giriniz.");
}
		else
		printf("Çýkýþ yapmak istediðiniz oda boþ");
}
    else 
    printf("Lütfen geçerli bir oda numarasý giriniz.");
}

void arama(){
	
	int a,oda,i,sayac;
	char soyad[15],tarih[11];
	
	do{
	printf("Hangi bilgiye göre arama yapmak istersiniz?\n 1.Oda numarasý:\n 2.Soy isim:\n 3.Otele giriþ tarihi:\n 4.Ana menüye dönmek:)\n");
	scanf("%d",&a);
	if(a==1){
		printf("Kaç numaralý odadaki müþterinin bilgilerini görmek istiyorsunuz.\n");
		scanf(" %d",&oda);
		if(oda<=10 && oda>=1){
			--oda;
			if(otel[oda].odadoluluk==1){
			printf(" Oda no: %d\n Ýsim: %s\n Soy isim: %s\n TC.: %s\n Otele girþ tarihi: %s\n", otel[oda].odano, otel[oda].isim, otel[oda].soyisim, otel[oda].tc, otel[oda].tarih );	
			}
			else
			printf("Bu oda boþ.\n");
	    }
	    else
	    	printf("Girdiðiniz oda numarasý geçersiz. 1 ile 10 arasýnda bir sayý girniz.\n");
    }
	if(a==2){
		printf("Aramak istediðiniz soy isim nedir.\n");
		scanf(" %s",soyad);
		for(i=0,sayac=0;i<10;i++){
			if(strcmp(soyad,otel[i].soyisim)==0){
				sayac++;
			printf(" Oda no: %d\n Ýsim: %s\n Soy isim: %s\n TC.: %s\n Otele girþ tarihi: %s\n", otel[i].odano, otel[i].isim, otel[i].soyisim, otel[i].tc, otel[i].tarih );	
			}
		}
		if(sayac==0)
			printf("Otelimizde aradýðýnýz soy isme sahip biri bulunmamakta.\n");
	}
	if(a==3){
		printf("Arama yapmak istediðiniz otele giriþ tarihini gün.ay.yýl þeklinde giriniz.\n");
		scanf(" %s",tarih);
		if(tarihkontrol(tarih)==1){
		for(i=0,sayac=0;i<10;i++){
			if(strcmp(tarih,otel[i].tarih)==0){
				printf(" Oda no: %d\n Ýsim: %s\n Soy isim: %s\n TC.: %s\n Otele girþ tarihi: %s\n", otel[i].odano, otel[i].isim, otel[i].soyisim, otel[i].tc, otel[i].tarih );
			sayac++;
			}
		}
		if(sayac==0)
		printf("%s tarihinde otelimize kaydolan kimse yok.",tarih);
	    }
	    else 
	    arama();
	}
    if(a<1 || a>4)
    printf("Lütfen geçerli bir sayý giriniz.\n");
}while (a!=4);
}

void doluluk(){
	
	int secim,sayac,bos=0;
	float dolu=0;
	
	do{
	printf("Hangi iþlemi yapmak istersiniz.\n1.Doluluk Oraný: \n2.Dolu oda numaralarý: \n3.Boþ oda numaralarý:\n4.Ana Menü:\n");
	scanf(" %d",&secim);
	
	if(secim==1){
		for(sayac=0;sayac<10;sayac++){
		if(otel[sayac].odadoluluk==1)
			dolu++;
	}
		if(dolu>=0)
			printf("Otelimizdeki dolu odalarýn oraný= %%%.2f.\n",dolu*10);
	}
	
	if(secim==2){
		for(sayac=0;sayac<10;sayac++){
			if(otel[sayac].odadoluluk==1){
				dolu++;
			printf(" %d numaralý odamýz dolu.\n", sayac+1);	
			}
		}
		if(dolu==0)
			printf("Otelimizdeki tüm odalar boþ.\n");
	}
	
	if(secim==3){
	for(sayac=0;sayac<10;sayac++){
		if(otel[sayac].odadoluluk==0){
			bos++;
		printf(" %d numaralý odamýz boþ.\n", sayac+1);	
		}
	}
	if(bos==0)
	printf("Otelimizdeki tüm odalar dolu.\n");
}
	if(secim<1 || secim>4)
    	printf("Lütfen geçerli bir sayý giriniz.\n");
}while (secim !=4);
}

void menu(){
	char secim;
	
	do{
	printf("\nLütfen yapmak istediðiniz iþlemin numarasýný giriniz.\n 1) Yeni Müþteri Kayýt\n 2) Oda Deðiþikliði\n 3) Kayýtlarý göster\n 4) Müþteri çýkýþý\n 5) Arama\n 6) Doluluk\n 7) Çýkýþ\n");
	scanf( " %c", &secim);
	
		switch (secim){
	 		case '1' :
	 			musterikaydi();
	 			break;
	 		case '2': 
	 			odadegistirme();
	 			break ;
	 		case '3':
	 		    kayitlar();
	 			break;
	 		case '4':
	 			mustericikisi();
	 			break;
	 		case '5':
	 			arama();
	 			break;	 			
	 		case '6':
	 			doluluk();
	 			break;
	 		case '7':
	 			break;
	 		default :
	 			printf("Geçersiz seçim lütfen 1-7 arasýnda bir sayý seçiniz.\n");
		 }
	 } while(secim!=7);
}	

int main(){

    setlocale(LC_ALL,"Turkish");
   	
	for(int i=0;i<10;i++){
		memset(&otel[i],0,sizeof(otel[i]));
		otel[i].odano = i+1;	
	}
	 menu();
	 
   return 0;	
}
