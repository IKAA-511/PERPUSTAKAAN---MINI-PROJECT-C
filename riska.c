#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void login_admin(char nama_admin[])
{
    char password[20];
    do
    {
        printf("\t\t\t\t\t================== LOGIN ADMIN ==================\n");
        printf("\t\t\t\t\tNama admin : ");
        scanf(" %[^\n]", nama_admin);
        printf("\t\t\t\t\tPassword   : ");
        scanf(" %[^\n]", password);

        if (strlen(nama_admin) == 0 || strlen(password) == 0)
        {
            printf("\n\t\t\t\t\tNama admin / password tidak boleh kosong!!\n");
            printf("\t\t\t\t\tSilahkan login ulang!!\n\n");
            Sleep(1000);
            system("cls");
        }
        else if (strcmp(password, "12345") == 0)
        {
            printf("\n\t\t\t\t\tLogin berhasil!!\n");
            Sleep(1000);
            system("cls");
        }
        else
        {
            printf("\n\t\t\t\t\tPassword salah.\n");
            printf("\t\t\t\t\tSilahkan login ulang!!\n\n");
            Sleep(1000);
            system("cls");
        }
    } while (strlen(nama_admin) == 0 || strlen(password) == 0 || strcmp(password, "12345") != 0);
}
void input_tanggal(int *tanggal, int *bulan, int *tahun)
{
    int valid;
    printf("\n\t\t\t\t\t================== INPUT TANGGAL ==================\n");
    do
    {
        valid = 1;
        printf("\t\t\t\t\tMasukkan tahun   : ");
        scanf("%d", tahun);
        if (*tahun < 2000 || *tahun > 2030)
        {
            printf("\t\t\t\t\tTahun tidak valid!!\n");
            valid = 0;
        }
    } while (valid == 0);

    do
    {
        valid = 1;
        printf("\n\t\t\t\t\tMasukkan bulan   : ");
        scanf("%d", bulan);
        if (*bulan < 1 || *bulan > 12)
        {
            printf("\t\t\t\t\tBulan tidak valid!!\n");
            valid = 0;
        }
    } while (valid == 0);
    do
    {
        valid = 1;
        printf("\n\t\t\t\t\tMasukkan tanggal : ");
        scanf("%d", tanggal);
        if (*bulan == 1 || *bulan == 3 ||
            *bulan == 5 || *bulan == 7 ||
            *bulan == 8 || *bulan == 10 ||
            *bulan == 12)
        {
            if (*tanggal < 1 || *tanggal > 31)
            {
                printf("\t\t\t\t\tTanggal tidak valid!!\n");
                valid = 0;
            }
        }
        else if (*bulan == 4 || *bulan == 6 ||
                 *bulan == 9 || *bulan == 11)
        {
            if (*tanggal < 1 || *tanggal > 30)
            {
                printf("\t\t\t\t\tTanggal tidak valid!!\n");
                valid = 0;
            }
        }
        else if (*bulan == 2)
        {
            if ((*tahun % 4 == 0 && *tahun % 100 != 0) ||
                (*tahun % 400 == 0))
            {
                if (*tanggal < 1 || *tanggal > 29)
                {
                    printf("\t\tT\t\t\tanggal tidak valid!!\n");
                    valid = 0;
                }
            }
            else
            {
                if (*tanggal < 1 || *tanggal > 28)
                {
                    printf("\t\t\t\t\tTanggal tidak valid!!\n");
                    valid = 0;
                }
            }
        }
    } while (valid == 0);
    Sleep(1000);
    system("cls");
}

void menu_buku(char daftar_buku[][50], int stok[])
{
    printf("\n\t\t\t\t\t==================== DAFTAR BUKU ====================\n");
    for (int i = 0; i < 20; i++)
    {
        printf("\t\t\t\t\t%-2d. %-25s Stok : %d\n", i + 1,
               daftar_buku[i], stok[i]);
    }
    printf("\t\t\t\t\t=====================================================\n");
}

void tambah_stok(char daftar_buku[][50], int stok[])
{
    int kode, tambah;
    menu_buku(daftar_buku, stok);
    printf("\n\t\t\t\t\t==================== TAMBAH STOK ====================\n");
    printf("\t\t\t\t\tPilih buku : ");
    scanf("%d", &kode);
    while (kode < 1 || kode > 20)
    {
        printf("\t\t\t\t\tKode tidak valid!!\n");
        printf("\t\t\t\t\tPilih buku : ");
        scanf("%d", &kode);
    }
    printf("\t\t\t\t\tTambah stok : ");
    scanf("%d", &tambah);
    while (tambah <= 0)
    {
        printf("\t\t\t\t\tJumlah tidak valid!!\n");
        printf("\t\t\t\t\tTambah stok : ");
        scanf("%d", &tambah);
    }
    stok[kode - 1] += tambah;
    printf("\n\t\t\t\t\tStok berhasil ditambahkan!!\n");
    printf("\t\t\t\t\tStok sekarang : %d\n", stok[kode - 1]);
    Sleep(2000);
}

