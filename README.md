# Chess

## Goals
1. Use design patterns
2. Dynamic / Linear Programming if possible
3. NAMESPACES ??
4. Implement undo/redo features 
5. Castling !!

## Savepoints
1. Create UML [O]
2. Determine representation of the Board / Pieces on the Board [O]
3. Create Chess Pieces  <--
4. Test Chess Pieces & Chess Eating
5. Add pawn-transformation functionality
6. Create Board 
7. Give option to reverse the printing of the board based on which player is playing
8. Optimize the physical representation of the board

## Algorithms & Implementations
### Collision Detection and Game Over Detection
Collision detection WILL NOT require the latest concretion, BUT GAME OVER DETECTION WILL.

For collision detection: check the color (does not depend on latest concretion), if different then replace. 
For Game Over dectection: get the concretion, if opposing color & king, then return game_over.\
- use double dispatching to get the concretion -- get_result() will return true IF A KING (and you can get the color because all base Chess_Piece will have an is_white attribute)!!!!

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
K – king <br>
Q – queen <br>
R – rook <br>
B – bishop <br>
N – knight <br>
P – pawn <br>
| *R* | *N* | *B* | *Q* | *K* | *B* | *N* | *R* | <br>
| *P* | *P* | *P* | *P* | *P* | *P* | *P* | *P* | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
| -P- | -P- | -P- | -P- | -P- | -P- | -P- | -P- | <br>
| -R- | -N- | -B- | -Q- | -K- | -B- | -N- | -R- | <br>

* differentiation of *white* and -black- pieces.


