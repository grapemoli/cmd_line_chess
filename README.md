# Chess

## Goals
1. Use design patterns
2. Dynamic / Linear Programming if possible
3. NAMESPACES ??
4. Implement undo/redo features 
5. Implement Castling !!
6. With the UI, reflect the board's printing such that the player who is playing is on the bottom.

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
[![](https://mermaid.ink/img/pako:eNrtWm1v2zYQ_iucghrKaqPfhcBA0gDDUBTrkqFf6kKgJdomIoseSbnx0va3jy-SzTdZTqwNq-d8SCLe8e5499zxROopykiOoiTKCsjYLYZzCpdgUgLx8-oVuEMF5JiUbIFXTI--XSDG0g8YZQiMRqR-viGQ5j4DGY3Ae7JG6UdY4FyJSu85hRzNNz731VfB_gF-KVtI73A5n7QR_6CwZDNCl6lBarivKYWb1DBVmP51bNuuOYNitIbfK4S6uW4wW5BVJ9sdIQ-dTO9KPF_wwJLTj5hhTqhi-wUuUfrbGtFmVLPr323e1wq0XyTPEpW8PTRbfTLi7QFtLFUeTW8qXOSImposghkae4aETSCKApBvJUzBLZrhEitg7rB6gxZwjQmFBXgDhE1Vxiv5oKYgthMhBQMlmP1UT1fotzD1pAny5wIwTlOKVhQx4SW16PgykaMKkDu-ZeNIVrskTcDWua0poOc-Cl6G_0IpN0c3wdGMFIQKypSQwhyHmRKfiOXD7GFHeW0uLRbGNcYPfZP3WzwYauVa9xA8NuYNwab597JN8Ur-Tiw3Dyzm7ya3RUGPKKs4iqcSJ4mZuIMWIxKwJjg3ZVRlTuLA-Bzx9FEF1HG0Jm3aScoVkmwHQhN1MCTVi0aBGU_X0rup9D8LWQWzDK14vE5CeWjxf2vyQ6M4XE-e-sQpLj2QOkPPR2jQ7B6xevlvKlOYFC5RgBR_D1BeJ0c4ek6ahCWcE-bAhNH8OtBuIXeSSXYjp7YXyDXFR8I7XOz7kNy5oygldbao8DjJoejnXHhhLty354Jsv3-cXACHJYNcVNzfxqJ81KBTPTjoVPrO6HwROoOoVG9lp1ai1aJ6hGUP8g6ozDoUDfr1kwN_bcgZ__13Kvrc4dQSQa-qx0yo3fSP58KNVlPnQq3VSYZ6ceds6D8b5PHaqeWCXFOPmXC8uAPSQMWhyQL14OSAsuKcAf1ngD47PrUc0Kvqs2HvQeABeVBHY_tmoB_ddwNtyzkb-swGeeJPCqFY2ARuEUfKOvAGyGsTIK9NpJ7sYTvTuwvYXn48tRxsNwxx62F2mGMtB82jjEFgeRaTfHvsZFI9dieXbj462WR97jZLAXfQAjFRbqqC22hxipV3hWX6eqSVoTyVQfIx50124tBB_79HYXeBpi5G76z9gfk5odm8-wTWlOsrA_c_j63tR9SS0Dbw8u3mtWlTfFjtdqquuahQlQ3ltFZnUVai9PA4WJ4gDRLkqmNzW_JZeHPOv_d2oC3imWJRM-OWncIMlTtdMoV3ALZPePNfx2XfBeAk1bwxLlcVb8q30LilBGuFf5f_38DiBVDoSW2vfvr86bPpO8_62FDUch1vY9CXUKPWd4wDXn_maUF4cDBIwV6UurYYWAUHg1UUVBlIsMOMhKQqQFuG66IgXxgQ3gA5ns0QFVEHsJgTivliycAUMpQDMVNTty2KmGq38QyQGeALBNSKNRDNnGn9CuTJacd1n5Su9UYpIBlshCxHt8l2duHD2DBLlRU5As-LmNsUZLKnS1diO0-blO5DoOxAehX4p2wTepVIRa_Q75pVX9GryKlqe44WGdwZvPLZB8hbRMehAtvBdYb4GeLPhPjuTZYiVT3Nz9qcawDrQzrrjdUiOcjdQ5vKQQWzuPvMw9_G9XQZsSOm6_gcIUBH4wgBCsTHrECeUbxkumyDprpZS_yPbYMVsBUDo1CLGu5Q94Glk-MMmR8BMqKeqA9pEbieypeQjNdv-1dXzcB4bH-H61H3fnW9U_BryRGdwQxtNWxHxmPfxBDZ2pxDbG0NZjSMloguIc6jJFLJMIlEq7xEkygR_-ZoBquCT6KhJpkfwkuOOn0EoaLrek4h1gTpJJIk4c5vQgWsOLnflFmUzGDB0DCqVsIOVAvajqJcmv--_uZe_vn2Ny1c_FE?type=png)](https://mermaid.live/edit#pako:eNrtWm1v2zYQ_iucghrKaqPfhcBA0gDDUBTrkqFf6kKgJdomIoseSbnx0va3jy-SzTdZTqwNq-d8SCLe8e5499zxROopykiOoiTKCsjYLYZzCpdgUgLx8-oVuEMF5JiUbIFXTI--XSDG0g8YZQiMRqR-viGQ5j4DGY3Ae7JG6UdY4FyJSu85hRzNNz731VfB_gF-KVtI73A5n7QR_6CwZDNCl6lBarivKYWb1DBVmP51bNuuOYNitIbfK4S6uW4wW5BVJ9sdIQ-dTO9KPF_wwJLTj5hhTqhi-wUuUfrbGtFmVLPr323e1wq0XyTPEpW8PTRbfTLi7QFtLFUeTW8qXOSImposghkae4aETSCKApBvJUzBLZrhEitg7rB6gxZwjQmFBXgDhE1Vxiv5oKYgthMhBQMlmP1UT1fotzD1pAny5wIwTlOKVhQx4SW16PgykaMKkDu-ZeNIVrskTcDWua0poOc-Cl6G_0IpN0c3wdGMFIQKypSQwhyHmRKfiOXD7GFHeW0uLRbGNcYPfZP3WzwYauVa9xA8NuYNwab597JN8Ur-Tiw3Dyzm7ya3RUGPKKs4iqcSJ4mZuIMWIxKwJjg3ZVRlTuLA-Bzx9FEF1HG0Jm3aScoVkmwHQhN1MCTVi0aBGU_X0rup9D8LWQWzDK14vE5CeWjxf2vyQ6M4XE-e-sQpLj2QOkPPR2jQ7B6xevlvKlOYFC5RgBR_D1BeJ0c4ek6ahCWcE-bAhNH8OtBuIXeSSXYjp7YXyDXFR8I7XOz7kNy5oygldbao8DjJoejnXHhhLty354Jsv3-cXACHJYNcVNzfxqJ81KBTPTjoVPrO6HwROoOoVG9lp1ai1aJ6hGUP8g6ozDoUDfr1kwN_bcgZ__13Kvrc4dQSQa-qx0yo3fSP58KNVlPnQq3VSYZ6ceds6D8b5PHaqeWCXFOPmXC8uAPSQMWhyQL14OSAsuKcAf1ngD47PrUc0Kvqs2HvQeABeVBHY_tmoB_ddwNtyzkb-swGeeJPCqFY2ARuEUfKOvAGyGsTIK9NpJ7sYTvTuwvYXn48tRxsNwxx62F2mGMtB82jjEFgeRaTfHvsZFI9dieXbj462WR97jZLAXfQAjFRbqqC22hxipV3hWX6eqSVoTyVQfIx50124tBB_79HYXeBpi5G76z9gfk5odm8-wTWlOsrA_c_j63tR9SS0Dbw8u3mtWlTfFjtdqquuahQlQ3ltFZnUVai9PA4WJ4gDRLkqmNzW_JZeHPOv_d2oC3imWJRM-OWncIMlTtdMoV3ALZPePNfx2XfBeAk1bwxLlcVb8q30LilBGuFf5f_38DiBVDoSW2vfvr86bPpO8_62FDUch1vY9CXUKPWd4wDXn_maUF4cDBIwV6UurYYWAUHg1UUVBlIsMOMhKQqQFuG66IgXxgQ3gA5ns0QFVEHsJgTivliycAUMpQDMVNTty2KmGq38QyQGeALBNSKNRDNnGn9CuTJacd1n5Su9UYpIBlshCxHt8l2duHD2DBLlRU5As-LmNsUZLKnS1diO0-blO5DoOxAehX4p2wTepVIRa_Q75pVX9GryKlqe44WGdwZvPLZB8hbRMehAtvBdYb4GeLPhPjuTZYiVT3Nz9qcawDrQzrrjdUiOcjdQ5vKQQWzuPvMw9_G9XQZsSOm6_gcIUBH4wgBCsTHrECeUbxkumyDprpZS_yPbYMVsBUDo1CLGu5Q94Glk-MMmR8BMqKeqA9pEbieypeQjNdv-1dXzcB4bH-H61H3fnW9U_BryRGdwQxtNWxHxmPfxBDZ2pxDbG0NZjSMloguIc6jJFLJMIlEq7xEkygR_-ZoBquCT6KhJpkfwkuOOn0EoaLrek4h1gTpJJIk4c5vQgWsOLnflFmUzGDB0DCqVsIOVAvajqJcmv--_uZe_vn2Ny1c_FE)
