# Chess

## Goals
1. Use design patterns ✔️
2. Dynamic / Linear Programming if possible
3. NAMESPACES ??
4. Implement undo/redo features 
5. Implement Castling ✔️
6. With the UI, reflect the board's printing such that the player who is playing is on the bottom
7. Letter = x, Number = y system
8. Check for moving into check

## Savepoints
1. Create UML ✔️
2. Determine representation of the Board / Pieces on the Board ✔️
3. Create Chess Pieces  👈
4. Test Chess Pieces & Chess Eating 
5. Add pawn-transformation functionality ✔️
7. Create Board representation ✔️
8. Create Board builder
9. Give option to reverse the printing of the board based on which player is playing
10. Optimize the physical representation of the board

## Algorithms & Implementations
### Collision Detection and Game Over Detection
Collision detection WILL NOT require the latest concretion, BUT GAME OVER DETECTION WILL.

For collision detection: check the color (does not depend on latest concretion), if different then replace. 
For Game Over dectection: get the concretion, if opposing color & king, then return game_over.\
- use double dispatching to get the concretion -- get_result() will return true IF A KING (and you can get the color because all base Chess_Piece will have an is_white attribute)!!!!

### Castling Detection
- Neither the king nor the rook has previously moved.
- There are no pieces between the king and the rook.
- The king is not currently in check.
- The king does not pass through or finish on a square that is attacked by an enemy piece.
1. If the user attempts to move the king left/right 2 spaces -and- this is the King's first move:
2. Check that the rook in the direction of movement (if moves_.size() is 0, then it can be inferred that a rook is at this position)
3. Check that there are not pieces in between the king and rook
4. The king moves two spaces over in the direction specified
5. The corresponding rook moves +/-1 where the king's original position was (depends on the king's direction of motion)
^ Additional implementation: you can allow for movement *on top* of the rook to activate castling behavior


### Transformation Algorithm
1. For every pawn movement (in the Strategy), if the Pawn is moved to the end of the board, prompt the user for the piece they wish to transform the pawn into
2. Replace the pawn with the appropiate instance
^ Note, one does not need to check that the pawn moved to the 'correct end' of the board, because Pawn's are programmed to only allow forward movement


### Undo
Currently, undo() is only supported for when the user inputs a faulty coordinate. However, supporting undo for "undoing" the conglomerate moves that the two players have done is simple: pop the Chess_Piece off of Chess_Board.moves_, and pop off the Chess_Piece's previous placement stored in Chess_Piece.moves_. Then, restore the Chess_Piece's previous placement.



### User Interface
~ insert Board ~ <br>
WHITE'S TURN (input 'QUIT' to quit): <br>
Choose a piece to move: x, y <br>
New X coordinate: <br>
New Y coordinate: <br>

.. <br>
.. <br>
.. <br>



## Board Representation (2D Array)
The current implementation of the chess board is via a 2D array; however, to increase the ease of replacing representations of the chess board in the future, the board is wrapped in a class that does not specify representation. Along with ease of replacing representation of the board, the strategy for movement of the chess piece's can also be easily replaced. It is the client's responsibility to pair the appropiate strategy with the board representation.

The following symbols represent the following chess pieces:
K – king <br>
Q – queen <br>
R – rook <br>
B – bishop <br>
N – knight <br>
P – pawn <br>
| ~R~ | ~N~ | ~B~ | ~Q~ | ~K~ | ~B~ | ~N~ | ~R~ | <br>
| ~P~ | ~P~ | ~P~ | ~P~ | ~P~ | ~P~ | ~P~ | ~P~ | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
| -P- | -P- | -P- | -P- | -P- | -P- | -P- | -P- | <br>
| -R- | -N- | -B- | -Q- | -K- | -B- | -N- | -R- | <br>

* differentiation of -white- and ~black~ pieces.

