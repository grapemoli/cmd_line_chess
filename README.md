# Chess

## Goals
1. Use design patterns :check:
2. Dynamic / Linear Programming if possible
3. NAMESPACES ??
4. Implement undo/redo features 
5. Implement Castling :check:
6. With the UI, reflect the board's printing such that the player who is playing is on the bottom.
7. Check for moving into check

## Savepoints
1. Create UML [O]
2. Determine representation of the Board / Pieces on the Board [O]
3. Create Chess Pieces  <--
4. Test Chess Pieces & Chess Eating 
5. Add pawn-transformation functionality <--
7. Create Board representation <-- [O]
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
[![](https://mermaid.ink/img/pako:eNrtW19v2zYQ_yqcghrKYqPvRmAgaYBhKIp1ydCXuhBoibaJyKJHUm68tP3s45GSLFKU5cbasM7Og23xjveH97vjSVSeg5glJBgHcYqFuKN4wfEKTTOk_l69QvckxZKyTCzpWpjRN0siRPSekpig0YgV17cM86TJwEYj9I5tSPQBpzTRoqIHybEki22T-_qLYn-PP2ctpLc0W0zbiH9wnIk546uoRiq5bzjH26hmqjL9y8S23XB6xRgNv-eEdHPdUrFk6062e8YeO5neZnSxlB6Xow9UUMm4ZvsFr0j024bwctSwm8-21TcKzLoAz4pksj00lT6IeHtAzTy9ntFtTtOE8Loei1APjD0DQOOJoYLjGwApuiNzmlENyx1Sb8kSbyjjOEWvkbIoj2UOF3oKETsRIBhpweKnYrrGvoWoZ0OAvwskJI84WXMi1Bppl8PLMYxqOO74VuUyimJBojGqlrY1AczcJ8Ur6F8kkvXRrXc0ZinjijJjLK2P41iLHyv3cfxozcBZJEuYuROv6p6HyvbSt2HTo_0ODYbGNqNhiJ5K64doW_68bFO8hs-xFYWBxfytzm1RyBOJc0nCGcBoXM_qQYsRY7RhNKnLyLOEhZ7xBZHRk463EwdD2raT9FIA2V1uIJpYAdUJ1hVKqZDRBlY3gvUXPqtwHJO1DDdjX5Ja_F_L9DEg9xeb5z5hTLMGhp2h3gHs9apHKF_-m8o0ZNWKabyq7wOUF7njD66TRX4J53w6MJ8Mvwm0uw04uQadzIntJOByeCT6_VtFH5I79yOtpEgmHT0ndzT9nCovTJWH9lSBzv7HSRXUS66Az2F_25JewhK8-sIBr9Z3Bu-LwOsFrb4fPLECr33uEbU9yDugrptIlclhrpzsMIac06P_Nsg8EDmxPDFO95goxSr-46lya9QUqVJodXKlcO6cLP0nCzwWPLFUAZd7TJTjxR2QJTpMZZLoCydFtBXnBOk_Qcwj8RNLEeN0nzcLPQg8IE2KYFV3JebSvS8xtpyTpc9kgZMOlirFyiZ0RyTR1qHXCA6LEBwWgZ74sZrZOAOpjnyeW57Ylwxh61N6P8cGButPWQYe9ywmuHPtZNINfCeXaV062aB8d5ulgTtogZiqRnkqbbQ4taxxcFdf65FRRpIIgtTEXGOyE4cO-qlHYXdwqI-D763tQzRzwrA1DkpEWc2va7j_eWLtTqqW-HaJl-9GV3WbwsNqt1N16075qqwvp406i7JWpUeG3vKEuZcAXof1banJUm2Ee8812iIeaxY9M2zZKeqhcqcDk38HEPuEl786TjEvkGSR4Q1pts5lWb6VxorirRXNNxj-G1i8QBo9kb2qHz99_FRfu4b1YU1Ry0sINgabEgrUNhfGAW9z5v8LwoODQYr2otS1pYZVdDBYVUGFQKIdZgCSugBVDDdpyj4LpFYDJXQ-J1xFHeF0wTiVy5VAMyxIgtRMQ61aFDXV7vIFYnMklwRpjw0Q6znT-u7Ls9Otmz4p2piNUkHS2whZC90m29mFD2OjItJWJAR9X8TcpiCGni5aq-08KlO6D4HQgfQq8E9oE3qVyFWv0K_Puq_oVeRMtz1Hi_TuDI3y2QfIW0SHvgLbwXWG-Bni3wnx3Z0sJ7p6uq_zFecL1suD1t2qRXJQu4c2g0ENsbD7eUdzCzfTIVpHTDexOUKAicQRAjSAj_EAnk-8ZDq0QDPTqI2brxd7q18rBka-9tTfne4DSyfHGTI_AmRULdEvDxN0M4MbkFgWleT6uhyYTOx3jxvUve-Z7xT8mknC5zgmlYZqZDJpmugjWxuzj62tuQyGwYrwFaZJMA50MkwD1SavyDQYq58JmeM8ldNgaEj1V_-Bo0gfRcj5ppiTKp8wnwZAUsv5VanAuWQP2ywOxnOcCjIM8rWygxSCqlGSgPnviv8ygK-vfwOtA0YC?type=png)](https://mermaid.live/edit#pako:eNrtW19v2zYQ_yqcghrKYqPvRmAgaYBhKIp1ydCXuhBoibaJyKJHUm68tP3s45GSLFKU5cbasM7Og23xjveH97vjSVSeg5glJBgHcYqFuKN4wfEKTTOk_l69QvckxZKyTCzpWpjRN0siRPSekpig0YgV17cM86TJwEYj9I5tSPQBpzTRoqIHybEki22T-_qLYn-PP2ctpLc0W0zbiH9wnIk546uoRiq5bzjH26hmqjL9y8S23XB6xRgNv-eEdHPdUrFk6062e8YeO5neZnSxlB6Xow9UUMm4ZvsFr0j024bwctSwm8-21TcKzLoAz4pksj00lT6IeHtAzTy9ntFtTtOE8Loei1APjD0DQOOJoYLjGwApuiNzmlENyx1Sb8kSbyjjOEWvkbIoj2UOF3oKETsRIBhpweKnYrrGvoWoZ0OAvwskJI84WXMi1Bppl8PLMYxqOO74VuUyimJBojGqlrY1AczcJ8Ur6F8kkvXRrXc0ZinjijJjLK2P41iLHyv3cfxozcBZJEuYuROv6p6HyvbSt2HTo_0ODYbGNqNhiJ5K64doW_68bFO8hs-xFYWBxfytzm1RyBOJc0nCGcBoXM_qQYsRY7RhNKnLyLOEhZ7xBZHRk463EwdD2raT9FIA2V1uIJpYAdUJ1hVKqZDRBlY3gvUXPqtwHJO1DDdjX5Ja_F_L9DEg9xeb5z5hTLMGhp2h3gHs9apHKF_-m8o0ZNWKabyq7wOUF7njD66TRX4J53w6MJ8Mvwm0uw04uQadzIntJOByeCT6_VtFH5I79yOtpEgmHT0ndzT9nCovTJWH9lSBzv7HSRXUS66Az2F_25JewhK8-sIBr9Z3Bu-LwOsFrb4fPLECr33uEbU9yDugrptIlclhrpzsMIac06P_Nsg8EDmxPDFO95goxSr-46lya9QUqVJodXKlcO6cLP0nCzwWPLFUAZd7TJTjxR2QJTpMZZLoCydFtBXnBOk_Qcwj8RNLEeN0nzcLPQg8IE2KYFV3JebSvS8xtpyTpc9kgZMOlirFyiZ0RyTR1qHXCA6LEBwWgZ74sZrZOAOpjnyeW57Ylwxh61N6P8cGButPWQYe9ywmuHPtZNINfCeXaV062aB8d5ulgTtogZiqRnkqbbQ4taxxcFdf65FRRpIIgtTEXGOyE4cO-qlHYXdwqI-D763tQzRzwrA1DkpEWc2va7j_eWLtTqqW-HaJl-9GV3WbwsNqt1N16075qqwvp406i7JWpUeG3vKEuZcAXof1banJUm2Ee8812iIeaxY9M2zZKeqhcqcDk38HEPuEl786TjEvkGSR4Q1pts5lWb6VxorirRXNNxj-G1i8QBo9kb2qHz99_FRfu4b1YU1Ry0sINgabEgrUNhfGAW9z5v8LwoODQYr2otS1pYZVdDBYVUGFQKIdZgCSugBVDDdpyj4LpFYDJXQ-J1xFHeF0wTiVy5VAMyxIgtRMQ61aFDXV7vIFYnMklwRpjw0Q6znT-u7Ls9Otmz4p2piNUkHS2whZC90m29mFD2OjItJWJAR9X8TcpiCGni5aq-08KlO6D4HQgfQq8E9oE3qVyFWv0K_Puq_oVeRMtz1Hi_TuDI3y2QfIW0SHvgLbwXWG-Bni3wnx3Z0sJ7p6uq_zFecL1suD1t2qRXJQu4c2g0ENsbD7eUdzCzfTIVpHTDexOUKAicQRAjSAj_EAnk-8ZDq0QDPTqI2brxd7q18rBka-9tTfne4DSyfHGTI_AmRULdEvDxN0M4MbkFgWleT6uhyYTOx3jxvUve-Z7xT8mknC5zgmlYZqZDJpmugjWxuzj62tuQyGwYrwFaZJMA50MkwD1SavyDQYq58JmeM8ldNgaEj1V_-Bo0gfRcj5ppiTKp8wnwZAUsv5VanAuWQP2ywOxnOcCjIM8rWygxSCqlGSgPnviv8ygK-vfwOtA0YC)
