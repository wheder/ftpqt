# Introduction #

Mrknete na to prosim kluci na prilozenem jpegu, je takovy navrh jak jsem si
asi predstavoval, jak takovy server vypada.

# Details #

Lehky popis:
1) FTP paket se prijme (=odeslani prijmuti atd overeni plnosti...)a zaradi
> do fronty, pokud je jeste misto
2) pak se dekoduje pomoci imlementovaneho protokolu na nejaky jednodussi
> zapis obsahujici cilovou adresu, nazev souboru a posledni odeslany bajt
> a ulozi do sve fronty takovych souboru
3) z te si to postupne berou volna vlakna, ktere spravuje centralni rizeni
> to tak, ze vzdy pujci vlakno jednomu prvku z fronty na nastavenou dobu
> (cca 2000ms) obstara odesilani bajtu, na konci doby, zpet prvek do fronty
> ulozi s poslednim bajtem, ktery se odeslal
4) samotne vlakno provadi to, ze krom vyberu prvku z cela fronty, bere z
> cache souboru data, nebo si zazada z perzistentniho zdroje (to SQL je
> jen symbolicky)
5) urcity pocet bajtu zakoduje do FTP
6) a bud odesle nebo nejprve overi zda jeste klient ceka a popripade
> odstrani cely prvek z fronty

Pokud jsou nejaky obdelniky nejasny tak sem napiste nazev, zkusim to vysvetlit.

FTP Protokol = implementace casti tohohle protokolu, ktere potrebujeme

# Downloads #

![http://ftpqt.googlecode.com/files/002.jpg](http://ftpqt.googlecode.com/files/002.jpg)