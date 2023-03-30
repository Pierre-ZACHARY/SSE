https://github.com/Pierre-ZACHARY/SSE
# Rendu Programmation Haute Performance - 2023
Pierre ZACHARY
Matysse DESCAMPS

Les réponses aux questions du TD2 se trouvent dans /TP2-files/src

Les tests pour vérifier ces mêmes questions sont dans /TP2-files/tests

Vous pouvez compiler avec cmake et le CMakelists.txt à la racine 

Voici les résultats des bench fait sur les machines de la fac :



Taille de la matrice : 2048

|                   Algo                   |  User Time  | Context-Switches |  L1-loads  | L1-misses |  LLC-loads   | LLC-misses |
|:----------------------------------------:|:-----------:|:----------------:|:----------:|:---------:|:------------:|:----------:|
|                   Naif                   | 47.3663 sec |       186        | 2.544G/sec |   9.13%   |   181M/sec   |   6.07%    |
|                 Scalaire                 | 19.1021 sec |        65        | 8.096G/sec |   0.35%   | 803.426K/sec |   36.57%   |
|              Scalaire + SSE              | 11.1438 sec |        53        |  5.4G/sec  |   0.9%    | 908.29K/sec  |   71.41%   |
| Scalaire + SSE ( 2 registres à la fois ) |  10.8 sec   |        37        | 5.285G/sec |   0.95%   | 935.486K/sec |   71.07%   |
| Scalaire + SSE ( 4 registres à la fois ) | 9.9714 sec  |        35        | 5.546G/sec |   0.99%   |  1.065M/sec  |   59.43%   |
|                   Bloc                   | 26.6621 sec |       164        | 6.375G/sec |   0.68%   | 20.498M/sec  |   3.60%    |
|                Bloc + SSE                | 15.6267 sec |        59        | 2.694G/sec |   1.93%   | 34.833M/sec  |   23.13%   |


Taille de la matrice : 4096

|                   Algo                   |  User Time   | Context-Switches |  L1-loads  | L1-misses |  LLC-loads   | LLC-misses |
|:----------------------------------------:|:------------:|:----------------:|:----------:|:---------:|:------------:|:----------:|
|                   Naif                   | 825.1160 sec |       4672       | 1.167G/sec |  11.18%   | 85.468M/sec  |   51.22%   |
|                 Scalaire                 | 148.7711 sec |       705        | 8.318G/sec |   0.37%   | 738.960/sec  |   60.76%   |
|              Scalaire + SSE              | 87.7504 sec  |       490        | 5.489G/sec |   0.94%   | 932.889K/sec |   75.99%   |
| Scalaire + SSE ( 2 registres à la fois ) | 82.4601 sec  |       423        | 5.531G/sec |   1.02%   |  1.054M/sec  |   70.60%   |
| Scalaire + SSE ( 4 registres à la fois ) | 77.2085 sec  |       384        | 5.741G/sec |   1.14%   |  1.120M/sec  |   74.76%   |
|                   Bloc                   | 332.6311 sec |       1230       | 4.090G/sec |   0.69%   | 13.829M/sec  |   91.75%   |
|                Bloc + SSE                | 166.4112 sec |       871        | 2.018G/sec |   2.26%   | 27.314M/sec  |   66.57%   |


On peut voir qu'en utilisant les opérations SSE on peut grandement améliorer le temps d'exécution d'un même algorithme.

Pour la version par bloc, notre implémentation est la suivante : on init un bloc de registre 4x4 à 0 qui contiendra les résultats du bloc pour C, on load un 4x4 de A, on load un 4x4 de B, on transpose B, on multiplie A et B, on re-transpose B pour pouvoir faire la somme des multiplications, on fait la somme de chaque lignes, on attribut la ligne résultat à la ligne correspondante du bloc temporaire de C. On répète avec le bloc de A à sa droite et le bloc de B du dessous pour calculer la ligne suivante. Une fois que le bloc de C est calculé on l'attribut à la matrice finale, et on passe au bloc suivant.

Nous n'avons rien de spécial à ajouter par rapport aux implémentations, nous avons suivi les consignes.

Nb : Les perf que nous avons effectué sur la version par bloc sont moins bon qu'en utilisant time ( en 2048 pour scalaire_sse_16 nous avions 12 secondes contre 8 secondes pour bloc_sse avec time ) , nous n'avons pas sû expliquer cette différence.

