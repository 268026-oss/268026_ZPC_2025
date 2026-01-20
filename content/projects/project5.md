+++
date = '2025-09-28T19:52:30+02:00'
draft = false
title = 'Mini-projekt 5 - 3D tlač'
weight = 6
+++

# Mini projekt na 3D tlač

&nbsp;&nbsp;&nbsp;&nbsp;Zadaním tohoto projektu bolo vytvoriť mechanizmus s minimalne jedným uložením s presahom a jedným uložením na voľno. Následne bolo potrebné tento mechanizmus vytlačiť na 3D tlačiarňach a zložiť. Podmienkou bolo využiť do 100g filamentu.

&nbsp;&nbsp;&nbsp;&nbsp;Ja som sa rozhodol vytvoriť zmenšeninu spaľovacieho 12 valcového motora. Motor by mal kľukový mechanizmus s piestami, ojnicami a kľukovou hriadeľou. Zároveň som chcel prepojiť tento projekt s následujúcim projektom o elektronike a to tak, že by sa motor otáčal s pomocou elektroniky (viac o tejto téme v miniprojekte 6).

&nbsp;&nbsp;&nbsp;&nbsp;Začal som dizajnom vo Fusion 360. Tento program som zvolil kvôli jeho jednoduchosti, širokým možnostiam a je to program, v ktorom som robil svoje prvé projekty. Čo sa týka modelu zvolil som následovné parametre:
- zdvih: 15mm
- priemer valca: 15mm
- uhol medzi valcami: 60°
&nbsp;&nbsp;&nbsp;&nbsp;Potom ako som si stanovil tieto základné geometrické vlastnosti som začal s modelovaním. Rozhodol som sa do modelu pridať aj steper elektromotor a rotačný enkóder, čo sú súčiastky, ktoré využijem neskôr pri ďalšom miniprojekte. Dôležité bolo správne nastaviť tolerancie, aby komponenty správne pasovali a otáčali sa. Ak som potreboval nejaké spojenie, ktoré musí byť pevne spojené (nepohyblivé) použil som nulovú toleranciu. Ak som potreboval pohyblivé zvolil som 0,2mm (pri kruhovom priemere 0,1mm z každej strany). Toto určenie bolo veľmi dôležité, keďže som kľukovú hriadeľ rozdelil na viacero častí, aby ju bolo možné poskladať.

## Tatko vyzeral model po dokončení:

![Motor](/268026_ZPC_2025/images/Motor.png)

&nbsp;&nbsp;&nbsp;&nbsp;Ďalej som každú časť motora vyexportoval do .stl formátu a importoval do Prusa sliceru. Tam som na blok motora nastavil podpory (support) a na malé súčiatky (ojnice, piesty, čapy, kľuková hriadeľ) som nastavil brim, aby sa neodlepili od podložky. Tlačil som z materiálu PLA a z bielej a oranžovej farby aby boli jednotlivé diely ľahko rozoznateľné. Pre rýchlosť a výšku jednej vrstvy som zvolil z prednastavených parametrov 0,2mm structural. Tlač som realizoval na viackrát, keďže som použil 2 farby filamentu.

## Po vytlačení:
![Motortlac](/268026_ZPC_2025/images/motorvytlaceny.jpg)

&nbsp;&nbsp;&nbsp;&nbsp;Po vytlačení som odstárnil podpory, mierne obrúsil pár nedostatkov a namazal pohyblivé časti. Následne som začal celý model skladať. Tento krok bol celkom náročný, pretože viacero komponentov sa muselo skladať naraz a motor je pomerne malý - je tam málo miesta. Po zložení motora som pridal na jednu stranu motora steper motor s vytlačeným ozubeným kolesom a na druhú rotačný enkóder. Celkovo som využil približne 109g filamentu.

## Výsledný model:
![Motorkomplet](/268026_ZPC_2025/images/motorkomplet.jpg)
