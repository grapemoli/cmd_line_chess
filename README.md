# Chess

## Goals
1. Use design patterns
2. Dynamic / Linear Programming if possible
3. NAMESPACES ??

## Savepoints
1. Create UML <--
2. Determine representation of the Board / Pieces on the Board <--
3. Create Chess Pieces 
4. Test Chess Pieces & Chess Eating
5. Add pawn-transformation functionality
6. Create Board
7. Give option to reverse the printing of the board based on which player is playing
8. Optimize the physical representation of the board

## Board Representation (Structure TBD)
K – king <br>
Q – queen <br>
R – rook <br>
B – bishop <br>
N – knight <br>
P – pawn <br>
| *R* | *N* | *B* | *Q* | *K* | *B* | *N* | *R* | <br>
| *P* | *P* | *P* | *P* | *P* | *P* | *P* | *P* | <br>
|         |         |         |         |         |         |         |         | <br>
|         |         |         |         |         |         |         |         | <br>
|         |         |         |         |         |         |         |         | <br>
|         |         |         |         |         |         |         |         | <br>
| -P- | -P- | -P- | -P- | -P- | -P- | -P- | -P- | <br>
| -R- | -N- | -B- | -K- | -Q- | -B- | -N- | -R- | <br>


## UML
[![](https://mermaid.ink/img/pako:eNrdWG2L2kAQ_ivbhQNLlX4PclA9jpbj4HoW-kUIazKaxZhNdzdWudrf3n0zZjW-pEKE80vMPjPz7D6z2czkDUcsBhzgKCVCPFAy42SBxhlSv7s79AopkZRlIqG5sKPDBIQIXyhEgFiv5-4HjPD40KD_R1m8kN_ZEeiJZrPxMfAHJ5mYMr4IK9DWuha0ft8LgPNWAyoSlp81e2VsftboKaOzROqpHSwlfCSRZHztSFMSzcMa-Izfz4RKqPfbcqpsDXUO0QNMaUZN1naJHEBClpRxkqLPaCR5EclC3xgXELsQmgIZCvHBuZut4aXnzQL610OrMEA0k9Wh9eFQxFLG1bCQ3OR8h-SGTEFfiUieSb7DPlVJO_t2XRtzG_Jj1e9v1dFDYAVRIdVggJaMxlWIilBFTGkMnZWZfxetzVXZThhLq7ZFFjM_xmabCCtX_W5pTbha-kYS_leELtpTzktKfcibpEefSe1lQ7M1Ev8Sh9Namwg3kVaf6ddLiy7VVtM1OxuMx02kMW-m9radoWukjZ3gdTvPst5EX_tOb09gy9dIYTfFoz6XKOxobyKxrofaE1izNZLXTO-6_Ws4b3NymjKyPXUtXyN93RSvU9jxtqjxrg7WfYpf9VbLWwt7CViwpVnoSKrSvVndaqJ16grTGiRXuslTUx9yML3YftV-UJ6XrYO3jki7Q5ibuiCoNGUezM3mDyptjwdP3MkTeO2TZzJ3yQ3KrujA5Jd9QwTVTs2PYd7QgWsPa56Uo_3QO17z0d7x3a253PKmlQX0ZaJOFbVWt-H7_e3A_T3yPg0coCc_IewIvmUS-JREUDKUIz5FKTlCxy3Nw427eAF8QWiMA2wSNMYygQWMcaD-xjAlRSrHuGuh6ucXbeFSqoCCL51PqqZK-BhrSOm0URSkkGy0ziIcTEkqoIuLPFbCukDlKMRUzfrZfenRl80_bX1h7Q?type=png)](https://mermaid.live/edit#pako:eNrdWG2L2kAQ_ivbhQNLlX4PclA9jpbj4HoW-kUIazKaxZhNdzdWudrf3n0zZjW-pEKE80vMPjPz7D6z2czkDUcsBhzgKCVCPFAy42SBxhlSv7s79AopkZRlIqG5sKPDBIQIXyhEgFiv5-4HjPD40KD_R1m8kN_ZEeiJZrPxMfAHJ5mYMr4IK9DWuha0ft8LgPNWAyoSlp81e2VsftboKaOzROqpHSwlfCSRZHztSFMSzcMa-Izfz4RKqPfbcqpsDXUO0QNMaUZN1naJHEBClpRxkqLPaCR5EclC3xgXELsQmgIZCvHBuZut4aXnzQL610OrMEA0k9Wh9eFQxFLG1bCQ3OR8h-SGTEFfiUieSb7DPlVJO_t2XRtzG_Jj1e9v1dFDYAVRIdVggJaMxlWIilBFTGkMnZWZfxetzVXZThhLq7ZFFjM_xmabCCtX_W5pTbha-kYS_leELtpTzktKfcibpEefSe1lQ7M1Ev8Sh9Namwg3kVaf6ddLiy7VVtM1OxuMx02kMW-m9radoWukjZ3gdTvPst5EX_tOb09gy9dIYTfFoz6XKOxobyKxrofaE1izNZLXTO-6_Ws4b3NymjKyPXUtXyN93RSvU9jxtqjxrg7WfYpf9VbLWwt7CViwpVnoSKrSvVndaqJ16grTGiRXuslTUx9yML3YftV-UJ6XrYO3jki7Q5ibuiCoNGUezM3mDyptjwdP3MkTeO2TZzJ3yQ3KrujA5Jd9QwTVTs2PYd7QgWsPa56Uo_3QO17z0d7x3a253PKmlQX0ZaJOFbVWt-H7_e3A_T3yPg0coCc_IewIvmUS-JREUDKUIz5FKTlCxy3Nw427eAF8QWiMA2wSNMYygQWMcaD-xjAlRSrHuGuh6ucXbeFSqoCCL51PqqZK-BhrSOm0URSkkGy0ziIcTEkqoIuLPFbCukDlKMRUzfrZfenRl80_bX1h7Q)
