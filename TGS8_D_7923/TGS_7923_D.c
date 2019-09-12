 #include<stdio.h>
#include<conio.h>

void sethargaelektronik(int *harga,int jeniselektronik);
void hargaelektronik(int *harga,int unit);
void totalPembelian(int *totalharga, int harga);
void inputJumlahPembayaran(int *jmlpembayaran, int totalharga);
void hitungKembalian(int *kembalian, int totalharga, int jmlpembayaran);
void setHarga(int *totalharga);
void discount(int *totalstlhdiskon, int *diskon, int totalharga);
void setHargaDiskon(int *totalstlhdiskon);
void Totalhargamember(int *totalstlhdiskonmember,int *diskonmember, int kartu, int totalharga);

int input,lagi,totalstlhdiskon,totalstlhdiskonmember,diskonmember,diskon,harga,unit,totalharga,jmlpembayaran,kembalian,hrg,member, kartu =0;

int main()
{
	
	do
	{
		printf("\n*****Maju Mundur*****");
		printf("\n1.Televisi<Rp. 325000>");
		printf("\n2.Kulkas<Rp. 525000>");
		printf("\n3.Air Condisioner<Rp. 425000>");
		printf("\n4.Kipas Angin<Rp. 100000>");
		printf("\n5.Pembayaran 7923");
		printf("\n0.Keluar");
		printf("\nInput Menu Pilihan: ");scanf("%d",&input);

		
		switch(input)
		{
		case 1:printf("jumlah televisi yang dipesan=");scanf("%d",&unit);			
			break;
		case 2:printf("jumlah Kulkas yang dipesan=");scanf("%d",&unit);				
			break;
		case 3:printf("jumlah air condisioner yang dipesan=");scanf("%d",&unit);				
			break;
		case 4:printf("jumlah Kipas Angin yang dipesan=");scanf("%d",&unit);				
			break;
		case 5:
				printf("\nHarga sebelum diskon = %d \n",totalharga);

				discount(&totalstlhdiskon,&diskon,totalharga);		
				
				printf("\nAnda mendapatkan diskon senilai %d karena transaksi anda lebih dari Rp.750000",diskon);


				//DISKON MEMBER
				printf("\nApakah anda mempunyai kartu member <1.Ya 2.Tidak> ? ");scanf("%d",&member);
				//if(member==1)
				//{
				//	printf("\nMasukkan jenis kartu member\n1.Platinum\n2.Silver\n3.Gold ? ");scanf("%d",&kartu);
				//	Totalhargamember(&totalstlhdiskonmember,&diskonmember, kartu,totalharga);	
				//}
			

					if(diskon > 0)
					{

						if(member==1)
						{
							printf("\nMasukkan jenis kartu member\n1.Platinum\n2.Silver\n3.Gold ? ");scanf("%d",&kartu);
							Totalhargamember(&totalstlhdiskonmember,&diskonmember, kartu,totalstlhdiskon);	

							printf("\nAnda mendapatkan diskon member senilai %d ",diskonmember);
							printf("\nTotal Harga yang harus dibayar = %d",totalstlhdiskonmember);
							printf("\n\nMasukkan uang anda = ");scanf("%d",&jmlpembayaran);	
							inputJumlahPembayaran(&jmlpembayaran, jmlpembayaran);
							hitungKembalian(&kembalian, totalstlhdiskonmember, jmlpembayaran);
							printf("\nUang Kembalian = %d \n",kembalian);
						}
						else
						{
							printf("\nTotal Harga yang harus dibayar = %d",totalstlhdiskon);
							printf("\n\nMasukkan uang anda = ");scanf("%d",&jmlpembayaran);	
							inputJumlahPembayaran(&jmlpembayaran, jmlpembayaran);
							hitungKembalian(&kembalian, totalstlhdiskon, jmlpembayaran);
							printf("\nUang Kembalian = %d \n",kembalian);
						}
						

					}
					else
					{
						if(member==1)
						{
							printf("\nMasukkan jenis kartu member\n1.Platinum\n2.Silver\n3.Gold ? ");scanf("%d",&kartu);
							Totalhargamember(&totalstlhdiskonmember,&diskonmember, kartu,totalharga);	
							
							printf("\nAnda mendapatkan diskon member senilai %d ",diskonmember);
							printf("\nTotal Harga yang harus dibayar = %d",totalstlhdiskonmember);
							printf("\n\nMasukkan uang anda = ");scanf("%d",&jmlpembayaran);	
							inputJumlahPembayaran(&jmlpembayaran, jmlpembayaran);
							hitungKembalian(&kembalian, totalstlhdiskonmember, jmlpembayaran);
							printf("\nUang Kembalian = %d \n",kembalian);
						}
						else
						{
							printf("\nTotal Harga yang harus dibayar = %d",totalharga);
							printf("\n\nMasukkan uang anda = ");scanf("%d",&jmlpembayaran);	
							inputJumlahPembayaran(&jmlpembayaran, jmlpembayaran);
							hitungKembalian(&kembalian, totalharga, jmlpembayaran);
							printf("\nUang Kembalian = %d \n",kembalian);
						}
					}
				

			printf("Anda ingin melakukan transaksi lagi (1.YA 2.TIDAK) ? \n\n");scanf("%d",&lagi);
			if(lagi==1)
			{
				//input=0;
				setHarga(&totalharga);
				setHargaDiskon(&totalstlhdiskon);
				//input,lagi,totalstlhdiskon,diskon,harga,unit,totalharga,jmlpembayaran,kembalian,hrg=0;
			}
			else
				input =0;

			break;
		}

		if(input <=4 && input != 0 )
		{
			//if(diskon > 0)
			//{
			//	sethargaelektronik(&harga,input);
			//	printf("\npembelian anda %d x %d ",unit,harga);
			//	hargaelektronik(&harga,unit);
			//	printf("= %d \n",harga);
			//	totalPembelian(&totalstlhdiskon,harga);
			//	printf("\nTotal Pembelian = %d \n",totalstlhdiskon);
			//}
			//else
			//{
				sethargaelektronik(&harga,input);
				printf("\npembelian anda %d x %d ",unit,harga);
				hargaelektronik(&harga,unit);
				printf("= %d \n",harga);
				totalPembelian(&totalharga,harga);
				printf("\nTotal Pembelian = %d \n",totalharga);
			//}
		}


	}while(input!=0);
}

