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
[![](https://mermaid.ink/img/pako:eNrtW21v2zYQ_iucghrKaqPfhcBAXoBhKIp1ydAvdSHQEm0TkUWPpNx4affbxxdJFl9kObE2rIbywbF4x7vj3XPkkZSfg4SkKIiCJIOM3WG4pHANZjkQf2_egHuUQY5JzlZ4w3Tr7QoxFn_EKEFgMiHl8w2BNHUZyGQCPpAtij_BDKdKVPzAKeRouXO5r74J9o_wa95Ceo_z5ayN-AeFOVsQuo4bpIr7mlK4ixumCtO_TU3bNadXjNbwe4FQN9cNZiuy6WS7J-Sxk-l9jpcr7hly_AkzzAlVbL_ANYp_2yJatR5m3yvU8Tiu0y1kPBP-N9n1Z1uEdU_te8mzRjlvD3-tT6KqHTS6n4pZfFPgLEW0qccgNINv9pDA9OBEQP5WJgK4QwucYwX9fTbcoBXcYkJhBt4BYVGR8EI-qC6I7UVIwUAJZj-V3VV-Gah91gT5dwEYpzFFG4qY8JEacngZyVYF-T3funIjKx0SR6B2bWuS6b5Pgpfhv1DMm607b2tCMkIFZU5I1myHiRIfieHD5HFPedscWiiMq4wfuyYftng01sq17jF4qswbg1319bJN8UZ-RoabRwbz301ug4KeUFJwFM4lTqLm1DBqMSICW4LTpowiT0noaV8iHj-pgFqO1qRdO0m5QpLNQGiiDoakOtHIMOPxVno3lv5nPqtgkqAND7eRLwsN_u9VfmgU-2es5z5xinMHpFbTyxHqNbtHrF7-l8oUJoVLFCDF_yOUl8nhj56VJn4JQ8IcmTCaXwfansitZJL1zrmtBXJM4Ynw9k_2fUjuXFGUkjJbVHis5FD0IRdemQsP7bkgC_wfJxfAcckgBxX2t7AoH1XoVA8WOpW-AZ2vQqcXlWrfd25TtBpUj7DsQd4RM7MORYV-_WTBXxsy4L__SkWfbJxbIuhR9ZgJpZv-9Vy40WrKXCi1WslQDm7Ihv6zQR7gnVsuyDH1mAmnizsiDVQcqixQD1YOKCuGDOg_A_Tp9LnlgB5VnwV7DwKPyIMyGvXOQD_aewNty5ANfWaDPPEnmVAsbAJ3iCNlHXgH5MUMkBczUk_yWPd07gLqq4_nloPtiiFsPcz2c2xlY_MoY-QZnsEkd4-dTKrG7uTSxUcnm5yfu81SwB21QExMN0XGTbRYk5VzSdb09UQrQ2ksg-RizulsxaGDPkTBuTkwrh49ocAiFhvhKTcWfhFhy_H1AaYhKvVMZN3tviQ1hnD0FI79LbN6P-HeKKKYu3BoNufSjVU1zVVjcfh5atRoYsH11Uqvr8neNm0KjytwrNKkOShfKeJb-LQ6g7IR6zMPvWs4pF6CHHXYrN1cFl7B9-AVWlvEE8WieoYt5VQzVHZ3yeQvk9gh4dW3jhvxC8BJrHlDnG8KXtU4QmNN8U4a7is1_w8sXgCFntj06ucvn780fedYHzYUtbyxYmLQlVCi1nWMBV6353lBeHQ0SMFBlNq2NLAKjgarmFBlIMEeMxKSagKqGa6zjHxlQHgDpHixQFREHcBsSSjmqzUDc8hQCkRPTa3reNHV3OsyQBaArxBQI9ZAbOZM64tSz9aeVW8m4q1eKAUkvbsFw9Ftsq2l-Dg2zGJlRYrAyyJmlweJ3PioSi6uUroPgbIW6VXgn7JM6FUiFbVCv2NWdUWvIueq7DlZpHdlcKbPPkDeIjr0TbAdXAPEB4i_EOL74x6K1OzZfPfTuisz3jY1jnUMkoXcA7S5bFQwC7sPBt1lXHeXETuhu47PCQJ0NE4QoEB8ygjkQd5russyaK6Ltch95907A7ZiYOIrUf0V6iGwdHIMkPkRICPmE_W2OQLXc7kJSXi527-6qhqmU_NldYd68McPewW_5hzRBUxQraFumU5dE31kY3H2sbUVmME4WCO6hjgNokAlwywQpfIazYJIfE3RAhYZnwVjTWr-HkVylOkjCAXdln0yMSZIZ4EkCXd-FypgwcnDLk-CaAEzhsZBsRF2oFJQ3YpSaf6H8qcv8t_3fwCdAxSl?type=png)](https://mermaid.live/edit#pako:eNrtW21v2zYQ_iucghrKaqPfhcBAXoBhKIp1ydAvdSHQEm0TkUWPpNx4affbxxdJFl9kObE2rIbywbF4x7vj3XPkkZSfg4SkKIiCJIOM3WG4pHANZjkQf2_egHuUQY5JzlZ4w3Tr7QoxFn_EKEFgMiHl8w2BNHUZyGQCPpAtij_BDKdKVPzAKeRouXO5r74J9o_wa95Ceo_z5ayN-AeFOVsQuo4bpIr7mlK4ixumCtO_TU3bNadXjNbwe4FQN9cNZiuy6WS7J-Sxk-l9jpcr7hly_AkzzAlVbL_ANYp_2yJatR5m3yvU8Tiu0y1kPBP-N9n1Z1uEdU_te8mzRjlvD3-tT6KqHTS6n4pZfFPgLEW0qccgNINv9pDA9OBEQP5WJgK4QwucYwX9fTbcoBXcYkJhBt4BYVGR8EI-qC6I7UVIwUAJZj-V3VV-Gah91gT5dwEYpzFFG4qY8JEacngZyVYF-T3funIjKx0SR6B2bWuS6b5Pgpfhv1DMm607b2tCMkIFZU5I1myHiRIfieHD5HFPedscWiiMq4wfuyYftng01sq17jF4qswbg1319bJN8UZ-RoabRwbz301ug4KeUFJwFM4lTqLm1DBqMSICW4LTpowiT0noaV8iHj-pgFqO1qRdO0m5QpLNQGiiDoakOtHIMOPxVno3lv5nPqtgkqAND7eRLwsN_u9VfmgU-2es5z5xinMHpFbTyxHqNbtHrF7-l8oUJoVLFCDF_yOUl8nhj56VJn4JQ8IcmTCaXwfansitZJL1zrmtBXJM4Ynw9k_2fUjuXFGUkjJbVHis5FD0IRdemQsP7bkgC_wfJxfAcckgBxX2t7AoH1XoVA8WOpW-AZ2vQqcXlWrfd25TtBpUj7DsQd4RM7MORYV-_WTBXxsy4L__SkWfbJxbIuhR9ZgJpZv-9Vy40WrKXCi1WslQDm7Ihv6zQR7gnVsuyDH1mAmnizsiDVQcqixQD1YOKCuGDOg_A_Tp9LnlgB5VnwV7DwKPyIMyGvXOQD_aewNty5ANfWaDPPEnmVAsbAJ3iCNlHXgH5MUMkBczUk_yWPd07gLqq4_nloPtiiFsPcz2c2xlY_MoY-QZnsEkd4-dTKrG7uTSxUcnm5yfu81SwB21QExMN0XGTbRYk5VzSdb09UQrQ2ksg-RizulsxaGDPkTBuTkwrh49ocAiFhvhKTcWfhFhy_H1AaYhKvVMZN3tviQ1hnD0FI79LbN6P-HeKKKYu3BoNufSjVU1zVVjcfh5atRoYsH11Uqvr8neNm0KjytwrNKkOShfKeJb-LQ6g7IR6zMPvWs4pF6CHHXYrN1cFl7B9-AVWlvEE8WieoYt5VQzVHZ3yeQvk9gh4dW3jhvxC8BJrHlDnG8KXtU4QmNN8U4a7is1_w8sXgCFntj06ucvn780fedYHzYUtbyxYmLQlVCi1nWMBV6353lBeHQ0SMFBlNq2NLAKjgarmFBlIMEeMxKSagKqGa6zjHxlQHgDpHixQFREHcBsSSjmqzUDc8hQCkRPTa3reNHV3OsyQBaArxBQI9ZAbOZM64tSz9aeVW8m4q1eKAUkvbsFw9Ftsq2l-Dg2zGJlRYrAyyJmlweJ3PioSi6uUroPgbIW6VXgn7JM6FUiFbVCv2NWdUWvIueq7DlZpHdlcKbPPkDeIjr0TbAdXAPEB4i_EOL74x6K1OzZfPfTuisz3jY1jnUMkoXcA7S5bFQwC7sPBt1lXHeXETuhu47PCQJ0NE4QoEB8ygjkQd5russyaK6Ltch95907A7ZiYOIrUf0V6iGwdHIMkPkRICPmE_W2OQLXc7kJSXi527-6qhqmU_NldYd68McPewW_5hzRBUxQraFumU5dE31kY3H2sbUVmME4WCO6hjgNokAlwywQpfIazYJIfE3RAhYZnwVjTWr-HkVylOkjCAXdln0yMSZIZ4EkCXd-FypgwcnDLk-CaAEzhsZBsRF2oFJQ3YpSaf6H8qcv8t_3fwCdAxSl)
