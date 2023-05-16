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
[![](https://mermaid.ink/img/pako:eNrtW1tv2zYU_iucihpOaqPvQhAgabChKIp17dA91IVAS7RNRBZdinbipelvLy-6kCJp2Y6C1ZjykDg8Fx7yfDw8PKQfgpgkKAiDOIV5foPhnMIlmGSA_7x8CT6iFDJMsnyBV7lqfbNAeR59wChGYDwmxf_XBNLEZiDjMXhPNij6DFOcSFXRJ0YhQ_OtzX3xnbN_gHeZh_QOZ_OJj_g3hVk-I3QZaaSS-4pSuI00U7np3y9N2xWnU43q4a81Qu1c1zhfkFUr20dCbluZ3mV4vmCOIUe_w5gRui26TGF8GznILXL_LDBDbjlb8jPOMadJyT_gEkV_bhAtWxW7-u3zt-pTeWIfOFQ9CpT5QVTaKr0YXa9xmiCq92UQdDiYEgKqDuTwRfBGLA1wg2Y4w3Ix1OvjGi3gBhMKU_AacJvWMVuLf6QIymsVQjGQivPfCnG54gwcPyiC-HkBlnzES5SxKC-GGoVyFmSbd_6U7D3nzfG_KGJ669bZGpOUUE6ZEpLq7RwJQn3Ih8XRVVNe6SYPLSt3GzkYqf5UdyNwX1o0Atvy45ne1w-9M4OC7lG8Zmg4FV4M9aU88OgNwYbgRNexzhIydLTPEYvuBaE5XYq09ZPk6ATZnE5FVFMqqNacpjhn0UZMWCSmNHdZBeMYrdhwE7pWicH_WKJXYcwdYTpFG84sqDWaDseZ0-ynIe7smfVL5PGBS9jxvyaW3R32qD4O1SJROJWQKWx9KrLcAbILze1RWPbSA_U4oIq09b8HKtgPqcLYDmPsD6mvR85xyJEnjlOJcdLYDqHTgb59QpvqpkfocQhVp91TgaiytkOMFsN_fpQWlvcwPQ6motpyKiAVtnYI0aer2wefspcenUcmiLLMdyr4VNZ2iNAuFO6D0aKfHqWHolQUMEnKlfN-wQ1iSFoAXgNRBwaiDix0xbeyPO8sbVa13AdPIbFkGHqrf26OjWgcrgRDKM_CA8eQDSZxIGllkklhK5falFvZRGxsN0uCc-CBEUX5OmUmIhpBxKrJ63M9Vp2hJBJOsnFlCTf80EL_v3uhvg-Qd0sf0Yqz8ril7s7sNaHYrHifl-H2QsP9-aXOJuKFK4wful1E9jqURjnXn4OyojhjrvCSM0idhLmAELfIGdeE-UN9f7DlWVk8LX3lrKb6XBdLFik59IR1fc6b4oKpGa4b68--YvxF_PsCyM0tMkb45euXr_ogLetNd9tkY8OsVA5M-LRoPRxEvxhOBjuQoG4X3zLEHdIMxqZDtLtzaz3WChwpijGZMNnALEauWcN5lJAMeRKKIXdCCO6rK4vQvAatecmqMOUcDE0uMHDyjS8txnM7tRAwBjWExQqR18UVw1WakrsccBeCBM9miHLMA5jOCcVssczBFOYoAVxSUasshItSMxIDMgNsgYD0svKC7jjvzfVDI2NWqVC0UXshd6SRytgp-Suv6ka83Y-N-1MakSDgBOkI2FgB5tKMRb4WrfhWHZWh5RBVNpCUQpFddKrwm0gBOtVIeR7Q7ZhlztCpyqlMaZ6s0hmXngffXt1D147QI7xHeHcIrw-pFElQNR_g2MfR8hmUcRyNhTiSkKntOQu1F2kGH5Ulr1B7yWWTPSmER2RaFHlD4xGZi8Wj1yt2W5Q-wupJmY_Fo9kr9k1dn4T66zgHg0etT-hW3hqGxYs_RyzzPl3rXXqqLvW-YuxdejIurQ9SU3Xcc5xxmm43XmEamcidXOQzhQKehex4r6oddiWMaqGWx7HFPZ5uRCNl2UGbikYFxfZatH0uU-ISgseLF4g4XkEB1uMVKOw8YQQCRseIH4Qz15vfHYfyHVWSXWBp5eghcwqQ4cmkfO-NwNVUVNxiVqSSFxdlw-WlXScxqDu_kFB38DZjiPJwhaoeqhazi2o7LB_auzi1wfgVGY_2TTZfASIYBUtElxAnQRjIZTMJ2ILn7pMg5B8TNIPrlE2CkSLp3yYRHMVC44Q13RQyKR89pJNAkPjEP_Iu4JqRT9ssDsIZTHM0CtYrbgcqFFWtKBHmvy--uCL-PP4ESeoCFQ?type=png)](https://mermaid.live/edit#pako:eNrtW1tv2zYU_iucihpOaqPvQhAgabChKIp17dA91IVAS7RNRBZdinbipelvLy-6kCJp2Y6C1ZjykDg8Fx7yfDw8PKQfgpgkKAiDOIV5foPhnMIlmGSA_7x8CT6iFDJMsnyBV7lqfbNAeR59wChGYDwmxf_XBNLEZiDjMXhPNij6DFOcSFXRJ0YhQ_OtzX3xnbN_gHeZh_QOZ_OJj_g3hVk-I3QZaaSS-4pSuI00U7np3y9N2xWnU43q4a81Qu1c1zhfkFUr20dCbluZ3mV4vmCOIUe_w5gRui26TGF8GznILXL_LDBDbjlb8jPOMadJyT_gEkV_bhAtWxW7-u3zt-pTeWIfOFQ9CpT5QVTaKr0YXa9xmiCq92UQdDiYEgKqDuTwRfBGLA1wg2Y4w3Ix1OvjGi3gBhMKU_AacJvWMVuLf6QIymsVQjGQivPfCnG54gwcPyiC-HkBlnzES5SxKC-GGoVyFmSbd_6U7D3nzfG_KGJ669bZGpOUUE6ZEpLq7RwJQn3Ih8XRVVNe6SYPLSt3GzkYqf5UdyNwX1o0Atvy45ne1w-9M4OC7lG8Zmg4FV4M9aU88OgNwYbgRNexzhIydLTPEYvuBaE5XYq09ZPk6ATZnE5FVFMqqNacpjhn0UZMWCSmNHdZBeMYrdhwE7pWicH_WKJXYcwdYTpFG84sqDWaDseZ0-ynIe7smfVL5PGBS9jxvyaW3R32qD4O1SJROJWQKWx9KrLcAbILze1RWPbSA_U4oIq09b8HKtgPqcLYDmPsD6mvR85xyJEnjlOJcdLYDqHTgb59QpvqpkfocQhVp91TgaiytkOMFsN_fpQWlvcwPQ6motpyKiAVtnYI0aer2wefspcenUcmiLLMdyr4VNZ2iNAuFO6D0aKfHqWHolQUMEnKlfN-wQ1iSFoAXgNRBwaiDix0xbeyPO8sbVa13AdPIbFkGHqrf26OjWgcrgRDKM_CA8eQDSZxIGllkklhK5falFvZRGxsN0uCc-CBEUX5OmUmIhpBxKrJ63M9Vp2hJBJOsnFlCTf80EL_v3uhvg-Qd0sf0Yqz8ril7s7sNaHYrHifl-H2QsP9-aXOJuKFK4wful1E9jqURjnXn4OyojhjrvCSM0idhLmAELfIGdeE-UN9f7DlWVk8LX3lrKb6XBdLFik59IR1fc6b4oKpGa4b68--YvxF_PsCyM0tMkb45euXr_ogLetNd9tkY8OsVA5M-LRoPRxEvxhOBjuQoG4X3zLEHdIMxqZDtLtzaz3WChwpijGZMNnALEauWcN5lJAMeRKKIXdCCO6rK4vQvAatecmqMOUcDE0uMHDyjS8txnM7tRAwBjWExQqR18UVw1WakrsccBeCBM9miHLMA5jOCcVssczBFOYoAVxSUasshItSMxIDMgNsgYD0svKC7jjvzfVDI2NWqVC0UXshd6SRytgp-Suv6ka83Y-N-1MakSDgBOkI2FgB5tKMRb4WrfhWHZWh5RBVNpCUQpFddKrwm0gBOtVIeR7Q7ZhlztCpyqlMaZ6s0hmXngffXt1D147QI7xHeHcIrw-pFElQNR_g2MfR8hmUcRyNhTiSkKntOQu1F2kGH5Ulr1B7yWWTPSmER2RaFHlD4xGZi8Wj1yt2W5Q-wupJmY_Fo9kr9k1dn4T66zgHg0etT-hW3hqGxYs_RyzzPl3rXXqqLvW-YuxdejIurQ9SU3Xcc5xxmm43XmEamcidXOQzhQKehex4r6oddiWMaqGWx7HFPZ5uRCNl2UGbikYFxfZatH0uU-ISgseLF4g4XkEB1uMVKOw8YQQCRseIH4Qz15vfHYfyHVWSXWBp5eghcwqQ4cmkfO-NwNVUVNxiVqSSFxdlw-WlXScxqDu_kFB38DZjiPJwhaoeqhazi2o7LB_auzi1wfgVGY_2TTZfASIYBUtElxAnQRjIZTMJ2ILn7pMg5B8TNIPrlE2CkSLp3yYRHMVC44Q13RQyKR89pJNAkPjEP_Iu4JqRT9ssDsIZTHM0CtYrbgcqFFWtKBHmvy--uCL-PP4ESeoCFQ)
