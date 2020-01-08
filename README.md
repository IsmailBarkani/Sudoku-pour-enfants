![1](https://user-images.githubusercontent.com/51321011/59166200-3aeb5f00-8b27-11e9-9beb-6ec87afc2e47.png)

Le sudoku, est un jeu en forme de grille dont le but est de la remplir avec une série des chiﬀres (ou des lettres ou des symboles) 
tous diﬀérents qui ne se trouvent jamais plus d’une  fois sur la même ligne, dans la même colonne ou dans la même région 
(également appelée «bloc», «groupe», «secteur »ou «sous-grille»), Puisque le jeu est destiné aux enfants, et pour simpliﬁer, 
la forme de sudoku sera une grille de 4 régions, les régions étant alors des carrés de 2x2 à remplir par des objets qui attirent 
l’attention de l’enfant.

# :pencil2: modélisation

## :ok: Vériﬁcation

Dans un premier temps, on s’intéresse à la génération de grilles bien formées (les quelles il existe au moins une solution). 
Pour cela, il s’agit de générer des grilles complètes vériﬁant toutes les conditions et en suite de retirer certaines valeurs.
Pour que le jeu soit intéressant, il faut au moins retirer la moitié des valeurs des cases. Une première approche pourra consister à 
générer aléatoirement des grilles et ensuite à vériﬁer qu’elle vériﬁe  bien les conditions pour être un sudoku valide. Dans un second
 temps, on pourra expérimenter avec des algorithmes un peu plus eﬃcaces pour construire la grille. On évitera par exemple de mettre 
plusieurs fois la même valeur sur la même ligne.

## :repeat: Résolution (BackTracking)
Pour résoudre le sudoku en basant sur l’état initiale donnée on commencera par implémenter un premier algorithme consistant
simplement à explorer toutes les possibilités et de remplir de plus en plus de cases de la grille tout en respectant les contraintes.
Quand on se trouve bloqué, c’est à dire qu’aucune nouvelle case ne peut être complétée sans violer les contraintes, on revient au 
dernier embranchement non encore emprunté dans l’arbre des possibilités.
<p align="center">
  <img src="https://user-images.githubusercontent.com/51321011/59166392-7c7d0980-8b29-11e9-9411-3c8070f8e1fd.PNG">
</p>


# :camera: Les interfaces

<p align="center">
  <img src="https://user-images.githubusercontent.com/51321011/59166214-61a99580-8b27-11e9-857e-3ae6866e74a0.PNG">
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/51321011/59166215-61a99580-8b27-11e9-9ce7-bd9e62ab92c4.PNG">
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/51321011/59166216-61a99580-8b27-11e9-8352-7a409a22fa81.PNG">
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/51321011/59166217-62422c00-8b27-11e9-9dcb-321242002aca.PNG">
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/51321011/59166218-62422c00-8b27-11e9-8a2f-916e4798d1dc.PNG">
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/51321011/59166219-62422c00-8b27-11e9-9a22-dcaf8217a69d.PNG">
</p>

# :wrench: Outiles


![ref](https://user-images.githubusercontent.com/51321011/59166629-e696ae00-8b2b-11e9-8895-01d71df200de.PNG)
