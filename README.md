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
K – king
Q – queen
R – rook
B – bishop
N – knight
P – pawn 
| *R* | *N* | *B* | *Q* | *K* | *B* | *N* | *R* |
| *P* | *P* | *P* | *P* | *P* | *P* | *P* | *P* |
|         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |
|         |         |         |         |         |         |         |         |
| -P- | -P- | -P- | -P- | -P- | -P- | -P- | -P- |
| -R- | -N- | -B- | -K- | -Q- | -B- | -N- | -R- |


## UML
[![](https://mermaid.ink/img/pako:eNrdV02L2zAQ_SuqYGFLE3oXYaHJUiilsN099GIwijyJRRwrleQ0IU1_e_UVx1rH3g1tclhfbM_TvNE8j6TxDjORASaYFVSpe07nki5RUiJz3dygRyio5qJUOV8pb53koFT6wIEBGv0eDtED_VV2QF95Oe-AvlcAXW5jrnKx6gAfhVh0hSv5PNdJmzb9TJkWchvoC8oW6Qn4Bb8fOddw2u8Q00g2sUKie5jxkjvpjmqOIadrLiQt0Ef0pGXFdGVfnAuoI4UNgVwI9S64u-8TpbzzgL2GaJMSxEvdNG3bJiYKIY1ZaVl_GY9MBZUZCfxj-3JEPzTD3jqOA8X75qg_zWERAhtglTZGgtaCR9RcpYax4Bncbtx8B2jr7oFgf5DWC2CL7ZqZ23g9KbfhATqZRlDIjb-QNHax_bs06PXa2IB95eDwCyXrto9rFoIL2JOtn9A5teAZL6SP30KvKZCP2KNQmFIY8RqFAuWFJLIHyTUFsvF65HHTOad-HN-l9hJ3kl5THR-xR58wpXMUCpz_VaPjYW4ziI_usPQcsGulnp5eqA4aV7zIQFqvU7EmElwb9rxXaDUFdcMShWfWHdKVO3xIo2GLYOnqiTQarAiehsVIovYsGrIIepO6E2sN-ek3PdLs_2IOd2iQRuv4TLDOLuwN59zZsb65nOuSdw00oE9Ts9BNrqHgR6OD4e6uWfdtxy-lBjmjDGrP2hK71lIihAd4CXJJeWZ-iJyyCdY5LCHBxDxmMKNVoRM88FDzl8mOCN_CAJVcB5_CzIXKBFvIJLg3IWilxdO2ZJjMaKFggKtVZhQJRLUVMm6m9S38ndnb_i9JzQ0s?type=png)](https://mermaid.live/edit#pako:eNrdV02L2zAQ_SuqYGFLE3oXYaHJUiilsN099GIwijyJRRwrleQ0IU1_e_UVx1rH3g1tclhfbM_TvNE8j6TxDjORASaYFVSpe07nki5RUiJz3dygRyio5qJUOV8pb53koFT6wIEBGv0eDtED_VV2QF95Oe-AvlcAXW5jrnKx6gAfhVh0hSv5PNdJmzb9TJkWchvoC8oW6Qn4Bb8fOddw2u8Q00g2sUKie5jxkjvpjmqOIadrLiQt0Ef0pGXFdGVfnAuoI4UNgVwI9S64u-8TpbzzgL2GaJMSxEvdNG3bJiYKIY1ZaVl_GY9MBZUZCfxj-3JEPzTD3jqOA8X75qg_zWERAhtglTZGgtaCR9RcpYax4Bncbtx8B2jr7oFgf5DWC2CL7ZqZ23g9KbfhATqZRlDIjb-QNHax_bs06PXa2IB95eDwCyXrto9rFoIL2JOtn9A5teAZL6SP30KvKZCP2KNQmFIY8RqFAuWFJLIHyTUFsvF65HHTOad-HN-l9hJ3kl5THR-xR58wpXMUCpz_VaPjYW4ziI_usPQcsGulnp5eqA4aV7zIQFqvU7EmElwb9rxXaDUFdcMShWfWHdKVO3xIo2GLYOnqiTQarAiehsVIovYsGrIIepO6E2sN-ek3PdLs_2IOd2iQRuv4TLDOLuwN59zZsb65nOuSdw00oE9Ts9BNrqHgR6OD4e6uWfdtxy-lBjmjDGrP2hK71lIihAd4CXJJeWZ-iJyyCdY5LCHBxDxmMKNVoRM88FDzl8mOCN_CAJVcB5_CzIXKBFvIJLg3IWilxdO2ZJjMaKFggKtVZhQJRLUVMm6m9S38ndnb_i9JzQ0s)
