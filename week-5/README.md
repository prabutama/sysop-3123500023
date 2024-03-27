# PRAKTIKUM 5 
## Proses dan Manajemen Proses
### POKOK BAHASAN
- Proses pada Sistem Operasi Linux
- Manajemen Proses pada Sistem Operasi Linux
### TUJUAN BELAJAR
Setelah mempelajari materi dalam bab ini, mahasiswa diharapkan mampu:
- Memahami konsep proses pada sis tem operasi Linux.
- Menampilkan beberapa cara menampilkan hubungan proses parent dan child.
- Menampilkan status proses dengan beberapa format berbeda.
- Melakukan pengontrolan proses pada shell.
- Memahami penjadwalan prioritas.
### DASAR TEORI
#### 1.	KONSEP PROSES PADA SISTEM OPERASI LINUX
Proses adalah program yang sedang dieksekusi. Setiap kali menggunakan utilitas sistem atau program aplikasi dari shell, satu atau lebih proses ”child” akan dibuat oleh shell sesuai perintah yang diberikan. Setiap kali instruksi dibe rikan pada Linux shell, maka kernel akan menciptakan sebuah proses-id. Proses ini disebut juga dengan terminology Unix sebagai sebuah Job.   Proses Id (PID) dimulai dari 0, yaitu proses INIT, kemudian diikuti oleh proses berikutnya (terdaftar pada /etc/inittab).
Beberapa tipe proses :
- Foreground </br>
    Proses yang diciptakan oleh pemakai langsung pada terminal (interaktif, dialog)
- Batch </br>
    Proses yang dikumpulkan dan dijalankan secara sekuensial (satu persatu).   Prose Batch tidak diasosiasikan (berinteraksi) dengan terminal.
- Daemon </br>
    Proses yang menunggu permintaan (request) dari proses lainnya dan menjalankan tugas sesuai dengan permintaan tersebut. Bila tidak ada request, maka program ini akan berada dalam kondisi “idle” dan tidak menggunakan waktu hitung CPU. Umumnya nama proses daemon di UNIX berakhiran d, misalnya inetd, named, popd dll
#### 2. SINYAL
Proses dapat mengirim dan menerima sinyal dari dan ke proses lainnya. Proses mengirim sinyal melalui instruksi “kill” dengan format </br>
   
    kill [-nomor sinyal] PID
Nomor sinyal : 1 s/d maksimum nomor sinyal yang didefinisikan system Standar nomor sinyal yang terpenting adalah :

| No Sinyal | Nama       | Deskripsi      |
|-----------|------------|----------------|
| 1         | SIGHUP     | Hangup, sinyal dikirim bila proses terputus, misalnya melalui putusnya hubungan modem|
| 2         | SIGINT     | Sinyal interrupt, melalui ^C|
| 3         | SIGQUIT    | Sinyal Quit, melalui ^\|
| 9         | SIGKILL    | Sinyal Kill, menghentikan proses|
| 15        | SIGTERM    | Sinyal terminasi software|

#### 3. MENGIRIM SINYAL
Mengirim sinyal adalah satu alat komunikasi antar proses, yaitu memberitahukan proses yang sedang berjalan bahwa ada sesuatu yang harus dikendalikan. Berdasarkan sinyal yang dikirim ini maka proses dapat bereaksi dan administrator/programmer   dapat   menentukan   reaksi   tersebut.	Mengirim sinyal menggunakan instruksi

    kill [-nomor sinyal] PID
Sebelum mengirim sinyal PID proses yang akan dikirim harus diketahui terlebih dahulu.

