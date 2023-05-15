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
[![](https://mermaid.ink/img/pako:eNrtWm2v2yYU_ivMU6e0TdTv1lWk3nu1qaqmdbfT9qGpLGKTBMUxLsZpstt7f_t4sWMwEMdVFcma8yUJ5w04Dwc4h8cgJgkKwiBOYVHcY7imcAcWGeCfFy_AA0ohwyQrNjgvVOvdBhVF9AGjGIHZjFT_bwmkic1w8202Ax_g18xDeo-z9cJH_IvCrFgRuos0Us39llJ4jDTjvDPf5mZvFKdTjbLwZ4lQN9ctLjYk72R7IGTbyfQ-w-sNcww5-hXGjNBjZTKF8TZykDvk_tlghtxytuTfuMCcJiXvSJryvySL7hFDsfB5TVeCtQI5tdFtidMEKdHKFQZB95EpQbiAw50ca3cCgeAerXCGJeYaGN6iDdxjQmEK3oCPjJYxK8UfKYKKRoVQDKTi4qdKXALbANejIojPz-AQhaDA_6KI6a1HZ2tMUkI5ZUlIqrdDNV8h7xp3W0N5rZudSGklPAWHWv8UHOufL3XJZ13UoKADikuGJksxr6GOeI_aEOwJTnQVuIhi4fCklxZz2FLLHnIlDh3hpTrKLCETRw_XiEUHQWh7QZGOfpKc5onDlCAqTwmq5SoOf6bGE-3IHhWuXsE4Rjmb7EPXOjL4n2pgK_i5I4IFRJxZKGw19Yeg07QOxpe9uCU6eKekW_m3CVq3-AjfgcNX7ODXDJvCngk6d5C0-brjqpQZETlwRIqD449BJLgMksKgN2o-S-oIqoGDSl4HrhnnpEEvqizqJeFNCY1QHDgU1Z3zmlhUFr1grDrUF46V1hGPA8ejSG5cE43CnheLsjN9kSg1jjgc-rlP5s-uiURl0YvFqkN90VhpHfE4WDyKdGOdNAWnpCl4A36DOwT-2CMqdMVbmeF2JiJPCdhHT8qwZph4M4Nujr1onOSCIZR3ZMeIDR5xfenikQfLLia13XdxiVDc2SW5QDwAoqgoU2ZioRUohBci4QXPLPvz3e3ZvpTz_zvrTZ5eFmIeUM5ZUcZU6chGv2LT_DEDcmXW4fdGQ_jcXhtS3LkmHJSc4oy5lnzBIHUS1gI5vDvOWCP6WU2W1kkrKXpmB7MLV8ZEyJAbGXHo0-dPn3UWS4M-YhfZCOMnlYbQ81ml3zONl88UJudmSpWP3jFEYWsVtydLq0FacGkUODY1Y6Qw2cNMJK2du2tCMuTZgyZ8OHx71EZm1LkaXpJXXXkFJiYX-MXJN5tbjK9cy--OIrnk2pUxe-epi4ZGTIyFOIpykSA9aFt7U781-Kg8UIda3dMmew4LHpFldVkMjZKri8Wj1yu2rY5b4akA62PxaPaKfVH5llCvJTsYPGp9QluZTwyr-rhjbXgLvaNLh-pSb81_dOlgXNoclpZqD3XsTW23G88jjIvtV7nIVwoFfJs787qjEVpKGDVCHU9Jquye3onW0eoMbSkaFRS777_2fqrEaSvV01N8a93PeypYWonPngq-XJin946gVVq6WLwXzlyPcfqdPF-7dLTA0skxQmYIkOGHSfkQC4G3y4JRHjCqo-TNTd0wn9vnW4N69vleY-Bdxk_mPFyhk4VTi2nitB0C4OeUgwmmwQ7RHcRJEAYS44uAbdAOLYKQ_0zQCvKL7CKYKpL-9FFwVKuCE0q6r2RS3lVIF4Eg8Vl64iZgycjHYxYH4QqmBZoGZZ7wXaFSdGpFiUgV_F69shRfT_8B1lWxIw?type=png)](https://mermaid.live/edit#pako:eNrtWm2v2yYU_ivMU6e0TdTv1lWk3nu1qaqmdbfT9qGpLGKTBMUxLsZpstt7f_t4sWMwEMdVFcma8yUJ5w04Dwc4h8cgJgkKwiBOYVHcY7imcAcWGeCfFy_AA0ohwyQrNjgvVOvdBhVF9AGjGIHZjFT_bwmkic1w8202Ax_g18xDeo-z9cJH_IvCrFgRuos0Us39llJ4jDTjvDPf5mZvFKdTjbLwZ4lQN9ctLjYk72R7IGTbyfQ-w-sNcww5-hXGjNBjZTKF8TZykDvk_tlghtxytuTfuMCcJiXvSJryvySL7hFDsfB5TVeCtQI5tdFtidMEKdHKFQZB95EpQbiAw50ca3cCgeAerXCGJeYaGN6iDdxjQmEK3oCPjJYxK8UfKYKKRoVQDKTi4qdKXALbANejIojPz-AQhaDA_6KI6a1HZ2tMUkI5ZUlIqrdDNV8h7xp3W0N5rZudSGklPAWHWv8UHOufL3XJZ13UoKADikuGJksxr6GOeI_aEOwJTnQVuIhi4fCklxZz2FLLHnIlDh3hpTrKLCETRw_XiEUHQWh7QZGOfpKc5onDlCAqTwmq5SoOf6bGE-3IHhWuXsE4Rjmb7EPXOjL4n2pgK_i5I4IFRJxZKGw19Yeg07QOxpe9uCU6eKekW_m3CVq3-AjfgcNX7ODXDJvCngk6d5C0-brjqpQZETlwRIqD449BJLgMksKgN2o-S-oIqoGDSl4HrhnnpEEvqizqJeFNCY1QHDgU1Z3zmlhUFr1grDrUF46V1hGPA8ejSG5cE43CnheLsjN9kSg1jjgc-rlP5s-uiURl0YvFqkN90VhpHfE4WDyKdGOdNAWnpCl4A36DOwT-2CMqdMVbmeF2JiJPCdhHT8qwZph4M4Nujr1onOSCIZR3ZMeIDR5xfenikQfLLia13XdxiVDc2SW5QDwAoqgoU2ZioRUohBci4QXPLPvz3e3ZvpTz_zvrTZ5eFmIeUM5ZUcZU6chGv2LT_DEDcmXW4fdGQ_jcXhtS3LkmHJSc4oy5lnzBIHUS1gI5vDvOWCP6WU2W1kkrKXpmB7MLV8ZEyJAbGXHo0-dPn3UWS4M-YhfZCOMnlYbQ81ml3zONl88UJudmSpWP3jFEYWsVtydLq0FacGkUODY1Y6Qw2cNMJK2du2tCMuTZgyZ8OHx71EZm1LkaXpJXXXkFJiYX-MXJN5tbjK9cy--OIrnk2pUxe-epi4ZGTIyFOIpykSA9aFt7U781-Kg8UIda3dMmew4LHpFldVkMjZKri8Wj1yu2rY5b4akA62PxaPaKfVH5llCvJTsYPGp9QluZTwyr-rhjbXgLvaNLh-pSb81_dOlgXNoclpZqD3XsTW23G88jjIvtV7nIVwoFfJs787qjEVpKGDVCHU9Jquye3onW0eoMbSkaFRS777_2fqrEaSvV01N8a93PeypYWonPngq-XJin946gVVq6WLwXzlyPcfqdPF-7dLTA0skxQmYIkOGHSfkQC4G3y4JRHjCqo-TNTd0wn9vnW4N69vleY-Bdxk_mPFyhk4VTi2nitB0C4OeUgwmmwQ7RHcRJEAYS44uAbdAOLYKQ_0zQCvKL7CKYKpL-9FFwVKuCE0q6r2RS3lVIF4Eg8Vl64iZgycjHYxYH4QqmBZoGZZ7wXaFSdGpFiUgV_F69shRfT_8B1lWxIw)
