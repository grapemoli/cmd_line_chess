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
[![](https://mermaid.ink/img/pako:eNrtWVtrIjEU_ivZgRbbKvs-iNBaFkopdOvCPtQyxJmowXEym2RcpZffvkkmjkmTqLCsFLd9seZ855J8J5dzfI5SkqEojtIcMnaN4YTCORgWQPydnIAHlEOOScGmuGT1aH-KGEvuMUoR6HSI_n5FIM1cQPel0wH38HcREN3iYjIMCX9QWLAxofPEEK3Rl5TCVWI4F8G89OxoaqTXTO3he4XQbtQVZlNS7oQ9EDLbCbot8GTKZWjOpJNvMOWErrTTHKazxCPeofdzijny6619Cl77km1wjca4wIrfDeVXaAoXmFCYg69gwGmV8kp-USqIbUxIF0C5YF-0ukoii8jnWiD_OmCZxAAX3BxauUMpyQkVwyNCcnNcTENEKgQDLpZmI7kwHbaUdq18ZmLeTJAlQUuUVhy1RjJpYjODzmKwIDgzwZglwkOOswDeDvoCVEVGWh47E8STpRRYk6_HV57xHDOelIQxPMpRMicLxGyzr2t2aw78KXgQNryug7zsRLfBUgXVBiv1abPqVz9-fuWZehg6pacge--F28lS6OPnRl5qf8sN2I8c6Sp85Cnp8a-3usUPsxmUq-CCO9Lt26GGHz8_9fvpMATVvoIM6VD250jbO36S5Ov1MBRJT0GCVBj706Ns_Qc3iqoaDkNP7StIkA5lf4q0vWMlaVM3qSLUqpLMcqgWWwwqk2sKusb7tecWN0q95atoPJKSiqn4loBxSL0CGUqrlL5jIw6H2C0p6tbj1lwVc0lslmqPT49PJsSxYE7KJ7ayoTFpKb1tNfpvVwqTbSulgkluOKJQVOfbFstorTgZsTHg2xumEswWsJClkXeDZaRQovd7SeyNlphODJbGzKxuzAZLSh3KOWjZKHDqxXV6DvDct7P6FKkm1PsmhNNtaDohz6a_VKqjpFTFR2x0oywxVTdJbHRxXLHDcQA80o-G2God-SCOxaDCTB-jcdNCCkEcm0GFX_UDNDb7YB6AYzAEn6l6I9ZdPU_qB5tTn4x9UMaCbchPxj4UY81hOeDicEWTFRiLE_ZOXFZzVHBwCvryCcXEKQquEUfq9WfpqV4wApcjJgykXB-x3e56oNdzz31LurVbv3FwU4gbawxT1HhoRmwXTaIBEEaqey5qR3NE5xBnURyptBxGfComPoxi8W-GxrDK-TBq1yLzlw6J0IksBBVdaJ1chArpMJIisb6vwgWsOBmsijSKxzBnqB1VZSZWWhtqRlGGRdR3-kcV-fH6B7IDllM?type=png)](https://mermaid.live/edit#pako:eNrtWVtrIjEU_ivZgRbbKvs-iNBaFkopdOvCPtQyxJmowXEym2RcpZffvkkmjkmTqLCsFLd9seZ855J8J5dzfI5SkqEojtIcMnaN4YTCORgWQPydnIAHlEOOScGmuGT1aH-KGEvuMUoR6HSI_n5FIM1cQPel0wH38HcREN3iYjIMCX9QWLAxofPEEK3Rl5TCVWI4F8G89OxoaqTXTO3he4XQbtQVZlNS7oQ9EDLbCbot8GTKZWjOpJNvMOWErrTTHKazxCPeofdzijny6619Cl77km1wjca4wIrfDeVXaAoXmFCYg69gwGmV8kp-USqIbUxIF0C5YF-0ukoii8jnWiD_OmCZxAAX3BxauUMpyQkVwyNCcnNcTENEKgQDLpZmI7kwHbaUdq18ZmLeTJAlQUuUVhy1RjJpYjODzmKwIDgzwZglwkOOswDeDvoCVEVGWh47E8STpRRYk6_HV57xHDOelIQxPMpRMicLxGyzr2t2aw78KXgQNryug7zsRLfBUgXVBiv1abPqVz9-fuWZehg6pacge--F28lS6OPnRl5qf8sN2I8c6Sp85Cnp8a-3usUPsxmUq-CCO9Lt26GGHz8_9fvpMATVvoIM6VD250jbO36S5Ov1MBRJT0GCVBj706Ns_Qc3iqoaDkNP7StIkA5lf4q0vWMlaVM3qSLUqpLMcqgWWwwqk2sKusb7tecWN0q95atoPJKSiqn4loBxSL0CGUqrlL5jIw6H2C0p6tbj1lwVc0lslmqPT49PJsSxYE7KJ7ayoTFpKb1tNfpvVwqTbSulgkluOKJQVOfbFstorTgZsTHg2xumEswWsJClkXeDZaRQovd7SeyNlphODJbGzKxuzAZLSh3KOWjZKHDqxXV6DvDct7P6FKkm1PsmhNNtaDohz6a_VKqjpFTFR2x0oywxVTdJbHRxXLHDcQA80o-G2God-SCOxaDCTB-jcdNCCkEcm0GFX_UDNDb7YB6AYzAEn6l6I9ZdPU_qB5tTn4x9UMaCbchPxj4UY81hOeDicEWTFRiLE_ZOXFZzVHBwCvryCcXEKQquEUfq9WfpqV4wApcjJgykXB-x3e56oNdzz31LurVbv3FwU4gbawxT1HhoRmwXTaIBEEaqey5qR3NE5xBnURyptBxGfComPoxi8W-GxrDK-TBq1yLzlw6J0IksBBVdaJ1chArpMJIisb6vwgWsOBmsijSKxzBnqB1VZSZWWhtqRlGGRdR3-kcV-fH6B7IDllM)
