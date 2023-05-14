#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

int i,n,j,isadmin=0,ismember=3,kla=3,klm=3,login=3;
char username[50], pass[50];
FILE *listobat;
FILE *listobat2;
FILE *listmember;

struct{
	char nama[50],katg[50];
	int dos,harga;
}obat,a[50],temp;

struct{
	char username[50],pass[50],nama[50],alamat[100],nohp[15];
}user,b[50],x;

struct {
char kode[50];
} kodevirtual;

//Registrasi user
void registrasi(){
	FILE *listmember;
	listmember=fopen("List Member.dat","ab");
	printf("                                    ======================================\n");
	printf("                                    ==                                  ==\n");
	printf("                                    ==             REGISTRASI           ==\n");
	printf("                                    ==                                  ==\n");
	printf("                                    ======================================\n\n");
	printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n\n");
	printf(" Username :"); gets(user.username);
	printf(" Password :"); gets(user.pass);
	printf(" Alamat   :"); gets(user.alamat);
	printf(" Nama     :"); gets(user.nama);
	printf(" Nomor HP :"); gets(user.nohp); getchar();
	fwrite(&user, sizeof(user), 1, listmember);
	
	fclose(listmember);  
	system ("pause"); main();
}

//Input obat
void upobat(){
	FILE *listobat;
	listobat=fopen("List Obat.dat","ab");
	printf("Banyak Obat : "); scanf("%d",&n); getchar();
	for(i=1;i<=n;i++){
		printf("%d. Nama              : ",i); gets(obat.nama);
		printf("   Kategori Penyakit : "); gets(obat.katg);
		printf("   Dosis (mg)        : "); scanf("%d",&obat.dos);
		printf("   Harga             : "); scanf("%d",&obat.harga); getchar();
		fwrite(&obat, sizeof(obat), 1, listobat); 
	}
	fclose(listobat); 
	system ("pause"); admin();
}

//Lihat data obat
void lihatobat(){
int i=0,j,n=0;
	FILE *listobat; 
	listobat=fopen("List Obat.dat","rb+");
	while(fread(&obat,sizeof(obat),1,listobat)==1){
		a[i]=obat;
		i++;n++;
		}
	fclose(listobat);
	for (i=n-1;i>=1;i--) 
		for (j=1;j<=i;j++){ 
			if (strcmp(a[j-1].nama,a[j].nama)>0){ 
				temp=a[j-1]; 
				a[j-1]=a[j]; 
				a[j]=temp; 
			} 
		} 

	for (i=0;i<=n-1;i++) { 
		printf("%d. Nama              : %s\n",i+1,a[i].nama);
		printf("   Kategori Penyakit : %s\n",a[i].katg);
		printf("   Dosis             : %d mg\n",a[i].dos);
		printf("   Harga             : Rp %d\n",a[i].harga);
	}
	system ("pause");
	if (isadmin==1) admin();
	else member();
}

//Hapus obat
void hapusobat(){
	FILE *listobat;
	FILE *listobat2;
	char dicari[50];
	
	listobat = fopen("List Obat.dat", "rb");
	listobat2 = fopen("List Obat2.dat", "wb");
	printf("Silahkan masukkan nama obat yang akan dihapus: "); gets(dicari);
	while (fread(&obat,sizeof (obat),1, listobat)==1){
		if (strcmp(obat.nama, dicari)!=0){
		fwrite(&obat, sizeof(obat), 1, listobat2);
	}
}
	fclose(listobat);
	fclose(listobat2);
	remove("List Obat.dat");
	rename("List Obat2.dat","List Obat.dat");
	system ("pause"); 
	admin();
}

void hapusmember(){
	FILE *listmember;
	FILE *listmember2;
	char dicari[50];
	
	listmember = fopen("List Member.dat", "rb");
	listmember2 = fopen("List Member2.dat", "wb");
	printf("Silahkan masukkan nama member yang akan dihapus: "); gets(dicari);
	while (fread(&user,sizeof(user),1, listmember)==1){
		if (strcmp(user.nama, dicari)!=0){
		fwrite(&user, sizeof(user), 1, listmember2);
	}
}
	fclose(listmember);
	fclose(listmember2);
	remove("List Member.dat");
	rename("List Member2.dat","List Member.dat");
	system ("pause"); 
	admin();
}

