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
[![](https://mermaid.ink/img/pako:eNrtW21v2zYQ_iucggZKbaPfBcNAXoBhKIp1SdEvdUHQEm0TkUWPpNx4afbbxxfJFkXKcmI121znQ2Lzjsfj3XPH40seg5gmOIiCOEWc3xA0Y2gBxhmQP2_egFucIkFoxudkyU3r9RxzDj8SHGMwGNDi-xVFLHEZ6GAAPtAVhp9RShItCt4JhgSerV3u4XfJ_hF9yxpI70k2GzcRPzGU8SllC1ghldyXjKE1rKgqVf8-snU3nF4xZoQ_cozbua4In9NlK9stpfetTO8zMpsLz5ThZ8KJoEyz_YoWGP6-wqxsNezmd5P1zQDGLopngTPR7JrNeMrjzQ41_bQ94VVO0gSz6jgWoeoYu4cCjceHEo7XCqTgBk9JRjQst0i9wnO0IpShFLwDUqM8Frn6ortgvhWhBAMtmP9SdNfYtxD1aAjq5wxwwSDDS4a5tJGecngRqVYNxy3fojQjLwwCI7AxbWMAmL4PkpeTvzAU1da1tzWmKWWSMqE0rbajWIuP5PRRfL-l9KpTC6VypfJ9V-XdGp_3zeBm7D54KNXrg3X58aJp4KX6HVlmPreY_65yWxT8gONc4HCicBJVw_a8QYkIrChJqjLyLKGhp32GBXzQDq0Z2pDWzSRtCkW2HWGIxhmK6ngjJVzAlbIuVPbnPq1QHOOlCFeRLwod_jMgyiTis5HF_1TGk0G9P_s8dolrkjmgrjU9H9FetTvE9sVrDqYxLE2iASz_7jF4EUx-79XCyi_hZwqwtph4Scz1Ct_X14JafKly5tiWEzWn8EDE-9eLLiS3Lkp6kCKAtHtq8aLpp_DoLjzumsNDlfT_n_AA-8WHmlTY3fKjbVQCVn-pAVaPdwJsV4D1AlVv_o4tketJdYjUDuTtkb-NK8qAMN9qEWEUOYXEq5Q45sTj2GLDzKrD4CjM9MPD48oMU4RHMWotPorJnQLkVQJEnfUdW3ioOXUYHIeL2yMytB_KwNBfamGhtTgFxasEhTnbPrawMLPqsvjvQOAeoVF4Y7PLMF_r-wyjyylAfnCAqGsKmkpdpJrgBgusFQbvgLrpAeqmR40T3296OhcYm_uax4bT-JIhbDyB93OsVGP18MRnDotJbU5bmXS93splqpZWNpXF29XSWD5vQJ3MQHkqbADV8pdz61a19cAMhhOonOTC0Olc80ML_Wf3wvbWT9_l3lpLBndjwrA5lxq8zODDCu7fjqwVSaYX38rw8hWoV9Up3C-d1xJxdVLeDOWJaTOcRVnK1CNCb3pCzEvY3jK5l3lvPfzKSmHs8sqlobLc-bN0rNl137BhHamOXu-umPzrA98lvPzUcll5BgSFhjck2TIXZSaXI24o3rThvkT4b8DyDGggQduqX75--WoVPulyjqBbkvXceYUVFRqeGdhAdSUU0HZNVkO42_PfwLkH5lZV1wXMz_cGMtiJZM8FcolasDegZf5VLgVbXCnY6ny1YbhMU_qNA2lLkJDpFDPpf4miGWVEzBccTBDHCZA9DXUDKtnV3ghwQKdAzDHQMzZgrcZV4zuXx1pBb8oquDLrqgSnt26yDN0ku7Zo78dGONRaJBg8z2N19MSqBIRLufrDMuy7EKgKlk4F_qmqik4lMlladDtnXYZ0KnKiq6SDRXpXDyeRdgHyBtGhL9W2cJ0gfoL4MyG-3fgyrLNn9ele7brBeixobXAtUg25O2gT1ahhFrafmrirv-muPHZAd-OfAwQYbxwgQIP4kBmoI42XdFdl0MSUbZH7nNibARsxMPCVsXYV2_PJ8Ka5E2SOAjLm-Qn8ROE1pSwhmVyyuHft7FnbOmGXwf6Txge51JVCy8q5tdPa02lHl5WpKTEszg3rPZz0nGKUNTE3nTjqV9UYXE7Uvi0WvNgbDodly2hkv8p2qDtf4G9H-C0TmE1RXD7KHg43LaOR60wf2SpjfGxNpXjQDxaYLRBJgijQjh8HclOxwOMgkh8TPEV5KsZB35Cq_xShOAqoSELOVkWfVM4JsXGgSNKeT3IIlAt6t87iIJqilON-kC-V-wpBm1acKPU_FP9_of48_QNDo6rL?type=png)](https://mermaid.live/edit#pako:eNrtW21v2zYQ_iucggZKbaPfBcNAXoBhKIp1SdEvdUHQEm0TkUWPpNx4afbbxxfJFkXKcmI121znQ2Lzjsfj3XPH40seg5gmOIiCOEWc3xA0Y2gBxhmQP2_egFucIkFoxudkyU3r9RxzDj8SHGMwGNDi-xVFLHEZ6GAAPtAVhp9RShItCt4JhgSerV3u4XfJ_hF9yxpI70k2GzcRPzGU8SllC1ghldyXjKE1rKgqVf8-snU3nF4xZoQ_cozbua4In9NlK9stpfetTO8zMpsLz5ThZ8KJoEyz_YoWGP6-wqxsNezmd5P1zQDGLopngTPR7JrNeMrjzQ41_bQ94VVO0gSz6jgWoeoYu4cCjceHEo7XCqTgBk9JRjQst0i9wnO0IpShFLwDUqM8Frn6ortgvhWhBAMtmP9SdNfYtxD1aAjq5wxwwSDDS4a5tJGecngRqVYNxy3fojQjLwwCI7AxbWMAmL4PkpeTvzAU1da1tzWmKWWSMqE0rbajWIuP5PRRfL-l9KpTC6VypfJ9V-XdGp_3zeBm7D54KNXrg3X58aJp4KX6HVlmPreY_65yWxT8gONc4HCicBJVw_a8QYkIrChJqjLyLKGhp32GBXzQDq0Z2pDWzSRtCkW2HWGIxhmK6ngjJVzAlbIuVPbnPq1QHOOlCFeRLwod_jMgyiTis5HF_1TGk0G9P_s8dolrkjmgrjU9H9FetTvE9sVrDqYxLE2iASz_7jF4EUx-79XCyi_hZwqwtph4Scz1Ct_X14JafKly5tiWEzWn8EDE-9eLLiS3Lkp6kCKAtHtq8aLpp_DoLjzumsNDlfT_n_AA-8WHmlTY3fKjbVQCVn-pAVaPdwJsV4D1AlVv_o4tketJdYjUDuTtkb-NK8qAMN9qEWEUOYXEq5Q45sTj2GLDzKrD4CjM9MPD48oMU4RHMWotPorJnQLkVQJEnfUdW3ioOXUYHIeL2yMytB_KwNBfamGhtTgFxasEhTnbPrawMLPqsvjvQOAeoVF4Y7PLMF_r-wyjyylAfnCAqGsKmkpdpJrgBgusFQbvgLrpAeqmR40T3296OhcYm_uax4bT-JIhbDyB93OsVGP18MRnDotJbU5bmXS93splqpZWNpXF29XSWD5vQJ3MQHkqbADV8pdz61a19cAMhhOonOTC0Olc80ML_Wf3wvbWT9_l3lpLBndjwrA5lxq8zODDCu7fjqwVSaYX38rw8hWoV9Up3C-d1xJxdVLeDOWJaTOcRVnK1CNCb3pCzEvY3jK5l3lvPfzKSmHs8sqlobLc-bN0rNl137BhHamOXu-umPzrA98lvPzUcll5BgSFhjck2TIXZSaXI24o3rThvkT4b8DyDGggQduqX75--WoVPulyjqBbkvXceYUVFRqeGdhAdSUU0HZNVkO42_PfwLkH5lZV1wXMz_cGMtiJZM8FcolasDegZf5VLgVbXCnY6ny1YbhMU_qNA2lLkJDpFDPpf4miGWVEzBccTBDHCZA9DXUDKtnV3ghwQKdAzDHQMzZgrcZV4zuXx1pBb8oquDLrqgSnt26yDN0ku7Zo78dGONRaJBg8z2N19MSqBIRLufrDMuy7EKgKlk4F_qmqik4lMlladDtnXYZ0KnKiq6SDRXpXDyeRdgHyBtGhL9W2cJ0gfoL4MyG-3fgyrLNn9ele7brBeixobXAtUg25O2gT1ahhFrafmrirv-muPHZAd-OfAwQYbxwgQIP4kBmoI42XdFdl0MSUbZH7nNibARsxMPCVsXYV2_PJ8Ka5E2SOAjLm-Qn8ROE1pSwhmVyyuHft7FnbOmGXwf6Txge51JVCy8q5tdPa02lHl5WpKTEszg3rPZz0nGKUNTE3nTjqV9UYXE7Uvi0WvNgbDodly2hkv8p2qDtf4G9H-C0TmE1RXD7KHg43LaOR60wf2SpjfGxNpXjQDxaYLRBJgijQjh8HclOxwOMgkh8TPEV5KsZB35Cq_xShOAqoSELOVkWfVM4JsXGgSNKeT3IIlAt6t87iIJqilON-kC-V-wpBm1acKPU_FP9_of48_QNDo6rL)
