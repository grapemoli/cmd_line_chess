# Chess

## Goals
1. Use design patterns
2. Dynamic / Linear Programming if possible
3. NAMESPACES ??
4. Please use folders to seperate code accordingly
5. Implement undo/redo features 

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
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
|  -- |  -- |  -- |  -- |  -- |  -- |  -- |  -- | <br>
| -P- | -P- | -P- | -P- | -P- | -P- | -P- | -P- | <br>
| -R- | -N- | -B- | -K- | -Q- | -B- | -N- | -R- | <br>

* differentiation of *white* and -black- pieces.


## UML
[![](https://mermaid.ink/img/pako:eNrtWVtr2zAU_iuaoSNtE_ZuSqAXBqUMunawh6YYxVYSEcfKJDlL6OW3T7fYUiTHXQahC81LYn3n5vMdSz4nT1FKMhTFUZpDxq4wHFM4A4MCiM_REbhDOeSYFGyC50yvXk4QY8ktRikCvR4x1xcE0swXOHvu9cAt_F00QDe4GA-awB8UFmxE6CyxoLX0OaVwlVjORTDPfTcaLRk0oz18LxFql7rAbELmrWJ3hExbhW4KPJ5wGZp308lXmHJCV8ZpDtNpEoBb9H5OMEdhvbVPweulZBtcoREusOK3pvwCTeACEwpz8AXcc1qmvJQXSgWx2oR0AZQL9smoqyJyiHzSgPz0wDKJAS64vbTyl1KSEyqWh4Tk9rq4DRGpAO65SE2NnNoOO0NJfQy62oy2cmwLv9rSDoKWKC25WIzBguDMhjBLhL0cZ6izVAF3wUp9H2_GeQrKIiMhG2PEk6UEnPvV66vAeo4ZT-aEMTzMUTIjC8Rcsy9rQnXaw1W3FwKCrtupeLtaF2yk3WE0bOeQuJVb6H6olJ7amWuU2k6UUjskXuT59a-8gLcRI129YXdTYoeUYnVG76f2lav2HOuIdih_bf-QyNGvRvthR_tqp8fEtAM_xsMhESRfSvdDj_TUTo6KZwdqlPWDOjlUI7AfarSvdnJMTDvQYzz8_wTVbZDqKZ2mx-5uNOywp0yu039mvYn2_V5FqXdCfUkAmVNxK6EUMA4p31plfpfshKyIFiFbwT48PjzaIp4FO7YQbIpnw6Sj9LrV6N_dsAZk7jvLZIjGuFgXlHO1TESrC_MKq6-Og4mzYkuuOaJQtNDbcmfNPzyeawNuchTo3DjMFrBImx6ZjBQK2nxCRMV3xI3EYGk9Rs7IpJYlcxPKCei4UuBzUK7X9wRPQs_LJUVqUrQ5KfBGAtW44sn2l0p1lMxVgxBbIyMHpuoUiK1Riw97G0qD8NAc9rEz3wmJeBYbFaZmG4yrOU-TiGezUeGXfmmM7WFVQMAz2CQ-VQ1CbEZvgdJvnCB9MPZOGWucFX4w9q4YqzZLNXhF4HzIOBVMma3y7Gy90O_7-7eDbh2N1w6uC3HyjGCKKg_ViuuiKhgAmiXVeRV1oxmiM4izKI5UeQ0iPkEzNIhi8TNDI1jmfBB1NWT_rSAlTEEKoKQLo5OLUCEdRBISeXoRLmDJyf2qSKN4BHOGulE5z0RijaFqFWVYRP3N_IMhv17-AHZaVxs?type=png)](https://mermaid.live/edit#pako:eNrtWVtr2zAU_iuaoSNtE_ZuSqAXBqUMunawh6YYxVYSEcfKJDlL6OW3T7fYUiTHXQahC81LYn3n5vMdSz4nT1FKMhTFUZpDxq4wHFM4A4MCiM_REbhDOeSYFGyC50yvXk4QY8ktRikCvR4x1xcE0swXOHvu9cAt_F00QDe4GA-awB8UFmxE6CyxoLX0OaVwlVjORTDPfTcaLRk0oz18LxFql7rAbELmrWJ3hExbhW4KPJ5wGZp308lXmHJCV8ZpDtNpEoBb9H5OMEdhvbVPweulZBtcoREusOK3pvwCTeACEwpz8AXcc1qmvJQXSgWx2oR0AZQL9smoqyJyiHzSgPz0wDKJAS64vbTyl1KSEyqWh4Tk9rq4DRGpAO65SE2NnNoOO0NJfQy62oy2cmwLv9rSDoKWKC25WIzBguDMhjBLhL0cZ6izVAF3wUp9H2_GeQrKIiMhG2PEk6UEnPvV66vAeo4ZT-aEMTzMUTIjC8Rcsy9rQnXaw1W3FwKCrtupeLtaF2yk3WE0bOeQuJVb6H6olJ7amWuU2k6UUjskXuT59a-8gLcRI129YXdTYoeUYnVG76f2lav2HOuIdih_bf-QyNGvRvthR_tqp8fEtAM_xsMhESRfSvdDj_TUTo6KZwdqlPWDOjlUI7AfarSvdnJMTDvQYzz8_wTVbZDqKZ2mx-5uNOywp0yu039mvYn2_V5FqXdCfUkAmVNxK6EUMA4p31plfpfshKyIFiFbwT48PjzaIp4FO7YQbIpnw6Sj9LrV6N_dsAZk7jvLZIjGuFgXlHO1TESrC_MKq6-Og4mzYkuuOaJQtNDbcmfNPzyeawNuchTo3DjMFrBImx6ZjBQK2nxCRMV3xI3EYGk9Rs7IpJYlcxPKCei4UuBzUK7X9wRPQs_LJUVqUrQ5KfBGAtW44sn2l0p1lMxVgxBbIyMHpuoUiK1Riw97G0qD8NAc9rEz3wmJeBYbFaZmG4yrOU-TiGezUeGXfmmM7WFVQMAz2CQ-VQ1CbEZvgdJvnCB9MPZOGWucFX4w9q4YqzZLNXhF4HzIOBVMma3y7Gy90O_7-7eDbh2N1w6uC3HyjGCKKg_ViuuiKhgAmiXVeRV1oxmiM4izKI5UeQ0iPkEzNIhi8TNDI1jmfBB1NWT_rSAlTEEKoKQLo5OLUCEdRBISeXoRLmDJyf2qSKN4BHOGulE5z0RijaFqFWVYRP3N_IMhv17-AHZaVxs)