//Menu admin
void admin(){
	int pil;
	isadmin=1;
	system("cls");
	printf("                                    ======================================\n");
	printf("                                    ==         	                        ==\n" );
	printf("                                    ==         	   Menu Admin           ==\n" );
	printf("                                    ==         	                        ==\n" );
	printf("                                    ======================================\n\n");	
	printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");
	printf ("1. Input Data Obat\n");
	printf ("2. Lihat Data Obat\n");
	printf ("3. Hapus Data Obat\n");
	printf ("4. Update Data Member\n");
	printf ("5. Lihat Data Member\n");
	printf ("6. Hapus Member\n");
	printf ("7. Update Kode Virtual Account\n");
	printf ("8. Keluar\n");
	printf ("Pilihan : "); scanf("%d",&pil); getchar();
	
	switch(pil){
		case 1: system("cls");upobat();break;
		case 2: system("cls");lihatobat();break;
		case 3: system("cls");hapusobat();break;
		case 4: system("cls");upmember();break;
		case 5: system("cls");lihatmember();break;
		case 6: system("cls");hapusmember();break;
		case 7: system("cls");updatekode();break;
		case 8: system("cls");main();break;
		default: system("cls");admin();break;
	}
}

void upmember(){
	char username[20],alamat[50],nohp[20],nama[20];
	//printf("==Edit Data Member==");
	printf("                                    ======================================\n");
	printf("                                    ==                                  ==\n");
	printf("                                    ==           Edit Data Member       ==\n");
	printf("                                    ==                                  ==\n");
	printf("                                    ======================================\n\n");
	printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n\n");
	printf("\nList member :");
	listmember=fopen("List Member.dat","rb+");
	while(fread(&user,sizeof(user),1,listmember)==1){
		b[i]=user;
		i++;n++;
		}
	fclose(listmember);
	for (i=n-1;i>=1;i--) 
		for (j=1;j<=i;j++){ 
			if (strcmp(b[j-1].username,b[j].username)>0){ 
				x=b[j-1]; 
				b[j-1]=b[j]; 
				b[j]=x; 
			} 
		} 

	for (i=0;i<=n-1;i++) { 
		printf("%d. Username : %s\n",i+1,b[i].username);
		printf("    Password : %s\n",b[i].pass);
		printf("    Alamat   : %s \n",b[i].alamat);
		printf("    Nama     : %s\n",b[i].nama);
		printf("    No HP    : %s\n",b[i].nohp);
	}
	listmember=fopen("List Member.dat","rb+");
	printf("Pilih username member yang akan diedit : ");gets(username);
	printf("Nama baru   : "); gets(nama);
	printf("Alamat baru : "); gets(alamat);
	printf("No HP baru  : "); gets(nohp);
	while(fread(&user,sizeof(user),1,listmember)==1){
		if(strcmp(user.username, username)==0){
			fseek(listmember,-sizeof(user),SEEK_CUR);
			strcpy(user.nama, nama);
			strcpy(user.alamat, alamat);
			strcpy(user.nohp, nohp);
			fwrite(&user, sizeof(user), 1, listmember);
			getchar(); break;
		}
	}
	fclose(listmember);
	printf("Data berhasil diedit\n");
	system("pause");
	admin();
}

