
def sock_pairs(socks):
    sock_list = {}
    for sock in socks:
        sock_list[sock] = sock_list[sock] + 1 if sock in sock_list else 1

    pair_count = 0
    for sock in sock_list:
        pair_count += int(sock_list[sock] / 2)
        
    return pair_count