#### 4. MENGONTROL PROSES PADA SHELL
Shell menyediakan fasilitas job control yang memungkinkan mengontrol beberapa job atau proses yang sedang berjalan pada waktu yang sama. Misalnya bila melakukan pengeditan file teks dan ingin melakukan interrupt pengeditan untuk mengerjakan hal lainnya. Bila selesai, dapat kembali (switch) ke editor dan melakukan pengeditan file teks kembali.</br>
Job bekerja pada <strong>foreground</strong> atau <strong>background</strong>. Pada foreground hanya diper untukkan untuk satu job pada satu waktu. Job pada foreground akan mengontrol shell - menerima input dari keyboard dan mengirim output ke layar. Job pada background tidak menerima input dari terminal, biasanya berjalan tanpa memerlukan interaksi</br>
Job pada foreground kemungkinan dihentikan sementara (suspend), dengan menekan [Ctrl-Z]. Job yang dihentikan sementara dapat dijalankan kembali pada foreground atau background sesuai keperluan dengan menekan <strong>”fg”</strong> atau <strong>”bg”</strong>. Sebagai catatan, menghentikan job seme ntara sangat berbeda dengan melakuakan interrupt job (biasanya menggunakan [Ctrl-C]), dimana job yang diinterrup akan dimatikan secara permanen dan tidak dapat dijalankan lagi.

#### 5. MENGONTROL PROSES LAIN
Perintah ps dapat digunakan untuk menunjukkan semua proses yang sedang berjalan pada mesin (bukan hanya proses pada shell saat ini) dengan format :

    ps –fae atau
    ps -aux
Beberapa versi UNIX mempunyai utilitas sistem yang disebut top yang menyediakan cara interaktif untuk memonitor aktifitas sistem. Statistik secara detail dengan proses yang berjalan ditampilkan dan secara terus-menerus di-refresh . Proses ditampilkan secara terurut dari utilitas CPU. Kunci yang berguna pada top adalah

    s – set update frequency
    u – display proses dari satu user
    k – kill proses (dengan PID)
    q – quit
Utilitas untuk melakukan pengontrolan proses dapat ditemukan pada sistem UNIX adalah perintah killall. Perintah ini akan menghentikan proses sesuai PID atau job number proses.

#### TUGAS PENDAHULUAN :
Jawablah pertanyaan-pertanyaan di bawah ini :
1.	Apa yang dimaksud dengan proses ?
    
        Suatu proses didefinisikan sebagai urutan instruksi yang dieksekusi dalam urutan yang telah ditentukan. Dengan kata sederhana, setiap program yang dijalankan disebut sebagai proses. Proses mengubah statusnya saat dijalankan dan dapat berupa baru, siap, berjalan, menunggu, atau dihentikan. Suatu proses di OS dikelola oleh Process Control Block (PCB) .

2.	Apa yang dimaksud perintah untuk menampilkan status proses :
ps, pstree.

        $ ps: Perintah pada linux untuk mengetahui tentang daftar proses bersama dengan informasi lain seperti PID.

        $ pstree: Perintah ini mirip dengan ps, tetapi alih-alih mendaftar proses yang sedang berjalan, ia menunjukkannya secara hierarki pohon. Format seperti pohon adalah cara yang lebih mudah untuk menampilkan hierarki proses dan membuat output lebih menarik secara visual.

3.	Sebutkan opsi yang dapat diberikan pada perintah ps

        -e: Menampilkan informasi tentang semua proses, bahkan yang dimulai oleh pengguna lain.

        -f: Menampilkan output dalam format yang lebih rinci, termasuk informasi seperti UID, PID, PPID, C, STIME, TTY, TIME, dan CMD.

        -l: Menampilkan output dalam format yang lebih panjang dengan informasi tentang setiap proses.

        -u <user>: Menampilkan informasi hanya tentang proses yang dimulai oleh pengguna tertentu.

        -aux atau -ef: Menampilkan semua proses dalam format yang panjang, termasuk informasi tentang pengguna, CPU, dan memori yang digunakan.

        -p <pid>: Menampilkan informasi tentang proses dengan PID tertentu.

        -o <format>: Mengizinkan Anda menentukan kolom-kolom tertentu yang ingin ditampilkan dalam output.

4.	Apa yang dimaksud dengan sinyal ? Apa perintah untuk mengirim sinyal ?

        Sinyal adalah peristiwa yang dihasilkan oleh sistem UNIX dan Linux sebagai respons terhadap kondisi tertentu . Setelah menerima sinyal, suatu proses dapat mengambil tindakan.
        Sinyal sama seperti interupsi; ketika dibuat di tingkat pengguna, panggilan dilakukan ke kernel OS, yang kemudian bertindak sesuai dengan itu.
