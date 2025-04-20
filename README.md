> ![git text](/Security/img/IFS.png)

> [!NOTE]
> **Description:**
> - Script C++ ini saya buat untuk mengatur perlindungan baterai Android secara otomatis berdasarkan opsi yang dipilih.
<hr/>

> [!IMPORTANT]
> **Features:**
> 1. Battery lifespan extension: Menghentikan charging otomatis di 70%, 80%, atau 85%.
> 2. Automatic battery management: Tidak perlu monitoring manual saat charging.
> 3. Lightweight & fast: Script sederhana tanpa beban resource berat.
> 4. Safe to use: Tidak memodifikasi sistem permanen (reversible).
> 5. Easy to control: Cukup dengan opsi sederhana (-d, -L, -O, -R).
> - *Effectiveness may vary depending on the device and system firmware.*
<hr/>

> [!TIP]
> **Tips Before Use:**
> - Pastikan perangkat Android kamu sudah mengaktifkan `adb shell`.
> - Untuk fitur maksimal, beberapa perangkat mungkin membutuhkan akses root.
> - Gunakan pada perangkat yang mendukung kontrol charging melalui adb/sysfs.
<hr/>

> [!WARNING]
> **License & Credit Notice:**
> - Jika Anda ingin menggunakan atau menyertakan script ini dalam proyek lain/module, harap mencantumkan **credit** kepada pembuat asli.
> - Penggunaan tanpa izin atau perubahan tanpa mencantumkan sumber **adalah pelanggaran**.
> - Penulis tidak bertanggung jawab atas kerusakan/perubahan pada perangkat akibat penggunaan script ini.
<hr/>

<div style="background-color: #e7f3fe; padding: 10px; border-left: 6px solid #2196F3;">
<strong>Usage:</strong><br><br>
ChargerEfisen [OPTION]

- <code>-d</code> : Aktifkan proteksi di <strong>85%</strong>.
- <code>-L</code> : Aktifkan proteksi di <strong>80%</strong>.
- <code>-O</code> : Aktifkan proteksi di <strong>70%</strong>.
- <code>-R</code> : Reset baterai ke <strong>default</strong>.
- <code>-h</code>, <code>--help</code> : Bantuan pemakaian.
</div>


<h2>📚 Example Commands</h2>

<pre><code># Aktifkan proteksi 85%
ChargerEfisen -d

# Aktifkan proteksi 80%
ChargerEfisen -L

# Aktifkan proteksi 70%
ChargerEfisen -O

# Reset profil baterai
ChargerEfisen -R
</code></pre>

<hr/>

<h2>ℹ️ More Info</h2>

<ul>
<li><a href="https://developer.android.com/studio/command-line/adb" target="_blank">Android Developer Documentation</a></li>
<li><a href="https://forum.xda-developers.com" target="_blank">XDA Developers Community</a></li>
<li><a href="https://stackoverflow.com/questions/tagged/android" target="_blank">Stack Overflow Help & Q&A</a></li>
</ul>

<hr/>
