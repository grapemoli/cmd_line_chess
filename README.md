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
[![](https://mermaid.ink/img/pako:eNrtWm1v2zYQ_iuchgZqa6PfhcBAk2BDUQzrkmH7UBcCLdE2YVl0Kcq1lya_fXyRLFIkI2sYjAlTviThPXdH8R4eySMfg4SkKIiCJINFcYfhisItmOeA_7x6Be5RBhkmebHGu0K13q5RUcSfMEoQmE5J9f8NgTS1Adffp1PwCX7LPaKPOF_NfcLfKcyLJaHbWBPV6PeUwmOsOeed-T4ze6OQTjPKw28lQt2oG1ysya4Tdk_IphP0McerNXN8cvwTTBihx8plBpNN7BB36P25xgy59WzNP3CBuUxq_gy3KP51j2jdquC1mhzQ-KbEWYqUQhUAQ6BHxtQgXMERRM6wW8E7cIeWOMeSaQ35btAa7jGhMAPvwAOjZcJK8Y9UQUVjQhgG0nDxQ6Uu6WxQ6lEJxM-P4BBHoMB_oZjprUdna0IyQrlkQUimt_OB5f3lggfGg9VI3upuQ6mtlCfgUNufgGP952td81lXNSTogJKSoXAhxjXSeX7lsRuBPcGpbgMXMe9OhtN-ZswPl2b2kFsJz8SXeUpCR3dWiMUHIWiPuRId_SI5qKHDlRCquAipFZgMF0z1Pd6SPSpcvYJJgnYs3EeuuWLgn2oaK7K5Z71FO5xbnGs19Sec07VOvde90JIJvFMyrPy3SVG3-kjWQZFVrMmXTInCn0kxdwK0cd05U-qM_BsU_8TG79_hHziPgMKhNyM-S-lIoUFRSG7eL5nDpEMvhyzpOalLKY3EGxTx1HnwksxTHr3UqzrUl3yV1ZF9g2KfKDNcknvCn5d5sjN9eSctjqwb1n5N1q0uyTvl0cu8qkN9uVdZHdk3EPaJ8p4Y14L7BXeIIdkD8A6IgiUQBUthK9nIOrKz8Hcqcz56SnQ1IPRW4tyIvWgMdwIQyXOr44sNjDhkdGHkhrALpBbuLpRIs51dktPBQyCKijJjJhdaacEqG-ujPAUrIeZsoDadLM3W8HfI_7-D35TH5a3HPdpxKMqZuqexJ4GCGWGRE7TOudca0Wc6SuQHV5bQzDqnjEOyozhnroxQMEidghNzXKlI9N9YGGx9Vhcp68F2Vi2vPIOfSIjU9GVi3UpbXYDaGbY1cezrKyNCcg2JDS-fv3z-okMsC_qQu8TGunQyeWVoPb9o9Z8E8r8ZK2c01JXVB4YotDKZGRDtttOaE40Bx07AGEyY7mGeoNC9nUhJjjzrcMiDEIHDqTwfmXdrDZbsqq68AaGJAldO3HRmAd-4cs8tRTLftG_j7NW3vp40Vt9EqKN4Jwq3By1QzU2xgaPywBBpN6y22BN6j8qiOvpGxuWuC-Kx61XbVBvM6HTV64N4LHvVvqpaUaTfWjsAHrM-pY2sfEbVTbxjbnivlMeQDjWk3tcFY0gHE9JmAVyoZdqxNrXDbjzJMI7y3-QkXyoW8GXuhXckjdJC0qhR6ni0UtUq9U609o8vyBaiUVGx-8Rvr6dKnbZKWT3VN1ZFoqeBhVXG7Wng65l3DN4vaF2Cna3ei2euB0D9drdvXTZaZOlEjJQZAmX4ZlI-_kLg_aLgJ4GEVVvJ6-u6YTaz97eG9MWHgo2DDznfmfN0hU4eTi2mi9NyCIAfqX2M31BVuwgmwRbRLcRpEAVyKswDtkZbNA8i_meKlpAf9ufBRIn0t5gCUU0eLijpvtLJ-BdBOg-EiA_mE3cBS0YejnkSREuYFWgSlLuULx6VoVMrSkWXfqmefYpfT38DrZ3UgQ?type=png)](https://mermaid.live/edit#pako:eNrtWm1v2zYQ_iuchgZqa6PfhcBAk2BDUQzrkmH7UBcCLdE2YVl0Kcq1lya_fXyRLFIkI2sYjAlTviThPXdH8R4eySMfg4SkKIiCJINFcYfhisItmOeA_7x6Be5RBhkmebHGu0K13q5RUcSfMEoQmE5J9f8NgTS1Adffp1PwCX7LPaKPOF_NfcLfKcyLJaHbWBPV6PeUwmOsOeed-T4ze6OQTjPKw28lQt2oG1ysya4Tdk_IphP0McerNXN8cvwTTBihx8plBpNN7BB36P25xgy59WzNP3CBuUxq_gy3KP51j2jdquC1mhzQ-KbEWYqUQhUAQ6BHxtQgXMERRM6wW8E7cIeWOMeSaQ35btAa7jGhMAPvwAOjZcJK8Y9UQUVjQhgG0nDxQ6Uu6WxQ6lEJxM-P4BBHoMB_oZjprUdna0IyQrlkQUimt_OB5f3lggfGg9VI3upuQ6mtlCfgUNufgGP952td81lXNSTogJKSoXAhxjXSeX7lsRuBPcGpbgMXMe9OhtN-ZswPl2b2kFsJz8SXeUpCR3dWiMUHIWiPuRId_SI5qKHDlRCquAipFZgMF0z1Pd6SPSpcvYJJgnYs3EeuuWLgn2oaK7K5Z71FO5xbnGs19Sec07VOvde90JIJvFMyrPy3SVG3-kjWQZFVrMmXTInCn0kxdwK0cd05U-qM_BsU_8TG79_hHziPgMKhNyM-S-lIoUFRSG7eL5nDpEMvhyzpOalLKY3EGxTx1HnwksxTHr3UqzrUl3yV1ZF9g2KfKDNcknvCn5d5sjN9eSctjqwb1n5N1q0uyTvl0cu8qkN9uVdZHdk3EPaJ8p4Y14L7BXeIIdkD8A6IgiUQBUthK9nIOrKz8Hcqcz56SnQ1IPRW4tyIvWgMdwIQyXOr44sNjDhkdGHkhrALpBbuLpRIs51dktPBQyCKijJjJhdaacEqG-ujPAUrIeZsoDadLM3W8HfI_7-D35TH5a3HPdpxKMqZuqexJ4GCGWGRE7TOudca0Wc6SuQHV5bQzDqnjEOyozhnroxQMEidghNzXKlI9N9YGGx9Vhcp68F2Vi2vPIOfSIjU9GVi3UpbXYDaGbY1cezrKyNCcg2JDS-fv3z-okMsC_qQu8TGunQyeWVoPb9o9Z8E8r8ZK2c01JXVB4YotDKZGRDtttOaE40Bx07AGEyY7mGeoNC9nUhJjjzrcMiDEIHDqTwfmXdrDZbsqq68AaGJAldO3HRmAd-4cs8tRTLftG_j7NW3vp40Vt9EqKN4Jwq3By1QzU2xgaPywBBpN6y22BN6j8qiOvpGxuWuC-Kx61XbVBvM6HTV64N4LHvVvqpaUaTfWjsAHrM-pY2sfEbVTbxjbnivlMeQDjWk3tcFY0gHE9JmAVyoZdqxNrXDbjzJMI7y3-QkXyoW8GXuhXckjdJC0qhR6ni0UtUq9U609o8vyBaiUVGx-8Rvr6dKnbZKWT3VN1ZFoqeBhVXG7Wng65l3DN4vaF2Cna3ei2euB0D9drdvXTZaZOlEjJQZAmX4ZlI-_kLg_aLgJ4GEVVvJ6-u6YTaz97eG9MWHgo2DDznfmfN0hU4eTi2mi9NyCIAfqX2M31BVuwgmwRbRLcRpEAVyKswDtkZbNA8i_meKlpAf9ufBRIn0t5gCUU0eLijpvtLJ-BdBOg-EiA_mE3cBS0YejnkSREuYFWgSlLuULx6VoVMrSkWXfqmefYpfT38DrZ3UgQ)
