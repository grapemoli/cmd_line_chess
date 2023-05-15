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
[![](https://mermaid.ink/img/pako:eNrtWltv2zYU_iuchg5ua6PvQmCgSbChKIZ16bA91IVAS7RNWBZdUnLjpclvH2-ySJG0rKIwnEF-sc1z1Tkfb-foIUpJhqI4SnPI2C2GSwo3YFYA_nnxAtyhHJaYFGyFt0yN3qwQY8kHjFIEJhOi_18TSDOX4erbZAI-wK9FgPQeF8tZiPgXhQVbELpJDFLN_ZZSuE8M49yZb1PbG8XpVaMs_Fkh1M11jdmKbDvZ7ghZdzK9L_ByVXoeOfkVpiWhe20yh-k68ZA75P5Z4RL55VzJvzHDnCYlb0ie87-kSG5RiVKR85quBGsFMrTJdYXzDClRnQqLYObIliBcwJNOjrUbgUBwixa4wBJzDQyv0QruMKEwB2_Ax5JWaVmJP1IEsUaFUAykYvaTFpfAtsD1oAji8zO4T2LA8L8oKc3RvXc0JTmhnDInJDfHoYpXzF3jaWsor02zIymthMfgvtY_Bvv650tT8skUtSjoHqVViUZzEdfYRHxAbQx2BGemCsySVCQ866XFfmypZQe5Eo-O-FQdVZGRkcfDJSqTe0FoZ0GR9mGSDPPIY0oQVaYE1UkVh3-ZbAljeJ6jZEN2iNmOPdZYVYjyT3IHW7hwgNUa6o8qr2kTXy97ccuEc6dkpvi3jUO_-IDIy0Ok2GfPubgJezaO_EuZy9e9-kmZAWSXBzJxYvsxIAOnoUwYDK5tT5I64OTycCKP1udcjaTBIFAc6imLkBIa0HV56FJXsnPCS1kM4ks71BdhWusAscuDmLjOnxNgwl4QXtKZvuCSGgdoXeAZShaBzgkuZTEIL-1QX4BprQPELgliogxWF_PAoZgH3oDf4AaBP3aIilCka1l59RbIDoXBh0Apq2YYBStWfo6dGBxtBUMsb4We0Fo84nTfxSMPaV1Map_t4hILZqdLEvPHZveRUmoromHGdmRP5fw_R7ipBsty_x3aUsRQUaoGhYtlxWZEfALkvKnXxysDr1MX6VLci3APZUtxUfpWClZC6iUs-WxMuDvexUD4qcNhOOnU6Y6A0G2PWIGQa2ISm5P60-dPn00WR4P5xD6ytc4eVFpCT0eVfk8YT48UJscipZoU70pEYWuetoNldLocuDQKPLuO9aQw28FC1FG9219GChTYJEb8cfj-ZTyZ1U1peMlWu_IKjGwu8IuXbzJ1GF_5pt8NRXLKtfsv7j5St6asVS8V4ijZigLfvbH3Nl1Ci4_KQ2xsdNdccmA3D4jM9Z0rthp7PpaA3qDYWp-H4kObL8QS0BwU-6IqEbHZsfQwBNSGhNayeBbrLqxnbgTbiUNKn2tKg53lIaXPJqXNjWGu9lDP3tROu9WEt26eX-UkXygU8G3uyDsEjdBcwqgR6nhhQRfJTCdaR6sjtLkYVFDsvqC6-6kSp63ySk_xtXOB7qlg7tQPeyr4cmIFO_gErT7KyeK9cOZ75aPfyfO1T0cLLJ0cA2SeA2T4YVK-7oPA2zkrKV8w9FHy6qoemE7d861FPfqSWGPgXcFP5ny5QgcLhxHbxGE7BCDMKR8mGkcbRDcQZ1EcSYzPonKFNmgWxfxnhhawystZNFYk8wU7waFnBSdUdKdlcu4qpLNIkHiUHrkJWJXk475Io3gBc4bGUbXN-K6gFR1GUSaKAb_rd_nE1-N_73k0rA?type=png)](https://mermaid.live/edit#pako:eNrtWltv2zYU_iuchg5ua6PvQmCgSbChKIZ16bA91IVAS7RNWBZdUnLjpclvH2-ySJG0rKIwnEF-sc1z1Tkfb-foIUpJhqI4SnPI2C2GSwo3YFYA_nnxAtyhHJaYFGyFt0yN3qwQY8kHjFIEJhOi_18TSDOX4erbZAI-wK9FgPQeF8tZiPgXhQVbELpJDFLN_ZZSuE8M49yZb1PbG8XpVaMs_Fkh1M11jdmKbDvZ7ghZdzK9L_ByVXoeOfkVpiWhe20yh-k68ZA75P5Z4RL55VzJvzHDnCYlb0ie87-kSG5RiVKR85quBGsFMrTJdYXzDClRnQqLYObIliBcwJNOjrUbgUBwixa4wBJzDQyv0QruMKEwB2_Ax5JWaVmJP1IEsUaFUAykYvaTFpfAtsD1oAji8zO4T2LA8L8oKc3RvXc0JTmhnDInJDfHoYpXzF3jaWsor02zIymthMfgvtY_Bvv650tT8skUtSjoHqVViUZzEdfYRHxAbQx2BGemCsySVCQ866XFfmypZQe5Eo-O-FQdVZGRkcfDJSqTe0FoZ0GR9mGSDPPIY0oQVaYE1UkVh3-ZbAljeJ6jZEN2iNmOPdZYVYjyT3IHW7hwgNUa6o8qr2kTXy97ccuEc6dkpvi3jUO_-IDIy0Ok2GfPubgJezaO_EuZy9e9-kmZAWSXBzJxYvsxIAOnoUwYDK5tT5I64OTycCKP1udcjaTBIFAc6imLkBIa0HV56FJXsnPCS1kM4ks71BdhWusAscuDmLjOnxNgwl4QXtKZvuCSGgdoXeAZShaBzgkuZTEIL-1QX4BprQPELgliogxWF_PAoZgH3oDf4AaBP3aIilCka1l59RbIDoXBh0Apq2YYBStWfo6dGBxtBUMsb4We0Fo84nTfxSMPaV1Map_t4hILZqdLEvPHZveRUmoromHGdmRP5fw_R7ipBsty_x3aUsRQUaoGhYtlxWZEfALkvKnXxysDr1MX6VLci3APZUtxUfpWClZC6iUs-WxMuDvexUD4qcNhOOnU6Y6A0G2PWIGQa2ISm5P60-dPn00WR4P5xD6ytc4eVFpCT0eVfk8YT48UJscipZoU70pEYWuetoNldLocuDQKPLuO9aQw28FC1FG9219GChTYJEb8cfj-ZTyZ1U1peMlWu_IKjGwu8IuXbzJ1GF_5pt8NRXLKtfsv7j5St6asVS8V4ijZigLfvbH3Nl1Ci4_KQ2xsdNdccmA3D4jM9Z0rthp7PpaA3qDYWp-H4kObL8QS0BwU-6IqEbHZsfQwBNSGhNayeBbrLqxnbgTbiUNKn2tKg53lIaXPJqXNjWGu9lDP3tROu9WEt26eX-UkXygU8G3uyDsEjdBcwqgR6nhhQRfJTCdaR6sjtLkYVFDsvqC6-6kSp63ySk_xtXOB7qlg7tQPeyr4cmIFO_gErT7KyeK9cOZ75aPfyfO1T0cLLJ0cA2SeA2T4YVK-7oPA2zkrKV8w9FHy6qoemE7d861FPfqSWGPgXcFP5ny5QgcLhxHbxGE7BCDMKR8mGkcbRDcQZ1EcSYzPonKFNmgWxfxnhhawystZNFYk8wU7waFnBSdUdKdlcu4qpLNIkHiUHrkJWJXk475Io3gBc4bGUbXN-K6gFR1GUSaKAb_rd_nE1-N_73k0rA)
