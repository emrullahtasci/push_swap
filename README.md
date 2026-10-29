# push_swap

![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)
![42 Kocaeli](https://img.shields.io/badge/42-Kocaeli-000000?style=flat-square&logo=42&logoColor=white)

İki stack ve sınırlı sayıda işlemle bir tam sayı dizisini **en az hamlede** sıralayan
bir C programı. Girdinin ne kadar karışık olduğunu ölçen bir **disorder metriği**,
dört farklı sıralama stratejisi ve hamle sayılarını raporlayan bir **benchmark modu**
içerir.

## Nasıl çalışır?

Sayılar `a` stack'ine yüklenir, `b` stack'i boş başlar. Program sadece aşağıdaki
11 işlemi kullanarak `a`'yı küçükten büyüğe sıralar ve kullandığı işlemleri sırayla
ekrana yazar.

| İşlem | Açıklama |
| --- | --- |
| `sa` / `sb` / `ss` | `a` / `b` / ikisinin en üstteki iki elemanını yer değiştirir |
| `pa` / `pb` | `b`'nin tepesini `a`'ya / `a`'nın tepesini `b`'ye taşır |
| `ra` / `rb` / `rr` | `a` / `b` / ikisini bir yukarı döndürür (ilk eleman sona gider) |
| `rra` / `rrb` / `rrr` | `a` / `b` / ikisini bir aşağı döndürür (son eleman başa gelir) |

```
$ ./push_swap 3 2 1
sa
rra
```

## Derleme

```bash
make        # push_swap programını derler (libft dahil)
make clean  # .o dosyalarını siler
make fclean # .o dosyalarını ve programı siler
make re     # baştan derler
```

## Kullanım

```bash
./push_swap 4 67 3 87 23          # ayrı argümanlar
./push_swap "4 67 3 87 23"        # tek string
./push_swap --complex 5 1 4 2 3   # strateji seçerek
./push_swap --bench 5 1 4 2 3     # hamle istatistikleriyle
```

Sonucu 42'nin verdiği checker programıyla doğrulamak için:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```

### Bayraklar

| Bayrak | Strateji | Algoritma | Karmaşıklık |
| --- | --- | --- | --- |
| `--simple` | Simple | 3 eleman için sabit kurallar, fazlası için en küçüğü `b`'ye atma (selection) | O(n²) |
| `--medium` | Medium | Chunk sort | O(n√n) |
| `--complex` | Complex | İndeksler üzerinde radix sort (100 ve altı için chunk sort) | O(n log n) |
| `--adaptive` | Adaptive *(varsayılan)* | Girdinin karışıklığına göre en uygun stratejiyi seçer | duruma göre |
| `--bench` | | Bitince disorder, strateji ve işlem sayılarını `stderr`'e yazar | |

## Stratejiler

### Disorder metriği

Girdinin ne kadar karışık olduğunu ölçmek için tüm sayı çiftlerine bakılır ve
yanlış sırada olan çiftlerin (inversion) oranı hesaplanır:

```
disorder = yanlış sıradaki çift sayısı / toplam çift sayısı
```

`0.0` tamamen sıralı, `1.0` tamamen ters sıralı bir dizi demektir.

### Adaptive seçim

```
eleman sayısı ≤ 5  → Simple
disorder < 0.2     → Simple   (neredeyse sıralı dizi)
disorder < 0.5     → Medium
disorder ≥ 0.5     → Complex
```

### Simple: küçük diziler ve selection

- **2 eleman:** gerekiyorsa tek `sa`.
- **3 eleman:** 6 olası sıralamanın her biri için sabit bir kural; en fazla 2 hamle.
- **Daha fazlası:** En küçük eleman en kısa yoldan (`ra` ya da `rra`) tepeye getirilip
  `b`'ye atılır. 3 eleman kalınca sıralanır ve `b`'deki elemanlar geri alınır.

### Medium: chunk sort

1. Her sayıya sıralı hâlindeki yerine göre bir **indeks** (0, 1, 2, …) verilir.
2. İndeksler eşit aralıklara (chunk) bölünür; aralık sayısı dizi boyutuna göre
   2, 5, 8 veya 11 olur.
3. Her chunk'taki elemanlar en kısa yoldan tepeye getirilip `b`'ye atılır.
4. `b`'den her seferinde en büyük eleman bulunup `a`'ya geri alınır.

### Complex: radix sort

Sayıların kendisi yerine 0'dan başlayan indeksleri kullanılır, böylece negatif
sayılar sorun olmaz. Her bit için: biti 0 olanlar `b`'ye atılır (`pb`), 1 olanlar
döndürülür (`ra`), sonra hepsi `a`'ya geri alınır. Hamle sayısı tahmin edilebilirdir
ve büyük dizilerde iyi sonuç verir.

## Performans

Rastgele dizilerle ölçülen ortalama hamle sayıları:

| Boyut | Adaptive | Simple | Medium | Complex |
| --- | ---: | ---: | ---: | ---: |
| 3 | 1 | 1 | 1 | 1 |
| 5 | 8 | 8 | 8 | 7 |
| 100 | 781 | 1458 | 778 | 781 |
| 500 | 7220 | 32701 | 7408 | 6784 |

Neredeyse sıralı girdilerde Adaptive daha az hamleyle bitirir; örneğin 100 sayıda
ortalama 355 hamle.

### `--bench` örneği

```
$ ./push_swap --bench 5 3 1 4 2 > /dev/null
[bench] disorder: 70.00%
[bench] strategy: Adaptive / O(n^2)
[bench] total_ops: 8
[bench] sa: 0  sb: 0  ss: 0  pa: 2  pb: 2
[bench] ra: 4  rb: 0  rr: 0  rra: 0  rrb: 0  rrr: 0
```

## Hata yönetimi

Aşağıdaki durumlarda program `stderr`'e `Error` yazar ve çıkar:

- Sayı olmayan bir argüman (`1 a 3`)
- `int` sınırlarının dışında bir sayı (`2147483648`)
- Tekrar eden bir sayı (`1 2 2`, `-0 0`)
- Bilinmeyen bir bayrak (`--foo`)

Argüman verilmezse ya da dizi zaten sıralıysa hiçbir şey yazmaz.

## Proje yapısı

```
.
├── Makefile
├── push_swap.h
├── src/            # main, argüman ayrıştırma, indeksleme, strateji seçimi, hata
├── stack/          # bağlı liste tabanlı stack fonksiyonları
├── operations/     # sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
├── algorithms/     # simple, chunk, radix ve adaptive sort
├── metrics/        # disorder hesabı
├── bench/          # --bench çıktısı
└── libft/          # kendi C kütüphanemiz
```

## Ekip

| | |
| --- | --- |
| **Emrullah Taşcı** | [@emrullahtasci](https://github.com/emrullahtasci) |
| **Miraç Ege Kotan** | [@Mirac-Ege](https://github.com/Mirac-Ege) |

42 Kocaeli, 2026
