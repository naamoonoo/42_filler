# Filler

![Visualizer](/resources/Filler.gif)
<br/>
Filler is making a champion to defeat tetris like game against other player.
To win this game, occupy more space compared to competitor.

[filler.en.pdf](/resources/filler.en.pdf) is the task file.

## Project Structure

This project consists of two parts:

* Champion(hnam.filler)
* Visualizer (Bonus)

## heatmap algorithm

`hnam.filler` is based on the `heat map` algorithm.
Champion get piece randomly generated by virtual machine, then calculate the best position for surrounding the opponent.
like `flood fill`, recursively check valid and spread out to get the distance.

<img src="https://i.stack.imgur.com/iXlVH.png"/>

## Installation

Clone repository and then go into the created directory and run the following command:

```
make
```

## Usage

### `hnam.filler`

```
Usage: ./filler_vm -p1 ./player1 -p2 ./player2 -f resources/maps/map0X
    -p1, p2      — set player hnam.filler and other component located in /resoucres/players
    -f           — getting a map
```

### `visualizer`

getting a trace first, then forward the trace to visualizer
```
usage:
./filler_vm -p1 ./hnam.filler -p2 ./resources/players/champely.filler -f resources/maps/map00 >> trace_XX
./visualizer trace_XX
```

Visualizer is made up of [SDL2](https://www.libsdl.org/download-2.0.php) graphic library
<img src="/resources/vs_hcao.png">

