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
[![](https://mermaid.ink/img/pako:eNrtW1tv2zYU_iuchhpKaqPvQhAgabChKIp17dA91IVAS7QtRBZdknbspelvLy-6kCJpJbE6z5jzkDg8V_J85-iIpO-DBKcoiIIkh5TeZHBG4AKMC8B_XrwAH1AOWYYLOs-WVI2-niNK4_cZShAYjXD5_zWGJLUZ8GgE3uE1ij_BPEulqvgjI5Ch2dbmvvjG2d_Du8JDepsVs7GP-BeBBZ1isog1UsV9RQjcxpqr3PVvl6bvitOpRln4c4VQN9d1Rud42cn2AePbTqa3RTabM8eU499gwjDZliZzmNzGDnKH3N_zjCG3nC35KaMZp0nJ3-ECxX-sEalGFbv67Yu3sqkiIXgWqGB-MNT2BMb8EKo8lTGMr1dZniKiWzIIOhhMCQFUB254CrwWiQFu0DQrMpkKTXZcozlcZ5jAHLwC3KdVwlbiHymCaKNCKAZSMf2lFJf5ZqD4XhHEz69gUS0QLacaR6BeNG8yKdkN56XZPyhm-ujWOZrgHBNOmWCc6-McB0J9xKfFsdVQXuouh5aXu50cDJU9ZW4INpVHQ7CtPp7ptr7rxgwK2qBkxVA4EVGM9EQeePRGYI2zVNexKlIcOsZniMUbQWgv10tAJWmzQ6kQ3vqFt-G2Q1iukFBghkQRVVgE1YpLnlEWr8WixyIs1DUzmCRoycJ15Mo0g_-hygCFU3eN6hWxWWHBtTX0dKw63d4PtWc_Wb9EL5-4hC7_a-aD2-ApMw6XGaJdOZbSLXzdF53uQt2H5u6ngbRyAvvhwC4a8MODHTwO7cLZHmv9d6nvhL7DoU--fx1LrZXO9gi_HvQ9psQqMyeUHw7lav_gWGCuvO0R5-X0fz7SS89PUD8c1MUe2LEAXfjaI8z3V_cYjEsrJ4QfsGGWG7jHgnHlbY8o70PhY3Be2jkh_RBIFxvcOOfKuV1wgxiSHoBXQJwSAHFKIHQlt_Lwxrn1Xe_133s2miuG0Ls77OZYi8FwKRgiuUcxcEzZYBIveZ1Msknu5FINRiebqNHdbkmADzyAIIiucmYiolWIrBMbfa1HyhhKYxEkG1eWcCsOHfT_exSa8yJ58vgBLTkrr33qZNXOCcVmPTNoVbIvNNyfX-psomy4HgVPfeTEdh5Kp8LHFfAYDFyJqlQYlCXJCuaqQ5RB4iTMBNa4bWcBFPMM9YeRLc-qHfQqqM4tdV-ME8kiJUPPM0QPTltcMPkrv1d59an0WD-CqRa6le72efch4aTLysdxbEzi85fPX_S1sJw3MWOTjUd8rbKFwQ6tT0fifwxsgx1AUGfdbxji8WiXfjMg2j0OK_sbBY6mylhMmK5hkSDXqmU0TnGBPO1LyIMQgU19-BWZh_INL16WrpyD8KyVEk6-0aXFeG43MgLFoEGwSBB5daFmuMpzfEcBDyFIs-kUEQ55APMZJhmbLyiYQIpSwCUVte55uCgx6z7AU8DmCMgoqyjogfPeorhv9fiq8YrX6snLA-nsrAb-HFT1wVg1n3FH3Nul3it61kKBdD1FwAltT62zMZOIzjJe8qYirqpSHwpFH9Srwq-iWelVI-EdS79zlt1NryonsvnaW6WzpllXiP6VzPDYDp2CrgeQLXpKjFNi7JMYzVs4QbLmtm-g2e_b1S1A4307EeJIQsbYv2guZBp8RO4tRtpFRpvs6Vo8IpNyRz4y7lC6WDx6vWK35f5QVN-o9LF4NHvFvqrzski_HOpg8Kj1Cd3Ko-aovPDqKIHem5unkB5rSL2XeE8hPZqQNu9uE_WG6XitaofduIZstDB3MsmnCgW8t9hxXVvrYCSMGqGOu-HloavuRGtzbwdtIgYVFLs37O1XQSUuIfh88RIRz1dQgvX5ChR29piBgNFzxJ-EM9el9x37ADs2ZnaBpZPjBJljgAxvJuUXHhC4mog9voSVreTFRTVweWlvzRjUnd_HaQy8KRgivFyh2kI9YpqoH4fV90xcnNpk_IqM76yYbL7di2AYLBBZwCwNokCmzThgc967j4OIf0zRFK5yNg6GiqR_mUpwlInGCSuyLmVyPntIxoEg8YV_4CbgiuGP2yIJoinMKRoGqyX3A5WK6lGUCvffld_bEn8efgD23uj6?type=png)](https://mermaid.live/edit#pako:eNrtW1tv2zYU_iuchhpKaqPvQhAgabChKIp17dA91IVAS7QtRBZdknbspelvLy-6kCJpJbE6z5jzkDg8V_J85-iIpO-DBKcoiIIkh5TeZHBG4AKMC8B_XrwAH1AOWYYLOs-WVI2-niNK4_cZShAYjXD5_zWGJLUZ8GgE3uE1ij_BPEulqvgjI5Ch2dbmvvjG2d_Du8JDepsVs7GP-BeBBZ1isog1UsV9RQjcxpqr3PVvl6bvitOpRln4c4VQN9d1Rud42cn2AePbTqa3RTabM8eU499gwjDZliZzmNzGDnKH3N_zjCG3nC35KaMZp0nJ3-ECxX-sEalGFbv67Yu3sqkiIXgWqGB-MNT2BMb8EKo8lTGMr1dZniKiWzIIOhhMCQFUB254CrwWiQFu0DQrMpkKTXZcozlcZ5jAHLwC3KdVwlbiHymCaKNCKAZSMf2lFJf5ZqD4XhHEz69gUS0QLacaR6BeNG8yKdkN56XZPyhm-ujWOZrgHBNOmWCc6-McB0J9xKfFsdVQXuouh5aXu50cDJU9ZW4INpVHQ7CtPp7ptr7rxgwK2qBkxVA4EVGM9EQeePRGYI2zVNexKlIcOsZniMUbQWgv10tAJWmzQ6kQ3vqFt-G2Q1iukFBghkQRVVgE1YpLnlEWr8WixyIs1DUzmCRoycJ15Mo0g_-hygCFU3eN6hWxWWHBtTX0dKw63d4PtWc_Wb9EL5-4hC7_a-aD2-ApMw6XGaJdOZbSLXzdF53uQt2H5u6ngbRyAvvhwC4a8MODHTwO7cLZHmv9d6nvhL7DoU--fx1LrZXO9gi_HvQ9psQqMyeUHw7lav_gWGCuvO0R5-X0fz7SS89PUD8c1MUe2LEAXfjaI8z3V_cYjEsrJ4QfsGGWG7jHgnHlbY8o70PhY3Be2jkh_RBIFxvcOOfKuV1wgxiSHoBXQJwSAHFKIHQlt_Lwxrn1Xe_133s2miuG0Ls77OZYi8FwKRgiuUcxcEzZYBIveZ1Msknu5FINRiebqNHdbkmADzyAIIiucmYiolWIrBMbfa1HyhhKYxEkG1eWcCsOHfT_exSa8yJ58vgBLTkrr33qZNXOCcVmPTNoVbIvNNyfX-psomy4HgVPfeTEdh5Kp8LHFfAYDFyJqlQYlCXJCuaqQ5RB4iTMBNa4bWcBFPMM9YeRLc-qHfQqqM4tdV-ME8kiJUPPM0QPTltcMPkrv1d59an0WD-CqRa6le72efch4aTLysdxbEzi85fPX_S1sJw3MWOTjUd8rbKFwQ6tT0fifwxsgx1AUGfdbxji8WiXfjMg2j0OK_sbBY6mylhMmK5hkSDXqmU0TnGBPO1LyIMQgU19-BWZh_INL16WrpyD8KyVEk6-0aXFeG43MgLFoEGwSBB5daFmuMpzfEcBDyFIs-kUEQ55APMZJhmbLyiYQIpSwCUVte55uCgx6z7AU8DmCMgoqyjogfPeorhv9fiq8YrX6snLA-nsrAb-HFT1wVg1n3FH3Nul3it61kKBdD1FwAltT62zMZOIzjJe8qYirqpSHwpFH9Srwq-iWelVI-EdS79zlt1NryonsvnaW6WzpllXiP6VzPDYDp2CrgeQLXpKjFNi7JMYzVs4QbLmtm-g2e_b1S1A4307EeJIQsbYv2guZBp8RO4tRtpFRpvs6Vo8IpNyRz4y7lC6WDx6vWK35f5QVN-o9LF4NHvFvqrzski_HOpg8Kj1Cd3Ko-aovPDqKIHem5unkB5rSL2XeE8hPZqQNu9uE_WG6XitaofduIZstDB3MsmnCgW8t9hxXVvrYCSMGqGOu-HloavuRGtzbwdtIgYVFLs37O1XQSUuIfh88RIRz1dQgvX5ChR29piBgNFzxJ-EM9el9x37ADs2ZnaBpZPjBJljgAxvJuUXHhC4mog9voSVreTFRTVweWlvzRjUnd_HaQy8KRgivFyh2kI9YpqoH4fV90xcnNpk_IqM76yYbL7di2AYLBBZwCwNokCmzThgc967j4OIf0zRFK5yNg6GiqR_mUpwlInGCSuyLmVyPntIxoEg8YV_4CbgiuGP2yIJoinMKRoGqyX3A5WK6lGUCvffld_bEn8efgD23uj6)
