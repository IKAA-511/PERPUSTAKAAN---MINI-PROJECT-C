#include <stdio.h>
#include <string.h>

// LOGIN ADMIN
void login_admin(char nama_admin[])
{
    int pass;
    do
    {
        printf("========== LOGIN ADMIN ==========\n");

        printf("Nama admin : ");
        fgets(nama_admin, sizeof(nama_admin), stdin);
        nama_admin[strcspn(nama_admin, "\n")] = '\0';

        printf("Password   : ");
        scanf("%d", &pass);

        if (pass == 12345)
        {
            printf("\nLogin berhasil!!\n");
        }
        else
        {
            printf("\nPassword salah.\n");
            printf("Silahkan login ulang!!\n\n");
        }

    } while (pass == 12345);
    Sleep(1000);
    system("cls");
}

void input_tanggal(int *tanggal, int *bulan, int *tahun)
{
    int valid;
    printf("========= INPUT TANGGAL =========\n");
    do
    {
        valid = 1;
        printf("Masukkan Tahun   : ");
        scanf("%d", tahun);
        if (*tahun < 2000 || *tahun > 2030)
        {
            printf("Tahun Tidak Valid\n");
            valid = 0;
        }

    } while (valid == 0);

    do
    {
        valid = 1;
        printf("\nMasukkan Bulan   : ");
        scanf("%d", bulan);
        if (*bulan < 1 || *bulan > 12)
        {
            printf("Bulan Tidak Valid\n");
            valid = 0;
        }

    } while (valid == 0);

    do
    {
        valid = 1;
        printf("\nMasukkan Tanggal : ");
        scanf("%d", tanggal);
        if (valid == 1)
        {
            if (*bulan == 1 || *bulan == 3 ||
                *bulan == 5 || *bulan == 7 ||
                *bulan == 8 || *bulan == 10 ||
                *bulan == 12)
            {
                if (*tanggal < 1 || *tanggal > 31)
                {
                    printf("Tanggal Tidak Valid\n");
                    valid = 0;
                }
            }

            else if (*bulan == 4 || *bulan == 6 ||
                     *bulan == 9 || *bulan == 11)
            {
                if (*tanggal < 1 || *tanggal > 30)
                {
                    printf("Tanggal Tidak Valid\n");
                    valid = 0;
                }
            }

            else if (*bulan == 2)
            {
                if ((*tahun % 4 == 0 && *tahun % 100 != 0) || (*tahun % 400 == 0))
                {
                    if (*tanggal < 1 || *tanggal > 29)
                    {
                        printf("Tanggal Tidak Valid\n");
                        valid = 0;
                    }
                }

                else
                {
                    if (*tanggal < 1 || *tanggal > 28)
                    {
                        printf("Tanggal Tidak Valid\n");
                        valid = 0;
                    }
                }
            }
        }

    } while (valid == 0);
    Sleep(1000);
    system("cls");
}

void menu_buku(char daftar_buku[][50], int stok[])
{
    printf("\n============== DAFTAR BUKU ==============\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%-2d. %-25s Stok : %d\n", i + 1, daftar_buku[i], stok[i]);
    }
    printf("==========================================\n");
}

// TAMBAH STOK
void tambah_stok(char daftar_buku[][50], int stok[])
{
    int kode, tambah;
    menu_buku(daftar_buku, stok);
    printf("========== TAMBAH STOK ==========\n");
    printf("\nPilih buku : ");
    scanf("%d", &kode);

    while (kode < 1 || kode > 10)
    {
        printf("Kode tidak valid\n");

        printf("Pilih buku : ");
        scanf("%d", &kode);
    }

    printf("Tambah stok : ");
    scanf("%d", &tambah);

    while (tambah <= 0)
    {
        printf("Jumlah tidak valid\n");

        printf("Tambah stok : ");
        scanf("%d", &tambah);
    }

    stok[kode - 1] += tambah;

    printf("\nStok berhasil ditambahkan!!\n");
    printf("Stok sekarang : %d\n", stok[kode - 1]);
}
