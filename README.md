<img src="git_utils/banner.png" alt="logo-so_long" style="width: 100%">

<br>

---

<br>

<details>
<summary>FRENCH VERSION</summary>

## Index 
- [Introduction](#introduction)
- [Objectif](#objectif)
- [Aperçu du projet](#aperçu-du-projet)
- [Fonctionnalités clés](#fonctionnalités-clés)
- [Éléments du jeu](#éléments-du-jeu)
- [Contrôles](#contrôles)
- [Structure du code](#structure-du-code)
- [En détail](#en-détail)
	- [Structure](#structure-t_game)
	- [Fichiers sources](#fichiers-sources)
	- [Fonctions de la Minilibx](#fonctions-de-la-minilibx-utilisées)
	- [Procédé](#procédé)
- [Compilation et exécution](#compilation-et-exécution)
- [Captures d'écran](#captures-décran)
- [Résultat](#résultat)
- [Ressources](#ressources)

<br>

## Introduction
Bienvenue dans So_Long, un projet de jeu 2D développé en C dans le cadre d'un programme d'apprentissage de la programmation. Ce projet se concentre sur la création d'un jeu simple en utilisant la bibliothèque graphique MinilibX. L'objectif est de construire un jeu où un joueur se déplace à travers une carte, collecte des objets, évite des obstacles et atteint la sortie.

<br>
<br>

## Objectif
L'objectif principal du projet So_Long est de mettre en œuvre un jeu de base en utilisant C et la bibliothèque MinilibX. Le jeu implique la gestion des entrées utilisateur, le rendu graphique et la gestion des éléments du jeu tels que le joueur, les objets, les obstacles et la sortie.

<br>
<br>

## Aperçu du projet
So_Long est un jeu basé sur un labyrinthe où le joueur se déplace à travers une carte représentée par une grille. La carte contient divers éléments, notamment le joueur, des objets collectibles, des obstacles et une sortie. La tâche du joueur est de collecter tous les objets et d'atteindre la sortie tout en évitant les obstacles.

<br>
<br>

## Fonctionnalités clés
Mouvement du joueur : Utilisez les touches fléchées (haut, bas, gauche, droite) pour déplacer le joueur.
Collection d'objets : Collectez des objets représentés par des symboles spécifiques sur la carte.
Sortie : Atteignez la sortie pour terminer le jeu.
Évitement d'obstacles : Déplacez-vous autour des obstacles représentés par des symboles spécifiques.
Graphismes : Graphismes 2D simples implémentés à l'aide de la bibliothèque MinilibX.

<br>
<br>

## Éléments du jeu
Le jeu comprend les éléments suivants :

Joueur (P) : Le personnage principal contrôlé par le joueur.
Objet (C) : Objets collectibles que le joueur doit récupérer.
Killer (x) : Obstacles que le joueur doit éviter.
Mur (1) : Murs solides qui restreignent le mouvement.
Sol (0) : Espaces ouverts où le joueur peut se déplacer.
Sortie (E) : L'objectif pour le joueur.

<br>
<br>

## Contrôles
Touches fléchées : Déplacer le joueur dans la direction correspondante.
W, A, S, D : Touches alternatives pour le mouvement (haut, gauche, bas, droite).
Touche ESC : Quitter le jeu.

<br>
<br>

## Structure du code
Le projet est structuré comme suit :

```shell
├── Makefile                # Script de compilation
├── img                     # Images du jeu
│   ├── *.xpm               # Images en .xpm
├── inc                     # En-têtes et bibliothèques
│   ├── ft_printf           # Implémentation de printf
│   ├── get_next_line       # Lecture ligne par ligne
│   ├── mlx                 # Bibliothèque graphique MiniLibX
│   └── so_long.h           # En-tête principal du projet
├── maps                    # Cartes du jeu
│   ├── index_maps          # Index des cartes
│   ├── *.ber               # Carte au format ber
└── src                     # Code source
	├── ft_free.c           # Libération mémoire
	├── ft_utils.c          # Fonctions utilitaires
	├── img_board.c         # Affichage du tableau
	├── img_drawer.c        # Dessin de la carte
	├── img_handler.c       # Gestion des images
	├── keypress.c          # Gestion des touches
	├── main.c              # Point d'entrée du programme
	├── map_parser.c        # Analyse des cartes
	├── move_killers.c      # Déplacement des ennemis
	├── move_player.c       # Déplacement du joueur
	└── win_creator.c       # Gestion des écrans finaux
```

<br>
<br>

## En détail

### Structure ```t_game```

```c
typedef struct s_game
{
	int		fd;                     // Fichier de la carte
	char	**map;                  // Carte du jeu
	char	**map_copy;             // Copie de la carte
	char	*name_map;              // Nom de la carte
	int		x, y;                   // Dimensions de la carte
	int		pl_x, pl_y;             // Position du joueur
	int		exit_x, exit_y;         // Position de la sortie
	int		path_start[2];          // Départ chemin
	int		path_end[2];            // Arrivée chemin
	int		max_coin;               // Total pièces
	int		coin;                   // Pièces actuelles
	int		coin_collected;         // Pièces collectées
	int		started;                // Jeu commencé
	void	*mlx, *win;             // MLX et fenêtre
	void	*img;                   // Image du jeu
	int		*addr;                  // Données image
	int		bpp, line_len;          // Bits/pixel, longueur ligne
	int		endian;                 // Endianness
	int		size;                   // Taille image
	int		window_width, window_height; // Dimensions fenêtre
	int		image_width, image_height;   // Dimensions image
	int		x_offset, y_offset;     // Décalage image
	int		moves;                  // Déplacements
	int		finished;               // Jeu terminé
	int		nb_killers;             // Nombre d'ennemis
	int		**tab_killers;          // Tableau ennemis
	void	*img_plup, *img_pldo, *img_plri, *img_plle; // Images joueur
	void	*img_kil1, *img_kil2, *img_kil3;           // Images ennemis
	void	*img_floo, *img_wall, *img_item;           // Images tuiles
	void	*img_exop, *img_excl;                      // Images sortie
	void	*img_boar, *img_swin, *img_lose, *img_load; // Images fin/chargement
} 				t_game;
```

<br>
<br>

---

### Fichiers sources

- ft_free.c
```c
static void free_tab(char **tab);
static void free_killers(t_game *game);		
int ft_free_info(t_game *info);
```

- ft_utils.c
```c
char *ft_itoa(int nb);
int ft_error(int error);
void create_tab_killers(t_game *game);
```

- img_board.c
```c
void print_final_score(t_game *game);
void draw_move_board(t_game *game);
void draw_coin_board(t_game *game);
void draw_coin_board_max(t_game *game);
```

- img_drawer.c
```c
void draw_map(t_game *game, char direction);
```

- img_handler.c
```c
void set_images(t_game *game);
void images_cleaner(t_game *game);
```

- keypress.c
```c
int handle_keypress(int keycode, t_game *game);
```

- main.c
```c
static int init_args(t_game *info, char *av);
int main(int argc, char *argv[]);
```

- map_parser.c
```c
static int get_size(t_game *info);
static int is_valid_charac(t_game *info, int i, int j);
static int is_valid_map(t_game *info, int p, int c, int e);
static int path_ok(int y, int x, int *coin, t_game *info);
int parse_map(t_game *info);
```

- move_killers.c
```c
void move_all_killers(t_game *game);
```

- move_player.c
```c
void move_player(int keycode, t_game *game);
```

- win_creator.c
```c
static void ending_screen(t_game *game, int result);
static void loading_screen(t_game *game);
void finish_game(t_game *game, int result);
void launch_screen(t_game *game);
```

<br>

---


### Fonctions de la Minilibx utilisées
```c
mlx_init():
```
Initialise une connexion avec le serveur graphique X.
Alloue la mémoire nécessaire et initialise une structure qui stocke des informations sur la connexion graphique.

```c
mlx_new_window():
```
Crée une nouvelle fenêtre graphique.
Prend comme paramètres la connexion graphique initialisée avec mlx_init(), les dimensions de la fenêtre, et le titre de la fenêtre. Retourne un identifiant unique pour la fenêtre.

```c
mlx_new_image():
```
Crée une nouvelle image en mémoire.
Prend comme paramètres la connexion graphique et les dimensions de l'image. Retourne un identifiant unique pour l'image.

```c
mlx_get_data_addr():
```
Obtient l'adresse du premier octet de l'image.
Prend comme paramètres l'identifiant de l'image, un pointeur vers la variable qui stockera l'adresse, et des variables pour les informations sur la largeur, la hauteur, et les bits par pixel.

```c
mlx_hook():
```
Associe une fonction à un événement, comme une touche pressée.
Prend comme paramètres l'identifiant de la fenêtre, le type d'événement, une fonction à appeler, et un paramètre qui sera passé à la fonction.

```c
mlx_put_image_to_window():
```
Affiche une image dans une fenêtre.
Prend comme paramètres la connexion graphique, l'identifiant de la fenêtre, l'identifiant de l'image, et les coordonnées où afficher l'image.

```c
mlx_destroy_image():
```
Détruit une image précédemment créée.
Prend comme paramètres la connexion graphique et l'identifiant de l'image à détruire.

```c
mlx_destroy_window():
```
Ferme une fenêtre graphique.
Prend comme paramètres la connexion graphique et l'identifiant de la fenêtre à fermer.

```c
mlx_loop():
```
Lance la boucle principale de gestion des événements graphiques.
Boucle infinie qui gère les événements tels que les touches pressées.

<br>
<br>

---

### Procédé

1. Inclusions de bibliothèques
Le programme utilise plusieurs bibliothèques standard telles que ```<unistd.h>```, ```<stdlib.h>```, ```<fcntl.h>```, ```<math.h>```, ainsi que des bibliothèques tierces telles que ```"get_next_line/get_next_line.h"```, ```"ft_printf/ft_printf.h"```, et ```"../inc/mlx/mlx.h"```. Ces inclusions fournissent des fonctionnalités de base, des entrées/sorties, des fonctions mathématiques, et des outils pour l'interface graphique avec la MiniLibX.

<br>

2. Définition des constantes
Le fichier d'en-tête définit un ensemble de constantes représentant différents éléments du jeu, tels que le joueur, les objets, les murs, le sol, la sortie, etc. Ces constantes facilitent la lecture et la compréhension du code en remplaçant les valeurs numériques par des noms significatifs.

<br>

3. Structure de données
Le programme utilise une structure appelée ```t_game``` pour stocker diverses informations sur l'état du jeu. Cette structure contient des membres tels que des tableaux pour stocker la carte du jeu, des variables pour suivre la position du joueur, des compteurs pour les objets collectés, des gestionnaires pour l'interface graphique (MiniLibX), et d'autres informations relatives au jeu.

<br>

4. Gestion des touches
La fonction ```handle_keypress``` est appelée en réponse à l'appui sur une touche. Elle traite les événements clavier, déclenche des actions en fonction de la touche pressée, et met à jour l'état du jeu en conséquence.

<br>

5. Analyse de la carte
La fonction parse_map est responsable de l'analyse de la carte du jeu à partir d'un fichier. Elle extrait les informations nécessaires et initialise la structure ```t_game``` en conséquence.

<br>

6. Initialisation de l'interface graphique
La fonction ```launch_screen``` initialise l'interface graphique en utilisant la MiniLibX. Elle crée la fenêtre, charge les images nécessaires, et prépare le terrain de jeu initial.

<br>

7. Boucle principale du jeu
La boucle principale du jeu gère le déroulement du jeu. Elle surveille les événements (y compris les touches pressées), met à jour l'état du jeu, dessine la carte, et réagit aux actions du joueur.

<br>

8. Mouvement du joueur
La fonction move_player est appelée pour déplacer le joueur en fonction de la touche pressée. Elle vérifie la validité du mouvement, met à jour les coordonnées du joueur, et effectue d'autres actions nécessaires.

<br>

9. Gestion des ennemis
Le programme inclut une fonction ```move_all_killers``` pour déplacer les ennemis (désignés comme "```killers```") sur la carte.

<br>

10. Gestion de l'affichage
Plusieurs fonctions sont dédiées à la gestion de l'affichage, notamment la fonction ```draw_map``` qui dessine la carte du jeu. (voir fichier drawing.c).

<br>

11. Gestion de la mémoire
Le fichier ft_free.c contient des fonctions pour libérer la mémoire allouée dynamiquement pendant l'exécution du programme, assurant une gestion propre des ressources.

<br>

12. Fin du jeu
La fonction ```finish_game``` est responsable de la gestion de la fin du jeu, indiquant si le joueur a gagné ou perdu.

<br>

13. Détails graphiques
Le programme utilise la MiniLibX pour la gestion graphique, ce qui implique des manipulations d'images et des opérations sur les fenêtres.

<br>
<br>

## Compilation et exécution
Pour compiler le projet, exécutez les commandes suivantes :

```bash
git clone https://github.com/aceyzz/So_long.git
cd So_long/so_long
make
./so_long "maps/example_map.ber"
```

*Remarque : Remplacez "example_map.ber" par le chemin de votre fichier de carte souhaité. (voir fichier so_long/maps/index_maps)*

<br>
<br>

## Captures d'écran

<div style="display: grid; grid-template-columns: repeat(3, 1fr); gap: 20px;">
	<img src="git_utils/sc1.png" alt="term">
	<img src="git_utils/sc2.png" alt="loading screen">
	<img src="git_utils/sc3.png" alt="map1">
	<div style="display: grid; grid-template-columns: repeat(1, 2fr); gap: 10px;">
		<img src="git_utils/sc5.png" alt="map2">
		<img src="git_utils/sc6.png" alt="map2">
	</div>
	<img src="git_utils/sc4.png" alt="lose screen">
	<img src="git_utils/sc7.png" alt="map2">
</div>

<br>
<br>

## Résultat

<img src="git_utils/grade.png" alt="grade" style="width: 25%">

<br>
<br>

## Ressources
Documentation [MinilibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

<br>
<br>
<br>

## Licence
This work is published under the terms of **[42 Unlicense](./LICENSE)**.


>DON'T COPY, LEARN. RTFM.

</details>

<br>

---

<br>

<details>
<summary>ENGLISH VERSION</summary>

## Index 
- [Introduction](#introduction)
- [Objective](#objective)
- [Project Overview](#project-overview)
- [Key Features](#key-features)
- [Game Elements](#game-elements)
- [Controls](#controls)
- [Code Structure](#code-structure)
- [In Detail](#in-detail)
	- [Structure](#structure-t_game)
	- [Source Files](#source-files)
	- [Minilibx Functions](#minilibx-functions-used)
	- [Process](#process)
- [Compilation and Execution](#compilation-and-execution)
- [Screenshots](#screenshots)
- [Result](#result)
- [Resources](#resources)

<br>

## Introduction
Welcome to So_Long, a 2D game project developed in C as part of a programming learning program. This project focuses on creating a simple game using the MinilibX graphics library. The goal is to build a game where a player moves through a map, collects items, avoids obstacles, and reaches the exit.

<br>
<br>

## Objective
The main objective of the So_Long project is to implement a basic game using C and the MinilibX library. The game involves handling user input, rendering graphics, and managing game elements such as the player, items, obstacles, and the exit.

<br>
<br>

## Project Overview
So_Long is a maze-based game where the player moves through a map represented by a grid. The map contains various elements, including the player, collectible items, obstacles, and an exit. The player's task is to collect all items and reach the exit while avoiding obstacles.

<br>
<br>

## Key Features
- **Player Movement**: Use arrow keys (up, down, left, right) to move the player.
- **Item Collection**: Collect items represented by specific symbols on the map.
- **Exit**: Reach the exit to complete the game.
- **Obstacle Avoidance**: Navigate around obstacles represented by specific symbols.
- **Graphics**: Simple 2D graphics implemented using the MinilibX library.

<br>
<br>

## Game Elements
The game includes the following elements:

- **Player (P)**: The main character controlled by the player.
- **Item (C)**: Collectible items the player must gather.
- **Killer (x)**: Obstacles the player must avoid.
- **Wall (1)**: Solid walls that restrict movement.
- **Floor (0)**: Open spaces where the player can move.
- **Exit (E)**: The player's goal.

<br>
<br>

## Controls
- **Arrow Keys**: Move the player in the corresponding direction.
- **W, A, S, D**: Alternative keys for movement (up, left, down, right).
- **ESC Key**: Exit the game.

<br>
<br>

## Code Structure
The project is structured as follows:

```shell
├── Makefile                # Compilation script
├── img                     # Game images
│   ├── *.xpm               # Images in .xpm format
├── inc                     # Headers and libraries
│   ├── ft_printf           # printf implementation
│   ├── get_next_line       # Line-by-line reading
│   ├── mlx                 # MiniLibX graphics library
│   └── so_long.h           # Main project header
├── maps                    # Game maps
│   ├── index_maps          # Map index
│   ├── *.ber               # Maps in .ber format
└── src                     # Source code
	├── ft_free.c           # Memory management
	├── ft_utils.c          # Utility functions
	├── img_board.c         # Board display
	├── img_drawer.c        # Map drawing
	├── img_handler.c       # Image management
	├── keypress.c          # Key handling
	├── main.c              # Program entry point
	├── map_parser.c        # Map parsing
	├── move_killers.c      # Enemy movement
	├── move_player.c       # Player movement
	└── win_creator.c       # End screen management
```

<br>
<br>

## In Detail

### Structure ```t_game```

```c
typedef struct s_game
{
	int		fd;                     // Map file
	char	**map;                  // Game map
	char	**map_copy;             // Map copy
	char	*name_map;              // Map name
	int		x, y;                   // Map dimensions
	int		pl_x, pl_y;             // Player position
	int		exit_x, exit_y;         // Exit position
	int		path_start[2];          // Path start
	int		path_end[2];            // Path end
	int		max_coin;               // Total coins
	int		coin;                   // Current coins
	int		coin_collected;         // Collected coins
	int		started;                // Game started
	void	*mlx, *win;             // MLX and window
	void	*img;                   // Game image
	int		*addr;                  // Image data
	int		bpp, line_len;          // Bits/pixel, line length
	int		endian;                 // Endianness
	int		size;                   // Image size
	int		window_width, window_height; // Window dimensions
	int		image_width, image_height;   // Image dimensions
	int		x_offset, y_offset;     // Image offset
	int		moves;                  // Moves
	int		finished;               // Game finished
	int		nb_killers;             // Number of enemies
	int		**tab_killers;          // Enemy table
	void	*img_plup, *img_pldo, *img_plri, *img_plle; // Player images
	void	*img_kil1, *img_kil2, *img_kil3;           // Enemy images
	void	*img_floo, *img_wall, *img_item;           // Tile images
	void	*img_exop, *img_excl;                      // Exit images
	void	*img_boar, *img_swin, *img_lose, *img_load; // End/loading images
} 				t_game;
```

<br>
<br>

---

### Source Files

- ft_free.c
```c
static void free_tab(char **tab);
static void free_killers(t_game *game);		
int ft_free_info(t_game *info);
```

- ft_utils.c
```c
char *ft_itoa(int nb);
int ft_error(int error);
void create_tab_killers(t_game *game);
```

- img_board.c
```c
void print_final_score(t_game *game);
void draw_move_board(t_game *game);
void draw_coin_board(t_game *game);
void draw_coin_board_max(t_game *game);
```

- img_drawer.c
```c
void draw_map(t_game *game, char direction);
```

- img_handler.c
```c
void set_images(t_game *game);
void images_cleaner(t_game *game);
```

- keypress.c
```c
int handle_keypress(int keycode, t_game *game);
```

- main.c
```c
static int init_args(t_game *info, char *av);
int main(int argc, char *argv[]);
```

- map_parser.c
```c
static int get_size(t_game *info);
static int is_valid_charac(t_game *info, int i, int j);
static int is_valid_map(t_game *info, int p, int c, int e);
static int path_ok(int y, int x, int *coin, t_game *info);
int parse_map(t_game *info);
```

- move_killers.c
```c
void move_all_killers(t_game *game);
```

- move_player.c
```c
void move_player(int keycode, t_game *game);
```

- win_creator.c
```c
static void ending_screen(t_game *game, int result);
static void loading_screen(t_game *game);
void finish_game(t_game *game, int result);
void launch_screen(t_game *game);
```

<br>

---

### Minilibx Functions Used
```c
mlx_init():
```
Initializes a connection with the X graphics server.
Allocates memory and initializes a structure to store graphics connection information.

```c
mlx_new_window():
```
Creates a new graphics window.
Takes parameters for the graphics connection initialized with mlx_init(), window dimensions, and the window title. Returns a unique identifier for the window.

```c
mlx_new_image():
```
Creates a new image in memory.
Takes parameters for the graphics connection and image dimensions. Returns a unique identifier for the image.

```c
mlx_get_data_addr():
```
Gets the address of the first byte of the image.
Takes parameters for the image identifier, a pointer to store the address, and variables for width, height, and bits per pixel.

```c
mlx_hook():
```
Associates a function with an event, such as a key press.
Takes parameters for the window identifier, event type, a function to call, and a parameter to pass to the function.

```c
mlx_put_image_to_window():
```
Displays an image in a window.
Takes parameters for the graphics connection, window identifier, image identifier, and coordinates to display the image.

```c
mlx_destroy_image():
```
Destroys a previously created image.
Takes parameters for the graphics connection and the image identifier to destroy.

```c
mlx_destroy_window():
```
Closes a graphics window.
Takes parameters for the graphics connection and the window identifier to close.

```c
mlx_loop():
```
Starts the main loop for handling graphics events.
An infinite loop that handles events such as key presses.

<br>
<br>

---

### Process

1. **Library Inclusions**  
The program uses several standard libraries such as ```<unistd.h>```, ```<stdlib.h>```, ```<fcntl.h>```, ```<math.h>```, as well as third-party libraries like ```"get_next_line/get_next_line.h"```, ```"ft_printf/ft_printf.h"```, and ```"../inc/mlx/mlx.h"```. These inclusions provide basic functionality, input/output, math functions, and tools for the graphical interface with MiniLibX.

<br>

2. **Constant Definitions**  
The header file defines a set of constants representing different game elements, such as the player, items, walls, floor, exit, etc. These constants improve code readability by replacing numeric values with meaningful names.

<br>

3. **Data Structure**  
The program uses a structure called ```t_game``` to store various information about the game's state. This structure contains members such as arrays for storing the game map, variables for tracking the player's position, counters for collected items, graphics interface handlers (MiniLibX), and other game-related information.

<br>

4. **Key Handling**  
The ```handle_keypress``` function is called in response to a key press. It processes keyboard events, triggers actions based on the pressed key, and updates the game's state accordingly.

<br>

5. **Map Parsing**  
The ```parse_map``` function is responsible for parsing the game map from a file. It extracts the necessary information and initializes the ```t_game``` structure accordingly.

<br>

6. **Graphics Initialization**  
The ```launch_screen``` function initializes the graphical interface using MiniLibX. It creates the window, loads the necessary images, and prepares the initial game board.

<br>

7. **Main Game Loop**  
The main game loop handles the game's progression. It monitors events (including key presses), updates the game's state, draws the map, and reacts to the player's actions.

<br>

8. **Player Movement**  
The ```move_player``` function is called to move the player based on the pressed key. It checks the validity of the movement, updates the player's coordinates, and performs other necessary actions.

<br>

9. **Enemy Management**  
The program includes a ```move_all_killers``` function to move enemies (referred to as "killers") on the map.

<br>

10. **Display Management**  
Several functions are dedicated to display management, including the ```draw_map``` function, which draws the game map (see drawing.c file).

<br>

11. **Memory Management**  
The ```ft_free.c``` file contains functions to free dynamically allocated memory during the program's execution, ensuring clean resource management.

<br>

12. **Game End**  
The ```finish_game``` function handles the end of the game, indicating whether the player has won or lost.

<br>

13. **Graphical Details**  
The program uses MiniLibX for graphical management, involving image manipulations and window operations.

<br>
<br>

## Compilation and Execution
To compile the project, run the following commands:

```bash
git clone https://github.com/aceyzz/So_long.git
cd So_long/so_long
make
./so_long "maps/example_map.ber"
```

*Note: Replace "example_map.ber" with the path to your desired map file. (see so_long/maps/index_maps file)*

<br>
<br>

## Screenshots

<div style="display: grid; grid-template-columns: repeat(3, 1fr); gap: 20px;">
	<img src="git_utils/sc1.png" alt="term">
	<img src="git_utils/sc2.png" alt="loading screen">
	<img src="git_utils/sc3.png" alt="map1">
	<div style="display: grid; grid-template-columns: repeat(1, 2fr); gap: 10px;">
		<img src="git_utils/sc5.png" alt="map2">
		<img src="git_utils/sc6.png" alt="map2">
	</div>
	<img src="git_utils/sc4.png" alt="lose screen">
	<img src="git_utils/sc7.png" alt="map2">
</div>

<br>
<br>

## Result

<img src="git_utils/grade.png" alt="grade" style="width: 25%">

<br>
<br>

## Resources
Documentation [MinilibX](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)

<br>
<br>
<br>

## License
This work is published under the terms of **[42 Unlicense](./LICENSE)**.


>DON'T COPY, LEARN. RTFM.

</details>

<br>

---
<br>