+++
date = '2025-09-28T19:52:30+02:00'
draft = false
title = 'Semestrálny projekt'
weight = 1
+++

&nbsp;&nbsp;&nbsp;&nbsp;V rámci výuky je aj semestrálny projekt. Tému pre tento projekt si volíme sami na základe tématiky Jak vyrobit (téměř) cokoliv - How to make (almost) anything. Tento projekt by mal obsahovať prvky 3D tlače, laserového rezania a elektroniky (arduino).

&nbsp;&nbsp;&nbsp;&nbsp;Ja som si za tému zvolil systém pre elektronické terče. Ide o systém, ktorý bude riadiť svetlá (červené a zelené) na terčoch a bude tým signalizovať kedy strelci majú strielať a kedy nie. Bude sa to využívať najmä pri rýchlopalných disciplínach kedy majú strelci len pár sekúnd na výstrel. Okrem prepínania svetiel bude mať systém aj rozpoznávanie neplatného výstrelu - ak bude výstrel mimo času, kedy je povolený (mimo zelené svetlo). 

Systém si predstavujem takto:
![Terce Koncept](/268026_ZPC_2025/images/tercekoncept.png)

&nbsp;&nbsp;&nbsp;&nbsp;Hlavným komponentom je riadiaca doska. Tá bude slúžiť ako ovládací prvok. Bude možné na nej voliť jednotlivé programy, bude ukazovať stav systému, čas a tiež ak nastane výstrel mimo času tak sa zobrazí a zobrazí sa aj na ktorom mieste (stave) sa to stalo. Riadiaca doska bude mať displej kde sa tieto informácie budú zobrazovať a tlačidlá, ktorými sa bude ovládať. Srdcom budem arduino, na ktoré sa nahrá program. Riadiaca doska bude mať samozrejme aj napájanie, pravdebodobne bude mať v sebe zdroj ktorý bude premieňať 230V na 5v pre arduino a taktiež napájať svetielka.
