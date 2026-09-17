# 📚 Sistem Informasi Peminjaman Buku Perpustakaan

Program **Sistem Informasi Peminjaman Buku Perpustakaan** merupakan mini project yang dibuat menggunakan bahasa pemrograman **C**. Program ini dibuat untuk membantu proses sederhana dalam peminjaman buku, pengelolaan stok buku, serta pencetakan bukti peminjaman.

Project ini dibuat sebagai latihan untuk memahami dasar-dasar pemrograman bahasa C, khususnya penggunaan **array, fungsi, percabangan, perulangan, validasi input, string, dan pengelolaan data sederhana**.

---

## 🎯 Tujuan

Program ini bertujuan untuk:

* Mempraktikkan penggunaan bahasa C dalam sebuah program sederhana.
* Mengimplementasikan fungsi dalam pemrograman C.
* Memahami penggunaan array satu dimensi dan multidimensi.
* Melatih penggunaan percabangan dan perulangan.
* Membuat validasi input dari pengguna.
* Membuat sistem peminjaman buku sederhana.
* Mengelola stok buku berdasarkan transaksi peminjaman.
* Menampilkan bukti peminjaman kepada pengguna.

---

## ✨ Fitur Program

Program memiliki beberapa fitur utama:

### 🔐 1. Login Admin

Sebelum menggunakan program, admin harus melakukan login.

* Input nama admin
* Input password
* Validasi password
* Password yang digunakan:

```text
12345
```

Jika password salah, admin akan diminta melakukan login kembali.

---

### 📅 2. Input Tanggal

Program meminta admin memasukkan:

* Tahun
* Bulan
* Tanggal

Program juga melakukan validasi tanggal berdasarkan jumlah hari dalam bulan.

Program dapat mengenali **tahun kabisat**, sehingga bulan Februari dapat memiliki 29 hari pada tahun tertentu.

Rentang tahun yang dapat dimasukkan:

```text
2000 - 2030
```

---

### 📖 3. Peminjaman Buku

Admin dapat memilih buku yang ingin dipinjam berdasarkan kode buku.

Program akan meminta:

* Kode buku
* Jumlah buku yang dipinjam

Sistem akan melakukan pengecekan:

* Kode buku valid atau tidak
* Jumlah peminjaman harus lebih dari 0
* Stok buku mencukupi atau tidak

Setelah peminjaman berhasil, stok buku akan otomatis berkurang.

Admin juga dapat menambahkan buku lain dalam satu proses peminjaman.

---

### 📦 4. Tambah Stok Buku

Admin dapat menambahkan stok buku yang tersedia.

Admin memilih:

1. Kode buku
2. Jumlah stok yang ingin ditambahkan

Program kemudian memperbarui jumlah stok buku secara otomatis.

---

### 🧾 5. Bukti Peminjaman

Program dapat menampilkan bukti peminjaman yang berisi:

* Nama admin
* Tanggal peminjaman
* Judul buku
* Jumlah buku yang dipinjam
* Total buku yang dipinjam
* Status peminjaman

Contoh tampilan:

```text
================== BUKTI PEMINJAMAN ==================
Admin   : Fad
Tanggal : 17/09/2026
------------------------------------------------------
No   Judul Buku              Jumlah
------------------------------------------------------
1    Laskar Pelangi          2
2    Bumi                    1
------------------------------------------------------
Total Buku Dipinjam : 3
Status : Berhasil
------------------------------------------------------
Terima Kasih
======================================================
```

---

## 📚 Daftar Buku

Program menyediakan 20 jenis buku:

| No | Judul Buku          |
| -: | ------------------- |
|  1 | Laskar Pelangi      |
|  2 | Bumi                |
|  3 | Atomic Habits       |
|  4 | Algoritma           |
|  5 | Pemrograman C       |
|  6 | Matematika Dasar    |
|  7 | Fisika Dasar        |
|  8 | Kimia Dasar         |
|  9 | Sejarah Indonesia   |
| 10 | Bahasa Inggris      |
| 11 | Bulan               |
| 12 | Matahari            |
| 13 | Komet               |
| 14 | Meteor              |
| 15 | Si Putih            |
| 16 | Negeri Para Bedebah |
| 17 | Pengantar Akuntansi |
| 18 | Romeo And Juliet    |
| 19 | Struktur Data       |
| 20 | Basis Data          |

---

## 🖥️ Menu Utama

Setelah login dan input tanggal berhasil, program menampilkan menu:

```text
==================== MENU ====================
1. Peminjaman Buku
2. Tambah Stok Buku
3. Lihat Bukti Peminjaman
4. Keluar
Pilih :
```

### Penjelasan Menu

**1. Peminjaman Buku**
Digunakan untuk melakukan transaksi peminjaman buku.

**2. Tambah Stok Buku**
Digunakan untuk menambahkan jumlah stok buku.

**3. Lihat Bukti Peminjaman**
Digunakan untuk melihat data peminjaman yang telah dilakukan.

**4. Keluar**
Digunakan untuk mengakhiri program.

---

## 🧠 Konsep Pemrograman yang Digunakan

Project ini menggunakan beberapa konsep dasar bahasa C, yaitu:

### 1. Function

Program dibagi menjadi beberapa fungsi agar kode lebih terstruktur.

Contohnya:

```c
void login_admin(char nama_admin[])
```

```c
void input_tanggal(int *tanggal, int *bulan, int *tahun)
```

```c
void tambah_stok(char daftar_buku[][50], int stok[])
```

