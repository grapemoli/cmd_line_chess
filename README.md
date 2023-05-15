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
[![](https://mermaid.ink/img/pako:eNrtWm1v2zYQ_iuchgZqaqPfhcBAk2BDUQzrkmH7UBcCLdE2YVl0Kdq1lya_fXyRLFIkLasojAlTviThPXdH8R4eySOfgoSkKIiCJINFcY_hgsI1mOaA_7x6BR5QBhkmebHEm0K13i1RUcQfMUoQGI9J-f8tgTS1ATffxmPwEX7NPaIPOF9MfcI_KcyLOaHrWBNV6HeUwkOsOeed-TYxe6OQTjPKwx9bhNpRt7hYkk0r7IGQVSvoQ44XS-b45PgXmDBCD6XLDCar2CFu0ft7iRly69maf-ECc5nU_BWuUfz7DtGqVcErNTmg8e0WZylSCmUADIEeGVODcAVHEDnD7gTvwD2a4xxLptXku0VLuMOEwgy8BY-MbhO2Ff9IFVTUJoRhIA0XP5Xqks4GpZ6UQPz8DPZxBAr8D4qZ3npwtiYkI5RLZoRkejsfWN5fLnhkPFi15I3uNpTaSnkE9pX9EThUf77WNV90VUOC9ijZMhTOxLhGOs-vPHYjsCM41W3gIubdyXDazYz54dLMDnIr4Zn4bZ6S0NGdBWLxXgiaY65EB79IDmrocCWEKi5CagUmwwVTfY_XZIcKV69gkqANC3eRa64Y-OeKxops7llv0Q7nFucaTd0J53StU-91J7RkAu-UDCv_bVLUrT6QtVdkFWvyJVOi8GdSzJ0AbVx7zpQ6A_96xT-x8fsx_APnEVA49GbEFykdKNQrCsnN-yVzmHTo5ZAlPSd1KaWBeL0injoPXpJ5yqOXemWHupKvtDqwr1fsE2WGS3JP-PMyT3amK--kxYF1_dqvybrVJXmnPHqZV3aoK_dKqwP7esI-Ud4T41pwv-AeMSR7AN4CUbAEomApbCUrWUd2Fv6OZc4nT4muAoTeSpwbsRON4UYAInludXyxgRGHjDaM3BC2gdTC3YYSaba1S3I6eAhEUbHNmMmFRlqwysb6KI_BQog5G6hNJ0uzMfwt8v_v4NflcXnr8YA2HIpypu5p7EmgYEZY5AStcu6NRvSJjhL5wZUlNLPOKeOQbCjOmSsjFAxSp-DIHFcqEv03FgZbn1VFymqwnVXLK8_gJxIiNX2ZWLNy3VQXoGaGbUwc-_rKiJBcQ2LDy6fPnz7rEMuCPuQusbEuHU1eGVovJ61-TyD_Y7G6OhENdWX1niEKrUxmBkS77bTmRG3AsRMwBhOmO5gnKHRvJ1KSI886HPIgRGB_LM9H5t1ajSWbsivXIDRR4MqJG08s4LUr99xRJPNN8zbOXn2r60lj9U2EOoo3onC71wJV3xQbOCoPDJF2w2qLPaH3qMzKo29kXO66IB67XrVVucGMjle9PojHslfti6oVRfqttQPgMetTWsnKZ1TexDvmhvdKeQhpX0PqfV0whLQ3Ia0XwJlaph1rUzPsxpMM4yj_VU7yuWIBX-ZOvCOplWaSRrVSy6OVslapd6Kxfzwhm4lGRcX2E7-9nip12ihldVRfWRWJjgZmVhm3o4EvZ94xeL-gcQl2tnonnrkeAHXb3b5x2WiQpRUxUKYPlOGbSfn4C4F3s4KfBBJWbiVvbqqGycTe3xrSkw8Fawfvc74z5-kKHT0cW0wXx-UQAD9S-xi_obJ2EYyCNaJriNMgCuRUmAZsidZoGkT8zxTNIT_sT4OREulvMQWinDxcsKW7UifjXwTpNBAiPpjP3AXcMvJ4yJMgmsOsQKNgu0n54lEaOraiVHTpt_LZp_j1_C_opdSF?type=png)](https://mermaid.live/edit#pako:eNrtWm1v2zYQ_iuchgZqaqPfhcBAk2BDUQzrkmH7UBcCLdE2YVl0Kdq1lya_fXyRLFIkLasojAlTviThPXdH8R4eySOfgoSkKIiCJINFcY_hgsI1mOaA_7x6BR5QBhkmebHEm0K13i1RUcQfMUoQGI9J-f8tgTS1ATffxmPwEX7NPaIPOF9MfcI_KcyLOaHrWBNV6HeUwkOsOeed-TYxe6OQTjPKwx9bhNpRt7hYkk0r7IGQVSvoQ44XS-b45PgXmDBCD6XLDCar2CFu0ft7iRly69maf-ECc5nU_BWuUfz7DtGqVcErNTmg8e0WZylSCmUADIEeGVODcAVHEDnD7gTvwD2a4xxLptXku0VLuMOEwgy8BY-MbhO2Ff9IFVTUJoRhIA0XP5Xqks4GpZ6UQPz8DPZxBAr8D4qZ3npwtiYkI5RLZoRkejsfWN5fLnhkPFi15I3uNpTaSnkE9pX9EThUf77WNV90VUOC9ijZMhTOxLhGOs-vPHYjsCM41W3gIubdyXDazYz54dLMDnIr4Zn4bZ6S0NGdBWLxXgiaY65EB79IDmrocCWEKi5CagUmwwVTfY_XZIcKV69gkqANC3eRa64Y-OeKxops7llv0Q7nFucaTd0J53StU-91J7RkAu-UDCv_bVLUrT6QtVdkFWvyJVOi8GdSzJ0AbVx7zpQ6A_96xT-x8fsx_APnEVA49GbEFykdKNQrCsnN-yVzmHTo5ZAlPSd1KaWBeL0injoPXpJ5yqOXemWHupKvtDqwr1fsE2WGS3JP-PMyT3amK--kxYF1_dqvybrVJXmnPHqZV3aoK_dKqwP7esI-Ud4T41pwv-AeMSR7AN4CUbAEomApbCUrWUd2Fv6OZc4nT4muAoTeSpwbsRON4UYAInludXyxgRGHjDaM3BC2gdTC3YYSaba1S3I6eAhEUbHNmMmFRlqwysb6KI_BQog5G6hNJ0uzMfwt8v_v4NflcXnr8YA2HIpypu5p7EmgYEZY5AStcu6NRvSJjhL5wZUlNLPOKeOQbCjOmSsjFAxSp-DIHFcqEv03FgZbn1VFymqwnVXLK8_gJxIiNX2ZWLNy3VQXoGaGbUwc-_rKiJBcQ2LDy6fPnz7rEMuCPuQusbEuHU1eGVovJ61-TyD_Y7G6OhENdWX1niEKrUxmBkS77bTmRG3AsRMwBhOmO5gnKHRvJ1KSI886HPIgRGB_LM9H5t1ajSWbsivXIDRR4MqJG08s4LUr99xRJPNN8zbOXn2r60lj9U2EOoo3onC71wJV3xQbOCoPDJF2w2qLPaH3qMzKo29kXO66IB67XrVVucGMjle9PojHslfti6oVRfqttQPgMetTWsnKZ1TexDvmhvdKeQhpX0PqfV0whLQ3Ia0XwJlaph1rUzPsxpMM4yj_VU7yuWIBX-ZOvCOplWaSRrVSy6OVslapd6Kxfzwhm4lGRcX2E7-9nip12ihldVRfWRWJjgZmVhm3o4EvZ94xeL-gcQl2tnonnrkeAHXb3b5x2WiQpRUxUKYPlOGbSfn4C4F3s4KfBBJWbiVvbqqGycTe3xrSkw8Fawfvc74z5-kKHT0cW0wXx-UQAD9S-xi_obJ2EYyCNaJriNMgCuRUmAZsidZoGkT8zxTNIT_sT4OREulvMQWinDxcsKW7UifjXwTpNBAiPpjP3AXcMvJ4yJMgmsOsQKNgu0n54lEaOraiVHTpt_LZp_j1_C_opdSF)
