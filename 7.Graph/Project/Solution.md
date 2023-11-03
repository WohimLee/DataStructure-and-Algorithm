&emsp;
# Solution

## Graph Construction
>Lifts
- Lift1 connects to Lift2, Lobby1, and Charger.
- Lift2 connects to Lift1, Lift3, and Lobby2.
- Lift3 connects to Lift2 and Lobby3.

>Lobbies
- Each `LobbyX` (where X is the floor number) connects to all `reception rooms` on that floor and its respective `lift`.

>Reception Rooms
- `DX.Y.1` connects to its paired office DX.Y.2 and LobbyX.
    - X is the floor number 
    - Y is the office-reception pair number

>Offices
- DX.Y.2 connects only to its paired reception room DX.Y.1