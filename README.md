# Chess

## Goals
1. Use design patterns
2. Dynamic / Linear Programming if possible
3. NAMESPACES ??
4. Implement undo/redo features 

## Savepoints
1. Create UML [O]
2. Determine representation of the Board / Pieces on the Board [O]
3. Create Chess Pieces  <--
4. Test Chess Pieces & Chess Eating
5. Add pawn-transformation functionality
6. Create Board 
7. Give option to reverse the printing of the board based on which player is playing
8. Optimize the physical representation of the board

## Algorithms
### Collision Detection and Game Over Detection
Collision detection WILL NOT require the latest concretion, BUT GAME OVER DETECTION WILL.

For collision detection: check the color (does not depend on latest concretion), if different then replace. 
For Game Over dectection: get the concretion, if opposing color & king, then return game_over.\
- use double dispatching to get the concretion -- get_result() will return true IF A KING (and you can get the color because all base Chess_Piece will have an is_white attribute)!!!!

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
| -R- | -N- | -B- | -K- | -Q- | -B- | -N- | -R- | <br>

* differentiation of *white* and -black- pieces.


## UML
[![](https://mermaid.ink/img/pako:eNrtWltv2zYU_iuchgZqa6PvQmCgSbChKIZ1ydA91IVAS7RNWBZdinLtpclvHy-SRYpkZA2DAWHyi22eq3g-8lDn8DFISIqCKEgyWBR3GK4o3IJ5Dvjn1StwjzLIMMmLNd4VavR2jYoi_oRRgsB0Sqr_NwTS1Ga4_jGdgk_we-4hfcT5au4j_klhXiwJ3cYaqeZ-Tyk8xppx7syPmemN4nSqURb-KBHq5rrBxZrsOtnuCdl0Mn3M8WrNHI8c_wITRuixMpnBZBM7yB1yf60xQ245W_IzLjCnSclf4RbFv-8RrUcVey0mJzS-KXGWIiVQBcAg6JExJQgXcASRI-xW4A7coSXOsURaA74btIZ7TCjMwDvwwGiZsFL8kSKoaFQIxUAqLn6qxCWcDUg9KoL4_AwOcQQK_DeKmT56dI4mJCOUUxaEZPo4n1juLyc8MB6shvJWNxtKaSU8AYda_wQc65-vdclnXdSgoANKSobChZjXSMf5lUdvBPYEp7oOXMTcnQyn_dSYDy7V7CHXEp7JX-YpCR3urBCLD4LQnnNFOvpJclJDhylBVHERVCswGS6Y8j3ekj0qXF7BJEE7Fu4j11ox-J9qGCuwuVe9BTucW5hrDfUHnNO0Dr3XvbglErhTMqz824SoW3wE66DAKnLyJbdEYc-EmHsDtPm690wpM-JvUPgTB7__Bn_gPAAKg94d8VlSRwgNCkLy8H7JPUwa9GLIop6zdSmhEXiDAp56H7wk8pRFL_Qqh_qCr9I6om9Q6BNlhktiT9jzIk860xd3UuOIumGd12Td6pK4Uxa9yKsc6ou9SuuIvoGgT5T3xLwW3C64QwxJD8A7IAqWQBQsha5kI-vIzsLfqcz56CnR1QyhtxLn5tiLwXAnGCL53up4YoNHvGR08cgDYReTStxdXGKb7XRJLgcPgCgqyoyZWGhtC1bZWJ_lKVgJMkcDteFkSbamv4P-_538pjwuux73aMdZUc5Un8ZeBIrNCItcoPWee60BfWYvESnuXBoOyo7inLlWfsEgdRJOCHFtOcJPIwHY8qwuRtaT6qxOXnkmOZEsUtK34-panEvAbkQZcy2zQWzo-fL1y1edxdKgT6qLbGSYk8orQ-r5Ra3_JlQDioZqPn1giEJrTzIDovUtLdQ3Chw53ZhMmO5hLorgzoNBSnLkyaghD0IEDqdCe2R2yRpesqtceQNCkwtcOfmmM4vxjWsXuaVI7hztvpqdR-tGo5FHEyGO4p0owR60QDU9X4OPyqN_pPVKbbIn9B6RRfUSGxltWheLR69XbFMdFaNT09bH4tHsFfumqj6R3n92MHjU-oQ2soYZVT11x9rwNofHkA41pN57AmNIBxPSJgEuVJp25KZ22I3LFcZL-Xe5yJcKBTzNvXAjpBFaSBg1Qh3XT6qqo-5E64T4Am0hBhUUu9_d7XyqxGmrKNVTfGPVFnoqWFgF2Z4Kvp3ZLfA-QauddbZ4L5y5rvL0O92-delogaWTY4TMECDDD5PyGhcC7xcFfxNIWHWUvL6uB2Yz-3xrUF-88tcY-JDzkznfrtDJwmnENHFKhwD4ObWH8SuqqhDBJNgiuoU4DaJALoV5wNZoi-ZBxH-maAn5a_s8mCiSfqtScFSLhxNKuq9kMv5EkM4DQeKT-cRNwJKRh2OeBNESZgWaBOUu5cmjUnQaRalw6bfqAqf4evoHGazFHw?type=png)](https://mermaid.live/edit#pako:eNrtWltv2zYU_iuchgZqa6PvQmCgSbChKIZ1ydA91IVAS7RNWBZdinLtpclvHy-SRYpkZA2DAWHyi22eq3g-8lDn8DFISIqCKEgyWBR3GK4o3IJ5Dvjn1StwjzLIMMmLNd4VavR2jYoi_oRRgsB0Sqr_NwTS1Ga4_jGdgk_we-4hfcT5au4j_klhXiwJ3cYaqeZ-Tyk8xppx7syPmemN4nSqURb-KBHq5rrBxZrsOtnuCdl0Mn3M8WrNHI8c_wITRuixMpnBZBM7yB1yf60xQ245W_IzLjCnSclf4RbFv-8RrUcVey0mJzS-KXGWIiVQBcAg6JExJQgXcASRI-xW4A7coSXOsURaA74btIZ7TCjMwDvwwGiZsFL8kSKoaFQIxUAqLn6qxCWcDUg9KoL4_AwOcQQK_DeKmT56dI4mJCOUUxaEZPo4n1juLyc8MB6shvJWNxtKaSU8AYda_wQc65-vdclnXdSgoANKSobChZjXSMf5lUdvBPYEp7oOXMTcnQyn_dSYDy7V7CHXEp7JX-YpCR3urBCLD4LQnnNFOvpJclJDhylBVHERVCswGS6Y8j3ekj0qXF7BJEE7Fu4j11ox-J9qGCuwuVe9BTucW5hrDfUHnNO0Dr3XvbglErhTMqz824SoW3wE66DAKnLyJbdEYc-EmHsDtPm690wpM-JvUPgTB7__Bn_gPAAKg94d8VlSRwgNCkLy8H7JPUwa9GLIop6zdSmhEXiDAp56H7wk8pRFL_Qqh_qCr9I6om9Q6BNlhktiT9jzIk860xd3UuOIumGd12Td6pK4Uxa9yKsc6ou9SuuIvoGgT5T3xLwW3C64QwxJD8A7IAqWQBQsha5kI-vIzsLfqcz56CnR1QyhtxLn5tiLwXAnGCL53up4YoNHvGR08cgDYReTStxdXGKb7XRJLgcPgCgqyoyZWGhtC1bZWJ_lKVgJMkcDteFkSbamv4P-_538pjwuux73aMdZUc5Un8ZeBIrNCItcoPWee60BfWYvESnuXBoOyo7inLlWfsEgdRJOCHFtOcJPIwHY8qwuRtaT6qxOXnkmOZEsUtK34-panEvAbkQZcy2zQWzo-fL1y1edxdKgT6qLbGSYk8orQ-r5Ra3_JlQDioZqPn1giEJrTzIDovUtLdQ3Chw53ZhMmO5hLorgzoNBSnLkyaghD0IEDqdCe2R2yRpesqtceQNCkwtcOfmmM4vxjWsXuaVI7hztvpqdR-tGo5FHEyGO4p0owR60QDU9X4OPyqN_pPVKbbIn9B6RRfUSGxltWheLR69XbFMdFaNT09bH4tHsFfumqj6R3n92MHjU-oQ2soYZVT11x9rwNofHkA41pN57AmNIBxPSJgEuVJp25KZ22I3LFcZL-Xe5yJcKBTzNvXAjpBFaSBg1Qh3XT6qqo-5E64T4Am0hBhUUu9_d7XyqxGmrKNVTfGPVFnoqWFgF2Z4Kvp3ZLfA-QauddbZ4L5y5rvL0O92-delogaWTY4TMECDDD5PyGhcC7xcFfxNIWHWUvL6uB2Yz-3xrUF-88tcY-JDzkznfrtDJwmnENHFKhwD4ObWH8SuqqhDBJNgiuoU4DaJALoV5wNZoi-ZBxH-maAn5a_s8mCiSfqtScFSLhxNKuq9kMv5EkM4DQeKT-cRNwJKRh2OeBNESZgWaBOUu5cmjUnQaRalw6bfqAqf4evoHGazFHw)