5.	Apa yang dimaksud dengan proses foreground dan background pada job control ?

        Proses Foreground:
        - Proses foreground adalah proses yang berjalan dan berinteraksi langsung dengan pengguna melalui terminal.
        - Ketika suatu proses berjalan di foreground, terminal akan menunggu hingga proses tersebut selesai atau dihentikan sebelum kembali ke prompt perintah.
        - Proses foreground menerima input dari keyboard dan mengirim output ke terminal secara langsung.

        Proses Background:
        - Proses background adalah proses yang berjalan di latar belakang tanpa mengganggu interaksi pengguna dengan terminal.
        - Ketika suatu proses berjalan di background, pengguna masih bisa menggunakan terminal untuk menjalankan perintah-perintah lain tanpa harus menunggu hingga proses tersebut selesai.
        - Proses background biasanya digunakan untuk tugas yang membutuhkan waktu lama atau tidak memerlukan input langsung dari pengguna.
6.	Apa yang dimaksud perintah-perintah penjadwalan prioritas :
top, nice, renice.
        
        1. top:
        - top adalah perintah yang digunakan untuk menampilkan daftar proses yang sedang berjalan secara real-time, disertai dengan informasi tentang penggunaan CPU, memori, dan berbagai statistik sistem lainnya.
        - Perintah ini sangat berguna untuk memantau aktivitas sistem secara langsung, termasuk proses-proses yang memakan banyak sumber daya.

        2. nice:
        - nice adalah perintah yang digunakan untuk menjalankan proses dengan prioritas yang lebih rendah atau lebih tinggi.
        - Dengan menggunakan nice, pengguna dapat menentukan seberapa banyak prioritas CPU yang akan diberikan kepada suatu proses. Semakin tinggi nilai prioritas (biasanya dari -20 hingga 19), semakin sedikit waktu CPU yang akan dialokasikan ke proses tersebut.

        3. renice:
        - renice adalah perintah yang digunakan untuk mengubah prioritas CPU dari proses yang sedang berjalan.
        - Dengan menggunakan renice, pengguna dapat mengubah prioritas CPU suatu proses setelah proses tersebut dimulai.

#### PERCOBAAN:
1.	Login sebagai user.

    <img src="./media/p1-6.png"
      style="width:5.48945in; object-fit: cover;" />

2.	Download program   C++   untuk   menampilkan   bilangan   prima   yang   bernama
primes.

    <img src="./media/p-2.png"
      style="width:5.48945in; object-fit: cover;" />

3.	Lakukan percobaan-percobaan di bawah ini kemudian analisa hasil percobaan.
4.	Selesaikan soal-soal latihan.

#### Percobaan 1 : Status Proses
6.	Pindah ke command line terminal (tty2) dengan menekan Ctrl+Alt+F2
dan login ke terminal sebagai user.

    <img src="./media/p1-6.png"
      style="width:5.48945in; object-fit: cover;" />

7.	Instruksi ps (process status) digunakan untuk melihat kondisi proses yang ada. PID adalah Nomor Identitas Proses, TTY adalah nama terminal dimana proses tersebut aktif, STAT berisi S (Sleepin g) dan R (Running), COMMAND merupakan instruksi yang digunakan.

    $ ps

    <img src="./media/p1-7.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Ps digunakan untuk melihat proses yang ada

8.	Untuk melihat fak tor/elemen lainnya, gunakan option –u (user). %CPU adalah presentasi CPU time yang digunakan oleh proses tersebut, %MEM adalah presentasi system memori yang digunakan proses, SIZE adalah jumlah memori yang digunakan, RSS (Real System Storage) adalah jumlah memori yang digunakan, START adalah kapan proses tersebut diaktifkan

    $ ps -u

    <img src="./media/p1-8.png"
      style="width:5.48945in; object-fit: cover;" />

     Analisa : Ps -u digunakan untuk menampilkan proses yang berjalan beserta user