```c
int peminjaman(...)
```

```c
void cetak_bukti(...)
```

---

### 2. Array

Array digunakan untuk menyimpan daftar buku dan stok.

Contohnya:

```c
char daftar_buku[20][50];
```

dan:

```c
int stok[20];
```

Array multidimensi digunakan untuk menyimpan nama atau judul buku dalam bentuk string.

---

### 3. Percabangan

Percabangan `if`, `else if`, dan `else` digunakan untuk menentukan kondisi program.

Contohnya digunakan untuk:

* Validasi password
* Validasi tanggal
* Validasi stok
* Validasi jumlah peminjaman
* Menentukan pilihan menu

---

### 4. Perulangan

Program menggunakan `do-while` dan `while` untuk proses yang harus dilakukan berulang kali.

Contohnya:

* Login ulang ketika password salah
* Meminta input tanggal kembali ketika tidak valid
* Memastikan kode buku valid
* Memastikan jumlah peminjaman sesuai stok
* Menambahkan lebih dari satu buku dalam transaksi

---

### 5. String

Library:

```c
#include <string.h>
```

digunakan untuk mengolah data berupa teks.

Beberapa fungsi string yang digunakan:

```c
strlen()
strcmp()
strcpy()
```

---

### 6. Pointer

Pointer digunakan pada beberapa fungsi untuk mengubah nilai variabel yang berasal dari `main()`.

Contohnya:

```c
void input_tanggal(int *tanggal, int *bulan, int *tahun)
```

Pointer juga digunakan untuk menyimpan jumlah data peminjaman:

```c
int *jumlah_data
```

---

### 7. Validasi Input

Program menggunakan validasi agar data yang dimasukkan pengguna sesuai dengan aturan.

Contohnya:

```text
Kode buku harus 1 - 20
Jumlah pinjam harus lebih dari 0
Jumlah pinjam tidak boleh melebihi stok
Bulan harus 1 - 12
Tahun harus 2000 - 2030
```

---

## 📁 Struktur Project

Struktur utama project:

```text
MINI PROJECT NEW/
│
├── main.c
├── riska.c
│
├── .vscode/
│   ├── c_cpp_properties.json
│   ├── launch.json
│   └── settings.json
│
└── README.md
```

### `main.c`

Berisi kode program C utama/versi awal yang digunakan dalam proses pengembangan project.

### `riska.c`

Berisi implementasi utama program Sistem Informasi Peminjaman Buku Perpustakaan.

### `.vscode/`

Berisi konfigurasi Visual Studio Code untuk membantu proses compile, debugging, dan pengaturan compiler C.

---

## ⚙️ Teknologi yang Digunakan

* **Bahasa:** C
* **Compiler:** GCC / MinGW
* **IDE:** Visual Studio Code
* **Operating System:** Windows
* **Library yang digunakan:**

  * `stdio.h`
  * `string.h`
  * `stdlib.h`
  * `windows.h`

---

## 🚀 Cara Menjalankan Program

### 1. Clone Repository

Clone repository dari GitHub ke komputer:

```bash
git clone <URL-REPOSITORY>
```

Kemudian masuk ke folder project:

```bash
cd "MINI PROJECT NEW"
```

---

### 2. Compile Program

Jika menggunakan GCC/MinGW, jalankan:

```bash
gcc riska.c -o riska
```

---

### 3. Jalankan Program

Di Windows:

```bash
riska.exe
```

atau:

```bash
.\riska.exe
```

---

## 🔑 Login Program

Gunakan password:

```text
12345
```

Nama admin dapat diisi sesuai kebutuhan.

---

## 🔄 Alur Program

Secara sederhana, alur program adalah:

```text
Mulai
  ↓
Login Admin
  ↓
Validasi Login
  ↓
Input Tanggal
  ↓
Menu Utama
  ↓
┌───────────────────────────┐
│ 1. Peminjaman Buku        │
│ 2. Tambah Stok Buku       │
│ 3. Lihat Bukti Peminjaman │
│ 4. Keluar                 │
└───────────────────────────┘
  ↓
Proses sesuai pilihan
  ↓
Kembali ke Menu
  ↓
Keluar
  ↓
Selesai
```

---

## 🎓 Tujuan Pembelajaran

Melalui project ini, pembelajaran yang diperoleh meliputi:

* Memahami struktur dasar program C.
* Membuat dan memanggil fungsi.
* Menggunakan array untuk menyimpan data.
* Menggunakan array multidimensi untuk data string.
* Menggunakan pointer sebagai parameter fungsi.
* Menggunakan percabangan untuk pengambilan keputusan.
* Menggunakan perulangan untuk proses berulang.
* Melakukan validasi input pengguna.
* Mengolah string menggunakan library `string.h`.
* Membuat program console dengan alur yang lebih terstruktur.

---

## 👩‍💻 Author

**Riska Fadhilah Dalimunthe**

Mini Project Pemrograman Bahasa C

---

## 📌 Catatan

Project ini dibuat sebagai **mini project pembelajaran bahasa C**. Program masih menggunakan penyimpanan data di dalam array sehingga data tidak tersimpan secara permanen setelah program ditutup.

Project ini dapat dikembangkan lebih lanjut dengan menambahkan:

* Penyimpanan data menggunakan file.
* Fitur pengembalian buku.
* Data anggota perpustakaan.
* Riwayat transaksi.
* Denda keterlambatan.
* Pencarian buku.
* Penambahan dan penghapusan data buku.
* Database untuk penyimpanan data secara permanen.
