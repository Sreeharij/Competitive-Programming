def main(players,chef_position,players_position):
    least_moves = chef_position
    player = -1
    for position in players_position:
        if (chef_position%position==0) and (chef_position//position-1)<least_moves:
            least_moves = chef_position//position-1
            player = position
    return player

for case in range(int(input())):
    N,K = map(int,input().split())
    P = map(int,input().split())
    print(main(N,K,P))