9.	Mencari proses yang spesifik pemakai. Proses diatas hanya terbatas pada proses milik pemakai, dimana pemakai teresbut melakukan login

    $ ps –u < user >

    <img src="./media/p1-9a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p1-9b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p1-9c.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : perintah tersebut digunakan untuk menampilkan proses pada user yang kita inginkan

10.	Mencari proses lainnya gunakan opsi a (all) dan au (all user)
    
    $ ps –a

    <img src="./media/p1-10a.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Digunakan untuk menampilkan proses pada user sekarang

    $ ps –au

    <img src="./media/p1-10b.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Digunakan untuk menampilkan proses semua user

11.	Logout dan tekan Alt+F7 untuk kembali ke mode grafis

    <img src="./media/p1-11.png"
      style="width:5.48945in; object-fit: cover;" />

#### Percobaan 2 : Menampilkan Hubungan Proses Parent dan Child
1. Pindah ke command line terminal (tty2) dengan menekan Ctrl+Alt+F2 dan login ke terminal sebagai user.

    <img src="./media/p1-6.png"
      style="width:5.48945in; object-fit: cover;" />

12.	Ketik ps –eH dan tekan Enter. Opsi e memilih semua proses dan opsi H menghasilkan tampilan proses secara hierarki. Proses child muncul dibawah proses parent. Proses child ditandai dengan awalan beberapa spasi.

    $ ps -eH

    <img src="./media/p2-12a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-12b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-12c.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-12d.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-12e.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Perintah diatas sama fungsinya dengan perintah ps pada perintah-perintah yang telah dijalankan sebelumnya yang perbedaanya hanya pada opsi yang ditambahkansetelahnya dimana pada perintah ps digabungkan dengan opsi– eH. Dan Ketika perintah ps – eH ini dieksekusi dengan cara menekan Enter, maka prosesnya akan berjalandengan cara membaca terlebih dahulu perintah ps yang kemudian dilanjutkan denganmembaca opsi e yang berfungsi memilih semua proses dan opsi H yang berfungsimenghasilkan tampilan proses secara hierarki.

13.	Ketik ps –e f dan tekan Enter. Tampilan serupa dengan langkah 2. Opsi
–f akan menampilkan status proses dengan karakter grafis (\ dan _)
    
    $ ps –e f

    <img src="./media/p2-13a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-13b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-13c.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-13d.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-13e.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Perintah serupa dengan tampilan dengan pada percobaan yang kedua diatas, yang hanya berbeda pada opsi yang ditambahkan dengan pada percobaan yang kedua diatas yang hanya berbeda pada opsi yang ditambahkan setelahe. diamana pada perintah ini ditambahkan opsi f yang berfungsi untuk mengetahui STAT (keadaan) darisebuah proses itu yang biyasanya ditandai dengan simbol S (sleeping) atau R (Running)

14.	Ketik pstree dan tekan Enter. Akan ditampilkan semua proses pada sistem dalam bentuk hirarki parent/child. Proses parent di sebelah kiri proses child. Sebagai contoh proses init sebagai parent (ancestor) dari semua proses pada sistem. Beberapa child dari init mempunyai child. Proses login mempunya i proses bash sebagai child. Proses bash mempunyai proses child startx. Proses startx mempunyai child xinit dan seterusnya.
    
    $ pstree

    <img src="./media/p2-14a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-14b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-14c.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Gambar diatas tampak struktur berupa sebuah pohon atau diagram. Yangmenyatakan system ditampilkan dalam bentuk hirarki parent/child. Proses parent disebelah kiri proses child.Sebagai contoh proses init sebagai parent (ancestor) dari semua proses pada sistem. Beberapa child dari init mempunyai child. Proses login mempunyai proses bash sebagai child. Proses bash mempunyai proses child startx. Proses startxmempunyai child xinit dan seterusnya hingga membentuk seperti pohon

