# Game Theory and Dynamic Programming

## Combinatorial games
Combinatorial games ar two-person games with perfect information and no chance move,
and with a win-or-lose outcome

## Impartial games and partizan games

Impartial games in which the set of moves available from any give position is the same for both players, and partizan games in which each player has a different set of possible moves from a given position

## Normal / Misere rule

Terminal position
- Normal: the last player to make a move wins
- misere: the last player to make a move loses

## Take awy game(misere rule)

## N and P Positions

P-position: the position wining for pervious player.
N-position: the position wining for next player.

P-position: Loose potions
N-position: Win potions

Terminal position: No legal move is possible
Steps
- #1 Mark all terminal positions as P-position
- #2 Mark all terminal positions which can reach(has at least) any P-position as N-position
- #3 Mark all the positions as P-position from which we can only move to N-position in step #2
- #4 If no new position break. Other wise got to #2