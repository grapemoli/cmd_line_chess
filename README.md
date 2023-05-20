# Chess

## Goals
1. Use design patterns ✔️
2. Dynamic / Linear Programming if possible
3. NAMESPACES ??
4. Implement undo/redo features 
5. Implement Castling ✔️
6. With the UI, reflect the board's printing such that the player who is playing is on the bottom.
7. Check for moving into check

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
[![](https://mermaid.ink/img/pako:eNrtWm1v2zYQ_iucghrKaqPfhcBA0gDDUBTrkqFf6kKgJdomIoseSbnx0va3jy-SzTdZTqwNq-d8SCLe8e5499zxROopykiOoiTKCsjYLYZzCpdgUgLx8-oVuEMF5JiUbIFXTI--XSDG0g8YZQiMRqR-viGQ5j4DGY3Ae7JG6UdY4FyJSu85hRzNNz731VfB_gF-KVtI73A5n7QR_6CwZDNCl6lBarivKYWb1DBVmP51bNuuOYNitIbfK4S6uW4wW5BVJ9sdIQ-dTO9KPF_wwJLTj5hhTqhi-wUuUfrbGtFmVLPr323e1wq0XyTPEpW8PTRbfTLi7QHV85Q_05sKFzmiph6LYAbGniFBE4ihgONbCVJwi2a4xAqWO6TeoAVcY0JhAd4AYVGV8Uo-qCmI7URIwUAJZj_V0xX2LUQ9aYL8uQCM05SiFUVM-EgtOb5M5KiC445v2biR1Q5JE7B1bWsC6LmPgpfhv1DKzdFNcDQjBaGCMiWkMMdhpsQnYvkwe9hRXptLi4VxjfFD3-T9Fg-GWrnWPQSPjXlDsGn-vWxTvJK_E8vNA4v5u8ltUdAjyiqO4qnESWKm7aDFiASsCc5NGVWZkzgwPkc8fVQBdRytSZt2knKFJNuB0EQdDEn1olFgxtO19G4q_c9CVsEsQyser5NQFlr835r80CgOV5OnPnGKSw-kztDzERo0u0esXv6byhQmhUsUIMXfA5TXyRGOnpMmYQnnhDkwYTS_DrRbyJ1kkr3Iqe0Fck3xkfAOF_s-JHfuKEpJnS0qPE5yKPo5F16YC_ftuSCb7x8nF8BhySAXFfe3sSgfNehUDw46lb4zOl-EziAq1TvZqZVotageYdmDvAMqsw5Fg3795MBfG3LGf_-dij51OLVE0KvqMRNqN_3juXCj1dS5UGt1kqFe3Dkb-s8Gebh2arkg19RjJhwv7oA0UHFoskA9ODmgrDhnQP8ZoE-OTy0H9Kr6bNh7EHhAHtTR2L4Z6Ef33UDbcs6GPrNBnviTQigWNoFbxJGyDrwB8tIEyEsTqSd72M707gK2Vx9PLQfbDUPcepgd5ljLQfMoYxBYnsUk3x47mVSP3cmlm49ONlmfu81SwB20QEyUm6rgNlqcYuVdYJm-HmllKE9lkHzMeZOdOHTQ_-9R2F2gqWvRO2t_YH5OaDbvPoE15frKwP3PY2v7EbUktA28fLt5bdoUH1a7naprLipUZUM5rdVZlJUoPTwOlidIgwS56tjclnwW3pzz770daIt4pljUzLhlpzBD5U6XTOEdgO0T3vzXcdl3AThJNW-My1XFm_ItNG4pwVrh3-T_N7B4ARR6Uturnz5_-mz6zrM-NhS1XMbbGPQl1Kj1HeOA1595WhAeHAxSsBelri0GVsHBYBUFVQYS7DAjIakK0JbhuijIFwaEN0COZzNERdQBLOaEYr5YMjCFDOVAzNTUbYsiptptPANkBvgCAbViDUQzZ1q_AXly2nHdJ6VrvVEKSAYbIcvRbbKdXfgwNsxSZUWOwPMi5jYFmezp0pXYztMmpfsQKDuQXgX-KduEXiVS0Sv0u2bVV_QqcqranqNFBncGr3z2AfIW0XGowHZwnSF-hvgzIb57k6VIVU_zszbnGsD6kM56Y7VIDnL30KZyUMEs7j7z8LdxPV1G7IjpOj5HCNDROEKAAvExK5BnFC-ZLtugqW7WEv9T22AFbMXAKNSihjvUfWDp5DhD5keAjKgn6kNaBK6n8iUk4_Xb_tVVMzAe29_hetS931zvFPxackRnMENbDduR8dg3MUS2NucQW1uDGQ2jJaJLiPMoiVQyTCLRKi_RJErEvzmawargk2ioSeZn8JKjTh9BqOi6nlOINUE6iSRJuPObUAErTu43ZRYlM1gwNIyqlbAD1YK2oyiX5r-vv7iXf779Dep6-4c?type=png)](https://mermaid.live/edit#pako:eNrtWm1v2zYQ_iucghrKaqPfhcBA0gDDUBTrkqFf6kKgJdomIoseSbnx0va3jy-SzTdZTqwNq-d8SCLe8e5499zxROopykiOoiTKCsjYLYZzCpdgUgLx8-oVuEMF5JiUbIFXTI--XSDG0g8YZQiMRqR-viGQ5j4DGY3Ae7JG6UdY4FyJSu85hRzNNz731VfB_gF-KVtI73A5n7QR_6CwZDNCl6lBarivKYWb1DBVmP51bNuuOYNitIbfK4S6uW4wW5BVJ9sdIQ-dTO9KPF_wwJLTj5hhTqhi-wUuUfrbGtFmVLPr323e1wq0XyTPEpW8PTRbfTLi7QHV85Q_05sKFzmiph6LYAbGniFBE4ihgONbCVJwi2a4xAqWO6TeoAVcY0JhAd4AYVGV8Uo-qCmI7URIwUAJZj_V0xX2LUQ9aYL8uQCM05SiFUVM-EgtOb5M5KiC445v2biR1Q5JE7B1bWsC6LmPgpfhv1DKzdFNcDQjBaGCMiWkMMdhpsQnYvkwe9hRXptLi4VxjfFD3-T9Fg-GWrnWPQSPjXlDsGn-vWxTvJK_E8vNA4v5u8ltUdAjyiqO4qnESWKm7aDFiASsCc5NGVWZkzgwPkc8fVQBdRytSZt2knKFJNuB0EQdDEn1olFgxtO19G4q_c9CVsEsQyser5NQFlr835r80CgOV5OnPnGKSw-kztDzERo0u0esXv6byhQmhUsUIMXfA5TXyRGOnpMmYQnnhDkwYTS_DrRbyJ1kkr3Iqe0Fck3xkfAOF_s-JHfuKEpJnS0qPE5yKPo5F16YC_ftuSCb7x8nF8BhySAXFfe3sSgfNehUDw46lb4zOl-EziAq1TvZqZVotageYdmDvAMqsw5Fg3795MBfG3LGf_-dij51OLVE0KvqMRNqN_3juXCj1dS5UGt1kqFe3Dkb-s8Gebh2arkg19RjJhwv7oA0UHFoskA9ODmgrDhnQP8ZoE-OTy0H9Kr6bNh7EHhAHtTR2L4Z6Ef33UDbcs6GPrNBnviTQigWNoFbxJGyDrwB8tIEyEsTqSd72M707gK2Vx9PLQfbDUPcepgd5ljLQfMoYxBYnsUk3x47mVSP3cmlm49ONlmfu81SwB20QEyUm6rgNlqcYuVdYJm-HmllKE9lkHzMeZOdOHTQ_-9R2F2gqWvRO2t_YH5OaDbvPoE15frKwP3PY2v7EbUktA28fLt5bdoUH1a7naprLipUZUM5rdVZlJUoPTwOlidIgwS56tjclnwW3pzz770daIt4pljUzLhlpzBD5U6XTOEdgO0T3vzXcdl3AThJNW-My1XFm_ItNG4pwVrh3-T_N7B4ARR6Uturnz5_-mz6zrM-NhS1XMbbGPQl1Kj1HeOA1595WhAeHAxSsBelri0GVsHBYBUFVQYS7DAjIakK0JbhuijIFwaEN0COZzNERdQBLOaEYr5YMjCFDOVAzNTUbYsiptptPANkBvgCAbViDUQzZ1q_AXly2nHdJ6VrvVEKSAYbIcvRbbKdXfgwNsxSZUWOwPMi5jYFmezp0pXYztMmpfsQKDuQXgX-KduEXiVS0Sv0u2bVV_QqcqranqNFBncGr3z2AfIW0XGowHZwnSF-hvgzIb57k6VIVU_zszbnGsD6kM56Y7VIDnL30KZyUMEs7j7z8LdxPV1G7IjpOj5HCNDROEKAAvExK5BnFC-ZLtugqW7WEv9T22AFbMXAKNSihjvUfWDp5DhD5keAjKgn6kNaBK6n8iUk4_Xb_tVVMzAe29_hetS931zvFPxackRnMENbDduR8dg3MUS2NucQW1uDGQ2jJaJLiPMoiVQyTCLRKi_RJErEvzmawargk2ioSeZn8JKjTh9BqOi6nlOINUE6iSRJuPObUAErTu43ZRYlM1gwNIyqlbAD1YK2oyiX5r-vv7iXf779Dep6-4c)