void sethargaelektronik(int *harga,int jeniselektronik)
{
	if(jeniselektronik==1)
	{
		*harga=325000;
		printf("Harga televisi : %d",*harga);
	}
	else if(jeniselektronik==2)
	{
		*harga=525000;
		printf("Harga Kulkas : %d",*harga);
	}
	else if(jeniselektronik==3)
	{
		*harga=425000;
		printf("Harga Air Condisiioner : %d",*harga);
	}
	else if(jeniselektronik==4)
	{
		*harga=100000;
		printf("Harga Kipas Angin : %d",*harga);
	}
	
}

void hargaelektronik(int *harga,int unit)
{
	*harga=*harga*unit;
}

void totalPembelian(int *totalharga, int harga)
{
	*totalharga=*totalharga+harga;
}

void inputJumlahPembayaran(int *jmlpembayaran, int totalharga)
{
	*jmlpembayaran;
}

void hitungKembalian(int *kembalian, int totalharga, int jmlpembayaran)
{
	*kembalian=jmlpembayaran-totalharga;
}

void setHarga(int *totalharga)
{
	*totalharga=0;
}

void setHargaDiskon(int *totalstlhdiskon)
{
	*totalstlhdiskon=0;
}

void discount(int *totalstlhdiskon, int *diskon, int totalharga)
{
	if(totalharga >= 750000)
	{
		*diskon = totalharga*10/100;
		*totalstlhdiskon=totalharga-*diskon;
	}
	else
	{
		printf("Anda tidak mendapatkan diskon !!!");
	}
}

void Totalhargamember(int *totalstlhdiskonmember,int *diskonmember, int kartu, int totalhargastlhdiskon)
{
	
	if(kartu==1)
	{
		
		*diskonmember=totalharga*5/100;;
		*totalstlhdiskonmember= totalharga-*diskonmember;
	}
	else if(kartu==2)
	{
		*diskonmember=totalharga*7/100;
		*totalstlhdiskonmember= totalharga-*diskonmember;
	}
	else if(kartu==3)
	{
		*diskonmember=totalharga*10/100;
		*totalstlhdiskonmember= totalharga-*diskonmember;
	}
}