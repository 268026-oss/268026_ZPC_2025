+++
date = '2025-09-28T19:52:30+02:00'
draft = false
title = 'Mini-projekt 6 - Arduino/elektronika'
weight = 7
+++

# Mini projekt zameraný na elektroniku a programovanie Arduina

&nbsp;&nbsp;&nbsp;&nbsp;Zadaním tohoto projektu bolo vytvoriť jednoduchý program, ktorý bude vykonávať nejakú funkciu. Ja som sa rozhodol tento projekt skombinovať s mini-projektom 5 - 3D tlač. Plánoval som poháňať môj vytlačený 12 valcový model spaľovacieho motora pomocou elektromotora. Taktiež som chcel aby bolo možné regulovať jeho otáčky a aby sa zobrazovali na displeji.

## Komponenty:
Na tento projekt som využil tieto súčiastky:
- krokový motor typu NEMA17
- riadiaca doska pre krokové motory (Mikrostep driver)
- Arduino uno
- LCD displej bez nadstavby (shieldu)
- 2x rotačný enkóder typu KY-040
- napájací zdroj 24V - pre driver a krokový motor
- rezistory - 220 Ohm, 1k Ohm, 10k Ohm
- vodiče (drôty)

## Zapojenie:
&nbsp;&nbsp;&nbsp;&nbsp;V tejto časti budem vysvetľovať zapojenie. Schému som vytvoril na stránke https://app.cirkitdesigner.com. Túto stránku som zvolil preto, lebo mala dostupné presnie tie elektrické komponenty, ktoré som použil.

![Cirkit](/268026_ZPC_2025/images/cirkit.png)

Zapojenie je celkom zložité, preto je celé dostupné na stránke: https://app.cirkitdesigner.com/project/fcb505d5-ba25-4acf-94c2-e7bc1970280e.
Poskytujem aj tabuľky zapojenia:

## Arduino:
| Komponent | Označenie pinu | Komponent 2 | Označenie pinu 2 |
|:-------------|:----------:|:------------:|:------------:|
| Ardunino | D3 | Driver | PUL+ |
| - | D4 | - | DIR+ |
| - | D5 | - | ENA+ |
| - | D9 | Breadboard | 27 RS |
| - | D10 | - | 25 |
| - | D11 | - | 20 |
| - | D12 | - | 19 |
| - | D13 | - | 18 |
| - | A0 | - | 17 |
| - | GND1 | Breadboard | Modrá (-) |
| - | 5V | - | Červená (+) |
| - | GND2 | WAGO spojka | 1 |

## Driver:
| Komponent | Označenie pinu | Komponent 2 | Označenie pinu 2 |
|:-------------|:----------:|:------------:|:------------:|
| Driver | VCC | Zdroj | +24V |
| - | GND | - | GND |
| - | A+ | Krokový motor | A |
| - | A- | - | C |
| - | B+ | - | B |
| - | B- | - | D |
| - | PUL- | WAGO spojka | 2 |
| - | DIR- | WAGO spojka | 3 |
| - | ENA- | WAGO spojka | 4 |

## Breadboard/displej:
| Komponent | Označenie pinu | Komponent 2 | Označenie pinu 2 |
|:-------------|:----------:|:------------:|:------------:|
| Breadboard | 30 VSS | Breadboard | Modrá (-) |
| - | 29 VDD | - | Červená (+) |
| - | 28 VO | - | 9 |
| - | 9 | - | 10k Ohm - Červená (+) |
| - | 9 | - | 1k Ohm - Modrá (-) |
| - | 26 R_S | - | Modrá (-) |
| - | 16 A | - | 220 Ohm - Čevená(+) |
| - | 15 K | - | Modrá (-) |

## Ovládací enkóder:
| Komponent | Označenie pinu | Komponent 2 | Označenie pinu 2 |
|:-------------|:----------:|:------------:|:------------:|
| Enkóder | CLK | Arduino | D6 |
| - | DT | - | D7 |
| - | SW | - | D8 |
| - | + | Breadboard | Červená (+) |
| - | GND | - | Modrá (-) |

## Merací enkóder:
| Komponent | Označenie pinu | Komponent 2 | Označenie pinu 2 |
|:-------------|:----------:|:------------:|:------------:|
| Enkóder | CLK | Arduino | A1 |
| - | DT | - | A2 |
| - | + | Breadboard | Červená (+) |
| - | GND | - | Modrá (-) |

## Vysvetlenie zapojenia:
Zapojenie vysvetlím rašej po častiach.

1. Microstep Driver
- VCC a GND sú + a - pre napájanie zo zdroja 24V. 
- A+, A-, B+, B- sú piny na ovládanie motora. 
- PUL je signál z arduina (pulzy) pre otáčanie motora. 
- DIR je pre ovládanie smeru otáčania motora. 
- ENA je pre aktiváciu motora.

2. Displej
Keďže displej nemal dodatočnú nadstavbu I2C tak bolo potrebné zapojiť viacej pinov. Ak by mal aj I2C jednotku bolo by zapojenie jednoduchšie. Zapojenie:
- VSS je mínus.
- VDD je napájanie.
- VO je pin pre nastavenie kontrastu textu displeja. Toto by normálne spravovala jednotka I2C ale tú bohužiaľ nemám k dispozícii. Bolo potrebné na tento pin priviesť cca 0,5V, čo má byť ideálny kontrast pre túto aplikáciu. Preto som využil rezistory (10k Ohm a 1k Ohm) a vytvoril tak delič napätia.
- RS je register select.
- R_W používam iba zápis takže ide na GND.
- E je enable - zapnutie displeja.
- D4 až D7 sú digitálne piny pre zobrazovanie textu. Zapájajú sa priamo do arduina.
- A je napájanie pre podsvietenie displeja. Je tu daný 220 Ohmový rezistor pre zníženie jasu.
- K je zemnenie pre podsvietenie takže ide do GND.

3. Ovládací enkóder
Pomocou tohto enkódera sa ovládajú otáčky, smer a zapnutie/vypnutie krokového motora. Otáčaním doprava sa otáčky zvyšujú a doľava znižujú. Stlačením sa prepína smer otáčania a dlhým podržaním sa motor vypne.

4. Merací enkóder
Slúži na merania otáčok za minútu, keďže jeho jedna celá otáčka pozostáva z 20 polôh. Je zapojený podobne ako ovládací enkóder.

## Kód:
Kód je dostupný na tomto linku:
📥 [Stiahnuť Arduino kód]( /268026_ZPC_2025/files/KodPreMotor.ino )


## Výsledok:
&nbsp;&nbsp;&nbsp;&nbsp;Tento projekt sa mi podaril celkom dobre. Je tu stále miesto na zlepšenie, napríklad: I2C modul pre displej alebo presnejšie meranie otáčok. Nepresnosť otáčok som spočítal a je približne 0-7 RPM, čo nie až také zlé ale mohlo byť lepšie. S projektom som ale celkom spokojný, všetko funguje tak ako má. Jediné čo by som vytkol je trošku zložité zapájanie, keďže bolo potrebné využiť veľa pinov arduina.

## Video:
<video controls width="640">
  <source src="/268026_ZPC_2025/videos/videomotor.mp4" type="video/mp4">
</video>