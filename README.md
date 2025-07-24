# ft_printf

## 📝 Proje Açıklaması

Bu proje, standart C kütüphanesinin `printf()` fonksiyonunun kişisel bir implementasyonudur. Proje, C programlama dilinde değişken sayıda argümanlarla çalışan fonksiyonları (variadic functions) öğrenmeyi amaçlar.

> *"Çünkü ft_putnbr() ve ft_putstr() artık yeterli değil."*

## 📋 İçindekiler

1. [Giriş](#giriş)
2. [Gereksinimler](#gereksinimler)
3. [Kurulum ve Kullanım](#kurulum-ve-kullanım)
4. [Desteklenen Formatlar](#desteklenen-formatlar)
5. [Bonus Kısım](#bonus-kısım)

## 🚀 Giriş

Bu projede, C dilinin en çok kullanılan fonksiyonlarından biri olan `printf()` fonksiyonunu yeniden oluşturacağız. Bu orta düzeyde zorlukta bir projedir ve C'de variadic (değişken argümanlı) fonksiyonların nasıl çalıştığını anlamamızı sağlar.

Başarılı bir `ft_printf()` implementasyonu için temiz, yapılandırılmış ve genişletilebilir kod yazımı esastır. Projeyi tamamladıktan sonra, bu fonksiyonu kendi `libft` kütüphanenize dahil edebilirsiniz.

## 📌 Gereksinimler

- Proje C dilinde yazılmalıdır
- Kod, norm kurallarına tam olarak uymalıdır
- Tanımsız davranışlar dışında beklenmeyen çökmeler (segmentation fault, bus error, double free vb.) olmamalıdır
- Dinamik bellek tahsisleri doğru şekilde serbest bırakılmalıdır
- Makefile aşağıdaki kuralları içermelidir: `$(NAME)`, `all`, `clean`, `fclean` ve `re`
- Makefile `-Wall -Wextra -Werror` flagleriyle `cc` derleyicisini kullanmalıdır

## 💻 Kurulum ve Kullanım

### Proje için

Bu projede unbuffered yaklaşım var. Bu:
	- Basit ve anlaşılır
	- Çok fazla sistem çağrısı, performans arttırmak istenirse buffer kullanılabilir, büyük projelerde buffer kullanmalısın.

### Derleme

```bash
git clone <repo-url>
cd ft_printf
make
```

### Kütüphaneyi Kullanma

Projenizi derlerken şu şekilde bağlayın:

```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lftprintf
```

### Fonksiyon Prototipi

```c
int ft_printf(const char *format, ...);
```

## 🔍 Desteklenen Formatlar

| Format | Açıklama |
|--------|----------|
| `%c`   | Tek karakter yazdırır |
| `%s`   | String yazdırır |
| `%p`   | Pointer adresini hexadecimal olarak yazdırır |
| `%d`   | Signed decimal integer yazdırır |
| `%i`   | Signed decimal integer yazdırır (d ile aynı) |
| `%u`   | Unsigned decimal integer yazdırır |
| `%x`   | Hexadecimal değeri küçük harflerle yazdırır |
| `%X`   | Hexadecimal değeri büyük harflerle yazdırır |
| `%%`   | Yüzde işareti yazdırır |

## ⭐ Bonus Kısım

Zorunlu kısım tamamen tamamlandıktan sonra, aşağıdaki özellikleri ekleyebilirsiniz:

- `-0.` flagleri ve minimum genişlik yönetimi
- `# +` flagleri (boşluk dahil)

**Not:** Bonus özellikleri eklemek istiyorsanız, projeyi baştan bu desteği düşünerek tasarlamanız önerilir.

---

Bu proje, 42 Okulu müfredatının bir parçasıdır.
