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
### Support for mulitple methods of position input
The following input styles are sought to be supported in this application: 
1. Algebraic-style notation (ex. A1; H 3; H,3)
2. Coordinates-style notation (ex. (1, 3); 1, 3; 1,3)

To do this, all algorithms that deal with string-to-coordinates conversions and validation will be moved its own seperate class. This allows for the decoupling of string validation from the client (the Chess Board), and allows the possible complexity of string validation to not affect the Chess Board-related algorithms.

The algorithm generally works as such: 
1. Clean the string (does not need to be called by the client)
2. Check the validity of the string (must be called by the client)
3. Return the x and y coordindates (must be called by the client)

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


## Bugs
### Minor Bugs
#### 1.1 Stream Corruption upon 'QUIT'
The following will cause a stream corruption:
![image](https://github.com/grapemoli/cmd_line_chess/assets/105399768/d4ecb814-18c8-4bd8-bc0b-d7b50ba76a14)
In other words, upon 'QUIT'-ing from the movement interface, there is a minor bug. This causes no problems to the program, but may confuse users. This may be a nice minor fix in the longrun.


## UML
[![](https://mermaid.ink/img/pako:eNrtW21v2zYQ_iucggZKY6PfDcNAXoBhKIp1SdEvdUHQEm0TkUWPpNx4afbbxxfJFkUycmI121znQ2Lzjsfj3XPH40seooSmOBpESYY4vyZoxtACjHMgf968ATc4Q4LQnM_JkpvWqznmHH4kOMGg36fl90uKWOoy0H4ffKArDD-jjKRaFLwVDAk8W7vcw--S_SP6lgdI70k-G4eInxjK-ZSyBayRKu4LxtAa1lSVqn8f2bobTq8YM8IfBcbtXJeEz-myle2G0rtWpvc5mc2FZ8rwM-FEUKbZfkULDH9fYVa1GnbzO2R9M4Cxi-JZ4FyEXbMZT3k87FDTT9sTXhYkSzGrj2MR6o6xeyjQeHwo4XilQAqu8ZTkRMNyi9RLPEcrQhnKwDsgNSoSUagvugvmWxFKMNCC-S9ld419C1EPhqB-TgAXDDK8ZJhLG-kpx2cD1arhuOVbVGbkpUHgAGxMGwwA0_de8nLyF4ai3rr2tiY0o0xSJpRm9XaUaPEDOX2U3G0p5_WpxVK5Svmeq_LTGp_2zOBm7B64r9TrgXX18Sw08FL9HlhmPrWY_65zWxR8j5NC4HiicDKoh-1pQIkBWFGS1mUUeUpjT_sMC3ivHdowtCGtwyRtCkW2HWGIxhmK6ngjI1zAlbIuVPbnPq1QkuCliFcDXxQ6_CdAVEnEZyOL_7GKJ4N6f_Z56BLXJHdA3Wh6PqK9aneI7bPXHExjWJpEA1j-3WHwMpj83muElV_CzxRgbTHxkpg7L33fXAsa8aXKmUNbTtSc4j0R718vupDcuijpQcoA0u5pxIumH8Oju_C4DYeHKun_P-EBdosPNam4u-VH26gCrP7SAKwe7wjYrgDrBare_B1aIteT6hCpHcjbIX8bV1QBYb41IsIocgyJVylxzInHocWGmVWHwVGa6YeHx6UZpgyPctRGfJSTOwbIqwSIOus7tPBQc-owOPYXt0NkaD9UgaG_NMJCa3EMilcJCnO2fWhhYWbVZfHfgcAdQqP0xmaXYb429xlGl2OA_OAAUdcUNJO6SDXBNRZYKwzeAXXTA9RNjxonudv0dC4wNvc1D4HT-IohDp7A-zlWqrF-eOIzh8WkNqetTLpeb-UyVUsrm8ri7WppLJ8GUCczUJEJG0CN_OXcutVt3TeD4RQqJ7kwdDo3_NBC_9m9sL3103e5N9aSwd2YMGzOpQavMviwhvu3I2tFkunFtzK8fAU6r-sU75bOG4m4PilvhvLEtBnOoixl6hGxNz0h5iVsb5ncy7y3Hn5lpThxeeXSUFvu_Fk60ey6bxxYR-qjN7srJv_6wJ8SXn1quaw8AYJCwxuTfFmIKpPLETcUb9pwXyL8N2B5AjSQoG3VL1-_fLUKn2w5R9Atyc7decU1FQLPDGyguhJKaLsmayDc7flv4NwDc6uq6wLmpzsDGTyJZM8FcoVasDOgZf5VLgVbXCnY6ny1YbjIMvqNA2lLkJLpFDPpf4miGWVEzBccTBDHKZA9DXUDKtnV3ghwQKdAzDHQMzZgrcdV8J3LQ6OgN2UVXJl1VYLTWzdZhg7Jbizau7ERDrUWKQbP81gTPYkqAeFSrv6wCvsuBKqCpVOBf6qqolOJTJYW3c5ZlyGdipzoKmlvkd7Vw0mkXYA8IDr2pdoWriPEjxB_JsS3G1-GdfasP91rXDdYjwWtDa5FaiD3CdpENWqYxe2nJu7qb7orj-3R3fhnDwHGG3sI0CDeZwbqSOMl3VUZNDFl28B9TuzNgEEM9H1lrF3FnvtkeNPcETIHARnz_AR-ovCKUpaSXC5ZPLB2hjc49Q2fsAvk0BmkGgzlcrCqpHb62LhcmdoRw_J8sFmIO2k4wygPMYdOFvXraQwuJmp_lghe7gGHw6plNLJfXzvUJ1_ab0f4Tc6cTVFSPb4eDjcto5HrNB_ZKld8bKGSO-pFC8wWiKTRINIOHkdy87DA42ggP6Z4iopMjKOeIdX_-UFxlJCQhIKtyj6ZnBNi40iRpD0f5RCoEPR2nSfRYIoyjntRsVTuKwVtWnGq1P9Q_p-F-vP4D341oXQ?type=png)](https://mermaid.live/edit#pako:eNrtW21v2zYQ_iucggZKY6PfDcNAXoBhKIp1SdEvdUHQEm0TkUWPpNx4afbbxxfJFkUycmI121znQ2Lzjsfj3XPH40seooSmOBpESYY4vyZoxtACjHMgf968ATc4Q4LQnM_JkpvWqznmHH4kOMGg36fl90uKWOoy0H4ffKArDD-jjKRaFLwVDAk8W7vcw--S_SP6lgdI70k-G4eInxjK-ZSyBayRKu4LxtAa1lSVqn8f2bobTq8YM8IfBcbtXJeEz-myle2G0rtWpvc5mc2FZ8rwM-FEUKbZfkULDH9fYVa1GnbzO2R9M4Cxi-JZ4FyEXbMZT3k87FDTT9sTXhYkSzGrj2MR6o6xeyjQeHwo4XilQAqu8ZTkRMNyi9RLPEcrQhnKwDsgNSoSUagvugvmWxFKMNCC-S9ld419C1EPhqB-TgAXDDK8ZJhLG-kpx2cD1arhuOVbVGbkpUHgAGxMGwwA0_de8nLyF4ai3rr2tiY0o0xSJpRm9XaUaPEDOX2U3G0p5_WpxVK5Svmeq_LTGp_2zOBm7B64r9TrgXX18Sw08FL9HlhmPrWY_65zWxR8j5NC4HiicDKoh-1pQIkBWFGS1mUUeUpjT_sMC3ivHdowtCGtwyRtCkW2HWGIxhmK6ngjI1zAlbIuVPbnPq1QkuCliFcDXxQ6_CdAVEnEZyOL_7GKJ4N6f_Z56BLXJHdA3Wh6PqK9aneI7bPXHExjWJpEA1j-3WHwMpj83muElV_CzxRgbTHxkpg7L33fXAsa8aXKmUNbTtSc4j0R718vupDcuijpQcoA0u5pxIumH8Oju_C4DYeHKun_P-EBdosPNam4u-VH26gCrP7SAKwe7wjYrgDrBare_B1aIteT6hCpHcjbIX8bV1QBYb41IsIocgyJVylxzInHocWGmVWHwVGa6YeHx6UZpgyPctRGfJSTOwbIqwSIOus7tPBQc-owOPYXt0NkaD9UgaG_NMJCa3EMilcJCnO2fWhhYWbVZfHfgcAdQqP0xmaXYb429xlGl2OA_OAAUdcUNJO6SDXBNRZYKwzeAXXTA9RNjxonudv0dC4wNvc1D4HT-IohDp7A-zlWqrF-eOIzh8WkNqetTLpeb-UyVUsrm8ri7WppLJ8GUCczUJEJG0CN_OXcutVt3TeD4RQqJ7kwdDo3_NBC_9m9sL3103e5N9aSwd2YMGzOpQavMviwhvu3I2tFkunFtzK8fAU6r-sU75bOG4m4PilvhvLEtBnOoixl6hGxNz0h5iVsb5ncy7y3Hn5lpThxeeXSUFvu_Fk60ey6bxxYR-qjN7srJv_6wJ8SXn1quaw8AYJCwxuTfFmIKpPLETcUb9pwXyL8N2B5AjSQoG3VL1-_fLUKn2w5R9Atyc7decU1FQLPDGyguhJKaLsmayDc7flv4NwDc6uq6wLmpzsDGTyJZM8FcoVasDOgZf5VLgVbXCnY6ny1YbjIMvqNA2lLkJLpFDPpf4miGWVEzBccTBDHKZA9DXUDKtnV3ghwQKdAzDHQMzZgrcdV8J3LQ6OgN2UVXJl1VYLTWzdZhg7Jbizau7ERDrUWKQbP81gTPYkqAeFSrv6wCvsuBKqCpVOBf6qqolOJTJYW3c5ZlyGdipzoKmlvkd7Vw0mkXYA8IDr2pdoWriPEjxB_JsS3G1-GdfasP91rXDdYjwWtDa5FaiD3CdpENWqYxe2nJu7qb7orj-3R3fhnDwHGG3sI0CDeZwbqSOMl3VUZNDFl28B9TuzNgEEM9H1lrF3FnvtkeNPcETIHARnz_AR-ovCKUpaSXC5ZPLB2hjc49Q2fsAvk0BmkGgzlcrCqpHb62LhcmdoRw_J8sFmIO2k4wygPMYdOFvXraQwuJmp_lghe7gGHw6plNLJfXzvUJ1_ab0f4Tc6cTVFSPb4eDjcto5HrNB_ZKld8bKGSO-pFC8wWiKTRINIOHkdy87DA42ggP6Z4iopMjKOeIdX_-UFxlJCQhIKtyj6ZnBNi40iRpD0f5RCoEPR2nSfRYIoyjntRsVTuKwVtWnGq1P9Q_p-F-vP4D341oXQ)
