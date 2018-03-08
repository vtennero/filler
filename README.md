# Filler

The goal of this project is to code a player (in the form of an executable) for the filler board game.

The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program). The game ends when the game piece cannot be placed anymore.

I created a visualizer that displays the development of the game, and notably the core of my player's strategy: a numbered heatmap, which guides my player to close contact with the adversary (it will go where the score is minimal).

## Installing

Clone the repository and:
```
make
```
## Running the tests

### With my visualizer (default)

Move the vtennero/filler to players/

Then execute the following command :

```
./filler -f maps/mapXX -p1 players/player1.filler -p2 players/player2.filler -q
```

Where player1 and player2 are the names of the executables chosen in the players folder, and mapXX is chosen from the maps folder.

### Without the visualizer

To disable the visualizer, simply delete the following line in main.c (line 72):

```
print_map(global);
```

Then do:
```
./filler -f maps/mapXX -p1 players/player1.filler -p2 players/player2.filler
```

### Other methods

Alternatively, you can create your own test file, following the rules found in the subject, with or without using the Virtual Machine.

## Additional Resources

Instructions : [Subject](https://www.dropbox.com/s/90u6wl81wbk5vyt/filler.en.pdf?dl=0)

## Disclaimer

This project, along with most projects from my github, follows the rules specified by the [42 Norm](https://www.dropbox.com/s/a6bpolsav238d97/norme.en.pdf?dl=0). Among others, it implies that all functions do not exceed 25 lines, as a means to make the code as clear as possible.

The following resources are provided with the subject: all players except vtennero.filler, map00-1-2 and the filler_vm executable

## Author

* **Victor Tenneroni** - [Website](http://victor-tenneroni.com/)