//pembayaran
void pembayaran(){
	FILE *f_kodeva;
	f_kodeva=fopen("Kode Virtual.dat","rb");
	while(fread(&kodevirtual,sizeof(kodevirtual),1,f_kodeva)==1){
		printf("Kode virtual akun saat ini : %s\n", kodevirtual.kode);
	}

	fclose(f_kodeva);

	int pil;
	system ("cls");
	printf ("==Metode Pembayaran==\n");
	printf ("\n1. COD\n");
	printf ("2. Transfer\n");
	printf ("Pilih metode pembayaran : "); scanf("%d", &pil);
	
	system("cls");
	if (pil == 1)
	printf("Obat akan segera dikirim ke %s. \n\n", user.alamat);
	else printf("Nomor virtual akun anda %s%s\nHarap segera melakukan pembayaran\n\n", kodevirtual.kode, user.nohp);
	printf("                                    ======================================\n");
	printf("                                    ==            Terima Kasih          ==\n");
	printf("                                    ==           Sudah Menggunakan      ==\n");
	printf("                                    ==            Layanan Kami          ==\n");
	printf("                                    ======================================\n\n");
	
	system("pause");
	member();
}

	
//Menu user
void member(){
	system ("cls");
	int pil,i=0,j,n=0;
	ismember=ismember-3;
	printf("                                    ======================================\n");
	printf("                                    ==                                  ==\n");
	printf("                                    ==           Kategori Obat          ==\n");
	printf("                                    ==                                  ==\n");
	printf("                                    ======================================\n\n");
	printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n\n");
	printf("1. Demam\n");
	printf("2. Batuk\n");
	printf("3. Perut\n");
	printf("4. Kulit\n");
	printf("Pilih Obat : "); scanf("%d",&pil);
	
	switch(pil){
		case 1: 
			system("cls");
			listobat=fopen("List Obat.dat","rb+");
			while(fread(&obat,sizeof(obat),1,listobat)==1){
				if (strcmp(obat.katg,"Demam")==0){
					a[i]=obat;
					i++;n++;
				}
			}
			fclose(listobat);
			for (i=n-1;i>=1;i--)
				for (j=1;j<=i;j++){ 
					if (strcmp(a[j-1].nama,a[j].nama)>0){ 
						temp=a[j-1]; 
						a[j-1]=a[j]; 
						a[j]=temp; 
					}		 
				} 

			for (i=0;i<=n-1;i++) { 
				printf("%d. Nama              : %s\n",i+1,a[i].nama);
				printf("    Kategori Penyakit : %s\n",a[i].katg);
				printf("    Dosis             : %d mg\n",a[i].dos);
				printf("    Harga             : Rp %d\n",a[i].harga);
			} break;
		
		case 2:
			system("cls");
			listobat=fopen("List Obat.dat","rb+");
			while(fread(&obat,sizeof(obat),1,listobat)==1){
				if (strcmp(obat.katg,"Batuk")==0){
					a[i]=obat;
					i++;n++;
				}
			}
			fclose(listobat);
			for (i=n-1;i>=1;i--)
				for (j=1;j<=i;j++){ 
					if (strcmp(a[j-1].nama,a[j].nama)>0){ 
						temp=a[j-1]; 
						a[j-1]=a[j]; 
						a[j]=temp; 
					}		 
				} 

			for (i=0;i<=n-1;i++) { 
				printf("%d. Nama              : %s\n",i+1,a[i].nama);
				printf("    Kategori Penyakit : %s\n",a[i].katg);
				printf("    Dosis             : %d mg\n",a[i].dos);
				printf("    Harga             : Rp %d\n",a[i].harga);
			} break;
		case 3:
			system("cls");
			listobat=fopen("List Obat.dat","rb+");
			while(fread(&obat,sizeof(obat),1,listobat)==1){
				if (strcmp(obat.katg,"Perut")==0){
					a[i]=obat;
					i++;n++;
				}
			}
			fclose(listobat);
			for (i=n-1;i>=1;i--)
				for (j=1;j<=i;j++){ 
					if (strcmp(a[j-1].nama,a[j].nama)>0){ 
						temp=a[j-1]; 
						a[j-1]=a[j]; 
						a[j]=temp; 
					}		 
				} 

			for (i=0;i<=n-1;i++) { 
				printf("%d. Nama              : %s\n",i+1,a[i].nama);
				printf("    Kategori Penyakit : %s\n",a[i].katg);
				printf("    Dosis             : %d mg\n",a[i].dos);
				printf("    Harga             : Rp%d\n",a[i].harga);
			} break;
		case 4:
			system("cls");
			listobat=fopen("List Obat.dat","rb+");
			while(fread(&obat,sizeof(obat),1,listobat)==1){
				if (strcmp(obat.katg,"Kulit")==0){
					a[i]=obat;
					i++;n++;
				}
			}
			fclose(listobat);
			for (i=n-1;i>=1;i--)
				for (j=1;j<=i;j++){ 
					if (strcmp(a[j-1].nama,a[j].nama)>0){ 
						temp=a[j-1]; 
						a[j-1]=a[j]; 
						a[j]=temp; 
					}		 
				} 

			for (i=0;i<=n-1;i++) { 
				printf("%d. Nama              : %s\n",i+1,a[i].nama);
				printf("    Kategori Penyakit : %s\n",a[i].katg);
				printf("    Dosis             : %d mg\n",a[i].dos);
				printf("    Harga             : Rp %d\n",a[i].harga);
			} break;
		}
	getchar();
	beliobat();
}

//Login user
void loginmember(){
	system("cls");
	FILE *listmember;
	listmember=fopen("List Member.dat","rb");
	int i=0;
	printf("                                    ======================================\n");
	printf("                                    ==                                  ==\n");
	printf("                                    ==           Login Member           ==\n");
	printf("                                    ==                                  ==\n");
	printf("                                    ======================================\n\n");
		printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n\n");
	printf ("Username : "); gets(username);
	printf ("Password : "); gets(pass);
	while(fread(&user,sizeof(user),1,listmember)==1){
		if (strcmp(username,user.username)==0 && strcmp(pass,user.pass)==0) {
			fclose(listmember);
			system("pause");
			member();break;
		}
	}
	if (ismember>0){
		if (klm>0){
			klm--;
			ismember--;
			printf ("Login gagal, kesempatan anda tinggal %d kali\n",klm);
			fclose(listmember);
			system("pause");
			loginmember();
		}
		else  {
			printf ("Kesempatan anda habis\n");
			fclose(listmember);
			system("pause");
			main();
		}
	}
}

