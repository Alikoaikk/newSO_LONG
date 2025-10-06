# so_long 🪄✨

![Game Preview](image.png)

*"It does not do to dwell on dreams and forget to live... but it's totally fine to play video games!"* - Albus Dumbledore (probably)

## Description

Welcome to Hogwarts' most challenging extra-curricular activity! 🏰

In this 2D magical adventure, you play as Harry Potter navigating through mysterious dungeons to collect all the Horcruxes (because apparently seven wasn't enough). Once you've grabbed them all, find the magical exit before Voldemort's Wi-Fi password changes again!

Built with the MiniLibX graphics library and powered by pure C wizardry, this game features collision detection smoother than Snape's haircare routine and pathfinding more reliable than the Marauder's Map.

## Magical Features ⚡

- **Crystal-clear graphics**: 120x120 pixel sprites (way better than those moving staircases)
- **Four-directional movement**: Up, down, left, right - basically Apparition but with arrow keys
- **Horcrux hunting**: Collect them all! (No basilisk fangs required)
- **Enchanted exits**: The door magically opens once you've grabbed all the Horcruxes
- **Move counter**: Because the Ministry of Magic likes to track everything you do
- **Foolproof map validation**: Checks walls, paths, and won't let you create a Room of Requirement
- **Custom maps**: Design your own dungeons with `.ber` files (Moody would be proud)

## Requirements (Muggle Equipment Needed) 🔧

- Linux operating system (No, Windows doesn't count as a Patronus)
- X11 development libraries (Ancient magic, basically)
- Make (Not the wand kind)
- GCC compiler (Greater Compiler of C-code)

## Installation (Casting the Spell) 🎯

```bash
make
```

*Accio executable!* This command summons the `so_long` binary along with the MiniLibX library. Much faster than waiting for your Hogwarts letter.

## Usage (How to Start Your Adventure) 🎮

```bash
./so_long <map_file.ber>
```

**Example:**
```bash
./so_long maps/valid_maps/map_normal.ber
```

*Pro tip: Start with `map_mini.ber` if you're still learning to walk in the wizarding world.*

## Controls (Your Spellbook) 📖

- **Arrow Keys**: Navigate through the dungeon (No broomstick required)
- **ESC**: Quit faster than Ron abandoning the trio (we forgive you, Ron)
- **X Button**: Close the window and pretend you were studying

## Map Format (Enchantment Instructions) 🗺️

Create your dungeon blueprints using `.ber` files (think of them as magical parchments).

**The Magical Symbols:**
- `1`: Wall (Harder than Hagrid's rock cakes)
- `0`: Floor (Safe to walk on, unlike the Whomping Willow)
- `P`: Player start (Where Harry spawns in)
- `C`: Collectible Horcrux (Shiny dark magic objects)
- `E`: Exit (Your way back to the common room)

### The Sacred Rules (Break Them and Face Detention) 📜

- Map must be **rectangular** (No weird shapes - this isn't Divination class)
- Map must be **completely surrounded by walls** (`1`) - We don't want Harry falling into the void
- Must have **exactly ONE player** (`P`) - No Time-Turner shenanigans here
- Must have **exactly ONE exit** (`E`) - One way out, just like Platform 9¾
- Must have **at least ONE Horcrux** (`C`) - Otherwise what's the point?
- Must have a **valid path** from Harry to all Horcruxes and the exit (No impossible mazes, Dumbledore)

### Example Dungeon

```
111111
1P0C01
100001
1C00E1
111111
```
*A simple 5x6 dungeon with 2 Horcruxes. Perfect for your first day at Hogwarts!*

## Project Structure (Hogwarts Library Layout) 📚

```
.
├── srcs/              # The main spellbook (core game logic)
├── includes/          # Ancient scrolls (header files)
├── mlx/              # MiniLibX graphics library (powered by Felix Felicis)
├── ft_printf/        # Custom printf (because printf was a Muggle invention)
├── get_next_line/    # File reading charm
├── sprites/          # Magical portraits (.xpm files of Harry & Horcruxes)
└── maps/             # The Map Collection
    ├── valid_maps/   # Approved by the Ministry
    └── invalid_maps/ # Cursed maps (for testing error handling)
```

## Compilation Spells 🪄

- **`make`**: Summon the executable (like calling the Knight Bus)
- **`make clean`**: Vanish all object files (Evanesco!)
- **`make fclean`**: Nuclear option - removes everything (Avada Kedavra for files)
- **`make re`**: Start fresh (basically a Pensieve for your code)

## Credits

**Created by:** akoaik (42 student)

*"After all this time?"*
*"Always compiling."* 💚

---

**Disclaimer:** No Horcruxes were harmed in the making of this game. Side effects may include: improved C programming skills, better understanding of graphics libraries, and an uncontrollable urge to yell "Expecto Patronum!" at segfaults.