int peminjaman(char daftar_buku[][50],
               int stok[], char buku_dipinjam[][50],
               int jumlah_dipinjam[], int *jumlah_data)
{
    int kode, jumlah, total = 0;
    char tambah;
    do
    {
        menu_buku(daftar_buku, stok);
        printf("\t\t\t\t\tPilih buku : ");
        scanf("%d", &kode);
        while (kode < 1 || kode > 20)
        {
            printf("\t\t\t\t\tKode tidak valid!!\n");
            printf("\t\t\t\t\tPilih buku : ");
            scanf("%d", &kode);
        }

        do
        {
            printf("\t\t\t\t\tJumlah pinjam : ");
            scanf("%d", &jumlah);
            if (jumlah <= 0)
            {
                printf("\t\t\t\t\tJumlah tidak valid!!\n");
            }
            else if (jumlah > stok[kode - 1])
            {
                printf("\t\t\t\t\tStok tidak mencukupi!!\n");
            }
        } while (jumlah <= 0 || jumlah > stok[kode - 1]);

        strcpy(buku_dipinjam[*jumlah_data],
               daftar_buku[kode - 1]);
        jumlah_dipinjam[*jumlah_data] = jumlah;
        stok[kode - 1] -= jumlah;
        total += jumlah;
        (*jumlah_data)++;
        printf("\n\t\t\t\t\tTambah buku lagi? (y/n) : ");
        scanf(" %c", &tambah);
    } while (tambah == 'y');
    Sleep(1000);
    return total;
}
void cetak_bukti(char nama_admin[],
                 int tanggal, int bulan,
                 int tahun, char buku_dipinjam[][50],
                 int jumlah_dipinjam[],
                 int jumlah_data, int total)
{
    printf("\n");
    printf("\t\t\t\t\t================== BUKTI PEMINJAMAN ==================\n");
    printf("\t\t\t\t\tAdmin   : %s\n", nama_admin);
    printf("\t\t\t\t\tTanggal : %02d/%02d/%d\n", tanggal, bulan, tahun);
    printf("\t\t\t\t\t------------------------------------------------------\n");
    printf("\t\t\t\t\tNo   Judul Buku              Jumlah\n");
    printf("\t\t\t\t\t------------------------------------------------------\n");
    for (int i = 0; i < jumlah_data; i++)
    {
        printf("\t\t\t\t\t%-3d %-25s %d\n", i + 1, buku_dipinjam[i],
               jumlah_dipinjam[i]);
    }
    printf("\t\t\t\t\t------------------------------------------------------\n");
    printf("\t\t\t\t\tTotal Buku Dipinjam : %d\n", total);
    printf("\t\t\t\t\tStatus : Berhasil\n");
    printf("\t\t\t\t\t------------------------------------------------------\n");
    printf("\t\t\t\t\tTerima Kasih\n");
    printf("\t\t\t\t\t======================================================\n");
    Sleep(2000);
}

int menu_utama()
{
    int pilihan;
    printf("\t\t\t\t\t==================== MENU ====================\n");
    printf("\t\t\t\t\t1. Peminjaman Buku\n");
    printf("\t\t\t\t\t2. Tambah Stok Buku\n");
    printf("\t\t\t\t\t3. Lihat Bukti Peminjaman\n");
    printf("\t\t\t\t\t4. Keluar\n");
    printf("\t\t\t\t\tPilih : ");
    scanf("%d", &pilihan);
    return pilihan;
}

void header()
{
    
}

int main()
{
    system("cls");
    printf("\t\t\t\t\t=================================================\n");
    printf("\t\t\t\t\t  SISTEM INFORMASI PEMINJAMAN BUKU PERPUSTAKAAN\n");
    printf("\t\t\t\t\t=================================================\n\n\n");

    char nama_admin[50];
    int tanggal, bulan, tahun;
    int pilihan;
    int jumlah_data = 0;
    int total = 0;
    char daftar_buku[20][50] =
        {
            "Laskar Pelangi",
            "Bumi",
            "Atomic Habits",
            "Algoritma",
            "Pemrograman C",
            "Matematika Dasar",
            "Fisika Dasar",
            "Kimia Dasar",
            "Sejarah Indonesia",
            "Bahasa Inggris",
            "Bulan",
            "Matahari",
            "Komet",
            "Meteor",
            "Si Putih",
            "Negeri Para Bedebah",
            "Pengantar Akuntansi",
            "Romeo And Juliet",
            "Struktur Data",
            "Basis Data"};

    int stok[20] = {5, 11, 6, 6, 2, 7, 3, 7, 4, 4,
                    5, 11, 6, 2, 6, 3, 7, 4, 4, 6};
    char buku_dipinjam[100][50];
    int jumlah_dipinjam[100];
    login_admin(nama_admin);
    input_tanggal(&tanggal, &bulan, &tahun);
    do
    {
        system("cls");
        pilihan = menu_utama();
        switch (pilihan)
        {
        case 1:
            total += peminjaman(daftar_buku,
                                stok, buku_dipinjam,
                                jumlah_dipinjam,
                                &jumlah_data);
            break;
        case 2:
            tambah_stok(daftar_buku, stok);
            break;
        case 3:
            if (jumlah_data == 0)
            {
                printf("\n\t\t\t\t\tBelum ada data peminjaman!!\n");
                Sleep(1000);
            }
            else
            {
                cetak_bukti(nama_admin, tanggal,
                            bulan, tahun, buku_dipinjam,
                            jumlah_dipinjam,
                            jumlah_data, total);
            }
            break;
        case 4:
            printf("\n\t\t\t\t\tTerimakasih.\n");
            printf("\t\t\t\t\tProgram selesai!!\n");
            Sleep(500);
            printf("\n\t\t\t\t\tTekan apa saja untuk keluar!!\n");
            break;
        default:
            printf("\n\t\t\t\t\tMenu tidak tersedia!!\n");
            Sleep(1000);
        }
    } while (pilihan != 4);
    return 0;
}