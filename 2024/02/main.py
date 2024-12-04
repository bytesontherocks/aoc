
import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    
    e1 = 0
    for l in lines:
    
        n = l.split()
        n_l = [int(i) for i in n]

        l_i = n_l.copy()
        l_i.sort()
        l_d = n_l.copy()
        l_d.sort(reverse=True)

        if n_l != l_i and n_l != l_d:
            continue
        
        last = n_l[0]
        d = []
        for i in n_l[1:]:
            delta = abs(i  - last)
            d.append(delta <= 3 and delta > 0)
            last = i
        if all(d):
            e1 += 1
 

    e2 = 0

    return e1, e2


if __name__ == "__main__":
    ex_res_1, ex_res_2 = calculate_ex("input.txt")