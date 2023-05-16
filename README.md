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
Currently, undo() is only supported for when the user inputs a faulty coordinate. However, supporting undo for "undoing" the conglomerate moves that the two players have done is simple: with the "UNDO" option chosen, just pop from the moves_ stack in Chess_Board.

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
[![](https://mermaid.ink/img/pako:eNrtWm1v2zYQ_iuchhpOaqPfhSBA0mBDURTr0qH7UBcCLdE2YVl0SNqJlya_fXyRLFIkI8sLsBlTPrQJ77nTkffwSB75GKUkQ1EcpTlk7AbDOYUrMCmA-HnzBtyiHHJMCrbAa6Zb3y8QY8lnjFIExmNS_n1NIM1cABmPwSeyRclXmONMmUq-cAo5mu9c9MUPAf8M74uA6CMu5pOQ8A8KCzYjdJUYogp9RSncJYarwvUfl7bvGuk1o7_w-wahdtQ1ZguyboXdErJsBX0s8HzBPV1OfoEpJ3RXfjKH6TLxiFv0_lxgjvx6ruZXzLCQKc1f4Qolv20RrVo1XP8birf-po6Elw5aXUUjud7gPEPU1LEEZlhtDUk5DwMEmd9LioMbNMMFVqSueX6NFnCLCYU5eAeER5uUb-QfSgWx2oQ0DJRh9lOprmaOxcdHLZA_P4OVGI4VKnjCyo4msRoi1RacFlr3QWAZ_gsl3GzdeVtTkhMqJFNCcrNdRFSaj0W3BEtqyVvT5aHS1soj8FDZH4Fd9euZqflsqloS9IDSDUfDqYxJbE6wQcBuDLYEZ6aNTZGRoad9jnjyIAXNzmvRLixSvZNie3C0UA-QlDojlGPGk62MUSLDyHxewTRFaz7cxr7ZYuGfKi5qxvjn_atyBxcOcRpN3Vnjddvkz1kntGKFcEpRQvxv88yv3jPuOMbJpfVUkpP01eaJPxW5uPbspXR6Eh1HIrkJ-_dJBA5jkXQ2mJuelbTnwXE8ULvhU8kmytkgERzpIUlEK_XsOY49-pR0KvTR3gb5U3amK4NKqz2FjqOQPEGfCoGkr0H6qI50JY-y2FPnyD2MqqucCnm0t0H6lJ3pSqDSak-hrhSSZSCSC-Piu-AGcaQ8AO-ArIoBWRWTttKlKlZ6C0T7WtpjoBxTAYbBqosfsZWNw7UExOpkNPB02QLJLXArSG11WlF6OWuFycTV7pYi5yBAI4rYJuc2Ixoz3KlQmmM91h9DWSKD5PLKUW7EoUX-f49CXVVVlfZbtBZQkUX1TYI7JzTMio-ar1UuvDB4f35pwmS-8GUNw653Cnkka4oL7ssQjEPqFcwlC4Sf3tQkO2BlbFefV7Wtari9xa7Q6KcKojSHgcxsDltTXYKaGbcxhdw7EytEao1IrK98-_7tuwlxLJhD7hNb687e5MDSen7R6jGB_I_FavBCNPRVxweOxB6kmdPsgBgXcs6cqA14VnprMGG2hUWKfKOGWZKRAgXW5aEIQgwe9lXd2L6TqbFkXbpyDoY2Cgy8uPGlAzx3V2i5cwP1rk0mEnUHtQdc5Tm5Z0CEEGR4NkNUJCgA8zmhmC9WDEwhQxkQmlq6X8yFKrUTGiAzwBcIqCjrKJiBC16HWYt_CNVIX4fBRGhSuUPJEPDybQTcsIOBZSKVO5hkLRavpNoYdzHlckIblOvtqxq8k4viq1qkYmV83T6rVfRVTU7VIv-PTXpTTCtVg7AGVw_E9WTtyXowWesTGEWKVM07evesVb14sDicSnWkKFP7cxYbj08sHFXFlth4tOGKAwt7QGVa1v5i672IDxKwG1Rbluf6eP96JAQJWA6q3emKd2w-hPEAAmZDSkt1CROXj3s8aSn4SqUP6amGNPhgqQ_pyYS0Pt5M9SHMc_Joht16qGVVX-_VJJ9pFohDzAtP02qlqaJRrdTyDq68rDGdaGxZXpBNZaOmYnuh1T0taXXauAboqL50CsEdDUyde6yOBu4OvCkN9qBxH3-weiee-Z4FdqtdvPXZ8O5ve8qcOGXEZlI9CUXgaiqvflJebiUvLqqGy0u3emFJX3x7XH_gQ8ERFekK7b-wb7E_sV8Oqze1PqTRmbAh632uDQvVEqJRtEJ0BXEWxZGaNpOIL8TefRLF4tcMzeAm55NopEXmw3GJKCeaEGzottTJRe8hnURSJAb-SXwCbjj5sivSKJ7BnKFRtFkLP1BpaN-KMun-p_KNuvzv6W93LHu-?type=png)](https://mermaid.live/edit#pako:eNrtWm1v2zYQ_iuchhpOaqPfhSBA0mBDURTr0qH7UBcCLdE2YVl0SNqJlya_fXyRLFIkI8sLsBlTPrQJ77nTkffwSB75GKUkQ1EcpTlk7AbDOYUrMCmA-HnzBtyiHHJMCrbAa6Zb3y8QY8lnjFIExmNS_n1NIM1cABmPwSeyRclXmONMmUq-cAo5mu9c9MUPAf8M74uA6CMu5pOQ8A8KCzYjdJUYogp9RSncJYarwvUfl7bvGuk1o7_w-wahdtQ1ZguyboXdErJsBX0s8HzBPV1OfoEpJ3RXfjKH6TLxiFv0_lxgjvx6ruZXzLCQKc1f4Qolv20RrVo1XP8birf-po6Elw5aXUUjud7gPEPU1LEEZlhtDUk5DwMEmd9LioMbNMMFVqSueX6NFnCLCYU5eAeER5uUb-QfSgWx2oQ0DJRh9lOprmaOxcdHLZA_P4OVGI4VKnjCyo4msRoi1RacFlr3QWAZ_gsl3GzdeVtTkhMqJFNCcrNdRFSaj0W3BEtqyVvT5aHS1soj8FDZH4Fd9euZqflsqloS9IDSDUfDqYxJbE6wQcBuDLYEZ6aNTZGRoad9jnjyIAXNzmvRLixSvZNie3C0UA-QlDojlGPGk62MUSLDyHxewTRFaz7cxr7ZYuGfKi5qxvjn_atyBxcOcRpN3Vnjddvkz1kntGKFcEpRQvxv88yv3jPuOMbJpfVUkpP01eaJPxW5uPbspXR6Eh1HIrkJ-_dJBA5jkXQ2mJuelbTnwXE8ULvhU8kmytkgERzpIUlEK_XsOY49-pR0KvTR3gb5U3amK4NKqz2FjqOQPEGfCoGkr0H6qI50JY-y2FPnyD2MqqucCnm0t0H6lJ3pSqDSak-hrhSSZSCSC-Piu-AGcaQ8AO-ArIoBWRWTttKlKlZ6C0T7WtpjoBxTAYbBqosfsZWNw7UExOpkNPB02QLJLXArSG11WlF6OWuFycTV7pYi5yBAI4rYJuc2Ixoz3KlQmmM91h9DWSKD5PLKUW7EoUX-f49CXVVVlfZbtBZQkUX1TYI7JzTMio-ar1UuvDB4f35pwmS-8GUNw653Cnkka4oL7ssQjEPqFcwlC4Sf3tQkO2BlbFefV7Wtari9xa7Q6KcKojSHgcxsDltTXYKaGbcxhdw7EytEao1IrK98-_7tuwlxLJhD7hNb687e5MDSen7R6jGB_I_FavBCNPRVxweOxB6kmdPsgBgXcs6cqA14VnprMGG2hUWKfKOGWZKRAgXW5aEIQgwe9lXd2L6TqbFkXbpyDoY2Cgy8uPGlAzx3V2i5cwP1rk0mEnUHtQdc5Tm5Z0CEEGR4NkNUJCgA8zmhmC9WDEwhQxkQmlq6X8yFKrUTGiAzwBcIqCjrKJiBC16HWYt_CNVIX4fBRGhSuUPJEPDybQTcsIOBZSKVO5hkLRavpNoYdzHlckIblOvtqxq8k4viq1qkYmV83T6rVfRVTU7VIv-PTXpTTCtVg7AGVw_E9WTtyXowWesTGEWKVM07evesVb14sDicSnWkKFP7cxYbj08sHFXFlth4tOGKAwt7QGVa1v5i672IDxKwG1Rbluf6eP96JAQJWA6q3emKd2w-hPEAAmZDSkt1CROXj3s8aSn4SqUP6amGNPhgqQ_pyYS0Pt5M9SHMc_Joht16qGVVX-_VJJ9pFohDzAtP02qlqaJRrdTyDq68rDGdaGxZXpBNZaOmYnuh1T0taXXauAboqL50CsEdDUyde6yOBu4OvCkN9qBxH3-weiee-Z4FdqtdvPXZ8O5ve8qcOGXEZlI9CUXgaiqvflJebiUvLqqGy0u3emFJX3x7XH_gQ8ERFekK7b-wb7E_sV8Oqze1PqTRmbAh632uDQvVEqJRtEJ0BXEWxZGaNpOIL8TefRLF4tcMzeAm55NopEXmw3GJKCeaEGzottTJRe8hnURSJAb-SXwCbjj5sivSKJ7BnKFRtFkLP1BpaN-KMun-p_KNuvzv6W93LHu-)
