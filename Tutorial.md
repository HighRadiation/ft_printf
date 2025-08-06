# ft_printf: Adım Adım Öğretici

Bu öğreticide, C dilinde kendi printf fonksiyonunuzu (ft_printf) nasıl yazacağınızı adım adım öğrenebilirsiniz.

---

## 1. Amaç

C'de printf fonksiyonu, biçimlendirilmiş çıktı almak için kullanılır. Bu projede, printf'in temel özelliklerini taklit eden kendi fonksiyonumuzu yazacağız.

---

## 2. Temel Fonksiyonun İskeletini Oluşturmak

İlk olarak, fonksiyonumuzun prototipini belirleyelim:

```c
int ft_printf(const char *format, ...);
```

Burada `...` değişken sayıda argüman alacağımızı gösterir. Bu yüzden `<stdarg.h>` kütüphanesini dahil etmeliyiz.

---

## 3. Format String’ini Okumak

Format stringini karakter karakter oku. `%` karakterini tespit ettiğinde, bir sonraki karakter format tipini belirler.

```c
#include <stdarg.h>
#include <unistd.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;
    
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            // Format türüne göre işle
            // örn: %d, %s, %c vs.
        }
        else
        {
            write(1, &format[i], 1);
            count++;
        }
        i++;
    }
    va_end(args);
    return count;
}
```

---

## 4. Temel Formatları Desteklemek

Şimdi en basitinden `%c` (karakter) ve `%s` (string) desteği ekleyelim:

```c
if (format[i] == 'c')
{
    char c = va_arg(args, int);
    write(1, &c, 1);
    count++;
}
else if (format[i] == 's')
{
    char *str = va_arg(args, char *);
    int j = 0;
    while (str && str[j])
    {
        write(1, &str[j], 1);
        count++;
        j++;
    }
}
```

---

## 5. Sayısal Formatları Eklemek

Sayıları ekrana basmak için önce sayıyı stringe çevirmek gerekir. Bunu kendi yardımcı fonksiyonunla yapabilirsin.

Örneğin pozitif bir tam sayıyı yazdırmak için:

```c
void ft_putnbr(int n, int *count)
{
    char c;
    if (n < 0)
    {
        write(1, "-", 1);
        (*count)++;
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10, count);
    c = (n % 10) + '0';
    write(1, &c, 1);
    (*count)++;
}
```

Ve printf içinde:

```c
else if (format[i] == 'd' || format[i] == 'i')
{
    int num = va_arg(args, int);
    ft_putnbr(num, &count);
}
```

---

## 6. Test Etme

Şimdi basit bir main.c dosyasıyla test edelim:

```c
#include "ft_printf.h"

int main()
{
    ft_printf("Karakter: %c\n", 'A');
    ft_printf("String: %s\n", "Merhaba");
    ft_printf("Sayi: %d\n", 42);
    return 0;
}
```

---

## 7. Hata Ayıklama ve İpuçları

- Her format tipi için ayrı fonksiyonlar yazarak kodunu temiz tut.
- Null pointer için `%s`'de `(null)` yazdırmayı unutma.
- Hexadecimal ve pointer (%x, %p) için kendi base conversion fonksiyonunu yazabilirsin.

---

## 8. Ekstra: Kendi Fonksiyonlarını Yaz

- `ft_strlen`, `ft_putstr`, `ft_itoa_base` gibi kendi fonksiyonlarını yazmak projede çok işine yarar.
- Format kontrolünü switch-case ile veya fonksiyon pointer array ile daha temiz yapabilirsin.

---

## 9. Sonuç

Bu öğretici temel bir ft_printf fonksiyonu yazmanı sağlayacak. Kademeli olarak diğer formatları (%u, %x, %X, %p, %%) da ekleyebilirsin.

Daha fazla örnek ve ileri düzey ipuçları için printf’in orijinal dokümantasyonuna ve open-source örneklere göz atabilirsin.

---

Başarılar!
