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
[![](https://mermaid.ink/img/pako:eNrtW1tv2zYU_iucihpOZqPvQhAgabChKIp16dA91IVAS7RNRBZdknbitelvHy-SRYqkFTsqVmPyQy48V_J8PCQP6a9RSjIUxVGaQ8ZuMJxTuASTAojPy5fgFuWQY1KwBV4x3fp6gRhL3mOUIjAek_L_awJp5jKQ8Ri8IxuUfIQ5zpSq5AOnkKP51uW--CbY38P7IkB6i4v5JET8i8KCzQhdJgap4r6iFG4Tw1Xh-rdL23fN6VWjLfy5Rqid6xqzBVm1st0SctfK9LbA8wX3dDn5Daac0G1pMofpXeIht8j9vcAc-eVcyY-YYUFTkr_DJUr-2CBatWp2_TMUb21TR8ILBy2uopFcr3GeIWrKWAQzrLaEhJwHAQLMryXEwQ2a4QIrUNc4v0YLuMGEwhy8AsKjdcrX8h8lglitQioGSjH7pRRXM8fC41dNkJ8XYCmGY4kKnrCyo0mshki1BaeFln0QvAz_gxJutm69rSnJCRWUKSG52S4iKtXHolsCJTXlV9PloePlficHI21PmxuBh8qjEdhWf56Ztr6bxiwKekDpmqPhVEYxNqfkIKA3BhuCM1PHusjI0NM-Rzx5kITmcGnSNkxSvZNkezg1UQ-ppDpjmmPGk40csEQOKfN5BdMUrfhwE_vml8X_WKFXY8yfKTpFGy4cqDWaDseZ1-3nIe7sB-tXyBMdV7ATv20s-w32qD4O1XLBP5WUKX19LrL8CbILze1ZWFnpgXocUOX2878HKngaUqWzHebY70pfj5zjkKNODqeS45SzHUKnA31PSW3aTI_Q4xCqT62nAlHtbYcYLbv_41Faet7D9DiYyqrJqYBU-tohRJ-v7in4VFZ6dB65QVTlulPBp_a2Q4R2ofApGC3t9Cg9FKWygElyoVzYBTeII-UBeAVkPRfIeq7Uld6pMru3tLmrAn8NFBIrhmGw-ufn2MjG4UoyxOosPPB02WKSB5JWJrUpbOXSi3Irm8yN7W4pcA4CMKKIrXNuI6KRRJzaujnWY20MZYkMkosrR7gRhxb6_z0K9X2AuiO6RSvBKvKWvgNz54Rmc_I9q9LthYH780uTTeYLXxo_dLlI3HmonPLOPw9lRXHBfemFcUi9hLmEkPDIm9ek-0NzfXDleVU8rWLlraaGQpcqFiU5DKR1c8yb4pKpma4b88-9KvxJ4vsCqMUtsXr46fOnz2YnHe_tcLtka8HcqRzY8GnRejiIfjKcDPYgQd8uvuFIBKSZjO2AGHfgznysFXi2KNZgwmwDixT5Rg2zJCMFCmwohiIIMXjYXVnE9jVozUtWpSvnYGhzgYGXb3zpMJ67WwsJY1BDWM4Qde27Y7jKc3LPgAghyPBshqjAPID5nFDMF0sGppChDAhJTd3tQoQotTMxIDPAFwioKOsomIEL3kBbu5YQVyN1Po1NhCaVW6sMAS_eRsANO7BnWSq3XslKrLpJlSUOUeViQiuUG4VOFX6Rq3mnGqlY0rvts1r-O1U5VbuTZ6v0pphWqAbZhr483YO1B2t3YK2PjhQpUDWfxbiHxOqRkYXhVIojBZnan7PYeO9l8VFViIqNd1IuObCwB0SmZek1tp5o-VgCeoNid2VBIt492AqxBDQHxb7oS43YfHvmYQioDQndqbu8uHxP50lLwYdhfUhPNaTBN4J9SE8mpPXxZqoPYZ6TRzPs1ttI6yR7ryb5TKNAHGL2vAY1jqAKRrVQy9PT8nbNdKKxZdlDm8pGDcX2CrF7WtLiCoLHi5eIOF5BCdbjFWjsPKMHEkbHiB-EM99L3D1H5T21i31gaeXoIXMKkBGbSfUKG4GrqayDpbzcSl5cVA2Xl271wqLufe5fG3hTcERFukI7C7sW28RuOayesfs4jc6EFVlP4m22UC0hGkVLRJcQZ1EcqWkzifhC7N0nUSz-zNAMrnM-iUaaZH5XQ3KUE00Q1nRTyuSi95BOIkkSA_8oTMA1Jx-2RRrFM5gzNIrWK-EHKhXtWlEm3X9Xfi1E_nr8F199yZA?type=png)](https://mermaid.live/edit#pako:eNrtW1tv2zYU_iucihpOZqPvQhAgabChKIp16dA91IVAS7RNRBZdknbitelvHy-SRYqkFTsqVmPyQy48V_J8PCQP6a9RSjIUxVGaQ8ZuMJxTuASTAojPy5fgFuWQY1KwBV4x3fp6gRhL3mOUIjAek_L_awJp5jKQ8Ri8IxuUfIQ5zpSq5AOnkKP51uW--CbY38P7IkB6i4v5JET8i8KCzQhdJgap4r6iFG4Tw1Xh-rdL23fN6VWjLfy5Rqid6xqzBVm1st0SctfK9LbA8wX3dDn5Daac0G1pMofpXeIht8j9vcAc-eVcyY-YYUFTkr_DJUr-2CBatWp2_TMUb21TR8ILBy2uopFcr3GeIWrKWAQzrLaEhJwHAQLMryXEwQ2a4QIrUNc4v0YLuMGEwhy8AsKjdcrX8h8lglitQioGSjH7pRRXM8fC41dNkJ8XYCmGY4kKnrCyo0mshki1BaeFln0QvAz_gxJutm69rSnJCRWUKSG52S4iKtXHolsCJTXlV9PloePlficHI21PmxuBh8qjEdhWf56Ztr6bxiwKekDpmqPhVEYxNqfkIKA3BhuCM1PHusjI0NM-Rzx5kITmcGnSNkxSvZNkezg1UQ-ppDpjmmPGk40csEQOKfN5BdMUrfhwE_vml8X_WKFXY8yfKTpFGy4cqDWaDseZ1-3nIe7sB-tXyBMdV7ATv20s-w32qD4O1XLBP5WUKX19LrL8CbILze1ZWFnpgXocUOX2878HKngaUqWzHebY70pfj5zjkKNODqeS45SzHUKnA31PSW3aTI_Q4xCqT62nAlHtbYcYLbv_41Faet7D9DiYyqrJqYBU-tohRJ-v7in4VFZ6dB65QVTlulPBp_a2Q4R2ofApGC3t9Cg9FKWygElyoVzYBTeII-UBeAVkPRfIeq7Uld6pMru3tLmrAn8NFBIrhmGw-ufn2MjG4UoyxOosPPB02WKSB5JWJrUpbOXSi3Irm8yN7W4pcA4CMKKIrXNuI6KRRJzaujnWY20MZYkMkosrR7gRhxb6_z0K9X2AuiO6RSvBKvKWvgNz54Rmc_I9q9LthYH780uTTeYLXxo_dLlI3HmonPLOPw9lRXHBfemFcUi9hLmEkPDIm9ek-0NzfXDleVU8rWLlraaGQpcqFiU5DKR1c8yb4pKpma4b88-9KvxJ4vsCqMUtsXr46fOnz2YnHe_tcLtka8HcqRzY8GnRejiIfjKcDPYgQd8uvuFIBKSZjO2AGHfgznysFXi2KNZgwmwDixT5Rg2zJCMFCmwohiIIMXjYXVnE9jVozUtWpSvnYGhzgYGXb3zpMJ67WwsJY1BDWM4Qde27Y7jKc3LPgAghyPBshqjAPID5nFDMF0sGppChDAhJTd3tQoQotTMxIDPAFwioKOsomIEL3kBbu5YQVyN1Po1NhCaVW6sMAS_eRsANO7BnWSq3XslKrLpJlSUOUeViQiuUG4VOFX6Rq3mnGqlY0rvts1r-O1U5VbuTZ6v0pphWqAbZhr483YO1B2t3YK2PjhQpUDWfxbiHxOqRkYXhVIojBZnan7PYeO9l8VFViIqNd1IuObCwB0SmZek1tp5o-VgCeoNid2VBIt492AqxBDQHxb7oS43YfHvmYQioDQndqbu8uHxP50lLwYdhfUhPNaTBN4J9SE8mpPXxZqoPYZ6TRzPs1ttI6yR7ryb5TKNAHGL2vAY1jqAKRrVQy9PT8nbNdKKxZdlDm8pGDcX2CrF7WtLiCoLHi5eIOF5BCdbjFWjsPKMHEkbHiB-EM99L3D1H5T21i31gaeXoIXMKkBGbSfUKG4GrqayDpbzcSl5cVA2Xl271wqLufe5fG3hTcERFukI7C7sW28RuOayesfs4jc6EFVlP4m22UC0hGkVLRJcQZ1EcqWkzifhC7N0nUSz-zNAMrnM-iUaaZH5XQ3KUE00Q1nRTyuSi95BOIkkSA_8oTMA1Jx-2RRrFM5gzNIrWK-EHKhXtWlEm3X9Xfi1E_nr8F199yZA)
