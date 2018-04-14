# lem-in
Le lem-in est le troisième projet de la branche algorithme du cursus de l’école 42.
Il s’agit d’un programme capable de lire dans un fichier ou sur l’entrée standard la définition d’une fourmilière composée de salles reliées entre elles par des tubes.
# Création d’une fourmilière
Une fourmilière est définie de la manière suivante:

	nombre_de_fourmis
	les_salles
	les_tubes
Voici un exemple de fourmilière possible:

	42
	##start
	1 23 3
	2 16 7
	#commentaire
	3 16 3
	4 16 5
	5 9 3
	6 1 5
	7 4 8
	##end
	0 9 5
	0-4
	0-6
	1-3
	4-3
	5-2
	3-5
	#autre commentaire
	4-2
	2-1
	7-6
	7-2
	7-4
	6-5
On a donc 3 parties : 

- Le nombre de fourmis au départ.

- La définition des salles sous la forme suivante : nom coord_x coord_y

- La définition des tubes : nom1-nom2

- Le tout entre-coupé de commentaires qui commencent par #

Les noms de salles ne peuvent pas commencer par la lettre ‘L’ majuscule et ne peuvent pas contenir le caractère ‘-’.

Toute les salles doivent avoir un nom différent.

Les lignes commençant par un ## sont des commandes modifiant les propriétés de la ligne significative qui vient juste après.
##start indique l’entrée de la fourmilière et ##end la sortie.

Toute commande inconnue sera considérée comme un commentaire.

La première ligne non conforme ou vide entraîne la fin de l’acquisition de la fourmilière et son traitement normal avec les données déjà acquises.
# Objectifs
Le but du projet est de trouver le moyen le plus rapide de faire traverser la fourmilière par n fourmis.
Évidemment, il y a quelques contraintes. Ne pas marcher sur ses congénères, tout en évitant les embouteillages.

Au début du jeu, toutes les fourmis sont sur la salle indiquée par la commande ##start. Le but est de les amener sur la salle indiquée par la commande ##end en prenant le moins de tours possible.

Chaque salle peut contenir une seule fourmi à la fois (sauf ##start et ##end qui peuvent en contenir autant qu’il faut).

On considère que les fourmis sont toutes dans la salle ##start au démarrage

À chaque tour le programme peux déplacer chaque fourmi une seule fois et ce suivant un tube (la salle réceptrice doit être libre).

À chaque tour le programme affiche une ligne montrant la destination des fourmis qui ont bougé pendant le tour.
# Exemples
Considérons le fichier test_map.txt comme définissant la fourmilière vu précédemment, en exécutant la commande:

	./lem-in < test_map.txt
ou pour le mode graphique:

	./lem-in -v < test_map.txt
Vous devriez avoir un retour ressemblant a ceci:

	42
	##start
	1 23 3
	2 16 7
	#commentaire
	3 16 3
	4 16 5
	5 9 3
	6 1 5
	7 4 8
	##end
	0 9 5
	0-4
	0-6
	1-3
	4-3
	5-2
	3-5
	#autre commentaire
	4-2
	2-1
	7-6
	7-2
	7-4
	6-5

	L1-2 L2-3
	L1-5 L3-2 L2-4 L4-3
	L1-6 L3-5 L5-2 L2-0 L4-4 L6-3
	L1-0 L3-6 L5-5 L7-2 L4-0 L6-4 L8-3
	L3-0 L5-6 L7-5 L9-2 L6-0 L8-4 L10-3
	L5-0 L7-6 L9-5 L11-2 L8-0 L10-4 L12-3
	L7-0 L9-6 L11-5 L13-2 L10-0 L12-4 L14-3
	L9-0 L11-6 L13-5 L15-2 L12-0 L14-4 L16-3
	L11-0 L13-6 L15-5 L17-2 L14-0 L16-4 L18-3
	L13-0 L15-6 L17-5 L19-2 L16-0 L18-4 L20-3
	L15-0 L17-6 L19-5 L21-2 L18-0 L20-4 L22-3
	L17-0 L19-6 L21-5 L23-2 L20-0 L22-4 L24-3
	L19-0 L21-6 L23-5 L25-2 L22-0 L24-4 L26-3
	L21-0 L23-6 L25-5 L27-2 L24-0 L26-4 L28-3
	L23-0 L25-6 L27-5 L29-2 L26-0 L28-4 L30-3
	L25-0 L27-6 L29-5 L31-2 L28-0 L30-4 L32-3
	L27-0 L29-6 L31-5 L33-2 L30-0 L32-4 L34-3
	L29-0 L31-6 L33-5 L35-2 L32-0 L34-4 L36-3
	L31-0 L33-6 L35-5 L37-2 L34-0 L36-4 L38-3
	L33-0 L35-6 L37-5 L39-2 L36-0 L38-4 L40-3
	L35-0 L37-6 L39-5 L41-2 L38-0 L40-4 L42-3
	L37-0 L39-6 L41-5 L40-0 L42-4
	L39-0 L41-6 L42-0
	L41-0
À la suite de la définition de la fourmilière se trouve la résolution du parcours au format:

	Lx-salle_a Ly-salle_b …
Où x et y désigne le numéro de la fourmis en mouvement et salle_a et salle_b désigne la nom de la salle de destination de la fourmis.
# Compilation (gcc ou clang)
(Attention: ce projet à été réalisé pour Mac OS X Sierra, il pourrait y avoir des erreurs de compilation sur d'autres systèmes)
(Attention: ce projet a été réalisé avec la SDL2 (https://www.libsdl.org/download-2.0.php) ainsi que SDL2_ttf2.0 (https://www.libsdl.org/projects/SDL_ttf) et SDL2_gfx (http://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/), assurez vous de les avoir sur votre machine)

Utilisez la commande suivante pour compiler les sources:

	make
l’exécutable lem-in sera créé à la racine du projet.
## Auteurs

* **[Gregory Colletto](https://github.com/Gcol)**
* **[Sporer Valentin](https://github.com/demonoidv)**
