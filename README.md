# Game tic-tak-toe

*only console*

# Screenshots

![image](https://github.com/user-attachments/assets/ed679eec-ffd7-4169-b84d-494da1c520b3)
![image](https://github.com/user-attachments/assets/ef0bd1c6-3d3f-47b1-a006-be8718aed7ac)

To select a player, you need to write 1 or 0

I think this code will tell you what's what:
```
static bool ChoicePlayer(int& choice) {
    if (choice == 1) {
        common.player = common.O;
        common.bot = common.X;
    }
    else if (choice == 0) {
        common.player = common.X;
        common.bot = common.O;
    }
    else {
        EndGame(choice);
    }
    return common.player && common.bot;
}
```