15.	Ketik pstree | grep mingetty dan tekan Enter. Akan menampilkan semua proses mingetty yang berjalan pada system yang berupa console virtual. Selain menampikan semua proses, proses dikelompokkan dalam satu baris dengan suatu angka sebagai jumlah proses yang berjalan.

    $ pstree | grep mingetty

    <img src="./media/p2-15.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : perintah ini digunakan untuk menampilkan semua proses mingetty yang berjalan pada system yang berupa console virtual. Outputnya kosong karena tidak program mingetty pada OS saya

16.	Untuk melihat semua PID untuk proses gunakan opsi –p.
    
    $ pstree –p

    <img src="./media/p2-16a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-16b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-16c.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-16d.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-16e.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-16f.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-16g.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa :  Proses tampilan dari perintah ini serupa dengan tampilan pada perintah yangdilakukan pada proses praktikum bagian 5 dimana data ditampilkan menyerupai sebuah struktur diagram atau pohon. yang pada proses ini hanya ditambahkan dengan imformasi mengenai PID dari proses yang digunakan dengan menambahkan Opsi– p


17.	Untuk menampilkan proses dan ancestor yang tercetak tebal gunakan opsi
–h.

    $ pstree –h

    <img src="./media/p2-17a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-17b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p2-17c.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : perintah $ pstree yang kemudian ditambahkan opsi – h berfungsi Untuk menampilkan proses dan ancestor dengan cara ditampilkan atau dicetak tebal

#### Percobaan 3 : Menampilkan Status Proses dengan Berbagai Format
9.	Pindah ke command line terminal (tty2) dengan menekan Ctrl+Alt+F2 dan login ke terminal sebagai user.

    <img src="./media/p1-6.png"
      style="width:5.48945in; object-fit: cover;" />

10.	Ketik ps –e | more dan tekan Enter. Opsi -e menampilkan semua proses dalam bentuk 4 kolom : PID, TTY, TIME dan CMD.

    $ ps –e | more

    <img src="./media/p3-10a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-10b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-10c.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-10d.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-10e.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : menampilkan semua proses dalam bentuk 4 kolom :PID, TTY, TIME dan CMD.Yang kemudian disortir dengan menggunakan More.
    
    Jika halaman penuh terlihat prompt --More-- di bagian bawah screen, tekan q untuk kembali ke prompt perintah.

11.	Ketik ps ax | more dan tekan Enter. Opsi a akan menampilkan semua proses yang dihasilkan terminal (TTY). Opsi x menampilkan semua proses yang tidak dihasilkan terminal. Secara logika opsi ini sama dengan opsi –e . Terdapa 5 kolom : PID, TTY, STAT, TIME dan COMMAND.
    
    $ ps ax | more

    <img src="./media/p3-11a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-11b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-11c.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-11d.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-11e.png"
      style="width:5.48945in; object-fit: cover;" />

    Jika halaman penuh terlihat prompt --More-- di bagian bawah screen, tekan q untuk kembali ke prompt perintah.

    Analisa : Opsi a yang berfungsi menampilkan semua proses yang dihasilkan terminal,setelah itu dilanjutkan dengan membaca Opsi x yang berfungsi untuk menampilkan semua proses yang tidak dihasilkan terminal. Secara logika opsi ax ini sama dengan opsi – e. dimana Terdapat 5 kolom untuk tampilan informasih seperti : PID, TTY, STAT, TIMEdan COMMAND. Yang kemudian ditampilkan dengan cara disortir dengan menggunakanMore

12.	Ketik ps –e f | more dan tekan Enter. Opsi –e f akan menampilkan semua proses dalam format daftar penuh.
    
    $ ps ef | more

    <img src="./media/p3-12a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-12b.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Ketika perintah $ ps – e f | more dieksekusi maka Opsi– e f akan menampilkan semua proses dalam format daftar penuh. Yang kemudian disortir dengan menggunakanMore.

    Jika halaman penuh terlihat prompt --More-- di bagian bawah screen, tekan q untuk kembali ke prompt perintah.

