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
[![](https://mermaid.ink/img/pako:eNrtWm1v2zYQ_iuchgZua6PfhcBAk6BDUQzrkqH7UBcCLdE2YVl0ScqNlya_fXyRLFIkrWgdDHiTv9jm3XNHHh--HfkQpSRDURylOWTsBsMlhRswK4D4vHgBblEOOSYFW-Et06XXK8RY8hGjFIHJhFT_rwikmatw-X0yAR_htyIg-oCL5Swk_IPCgi0I3SSGqNZ-SyncJ4ZzUZnvU7s2WtNrRnv4vUSoW-sKsxXZdqrdErLuVPpQ4OWKe5qcvIMpJ3Rfucxhuk484g7cnyvMkR_nIj9hhoVMIX-BG5T8tkO0LtXqNUwFNLkqcZ4hDag6wBKYPWMjiAB4OlEw7FryDtygBS6wYlpDviu0gjtMKMzBG3DHaZnyUv5REMQaE9IwUIbZTxVc0dmi1IMWyM_P4D6JAcN_oYSbpXtvaUpyQoVkTkhulovAivoKwR0XndVIXptuRwqtwWNwX9sfg33986WJfDKhlgTdo7TkaDSXcY1Nnl8E7MZgR3Bm2sAsEdXJcdbPjN1wZWYHhZUfMlIWGRl56rhEPLmXgnZHaNE-LFKRHnlcSaHuLCl1eivHjOsGJRuyQ8xXK5imaMtHu9g3gCz9x5rbmoH-qcDhIi4cIraK-rPQ69rk48te2qpnRaVUt4pvm7d--MDg82ewXL1POXlKfzbv_FOlq9c9uyrMQMrzJ6XcN_47pATPY6V0GJw7n5R04NX580odCE452ymHQWI50udMcho0sPH82agPnqeko_YY5GNVob6MrKyeIyXjgZIWJWWS45SElP6CdFSV6UtGZXGYHf8De0CVSjslGbXHIB2rCvUlZGV1oOQ5U1KmIWWwmfALbhBHqgbgDZCJVSATq9JWulb5bm-C8pCOfQikEmuFUTBj6NfYycLRVirE6tTsabGlI08zXTpqk9mlpNf9Li05IXdWSY2RAIEoYmXObS605gonvW1GeQKWUizYQF06OchW-Dvk_9_gN2l8dTtzi7ZCFRVc3ye5g0CrWd2iBmg9EV8aRJ-6Q0TBvUPDI9lSXHDfyGccUq_gwBDflCPraa0KLp7X-dE6qEZrLo6tcu49lxUiNSknlrnPXz5_MVUcC2YsfGJroj-YvLBQT0et_pMIqyDq4BienayzAGJyLFT64uk9RxQ649yOlnFn6TCpMeBZ96yWwmwHC5nr9q7AGSlQYJUaieaI44XRMuuGrNEl26oqr8DI1gIXXr3J1FF85RuZ1xSp0di-U3PXpvqS0VqbUglHyVYmVe-Nxb-577X0qNp4x8Y9qSsObCcCkHl1roytK1qfSsBuELau9mTx4cI2pBKwHIR91dmZ2Lx79igEzIZAa5WAjKv7dM_YCF4MD116rl0afCMwdOnZdGmzj5rrNdSzNrW73XpYYZ1-v6lBvtAsEMvckdcgDWiuaNSAOp6eVIlAsxKtXdcR2VwWaip2H5Ld9VTDaSsl1BO-dg7xPQ3MnRxpTwNfn5nVD7agdRf1bHgvnvme8fTber722WiRpVNjoMw5UEZsJtUTLgTezpk466S82kpeXtYF06m7v7WkR5_7NQ7eF2JnLqYrdPBwKLFdHJZDAMKaRmPChqqTfTSONohuIM6iOFJDYRbxFdqgWRSLnxlaQHEUnkVjLTJfVEqNavAIQUl3FSYXLYJ0FkmRCOajcAFLTu72RRrFC5gzNI7KbSYWj8rQoRRlskq_Vo835dfj38mixQk?type=png)](https://mermaid.live/edit#pako:eNrtWm1v2zYQ_iuchgZua6PfhcBAk6BDUQzrkqH7UBcCLdE2YVl0ScqNlya_fXyRLFIkrWgdDHiTv9jm3XNHHh--HfkQpSRDURylOWTsBsMlhRswK4D4vHgBblEOOSYFW-Et06XXK8RY8hGjFIHJhFT_rwikmatw-X0yAR_htyIg-oCL5Swk_IPCgi0I3SSGqNZ-SyncJ4ZzUZnvU7s2WtNrRnv4vUSoW-sKsxXZdqrdErLuVPpQ4OWKe5qcvIMpJ3Rfucxhuk484g7cnyvMkR_nIj9hhoVMIX-BG5T8tkO0LtXqNUwFNLkqcZ4hDag6wBKYPWMjiAB4OlEw7FryDtygBS6wYlpDviu0gjtMKMzBG3DHaZnyUv5REMQaE9IwUIbZTxVc0dmi1IMWyM_P4D6JAcN_oYSbpXtvaUpyQoVkTkhulovAivoKwR0XndVIXptuRwqtwWNwX9sfg33986WJfDKhlgTdo7TkaDSXcY1Nnl8E7MZgR3Bm2sAsEdXJcdbPjN1wZWYHhZUfMlIWGRl56rhEPLmXgnZHaNE-LFKRHnlcSaHuLCl1eivHjOsGJRuyQ8xXK5imaMtHu9g3gCz9x5rbmoH-qcDhIi4cIraK-rPQ69rk48te2qpnRaVUt4pvm7d--MDg82ewXL1POXlKfzbv_FOlq9c9uyrMQMrzJ6XcN_47pATPY6V0GJw7n5R04NX580odCE452ymHQWI50udMcho0sPH82agPnqeko_YY5GNVob6MrKyeIyXjgZIWJWWS45SElP6CdFSV6UtGZXGYHf8De0CVSjslGbXHIB2rCvUlZGV1oOQ5U1KmIWWwmfALbhBHqgbgDZCJVSATq9JWulb5bm-C8pCOfQikEmuFUTBj6NfYycLRVirE6tTsabGlI08zXTpqk9mlpNf9Li05IXdWSY2RAIEoYmXObS605gonvW1GeQKWUizYQF06OchW-Dvk_9_gN2l8dTtzi7ZCFRVc3ye5g0CrWd2iBmg9EV8aRJ-6Q0TBvUPDI9lSXHDfyGccUq_gwBDflCPraa0KLp7X-dE6qEZrLo6tcu49lxUiNSknlrnPXz5_MVUcC2YsfGJroj-YvLBQT0et_pMIqyDq4BienayzAGJyLFT64uk9RxQ649yOlnFn6TCpMeBZ96yWwmwHC5nr9q7AGSlQYJUaieaI44XRMuuGrNEl26oqr8DI1gIXXr3J1FF85RuZ1xSp0di-U3PXpvqS0VqbUglHyVYmVe-Nxb-577X0qNp4x8Y9qSsObCcCkHl1roytK1qfSsBuELau9mTx4cI2pBKwHIR91dmZ2Lx79igEzIZAa5WAjKv7dM_YCF4MD116rl0afCMwdOnZdGmzj5rrNdSzNrW73XpYYZ1-v6lBvtAsEMvckdcgDWiuaNSAOp6eVIlAsxKtXdcR2VwWaip2H5Ld9VTDaSsl1BO-dg7xPQ3MnRxpTwNfn5nVD7agdRf1bHgvnvme8fTber722WiRpVNjoMw5UEZsJtUTLgTezpk466S82kpeXtYF06m7v7WkR5_7NQ7eF2JnLqYrdPBwKLFdHJZDAMKaRmPChqqTfTSONohuIM6iOFJDYRbxFdqgWRSLnxlaQHEUnkVjLTJfVEqNavAIQUl3FSYXLYJ0FkmRCOajcAFLTu72RRrFC5gzNI7KbSYWj8rQoRRlskq_Vo835dfj38mixQk)