![image](https://github.com/grapemoli/cmd_line_chess/assets/105399768/2df35ad8-08ec-4466-8c38-e2d488acf922)



## UML
[![](https://mermaid.ink/img/pako:eNrtW1Fv2zYQ_iucggZKY6PvQmAgaYBhKIp1ydCXuhBoibaJyKJHUm68tPvt45GSLYqU5cRqtqbOg23xjnfHu--OJ1F5CBKWkiAKkgwLcU3xjOMFGudI_b16hW5IhiVluZjTpTCjb-dEiPgDJQlBwyErr68Y5qnLwIZD9J6tSPwRZzTVouJbybEks7XLffFVsX_AX_IW0juaz8ZtxD85zsWU8UVcI1Xcl5zjdVwzVZn-dWTbbji9YoyGPwpCurmuqJizZSfbDWN3nUzvcjqbS8-S449UUMm4ZvsVL0j8-4rwatSwm8827xsFxi_AsyC5bA_NRh9EvD2gZp72Z3xV0CwlvK7HItQDY88A0HhiqOD4FkCKrsmU5lTDcovUKzLHK8o4ztAbpCwqElnAhZ5CxFYECEZasPilnK6xbyHqwRDg7wQJyWNOlpwI5SO95PAsglENxy3fonKjKB0SR2jj2tYEMHPvFa-gf5NY1kfX3tGEZYwryoSxrD6OEy0-UsvHyd2Wcl5fWqiMq4wfuCbvtvh0YJQb3QN0X5k3QOvq51mb4iV8RpabTy3mf-rcFoXck6SQJJwATqJ62p62GBGhFaNpXUaRpyz0jM-IjO91QBuONqR1O0m7Ash2IAzRBAOoTjQyKmS8Au_G4H_hswonCVnKcBX5stDhP0GyKiI-H1n836p8Mqj3V5-HPnFNcwfUjaHHI9prdo_YPntOZRrDyiUawOp7D-VlMvmj10grv4SfKcG6cuIpOXdexr65FzTyC9qZl7adwJrCAxHv3y_6kNy5KWklZQLp8DTyRdOP6dFfety2pwe09D9OeqD98gMWFfa3_WgfVYDVFw3Aan1HwPYFWC9Q9c3fSyvkelE9IrUHeXvUbxOKKiHMVSMjjCHHlHiWFsc88XhpuWFW1WNylG767ulxZdSU6VFqbeRHubhjgjxLgsCzvpeWHrCmHpPjcHF7ZIaOQ5UY-qKRFtqKY1I8S1KYZ9svLS3Mqvps_nsQuEdqlNHY3GWYy-Z9hrHlmCDfOUHgmIJlyhZlJromkmiD0RsEJz0ITnpAT3K3mekcYGzOax5ansZXDGHrE3g_xwoG6w9PfO6wmODmtJNJ9-udXKZr6WSDKt5tlsbyaQvqVAUqMmkDqFG_nFO3uq-HRhlJYwiSC0NnciMOHfSfPQrbUz99lntjbRnCzQnD5hxqiKqCX9Rw_3pk7UiqvPh2hqfvQOd1m8L9ynmjENcX5a1Qnpw26izKUpUeGXrLE-ZewvaUyT3Me-3hBy-Ficurtobaduev0olm13PDln2krr05HZj8-4PYJbz61XFYeYIkiw1vSPNlIatKrjRuKN6y4b6J8P-A5QnSQIptr376_Olz3XeO9WFNUcvLBDYcXQklgF3HNHDszvwv0OwBs9W79QHm073hinbi1XNMXGET7Q1bVWUhpGiLHgCnrkobhsssY18EUr5EKZ1OCVfxRzibMU7lfCHQBAuSIjXTUDd9i5pqt_sCsSmSc4L0ig0k69nT-jbLQ6NtN81TvDK7pwKntzuyHN0mu7E178dGRaytSAl6XMSa6Emg0YuXao-Pq-TuQyC0Jb0K_At6h14lctVA9Ltm3Wz0KnKie6GDRXr3CKeQ9gHyFtGhr9R2cB0hfoT4IyG-vb3lRFfP-gt6jUMF65VA6zbWIjWQu4M2gUENs7D72Yi7-5vpELEDppv4HCDAROMAARrEh6wAHlw8ZTq0QRPTtkXuS8PeCtiKgaGvWfX3qrvA0slxhMyPABlVT_QrwQRdTuB2JJHlI4CLi2pgNLLfKHaoO98e3yr4LZeET3FCNho2I6ORa6KPbG3OPra2BjMYBAvCF5imQRToZBgHqlVekHEQqZ8pmeIik-NgYEj1F_qBo0wfRSj4qpyTqTVhPg6ApNz5TanAhWS36zwJoinOBBkExVLZQUpBm1GSgvnvy_8dgK9v_wIhmD-4?type=png)](https://mermaid.live/edit#pako:eNrtW1Fv2zYQ_iucggZKY6PvQmAgaYBhKIp1ydCXuhBoibaJyKJHUm68tPvt45GSLYqU5cRqtqbOg23xjnfHu--OJ1F5CBKWkiAKkgwLcU3xjOMFGudI_b16hW5IhiVluZjTpTCjb-dEiPgDJQlBwyErr68Y5qnLwIZD9J6tSPwRZzTVouJbybEks7XLffFVsX_AX_IW0juaz8ZtxD85zsWU8UVcI1Xcl5zjdVwzVZn-dWTbbji9YoyGPwpCurmuqJizZSfbDWN3nUzvcjqbS8-S449UUMm4ZvsVL0j8-4rwatSwm8827xsFxi_AsyC5bA_NRh9EvD2gZp72Z3xV0CwlvK7HItQDY88A0HhiqOD4FkCKrsmU5lTDcovUKzLHK8o4ztAbpCwqElnAhZ5CxFYECEZasPilnK6xbyHqwRDg7wQJyWNOlpwI5SO95PAsglENxy3fonKjKB0SR2jj2tYEMHPvFa-gf5NY1kfX3tGEZYwryoSxrD6OEy0-UsvHyd2Wcl5fWqiMq4wfuCbvtvh0YJQb3QN0X5k3QOvq51mb4iV8RpabTy3mf-rcFoXck6SQJJwATqJ62p62GBGhFaNpXUaRpyz0jM-IjO91QBuONqR1O0m7Ash2IAzRBAOoTjQyKmS8Au_G4H_hswonCVnKcBX5stDhP0GyKiI-H1n836p8Mqj3V5-HPnFNcwfUjaHHI9prdo_YPntOZRrDyiUawOp7D-VlMvmj10grv4SfKcG6cuIpOXdexr65FzTyC9qZl7adwJrCAxHv3y_6kNy5KWklZQLp8DTyRdOP6dFfety2pwe09D9OeqD98gMWFfa3_WgfVYDVFw3Aan1HwPYFWC9Q9c3fSyvkelE9IrUHeXvUbxOKKiHMVSMjjCHHlHiWFsc88XhpuWFW1WNylG767ulxZdSU6VFqbeRHubhjgjxLgsCzvpeWHrCmHpPjcHF7ZIaOQ5UY-qKRFtqKY1I8S1KYZ9svLS3Mqvps_nsQuEdqlNHY3GWYy-Z9hrHlmCDfOUHgmIJlyhZlJromkmiD0RsEJz0ITnpAT3K3mekcYGzOax5ansZXDGHrE3g_xwoG6w9PfO6wmODmtJNJ9-udXKZr6WSDKt5tlsbyaQvqVAUqMmkDqFG_nFO3uq-HRhlJYwiSC0NnciMOHfSfPQrbUz99lntjbRnCzQnD5hxqiKqCX9Rw_3pk7UiqvPh2hqfvQOd1m8L9ynmjENcX5a1Qnpw26izKUpUeGXrLE-ZewvaUyT3Me-3hBy-Ficurtobaduev0olm13PDln2krr05HZj8-4PYJbz61XFYeYIkiw1vSPNlIatKrjRuKN6y4b6J8P-A5QnSQIptr376_Olz3XeO9WFNUcvLBDYcXQklgF3HNHDszvwv0OwBs9W79QHm073hinbi1XNMXGET7Q1bVWUhpGiLHgCnrkobhsssY18EUr5EKZ1OCVfxRzibMU7lfCHQBAuSIjXTUDd9i5pqt_sCsSmSc4L0ig0k69nT-jbLQ6NtN81TvDK7pwKntzuyHN0mu7E178dGRaytSAl6XMSa6Emg0YuXao-Pq-TuQyC0Jb0K_At6h14lctVA9Ltm3Wz0KnKie6GDRXr3CKeQ9gHyFtGhr9R2cB0hfoT4IyG-vb3lRFfP-gt6jUMF65VA6zbWIjWQu4M2gUENs7D72Yi7-5vpELEDppv4HCDAROMAARrEh6wAHlw8ZTq0QRPTtkXuS8PeCtiKgaGvWfX3qrvA0slxhMyPABlVT_QrwQRdTuB2JJHlI4CLi2pgNLLfKHaoO98e3yr4LZeET3FCNho2I6ORa6KPbG3OPra2BjMYBAvCF5imQRToZBgHqlVekHEQqZ8pmeIik-NgYEj1F_qBo0wfRSj4qpyTqTVhPg6ApNz5TanAhWS36zwJoinOBBkExVLZQUpBm1GSgvnvy_8dgK9v_wIhmD-4)