13.	Ketik ps –eo pid, cmd | more dan tekan Enter. Opsi –eo akan menampilkan semua proses dalam format sesuai definisi user yaitu terdiri dari kolom PID dan CMD.
    
    $ ps –eo pid,cmd | more

    <img src="./media/p3-13a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-13b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-13c.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-13d.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-13e.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Ketika perintah ps– eo pid, cmd | more dieksekusi, maka prosesnya akan diawali dengan membaca perintah ps yang kemudian dilanjutkan dengan membaca Opsi – eo pid, cmd yang berfungsi untuk menampilkan semua proses dalam format sesuai definisi user yang terdiri dari kolom PID dan CMD

    Jika  halaman  penuh  et rlihat prompt   --More-- di  bagian  bawah  screen, tekan q untuk kembali ke prompt perintah.

14.	Ketik ps –eo pid,ppid,%mem,cmd | more dan tekan Enter. Akan menampilkan kolom PID, PPID dan %MEM.   PPID adalah proses ID dari proses parent. %MEM menampilkan persentasi memory system yang digunakan proses. Jika proses hanya menggunakan sedikit memory system akan dita mpilkan 0.

    $ ps –eo pid,ppid,%mem,cmd | more

    <img src="./media/p3-14a.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-14b.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-14c.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-14d.png"
      style="width:5.48945in; object-fit: cover;" />
    <img src="./media/p3-14e.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Ketika perintah ps – eo pid,ppid,%mem,cmd | more ini dieksekusi, maka prosesnya akan diawali dengan membaca perintah ps yang kemudian dilanjutkandengan membaca opsi – eo pid,ppid,%mem,cmd yang berfungsi untuk menampilkankolom PID, PPID dan %MEM. Dimana PPID adalah proses ID dari proses parentsedangkan %MEM menampilkan persentasi memory system yang digunakan proses

15.	Logout dan tekan Alt+F7 untuk kembali ke mode grafis

    <img src="./media/p1-11.png"
      style="width:5.48945in; object-fit: cover;" />

#### Percobaan 4 : Mengontrol proses pada shell
1.	Pindah ke command line terminal (tty2) dengan menekan Ctrl+Alt+F2 dan login ke terminal sebagai user.

    <img src="./media/p1-6.png"
      style="width:5.48945in; object-fit: cover;" />
2.	Gunakan perintah yes yang mengirim output y yang tidak pernah berhenti
    
    $ yes

    <img src="./media/p4-2.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : perintah yes ini digunakan untuk mengirim output y yang tidak pernah berhenti.

    Untuk menghentikannya gunakan Ctrl-C.

3.	Belokkan standart output ke /dev/null

    $ yes > /dev/null

    <img src="./media/p4-3.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa :Perintah ini digunakan membelokan standart output dari yes ke /dev/null

    Untuk menghentikannya gunakan Ctrl-C.

4.	Salah satu cara agar perintah yes tetap dijalankan tetapi shell tetap digunakan untuk hal yang lain dengan meletakkan proses pada background dengan
menambahkan karakter & pada akhir perintah.
    
    $ yes > /dev/null &

    <img src="./media/p4-4.png"
      style="width:5.48945in; object-fit: cover;" />
    
    Analisa : perintah yes tetap dijalankan tetapi shell lain tetap digunakan untuk hal laindengan meletakkan proses pada background dengan menambah karakter & pada akhir  perintah[1] merupakan job number pid

    Angka dalam ”[ ]” merupakan job number diikuti PID.
5.	Untuk melihat status proses gunakan perintah jobs.
    
    $ jobs

    <img src="./media/p4-5a.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Perintah ini digunakan untuk melihat proses yang telah digunakan

    Untuk menghentikan job, gunakan perintah kill diikuti job number atau PID proses.   Untuk identifikasi job number, diikuti prefix dengan karakter ”%”.
    
    $ kill %<nomor job>	contoh : kill %1

    <img src="./media/p4-5b.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : perintah diatas digunakan untuk menghentikan job untuk yes dan jobs untuk melihat proses yang telah diterminasi


4. Lihat status job setelah diterminasi
    
    $ jobs

    <img src="./media/p4-6.png"
      style="width:5.48945in; object-fit: cover;" />

    Analisa : Perintah ini digunakan untuk melihat proses yang telah digunakan






