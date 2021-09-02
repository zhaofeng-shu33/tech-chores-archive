k = input()
k = int(k)
Ls = input().split(' ')
m_n_list = []
for i in Ls:
    m,n = i.split(',')
    m_n_list.append([int(m), int(n)])
a = input()
a = int(a)
# print(m_n_list[-1][0] * 2)
dic_save = {}
def get_min(current_index, first_round_packet, second_round_packet, can_current_broken):
    #if current_index == 5 and first_round_packet + second_round_packet==15:
    #    import pdb
    #    pdb.set_trace()
    # import pdb
    # pdb.set_trace()
    if current_index == k:
        return first_round_packet + second_round_packet
    if can_current_broken:
        if dic_save.get((current_index+1, first_round_packet, second_round_packet, False)):
            current_broken = dic_save[(current_index+1, first_round_packet, second_round_packet, False)]
        else:
            current_broken = get_min(current_index+1, first_round_packet, second_round_packet, False)
            dic_save[(current_index+1, first_round_packet, second_round_packet, False)] = current_broken
    else:
        current_broken = 10000000
    if first_round_packet > m_n_list[current_index][0]:
        next_first_round_packet = m_n_list[current_index][0]
        next_second_round_packet = first_round_packet - m_n_list[current_index][0]
        if next_second_round_packet > m_n_list[current_index][1]:
            next_second_round_packet = m_n_list[current_index][1]
        if second_round_packet + next_second_round_packet > m_n_list[current_index][0]:
            next_second_round_packet = m_n_list[current_index][0]
        else:
            next_second_round_packet = second_round_packet + next_second_round_packet
    else:
        next_first_round_packet = first_round_packet
        if second_round_packet > m_n_list[current_index][0]:
            next_second_round_packet = m_n_list[current_index][0]
        else:
            next_second_round_packet = second_round_packet

    if dic_save.get((current_index+1, next_first_round_packet, next_second_round_packet, True)):
        no_broken = dic_save[(current_index+1, next_first_round_packet, next_second_round_packet, True)]
    else:
        no_broken = get_min(current_index+1, next_first_round_packet, next_second_round_packet, True)
        dic_save[(current_index+1, next_first_round_packet, next_second_round_packet, True)] = no_broken

    # no_broken = get_min(current_index + 1, next_first_round_packet, next_second_round_packet, True)
    return min(no_broken, current_broken)
    
print(get_min(0, a, 0, True))

