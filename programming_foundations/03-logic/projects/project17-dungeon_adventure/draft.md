### 26. ⭐ CAPSTONE PROJECT: Dungeon Adventure — A Text‑Based RPG 🏰

**Goal:** Combine everything from Modules 1–3 into one epic text‑based dungeon crawler.  
You’ll explore rooms, fight monsters, find treasure, and manage your health – all while reinforcing **variables, arithmetic, control flow, loops, random numbers, and state machines**.

---

##### 🧠 What This Project Cements

- **Input/Output** – `printf`, `scanf` with validation  
- **Arithmetic** – damage, healing, gold totals  
- **Conditionals** – `if`/`else`, `switch` for events and choices  
- **Loops** – main game loop, combat loop, input validation  
- **Randomness** – `rand()` with `srand(time(NULL))` for events, monster stats, loot  
- **State variables** – HP, gold, potions, room number  
- **Game logic** – win/lose conditions, rest mechanics  
- **Git workflow** – committing a complete, polished project  

---

##### 🏗️ Game Design

###### Player Stats
- `int hp` – starts at **30**  
- `int gold` – starts at **0**  
- `int potions` – starts at **1** (each potion heals **10 HP**, cannot exceed max 50)  

###### Dungeon Layout
- **5 rooms** in sequence. Start in room 1, must reach room 5 to win.  
- After each room (except the last), you may **rest** or **continue**.

###### Random Room Events (use `rand() % 100 + 1`)
| Event   | Chance | Effect |
|---------|--------|--------|
| Monster | 40%    | Fight a random monster (HP 5–15, attack 2–6). Victory gives gold (5–15) and possibly a potion (20% chance). |
| Treasure| 30%    | Gain gold (10–30) and maybe a potion (25% chance). |
| Trap    | 20%    | Lose 5–15 HP. |
| Empty   | 10%    | Nothing happens. |

###### Combat (for Monster events)
- Player chooses:  
  `[A]ttack` – deal random damage 3–8, then monster counter‑attacks.  
  `[P]otion` – use one potion (if available) to heal 10 HP.  
- Combat continues until monster HP ≤ 0 (victory) or player HP ≤ 0 (defeat).  
- After victory, award gold and possibly a potion.

###### Resting
- After clearing a room (except room 5), prompt: `[R]est (heal 5 HP, costs a turn) or [C]ontinue?`  
- Resting heals 5 HP (capped at 50) but **does not** advance to the next room.  
- You may rest multiple times in the same room.

###### Game Over & Victory
- If HP reaches 0 → **"Game Over. You have perished."**  
- If you survive room 5 → **"You escaped the dungeon! Victory!"** – show final gold.

---

###### 🛠️ Implementation Steps (Follow in Order)

1. **Create the project folder**
   ```bash
   mkdir -p ~/c_development/c-stuff/03-logic/project18-dungeon-adventure
   cd ~/c_development/c-stuff/03-logic/project18-dungeon-adventure
   code .
   ```

2. **Write the skeleton** in `dungeon.c`
   - `#include <stdio.h>`, `<stdlib.h>`, `<time.h>`
   - `main()`:
     - Seed random: `srand(time(NULL));`
     - Declare and initialize player variables.
     - Start a `while` loop that runs while `hp > 0 && current_room <= 5`.

3. **Inside the main loop:**
   - Print room header and player stats.
   - Generate a random event number.
   - Use `if`/`else` or `switch` to handle each event type.

4. **Implement the Monster event (the most complex)**
   - Generate monster HP (`5 + rand() % 11`) and attack (`2 + rand() % 5`).
   - Enter a `while` combat loop that runs while both are alive.
   - Inside combat:
     - Ask for action (`'a'` or `'p'`). Validate input.
     - If attack: generate player damage (`3 + rand() % 6`), apply to monster, print result.
     - If monster still alive, it counter‑attacks: subtract its attack from player HP.
     - If potion: if `potions > 0`, heal (max 50), decrement potions; else inform player.
   - After monster dies, award gold (`5 + rand() % 11`) and possibly a potion (if `rand() % 5 == 0`).

5. **Other events** – straightforward arithmetic updates.

6. **After the event (if player alive and room < 5):**
   - Ask `[R]est or [C]ontinue?` with validation.
   - If `'r'`: `hp += 5; if (hp > 50) hp = 50;`
   - If `'c'`: `current_room++;`
   - Stay in the same room if rest chosen.

7. **End game messages** – print victory or defeat.

8. **Input validation** – for every menu, use a loop that re‑prompts until a valid character is entered. Remember to clear the input buffer after `scanf`:
   ```c
   int c;
   while ((c = getchar()) != '\n' && c != EOF);
   ```

9. **Compile with warnings**
   ```bash
   gcc -Wall -Wextra dungeon.c -o dungeon
   ```

10. **Test thoroughly** – try different random seeds, edge cases (low HP, no potions, many rests).

11. **Commit to Git**
    ```bash
    cd ~/c_development/c-stuff
    git add 03-logic/project18-dungeon-adventure/dungeon.c
    git commit -m "Added Project 18: Dungeon Adventure capstone"
    git push origin main
    ```

---

###### 📦 Example Output Snippet

```
=== Room 1 ===
HP: 30 | Gold: 0 | Potions: 1

A monster appears! (HP: 12, Attack: 4)
[A]ttack or [P]otion? a
You deal 6 damage. Monster deals 4 damage.
Monster HP: 6 | Your HP: 26
[A]ttack or [P]otion? a
You deal 7 damage. Monster dies!
You gain 10 gold.
You found a potion!

HP: 26 | Gold: 10 | Potions: 2
[R]est (heal 5) or [C]ontinue? r
You rest. HP: 31

=== Room 2 ===
...
```

---

###### 🔥 Extra Challenges (Optional – for bragging rights)

- Add a **difficulty level** chosen at start (affects monster stats and trap damage).  
- Create a **shop** between rooms where you can buy potions with gold.  
- Use `enum` for event types (peek at Module 5 if you’re curious).  
- Save the highest gold ever earned to a file (requires Module 12, but you can come back later).

---