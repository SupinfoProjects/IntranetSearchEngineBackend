SearchEngineB2
==============
A B2 End Year Project.

Création d'un SearchEngine (SE) qui permet aux compagnie et aux individus de protegé leur vie privée
Il fonctionnera avec des ressources mise à disposition par HTTP et FTP.

Ce n'est pas un InternetSearchEngine, c'est un IntranetSearchEngine

==============
FrontEnd:

Disponible par HTTP, les users doivent pouvoir rentrer une queries sur la page d'accueil du SE.

Il doit présenté les résultat par page et donner la possibilité de changer le nombre de résultat par page.

Les users doivent pouvoir soummettre une URL au robot pour que celui-ci crawl la page et l'index dans ses résultat.

==============
BackEnd:

SE doit pouvoir crawl des ressources, par HTTP et FTP.

SE doit pouvoir enregistrer les URLs et les "re-crawler" régulièrement pour mettre à jour sa table.

SE doit prendre en compte les liens fourni dans la parti FrontEnd par les users.

SE doit identifier chaque resources avec des "mot-clée" contenu dans un champ, ce champ et générer en utilisant la balise "meta-keywords" de HTML, les titres "h1", les "bolds", "filename", etc...

Les resources textes (HTML, txt, etc) sont storé dans la database du crawler.

Les resources binaires (archive, images, etc) ne sont ni storé, ni mise en cache dans la database.

Pour chaque query, SE doit en priorité cherché les mot-clée, ensuite il fait une recherche texte sur toute les resources textuel.

Le résultat de cette recherche est l'union de ces deux recherches.

Les résultat sont trié par score, le plus haut score, et mis en avant.

SE doit être écrit en C++.

A REVENIR

// You can made it available over HTTP using any webserver through its (Fast)CGI interface, for example, or ever write your own HTTPd, or patch an existing, etc. at your option. //
A REVENIR

POSSIBLEMENT EXEC PHP

==============
Architecture:

Pour l'instant on utilisera notre ESXi, en cas de besoin en pourra prendre ce serveur

http://www.online.net/fr/serveur-dedie/dedibox-classic

Les database seront obligatoirement du MySQL (Oracle, MS-SQL, PostgreSQL)
Solution No-SQL interdite (Cassandra, etc...) !

Les database doivent fonctionner en Cluster, au moins 4 obligatoire.

Il faut avoir une bonne répartition des charge (Haute Disponibilité)

Le serveur web de SE ne doit pas être sur une même machine :

Il faut que les 4 nodes se répartisent le travail en utilisant un cinquième node qui va être chargé uniquement de répartir les charges entre les VM (4+1).

Les clients ne se connecte pas directement au 4 nodes, ils se connecte au 5eme node qui va se faire passer pour les VM.

On utilisera des reverse proxy pour query les serveur web SE.

Le 5eme node enverra la query et la mettra en cache.

On utilisera un indicateur de charge pour chaque VM:

-1 = Down

0 = Libre

=<1 = Nombre d'user


Notation sur 120/100 pts :

Software (60pts)
	FrontEnd (20pts)
		-Search (5pts)
		-Diplay per page (5pts)
		-Choose number per page (5pts)
		-Submit URL for Crawl (5pts)

	BackEnd (40 pts)
		-Maintains a list of "known" resources (1pts)
		-Crawl periodic (3pts)
		-Can crawl over HTTP et FTP (3pts)
		-Follow links to other resources (5pts)
		-Compute a set of "significant words" for each resources (12pts)
		-Can store text resources (1pts)
		-Can perform a search on significant words and full text (5pts)
		-Return a sorted by score union of these two search (5pts)
		-Algorithm coefficient against back-end part : x0.8 - x1.3 soit 80% ou 130%

Architecture (50pts)
	-Database en Cluster (25pts)
	-DNS-baseed webserver Cluster (20pts)
	-User use a reverse proxy to query the SE (5pts)

Bonus (10pts)
	-bonus features (10pts)

==============
https://docs.google.com/document/d/16YPbSUNxWJkfHPuvdTEuGM5omrR5lE3DdGRDWObnX8g/edit?usp=sharing

Deadline le 21 Juin 2014 à 23h59
Il faudra joindre au rendu un liste avec tout les membres du groupe ainsi que leur ID
Il y aura une présentation (ppt) de 20 minutes sous la forme d'un rendez-vous de prévente (Jeu de role)

