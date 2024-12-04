
import re

def calculate_ex(input_file_name):
    f = open(input_file_name, "r")
    lines = f.readlines()
    
    e1 = 0
    for l in lines:
        
        print("////")
        n = l.split()
        n_l = [int(i) for i in n]
        
        min_s = True
        max_s = True
        dampener_applied_min = False
        dampener_applied_max = False   

        inc_nl = n_l[0]
        dec_nl = inc_nl
        for i in n_l[1:]:
            d = abs(inc_nl - i)
            if i > inc_nl and d <= 3:
                inc_nl = i
            else:                
                if  d <= 1  and dampener_applied_min == False:
                    print(f"damped min i {i}, inc_nl {inc_nl}")
                    inc_nl = i
                    dampener_applied_min = True                   
                else:
                    min_s = False

            d = abs(i - dec_nl)
            if i < dec_nl and d <= 3:
                dec_nl = i
            else:                
                if  d <= 1  and dampener_applied_max == False:
                    print(f"damped max i {i}, dec_nl {dec_nl}")
                    dec_nl = i
                    dampener_applied_max = True
                else:
                    max_s = False

        safe = False
        if min_s or max_s:
            safe = True
            e1 +=1
        print(n_l)        
        print(safe)

    e2 = 0

    return e1, e2


if __name__ == "__main__":
    ex_res_1, ex_res_2 = calculate_ex("input.txt")