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

For collision detection: check the color, if different then replace. 
For Game Over dectection: get the concretion, if opposing color & king, then return game_over.

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
[![](https://mermaid.ink/img/pako:eNrtWu2P2jYY_1e8TJ1oC-r36ITUu9OmqprWXaftQ6kikxiwCHHqOBR2vfvb55eE2LFNSFUhZQpfAD-vtn9-bD-PH4OYJCgIgziFRXGP4ZrCHVhkgH9evAAPKIUMk6zY4LxQrXcbVBTRB4xiBGYzUv2_JZAmNsPNt9kMfIBfMw_pPc7WCx_xLwqzYkXoLtJINfdbSuEx0oxzZ77NTW8Up1ONsvBniVA31y0uNiTvZHsgZNvJ9D7D6w1zdDn6FcaM0GNlMoXxNnKQO-T-2WCG3HK25N-4wJwmJe9ImvK_JIvuEUOxmPOargRrBXJoo9sSpwlSotVUGAR9jkwJwgUc08mxdicQCO7RCmdYYq6B4S3awD0mFKbgDfjIaBmzUvyRIqhoVAjFQCoufqrEJbANcD0qgvj8DA5RCAr8L4qY3np0tsYkJZRTloSkejtU4xVy1_i0NZTXutmJlFbCU3Co9U_Bsf75Upd81kUNCjqguGRoshTjGuqI96gNwZ7gRFeBiygWE5700mJ2W2rZQ67EoSO8VEeZJWTi8HCNWHQQhPYsKNLRT5LDPHGYEkQ1U4JqTRWHP1P9iXZkjwqXVzCOUc4m-9C1jgz-pxrYCn7uiGABEWcWCltN_SHoNK2D8WUvbokO7pScVv5tgtYtPsJ34PAVO_g1w6awZ4LOHSRtvu64KmVGRA4ckeLg-GMQCS6DpDDojZrPkjqCauCgkteBa8Y5adCLKot6SXhTQiMUBw5Fdee8JhaVRS8YK4f6wrHSOuJx4HgUyY1rolHY82JROtMXiVLjiMOhn_tk_uyaSFQWvVisHOqLxkrriMfB4lGkG-ukKTglTcEb8BvcIfDHHlGhK97KDLczEXlKwD56UoY1w8SbGXRz7EXjJBcMobwjO3ps8IjrSxePPFh2MantvotLhOJOl-QCORcKzqSsWyPqZ2yP7KWc_-cRbrLusqzygHKKCpQxVQiysazYtBGfAbnO6mB6o-F1biNdijsR7qDkFGfMtYALBqmTsOarMeLuOCOH8LMaDs1JK8V5BoR2GcoYCBlAIyOqfPr86bPOYmnQe-wiG0H5pNIQej6r9HuG8fKRwuTcSKli0DuGKGyt0_ZgaRVFCy6NAscWZfQUJnuYiRS0c69MSIY8O8qEd4dvdlrPjKpVw0vyypVXYGJygV-cfLO5xfjKtfzuKJJLrl3nsveRugRoRL1YiKMoF-nOg7ZRN9VYg4_K43GoVTFtsmfr94gsq6tfaBRQXSwevV6xbXV4Ck_lVB-LR7NX7IvKnoR6ZdjB4FHrE9rK7GBYVbsda8Nbth2ndKhT6q3gj1M6mCltrhdLtYc69qb2tBuPHYxr6le5yFcKBXybO_NWoxFaShg1Qh0PQ6pcne5E62h1hrYUjQqK3bdZez9V4rSVuOkpvrVu2z0VLK00Zk8FXy7Munt70CoUXSzeC2eupzX9Tp6vXTpaYOnkGCEzBMjww6R8VoXA22XBKA8Y1VHy5qZumM_t861BPfsYrzHwLuMncx6u0MnCqcU0cdoOAfBzys4E02CH6A7iJAgDifFFwDZohxZByH8maAXLlC2CqSLpDxkFR7UqOKGk-0om5a5CuggEiY_SEzcBS0Y-HrM4CFcwLdA0KPOE7wqVolMrSkQy4PfqzaT4evoP3wKkBA?type=png)](https://mermaid.live/edit#pako:eNrtWu2P2jYY_1e8TJ1oC-r36ITUu9OmqprWXaftQ6kikxiwCHHqOBR2vfvb55eE2LFNSFUhZQpfAD-vtn9-bD-PH4OYJCgIgziFRXGP4ZrCHVhkgH9evAAPKIUMk6zY4LxQrXcbVBTRB4xiBGYzUv2_JZAmNsPNt9kMfIBfMw_pPc7WCx_xLwqzYkXoLtJINfdbSuEx0oxzZ77NTW8Up1ONsvBniVA31y0uNiTvZHsgZNvJ9D7D6w1zdDn6FcaM0GNlMoXxNnKQO-T-2WCG3HK25N-4wJwmJe9ImvK_JIvuEUOxmPOargRrBXJoo9sSpwlSotVUGAR9jkwJwgUc08mxdicQCO7RCmdYYq6B4S3awD0mFKbgDfjIaBmzUvyRIqhoVAjFQCoufqrEJbANcD0qgvj8DA5RCAr8L4qY3np0tsYkJZRTloSkejtU4xVy1_i0NZTXutmJlFbCU3Co9U_Bsf75Upd81kUNCjqguGRoshTjGuqI96gNwZ7gRFeBiygWE5700mJ2W2rZQ67EoSO8VEeZJWTi8HCNWHQQhPYsKNLRT5LDPHGYEkQ1U4JqTRWHP1P9iXZkjwqXVzCOUc4m-9C1jgz-pxrYCn7uiGABEWcWCltN_SHoNK2D8WUvbokO7pScVv5tgtYtPsJ34PAVO_g1w6awZ4LOHSRtvu64KmVGRA4ckeLg-GMQCS6DpDDojZrPkjqCauCgkteBa8Y5adCLKot6SXhTQiMUBw5Fdee8JhaVRS8YK4f6wrHSOuJx4HgUyY1rolHY82JROtMXiVLjiMOhn_tk_uyaSFQWvVisHOqLxkrriMfB4lGkG-ukKTglTcEb8BvcIfDHHlGhK97KDLczEXlKwD56UoY1w8SbGXRz7EXjJBcMobwjO3ps8IjrSxePPFh2MantvotLhOJOl-QCORcKzqSsWyPqZ2yP7KWc_-cRbrLusqzygHKKCpQxVQiysazYtBGfAbnO6mB6o-F1biNdijsR7qDkFGfMtYALBqmTsOarMeLuOCOH8LMaDs1JK8V5BoR2GcoYCBlAIyOqfPr86bPOYmnQe-wiG0H5pNIQej6r9HuG8fKRwuTcSKli0DuGKGyt0_ZgaRVFCy6NAscWZfQUJnuYiRS0c69MSIY8O8qEd4dvdlrPjKpVw0vyypVXYGJygV-cfLO5xfjKtfzuKJJLrl3nsveRugRoRL1YiKMoF-nOg7ZRN9VYg4_K43GoVTFtsmfr94gsq6tfaBRQXSwevV6xbXV4Ck_lVB-LR7NX7IvKnoR6ZdjB4FHrE9rK7GBYVbsda8Nbth2ndKhT6q3gj1M6mCltrhdLtYc69qb2tBuPHYxr6le5yFcKBXybO_NWoxFaShg1Qh0PQ6pcne5E62h1hrYUjQqK3bdZez9V4rSVuOkpvrVu2z0VLK00Zk8FXy7Munt70CoUXSzeC2eupzX9Tp6vXTpaYOnkGCEzBMjww6R8VoXA22XBKA8Y1VHy5qZumM_t861BPfsYrzHwLuMncx6u0MnCqcU0cdoOAfBzys4E02CH6A7iJAgDifFFwDZohxZByH8maAXLlC2CqSLpDxkFR7UqOKGk-0om5a5CuggEiY_SEzcBS0Y-HrM4CFcwLdA0KPOE7wqVolMrSkQy4PfqzaT4evoP3wKkBA)
