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
| -R- | -N- | -B- | -K- | -Q- | -B- | -N- | -R- | <br>

* differentiation of *white* and -black- pieces.


## UML
[![](https://mermaid.ink/img/pako:eNrtWm1v2zYQ_iuchhpqGqPfhcBAk2BDUQzrkmH7UBcCLdE2YVl0Kdq1lya_fXyRLFIkLasojAmTv9jmPXdH8R4eqSOfgoSkKIiCJINFcY_hgsI1mOaAf169Ag8ogwyTvFjiTaFa75aoKOKPGCUIjMek_H9LIE1twM238Rh8hF9zj-gDzhdTn_BPCvNiTug61kQV-h2l8BBrznlnvk3M3iik04zy8McWoXbULS6WZNMKeyBk1Qr6kOPFkjkeOf4FJozQQ-kyg8kqdohb9P5eYobcerbmX7jAXCY1f4VrFP--Q7RqVfBKTQ5ofLvFWYqUQhkAQ6BHxtQgXMERRM6wO8E7cI_mOMeSaTX5btES7jChMANvwSOj24RtxR-pgorahDAMpOHip1Jd0tmg1JMSiM_PYB9HoMD_oJjprQdna0IyQrlkRkimt_OB5f3lgkfGg1VL3uhuQ6mtlK_BvrJ_DQ7Vz9e65ouuakjQHiVbhsKZGNdI5_nIYzcCO4JT3QYuYt6dDKfdzJgPLs3sILcSnonf5ikJHd1ZIBbvhaA55kp08IvkoIYOV0Ko4iKkVmAyXDDV93hNdqhw9QomCdqwcBe55oqBf65orMjmnvUW7XBuca7R1J1wTtc69V53Qksm8E7JsPJvk6Ju9YGsvSKrWJMvmRKFP5Ni7gRo49pzptQZ-Ncr_omN34_hHziPgMKhNyO-SOlAoV5RSG7eL5nDpEMvhyzpOalLKQ3E6xXx1PvgJZmnPHqpV3aoK_lKqwP7esU-UWa4JPeEPy_zZGe68k5aHFjXr_2arFtdknfKo5d5ZYe6cq-0OrCvJ-wT5T0xrgX3C-4RQ7IH4C0QBUsgCpbCVrKSdWRn4e9Y5nzylOgqQOitxLkRO9EYbgQgku-tI8cjGyDxltEKklvCVpRau1thItW2d0vOiZGHRhQV24yZjGgkB6t4rI_1WDlDaSyCZPPKUm7EoUX-f49CXS2XhyAPaMOhKGfq2MaeEwpmxEfO1yoF32i8v5roMJEvXFlDs-ucQg7JhuKcuTJEwSB1ChaCBbyfztQkHsBYKGx9VhUtq-F2VjF9o59IiNT0ZWZ92JrqAtTMuI0pZB9nGSGSa0psePn0-dNnHWJZ0IfcJTbWqaPJkaH1ctLq9wTyPxar0YloqCOs9wxRaOU0MyDa6ac1J2oDjp2BMZgw3cE8QaF7e5GSHHnW5ZAHIQL7Y7k-Ms_aaizZlF25AqGJAiMnbjyxgFeu5HNHkUw4zdM5ezWujiuN1TgR6ijeiELuXgtUfXJs4Kh8gYi0E1db7Am9R2VWvgpHxmGvC-Kx61VblRvO6Hj064N4LHvVvqjaUaSfYjsAHrM-pZWshEblybxjbniPmIeQ9jWk3tsGQ0h7E9J6AZypZdqxNjXDblzRMF7tv8pJPlcs4MvciXsltdJM0qhWarnEUtYu9U409o8nZDPRqKjYXgGw11OlThulrY7qK6tC0dHAzCrrdjTw5cwzB-8TNA7FzlbvxDPXhaBuu9s3LhsNsrQiBsr0gTJ8MykvgyHwblbwN4GElVvJm5uqYTKx97eG9OTFwdrB-5zvzHm6QkcPxxbTxXE5BMCP1B7Gb6gsYQTXwRrRNcRpEAVyKkwDtkRrNA0i_jNFc8jf9qfBtRLpdzMFopw8XLClu1In408E6TQQIj6Yz9wF3DLyeMiTIJrDrEDXwXaT8sWjNHRsRano0m_lNVDx9fwvBCHXwg?type=png)](https://mermaid.live/edit#pako:eNrtWm1v2zYQ_iuchhpqGqPfhcBAk2BDUQzrkmH7UBcCLdE2YVl0Kdq1lya_fXyRLFIkLasojAmTv9jmPXdH8R4eqSOfgoSkKIiCJINFcY_hgsI1mOaAf169Ag8ogwyTvFjiTaFa75aoKOKPGCUIjMek_H9LIE1twM238Rh8hF9zj-gDzhdTn_BPCvNiTug61kQV-h2l8BBrznlnvk3M3iik04zy8McWoXbULS6WZNMKeyBk1Qr6kOPFkjkeOf4FJozQQ-kyg8kqdohb9P5eYobcerbmX7jAXCY1f4VrFP--Q7RqVfBKTQ5ofLvFWYqUQhkAQ6BHxtQgXMERRM6wO8E7cI_mOMeSaTX5btES7jChMANvwSOj24RtxR-pgorahDAMpOHip1Jd0tmg1JMSiM_PYB9HoMD_oJjprQdna0IyQrlkRkimt_OB5f3lgkfGg1VL3uhuQ6mtlK_BvrJ_DQ7Vz9e65ouuakjQHiVbhsKZGNdI5_nIYzcCO4JT3QYuYt6dDKfdzJgPLs3sILcSnonf5ikJHd1ZIBbvhaA55kp08IvkoIYOV0Ko4iKkVmAyXDDV93hNdqhw9QomCdqwcBe55oqBf65orMjmnvUW7XBuca7R1J1wTtc69V53Qksm8E7JsPJvk6Ju9YGsvSKrWJMvmRKFP5Ni7gRo49pzptQZ-Ncr_omN34_hHziPgMKhNyO-SOlAoV5RSG7eL5nDpEMvhyzpOalLKQ3E6xXx1PvgJZmnPHqpV3aoK_lKqwP7esU-UWa4JPeEPy_zZGe68k5aHFjXr_2arFtdknfKo5d5ZYe6cq-0OrCvJ-wT5T0xrgX3C-4RQ7IH4C0QBUsgCpbCVrKSdWRn4e9Y5nzylOgqQOitxLkRO9EYbgQgku-tI8cjGyDxltEKklvCVpRau1thItW2d0vOiZGHRhQV24yZjGgkB6t4rI_1WDlDaSyCZPPKUm7EoUX-f49CXS2XhyAPaMOhKGfq2MaeEwpmxEfO1yoF32i8v5roMJEvXFlDs-ucQg7JhuKcuTJEwSB1ChaCBbyfztQkHsBYKGx9VhUtq-F2VjF9o59IiNT0ZWZ92JrqAtTMuI0pZB9nGSGSa0psePn0-dNnHWJZ0IfcJTbWqaPJkaH1ctLq9wTyPxar0YloqCOs9wxRaOU0MyDa6ac1J2oDjp2BMZgw3cE8QaF7e5GSHHnW5ZAHIQL7Y7k-Ms_aaizZlF25AqGJAiMnbjyxgFeu5HNHkUw4zdM5ezWujiuN1TgR6ijeiELuXgtUfXJs4Kh8gYi0E1db7Am9R2VWvgpHxmGvC-Kx61VblRvO6Hj064N4LHvVvqjaUaSfYjsAHrM-pZWshEblybxjbniPmIeQ9jWk3tsGQ0h7E9J6AZypZdqxNjXDblzRMF7tv8pJPlcs4MvciXsltdJM0qhWarnEUtYu9U409o8nZDPRqKjYXgGw11OlThulrY7qK6tC0dHAzCrrdjTw5cwzB-8TNA7FzlbvxDPXhaBuu9s3LhsNsrQiBsr0gTJ8MykvgyHwblbwN4GElVvJm5uqYTKx97eG9OTFwdrB-5zvzHm6QkcPxxbTxXE5BMCP1B7Gb6gsYQTXwRrRNcRpEAVyKkwDtkRrNA0i_jNFc8jf9qfBtRLpdzMFopw8XLClu1In408E6TQQIj6Yz9wF3DLyeMiTIJrDrEDXwXaT8sWjNHRsRano0m_lNVDx9fwvBCHXwg)