## UML
[![](https://mermaid.ink/img/pako:eNrtW1tv2zYU_iucghrK6qDvQhAgabBhCIp16dA91IVAS7RNRJZcknLipdlvHy-STIqk5TjasHjKQxLxXMnznUOKpB6DpEhREAVJBim9xnBO4BJMcsB_3rwBtyiDDBc5XeAVVa3vF4jS-CNGCQJnZ0X1fFVAktoMxdkZ-FCsUfwZZjiVquJPjECG5hub-_w7Z_8I73MP6Qbn84mP-DuBOZ0VZBlrpJr7khC4iTVXuevfL0zfFadTjbLwW4lQN9cVpoti1cl2WxR3nUw3OZ4vmKPL8U8wYQXZVCYzmNzFDnKH3B8LzJBbzpb8jCnmNCn5M1yi-Nc1InWrYle_ffFWNlUkBM8S5cwPhsaewJgfQrWnMobxVYmzFBHdkkHQwWBKCKA6cMNT4L1IDHCNZjjHMhW22XGFFnCNCwIz8A5wn8qEleJBiiC6VSEUA6mY_lCJy3wzUPyoCOLnBFBGYoJWBFE-SrLT4WkkWmUKbPmW9UDSakjiCDSD6006JfvAeSn-E8VMb904W5MiKwinTIsi09s5XoT6iHefY3BLeat3LeTO1c6PbZd3ezwaK-PK9hg81O6Nwab-99RneCV-R8Ywjwzmv3Rug4IeUFIyFE4FTiK9VIw8TkRgXeBU11HmaRE62ueIxQ8yoK2BVqSNnySHQpDNQCiiCoagWtHIMGXxWoxuLMafuryCSYJWLFxHrjw0-J_q_FAodlewxz5xinMLpK2m5yPU6XaPWD39N41JTPIhkYDkf_cwXiWHO3qtNHFrGBJmz4RR_CrQ7ULeSiax_jm2uUD0KXwhvN3Fvg_NnTOKNFJliwxPKzkkfciFA3Phkz8XxIL_9eQC2C8ZRKfC_iYWOUY1OuVDC53S3oDOg9DpRKV8Dzy2Ei071SMse9C3R2VWoajRr55a8FeODPjvf6WidjqOLRFUr3rMhGqY_vFcuFJmqlyorLaSoerckA39Z4PY0Du2XBB96jETXq5ujzSQcaizQD60ckB6MWRA_xmgdquPLQdUr_pcsPegcI88qKLRvBmox_a7gfJlyIY-s0Hs-BcZN8x9AteIIekdeAfEsQkQxybCTnLXSFpnAc3hx6NnY7tmCL2b2W6OtWjUtzJGju4ZTOLtsZNJrrE7udTio5NN1OdutyRwRx6I8XJTZsxES6tYWUdY-lifKWMojUWQbMxZwq04dND_71HYHqDJo9hbY36gdk4oNus8gdbl-lzD_Y8XxvTDa4lrGjh8unmr-xTuV7tbVVfvlKvKunJamTMoK156WOgsT5A4CaLXoT4t2Sys3uffeTrgi3giWaRk6Jkp9FC1xQWTewagu5TX_3Uc9p0AVsSKN8T5qmR1-eYWG4qzVti3B_4bWDwBEj2xOapfvn75qo-d5X2oGfIcx5sYtDVUqLUHpgVeW_K4IDzaG6RgJ0rbvmhYBXuDlRdUEUiwxYyApCxADcNllhX3FPDRACmezRDhUQcwmxcEs8WSgimkKAVcUlGbJQoXNZfxFBQzwBYIyB4rIOo5470F8thajqt1UrxWEyWHpHMhZAy0T3drFt6PDdNYepEi8LyItRcFiVjTxSs-ncd1SvehUKxAelX4TSwTetVI-Fqh3z7LdUWvKqdy2fNilc6ZwSqffYDcozp0FdgOrgHiA8SfCfHtmyxBsnq2r7XZ76z11ULjnTUR4khCZuvPaaTd8jT4iNybi7TbkTbZMyt7RKbVjndkXMx0sXj0esXuqr2TqLmm6WPxaPaKfVNHVpF-49TB4FHrE7qr9ixufPt33uugQ0hfa0i9N4OHkL6akG7fTabqDSqy79y3w27cbTYWI_cyyWcKBXwhsuMOuPaaKWG0Feq4cF6dR-pOtJYtO2hT0aig2L3hbb_DKXEJwcPFK0QcrqAC6-EKFHZe0AMBo0PEn4Uz1016YxvVsT_h3p7YBZZOjgEyrwEyfDEpv6JA4HIqdqASVi0lz8_rhosL8yMMi7rzI5-tgV9yhggvV6ix0LSYJprpsP54xcWpdcavyPgQxmTz7UME42CJyBLiNIgCmTaTgC342n0SRPzfFM1gmbFJMFYk_QstwVElGieUZF3JZLz3kEwCQeID_8RNwJIVnzZ5EkQzmFE0DsoV9wNVippWlAr3P1Qfg4k_T38DrYAPlw?type=png)](https://mermaid.live/edit#pako:eNrtW1tv2zYU_iucghrK6qDvQhAgabBhCIp16dA91IVAS7RNRJZcknLipdlvHy-STIqk5TjasHjKQxLxXMnznUOKpB6DpEhREAVJBim9xnBO4BJMcsB_3rwBtyiDDBc5XeAVVa3vF4jS-CNGCQJnZ0X1fFVAktoMxdkZ-FCsUfwZZjiVquJPjECG5hub-_w7Z_8I73MP6Qbn84mP-DuBOZ0VZBlrpJr7khC4iTVXuevfL0zfFadTjbLwW4lQN9cVpoti1cl2WxR3nUw3OZ4vmKPL8U8wYQXZVCYzmNzFDnKH3B8LzJBbzpb8jCnmNCn5M1yi-Nc1InWrYle_ffFWNlUkBM8S5cwPhsaewJgfQrWnMobxVYmzFBHdkkHQwWBKCKA6cMNT4L1IDHCNZjjHMhW22XGFFnCNCwIz8A5wn8qEleJBiiC6VSEUA6mY_lCJy3wzUPyoCOLnBFBGYoJWBFE-SrLT4WkkWmUKbPmW9UDSakjiCDSD6006JfvAeSn-E8VMb904W5MiKwinTIsi09s5XoT6iHefY3BLeat3LeTO1c6PbZd3ezwaK-PK9hg81O6Nwab-99RneCV-R8Ywjwzmv3Rug4IeUFIyFE4FTiK9VIw8TkRgXeBU11HmaRE62ueIxQ8yoK2BVqSNnySHQpDNQCiiCoagWtHIMGXxWoxuLMafuryCSYJWLFxHrjw0-J_q_FAodlewxz5xinMLpK2m5yPU6XaPWD39N41JTPIhkYDkf_cwXiWHO3qtNHFrGBJmz4RR_CrQ7ULeSiax_jm2uUD0KXwhvN3Fvg_NnTOKNFJliwxPKzkkfciFA3Phkz8XxIL_9eQC2C8ZRKfC_iYWOUY1OuVDC53S3oDOg9DpRKV8Dzy2Ei071SMse9C3R2VWoajRr55a8FeODPjvf6WidjqOLRFUr3rMhGqY_vFcuFJmqlyorLaSoerckA39Z4PY0Du2XBB96jETXq5ujzSQcaizQD60ckB6MWRA_xmgdquPLQdUr_pcsPegcI88qKLRvBmox_a7gfJlyIY-s0Hs-BcZN8x9AteIIekdeAfEsQkQxybCTnLXSFpnAc3hx6NnY7tmCL2b2W6OtWjUtzJGju4ZTOLtsZNJrrE7udTio5NN1OdutyRwRx6I8XJTZsxES6tYWUdY-lifKWMojUWQbMxZwq04dND_71HYHqDJo9hbY36gdk4oNus8gdbl-lzD_Y8XxvTDa4lrGjh8unmr-xTuV7tbVVfvlKvKunJamTMoK156WOgsT5A4CaLXoT4t2Sys3uffeTrgi3giWaRk6Jkp9FC1xQWTewagu5TX_3Uc9p0AVsSKN8T5qmR1-eYWG4qzVti3B_4bWDwBEj2xOapfvn75qo-d5X2oGfIcx5sYtDVUqLUHpgVeW_K4IDzaG6RgJ0rbvmhYBXuDlRdUEUiwxYyApCxADcNllhX3FPDRACmezRDhUQcwmxcEs8WSgimkKAVcUlGbJQoXNZfxFBQzwBYIyB4rIOo5470F8thajqt1UrxWEyWHpHMhZAy0T3drFt6PDdNYepEi8LyItRcFiVjTxSs-ncd1SvehUKxAelX4TSwTetVI-Fqh3z7LdUWvKqdy2fNilc6ZwSqffYDcozp0FdgOrgHiA8SfCfHtmyxBsnq2r7XZ76z11ULjnTUR4khCZuvPaaTd8jT4iNybi7TbkTbZMyt7RKbVjndkXMx0sXj0esXuqr2TqLmm6WPxaPaKfVNHVpF-49TB4FHrE7qr9ixufPt33uugQ0hfa0i9N4OHkL6akG7fTabqDSqy79y3w27cbTYWI_cyyWcKBXwhsuMOuPaaKWG0Feq4cF6dR-pOtJYtO2hT0aig2L3hbb_DKXEJwcPFK0QcrqAC6-EKFHZe0AMBo0PEn4Uz1016YxvVsT_h3p7YBZZOjgEyrwEyfDEpv6JA4HIqdqASVi0lz8_rhosL8yMMi7rzI5-tgV9yhggvV6ix0LSYJprpsP54xcWpdcavyPgQxmTz7UME42CJyBLiNIgCmTaTgC342n0SRPzfFM1gmbFJMFYk_QstwVElGieUZF3JZLz3kEwCQeID_8RNwJIVnzZ5EkQzmFE0DsoV9wNVippWlAr3P1Qfg4k_T38DrYAPlw)