//Login admin
void loginadmin(){
	system ("cls");
	if(kla>0){
		printf("                                    ======================================\n");
		printf("                                    ==         	                        ==\n" );
		printf("                                    ==         	   Login Admin          ==\n" );
		printf("                                    ==         	                        ==\n" );
		printf("                                    ======================================\n\n");	
		printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");
		printf ("Username : "); gets(username);
		printf ("Password : "); gets(pass);
		kla--;
		
		if(strcmp(username,"admin")==0 && strcmp(pass,"1234")==0) admin();
		else{
			printf("Login gagal, kesempatan anda tinggal %d kali\n",kla);
			system ("pause");
			loginadmin();
		} 
	}
	else{
		printf("Kesempatan anda habis\n");
		system ("pause");
		main();
	} 
	
}

//Menu utama
int main(){	
    system ("color c7");
	int pil;
	isadmin=0;
	system ("cls");
	printf("                                    ======================================\n");
	printf("                                    ==== Selamat Datang di D'Medicine ====\n");
	printf("                                    ======================================\n\n");
	printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");
	printf ("1. Login Admin\n");
	printf ("2. Login User\n");
	printf ("3. Registrasi\n");
	printf ("4. Keluar\n");
	printf ("Pilihan : "); scanf("%d",&pil); getchar();
	
	switch(pil){
		case 1: system("cls");loginadmin();break;
		case 2: system("cls");loginmember();break;
		case 3: system("cls");registrasi();break;
		case 4: system("exit");break;
		default: system("cls");main();break;
	}
}

//update kode virtual
void updatekode(){
	FILE *f_kodeva;
		printf("                                    ======================================\n");
		printf("                                    ==         	                        ==\n" );
		printf("                                    ==     Update Kode Virtual Akun     ==\n" );
		printf("                                    ==         	                        ==\n" );
		printf("                                    ======================================\n\n");	
		printf("~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~\n");
	f_kodeva=fopen("Kode Virtual.dat","wb");
	printf("\nUpdate kode virtual akun : "); gets(kodevirtual.kode);
	fwrite(&kodevirtual,sizeof(kodevirtual),1,f_kodeva);

	fclose(f_kodeva);

	f_kodeva=fopen("Kode Virtual.dat","rb");
	while(fread(&kodevirtual,sizeof(kodevirtual),1,f_kodeva)==1){
		printf("Kode virtual akun saat ini : %s\n", kodevirtual.kode);
	}

	fclose(f_kodeva);
	system("pause");
	admin();
}

//Beli obat
void beliobat(){
	int val = 0;
	char yn[1], answer[25];
	FILE *f_listobat;
	
	f_listobat=fopen("List Obat.dat","rb+");
	printf("\nPilih obat : "); gets(answer);
	while (fread(&obat, sizeof(obat),1,f_listobat)==1){
		if(strcmp(answer, obat.nama)==0){
			printf("Apakah anda yakin membeli obat di bawah ini?\n");
			printf("Nama              : %s\n", obat.nama);
			printf("Kategori Penyakit : %s\n", obat.katg);
			printf("Dosis             : %d mg\n", obat.dos);
			printf("Harga             : Rp %d\n", obat.harga);
			val=1;
		}
	}
	if(val != 1){
		printf("\nData tidak ditemukan\n");
	}
	fclose(f_listobat);
	
	printf("\nLanjutkan pembayaran (y/n)? : "); gets(yn);
	if (strcmp(yn, "y")==0)pembayaran();
	else {
		printf("Pesanan Gagal\n\n"); 
		system("pause");
		member();
	}
}

void lihatmember (){
	int i=0,j,n=0;
	FILE *listmember; 
	listmember=fopen("List Member.dat","rb+");
	while(fread(&user,sizeof(user),1,listmember)==1){
		b[i]=user;
		i++;n++;
		}
	fclose(listmember);
	for (i=n-1;i>=1;i--) 
		for (j=1;j<=i;j++){ 
			if (strcmp(b[j-1].username,b[j].username)>0){ 
				x=b[j-1]; 
				b[j-1]=b[j]; 
				b[j]=x; 
			} 
		} 

	for (i=0;i<=n-1;i++) { 
		printf("%d. Username : %s\n",i+1,b[i].username);
		printf("   Password : %s\n",b[i].pass);
		printf("   Alamat   : %s \n",b[i].alamat);
		printf("   Nama     : %s\n",b[i].nama);
		printf("   No HP    : %s\n",b[i].nohp);
	}
	system ("pause");
	if (isadmin==1) admin();
	else member();
}
